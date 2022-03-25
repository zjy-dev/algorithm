#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int ret = fork();

    if (ret < 0) {
        printf("Fork Failed!!!\n");
        return -1;
    } else if (ret == 0) {// Child Process
        printf("Child Here!!!");
        return 0;
    } else if (ret > 0) {
        printf("Parent here!!!");
        return 0;
    }

    return 0;
}