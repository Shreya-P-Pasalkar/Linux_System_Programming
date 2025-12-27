#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int ModeToFlag(int mode)
{
    if(mode == 'R')
    {
        return O_RDONLY | O_CREAT;
    }
    else if(mode == 'W')
    {
        return O_WRONLY | O_CREAT;
    }
    else if(mode == 'R'&&'W')
    {
        return O_RDWR | O_CREAT;
    }
    else if(mode == 'A')
    {
        return O_APPEND | O_CREAT;
    }
    else
    {
        printf("Invalid mode\n");
    }
}

int OpenFile(char *fName ,int flag)
{
    int fd = 0;

    fd = open(fName,flag);

    return fd;
}

int main()
{
    int fd = 0;
    int flag;
    int mode;
    char file[50];

    printf("Enter File name : \n");
    scanf("%s",file);

    printf("Enter mode of file to open in (R/W/RW/A) : \n");
    scanf("%ls",&mode);

    flag = ModeToFlag(mode);
    fd = OpenFile(file,flag);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        perror("Error Encountered ");
    }
    else
    {
        printf("%s opened successfully using fd : %d\n",file,fd);
    }
    

    return 0;
}