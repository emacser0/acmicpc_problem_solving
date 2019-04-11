#include <stdio.h>
#include <time.h>
time_t timer;
struct tm *t;
char buf[100];

int
main() {
    timer=time(NULL);
    t=localtime(&timer);
    strftime(buf,100,"%Y-%m-%d",t);
    printf("%s\n",buf);
}
