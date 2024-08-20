#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int main(int argc, char *argv[])
{
    int a;
    if(argc<=1){
        printf("parameter error!,you should input a sleep time!\n");
        exit(1);
    }
    else if(argc==2)
    {
        a = atoi(argv[1]);
        sleep(a);
    }
    else 
    {
        printf("Too much parameter!\n");
        exit(1);
    }
    exit(0);
}