#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

int OpenFile(char *fName)
{
    int fd = 0;

    fd = open(fName,O_RDONLY);

    return fd;
}

int main()
{
    char file[100];
    int fd = 0;

    printf("Enter file name : \n");
    scanf("%s",file);

    fd = OpenFile(file);

    if(fd == -1)
    {
        printf("Unable to open the %s\n",file);
        perror("Error encountered");
    }
    else
    {
        printf("%s opened successfully using fd : %d\n",file,fd);
    }

    close(fd);

    return 0;
}