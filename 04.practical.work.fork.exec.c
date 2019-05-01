#include <stdio.h>
#include <unistd.h>
int main(){
    int pid = fork();
    if (pid==0) {
        int pid1 = fork();
        if (pid1==0) {
            printf("I am child after fork(), launching ps -ef\n");
            char *args[]={"/bin/ps", "-ef", NULL};
            execvp("/bin/ps",args);
            printf("Finished launching ps -ef\n"); //Launching ps-ef
            }
        else {
            printf("I am parent after fork(), child is %d\n", pid1);
        }
        printf("I am child after fork(), launching free -h\n");
        char *args[]={"/bin/free", "-h", NULL};
        execvp("/bin/free",args);
        printf("Finished launching free -h\n");
    }
    else printf("I am parent after fork(), child is %d\n", pid);
    return 0;
}

