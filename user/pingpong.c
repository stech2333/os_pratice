#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void
pingpong(void)
{
    int p1[2],p2[2];
    char buf[10];
    pipe(p1);
    pipe(p2);
    int c = fork();
    if(c==0)
    {
        read(p1[0],buf,4);
        printf("%d: recieved %s\n",getpid(),buf);
        write(p2[1],"pong",4);
    }else 
    {
        write(p1[1],"ping",4);
        wait(0);
        read(p2[0],buf,4);
        printf("%d: recieved %s\n",getpid(),buf);
    }
}


int main(int argc ,char *argv[])
{
    pingpong();
    exit(0);
}