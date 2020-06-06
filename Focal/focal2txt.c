#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static int verbose = 0;
static unsigned char file[040000];
static unsigned short BASE;
static int file_length = 0;
static int address_out_of_range = 0;

unsigned byte(int a) {
 int offset = a - BASE + 20;
 if((offset < 0) || (offset >= file_length)) {
  address_out_of_range = 1;
  return 0;
 } else {
  return *(file + offset);
 }
}

unsigned word(int a) {
 return byte(a) + (byte(a + 1) << 8);
}

char f2a(char c) {
 switch(c) {
   case '\201':
     return '+';
   case '\202':
     return '-';
   case '\203':
     return '/';
   case '\204':
     return '*';
   case '\205':
     return '^';
   case '\206':
     return '(';
   case '\207':
     return '[';
   case '\210':
     return '<';
   case '\211':
     return ')';
   case '\212':
     return ']';
   case '\213':
     return '>';
   case '\214':
     return ',';
   case '\215':
     return ';';
   case '\217':
     return '=';
   default:
     return c;
 }
}

void focal_print(char *name)
{
 int i;
 unsigned short ADDRESS, RELOC, STRING;
 unsigned long  SNUM;
 unsigned length;

 BASE = 0;
 address_out_of_range = 0;
 
 if(verbose) {
    fprintf(stderr, "Processing file <%s>.\n", name);
 }
 
 if((i = open(name, O_RDONLY)) < 0) {
  fprintf(stderr, "Can not open file <%s> ", name);
  perror("open()");
  return;
 }

 if((file_length = read(i, file, 040000)) < 0) {
  fprintf(stderr, "Can not read file <%s> ", name);
  perror("read()");
  close(i);
  return;
 }

 if(verbose) {
    fprintf(stderr, "File length = %d bytes.\n", file_length);
 }
 
 if(file_length >= 037777) {
  fprintf(stderr, "File is larger than 40000(oct) bytes.\n");
  close(i);
  return;
 }

 close(i);

 if(word(-20) != 01752) {
  fprintf(stderr, "File is not a valid FOCAL file. Singature = %o\n", word(-20));
  return;
 }

 fprintf(stderr, "FOCAL program length = %o(oct) bytes\n", length = word(-18));

 BASE = (unsigned short)word(-20);

 for(ADDRESS = BASE;;)
 {
  RELOC = word(ADDRESS);
  SNUM = (word(ADDRESS += 2)*1000L)/256L;
  if(address_out_of_range) {
    fprintf(stderr, "Address out of range in FOCAL file (%o,%o).\n", ADDRESS, ADDRESS - 2);
    return;
  }
  STRING = (ADDRESS + 2);

  printf("%3ld.", SNUM/1000L);
  SNUM %= 1000;
  if(SNUM % 10 >= 5) SNUM+=10;
  SNUM /= 10;
  printf("%02ld ", SNUM);

  for(i = STRING; byte(i) != 0216; i++){
   if(address_out_of_range) {
     fprintf(stderr, "Address out of range in FOCAL file (str,%o).\n", i);
     return;
   }
   printf("%c", f2a(byte(i)));
  }
  printf("\n");

  ADDRESS += RELOC;
  if(ADDRESS == 0)break;
 }
}

int main(int ac, char *av[]) {
 int i;

 for(i = 1; i < ac; i++) {
  if(!strcmp(av[i], "-v")) verbose = 1;
  else focal_print(av[i]);
 }

 exit(0);
}
