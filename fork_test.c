#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid_0;
    pid_t pid_1;
    pid_t pid_pai;

    printf("Eu sou o processo pai, meu PID é igual a = %d\n", getpid());

    pid_pai = getpid();
    pid_0 = fork();
    pid_1 = fork();
    

    if ((pid_0 != 0) && (pid_1 != 0))
        printf("Eu sou o processo pai, o PID do meu primeiro filho é igual a %d, e o do segundo é %d\n", pid_0, pid_1);
    else if(pid_pai != 0 && pid_1 != 0)
        printf("Eu sou o primeiro processo filho, o meu PID é %d\n", getpid());
    else if(pid_pai != 0 && pid_0 != 0)
        printf("Eu sou o segundo processo filho, o meu PID é %d\n", getpid());

    return 0;
}