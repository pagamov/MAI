#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    if (( pid = fork()) < 0)
        exit(0);
    else if(pid != 0)
        exit(0); // kill parent process

    fprintf(stderr,"child running...pid=%d\n", getpid());
    signal(SIGHUP, SIG_IGN);
    close(0);
    close(1);
    close(2);
    //
    chdir("/");
    //
    //
    setsid();
    //
    while(1) {
	       sleep(1);
    }
    return 0;
}
