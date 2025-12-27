#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>

#define SIZE_BUFFER 100

int ReadFile(char *fName)
{
    char Buffer[SIZE_BUFFER];
    int fd = 0;
    int iRet;
    int iBytes = 0;

    memset(Buffer , '\0' , SIZE_BUFFER);

    fd = open(fName , O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        perror("Error encountered ");
    }
    else
    {
        printf("File opened successfully\n");
    }

    printf("Data read from file : \n");
    while((iRet = read(fd,Buffer,sizeof(Buffer))) > 0)
    {
        printf("%s",Buffer);
        iBytes = iBytes+iRet;
    }
    printf("\n");

    if(iRet == -1)
    {
        printf("Unable to read the file");
        perror("Error encountered ");
    }

    return iBytes;
}

int main()
{
    char file[50];
    int iRet = 0;

    printf("Enter name of file : \n");
    scanf("%s",file);

    iRet = ReadFile(file);

    printf("Number of bytes read : %d\n", iRet);

    return 0;
}