#include<stdio.h>
#include<fcntl.h>    
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define SIZE_BUFFER 100

int main(int argc , char *argv[])
{
    int fd = 0, iSize = 0 , iRet = 0, iStart = 0, iEnd = 0 , iOff = 0;
    char temp = '\0';
    char Buffer[SIZE_BUFFER];

    memset(Buffer, '\0', SIZE_BUFFER);

    fd = open(argv[1],O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        perror("Error encountered ");
    }
    else
    {
        printf("File opened successfully\n");
    }

    while((iRet = read(fd, Buffer, SIZE_BUFFER)) > 0)
    {
        iSize = iSize + iRet;
    }

    iEnd = iSize - 1;

    while(iStart != iEnd)
    {
        temp = Buffer[iStart];
        Buffer[iStart] = Buffer[iEnd];
        Buffer[iEnd] = temp;
        iStart++;
        iEnd--;
    }

    iOff = lseek(fd , 0 , SEEK_SET);

    iRet = write(fd, Buffer, iSize);

    if(iRet == -1)
    {
        printf("Unable to write into the file\n");
        perror("Error encountered ");
    }
    else
    {
        printf("Number of Bytes written : %d\n",iRet);
    }

    return 0;
}