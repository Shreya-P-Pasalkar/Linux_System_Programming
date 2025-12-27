#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define SIZE_BUFFER 100

void strcpyX(char *src,char *dest)
{
    int fd1 = 0;
    int fd2 = 0;
    int iRet;
    int iBytes = 0;
    int iSize = 0;
    char Buffer[SIZE_BUFFER];

    memset(Buffer , '\0' , SIZE_BUFFER);

    fd1 = open(src , O_RDWR);

    if(fd1 == -1)
    {
        printf("Unable to open source file \n");
        perror("Error encountered");
    }

    printf("Data read from file : \t");
    while((iRet = read(fd1,Buffer,sizeof(Buffer))) > 0)
    {
        printf("%s",Buffer);
        iSize = iSize + iRet;
    }
    printf("\n");
    
    fd2 = open(dest , O_RDWR | O_CREAT | O_TRUNC , 0777);

    if(fd2 == -1)
    {
        printf("Unable to open destination file \n");
        perror("Error encountered");
    }

    iBytes = write(fd2,Buffer,iSize);

    if(iBytes == -1)
    {
        printf("Unable to writing into the file \n");
        perror("Error encountered");
    }
    else
    {
        printf("Number of bytes written : %d\n",iBytes);
    }
}
int main()
{
    char Source[50];
    char Dest[50];

    printf("Enter Source File : \n");
    scanf("%s",Source);

    printf("Enter Destination File : \n");
    scanf("%s",Dest);

    strcpyX(Source,Dest);

    return 0;
}