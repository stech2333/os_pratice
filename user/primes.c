#include "kernel/types.h"
#include "user/user.h"
#include "stddef.h"

void
map(int n, int fd[])
{
  close(n);
  dup(fd[n]);

  close(fd[0]);
  close(fd[1]);
}
void
primes()
{
  int num, num1;
  int fd[2];
  if (read(0, &num, sizeof(int)))
  {
    printf("prime %d\n", num);
    pipe(fd);
    if (fork() == 0)
    {
      map(1, fd);
      while (read(0, &num1, sizeof(int)))
      {
        if (num1 % num != 0)
        {
          write(1, &num1, sizeof(int));
        }
      }
    }
    else
    {
      wait(NULL);
      map(0, fd);
      primes();
    }  
  }  
}

int 
main(int argc, char *argv[])
{
  int fd[2];
  pipe(fd);
  if (fork() == 0)
  {
    map(1, fd);
    for (int i = 2; i < 36; i++)
    {
      write(1, &i, sizeof(int));
    }
  }
  else
  {
    wait(NULL);
    map(0, fd);
    primes();
  }
  exit(0);
}
