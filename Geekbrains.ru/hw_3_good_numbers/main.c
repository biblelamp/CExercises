#include <stdio.h>
#include <sys/time.h>

struct timeval tv1,tv2,dtv;
struct timezone tz;

void time_start()
{
    gettimeofday(&tv1, &tz);
}

long time_stop()
{
    gettimeofday(&tv2, &tz);
    dtv.tv_sec= tv2.tv_sec -tv1.tv_sec;
    dtv.tv_usec=tv2.tv_usec-tv1.tv_usec;
    if(dtv.tv_usec<0)
    {
        dtv.tv_sec--; dtv.tv_usec+=1000000;
    }
    return dtv.tv_sec*1000+dtv.tv_usec/1000;
}

int is_good(long x)
{
    long y=x;
    int s=0;
    while(x > 0)
    {
        s += x % 10;
        x /= 10;
    }
    if (y % s == 0) return 1;
    return 0;
}

int main()
{
    long count=0;
    time_start();
    for (long i = 1; i < 1000001; i++)
    {
        if (is_good(i))
        {
            count++;
        }
    }
    printf("Count of good number is %ld\n", count);
    printf("Time: %ld millisecond\n", time_stop());
    return 0;
}
