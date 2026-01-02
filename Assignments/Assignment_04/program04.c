#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define SIZE_BUFFER 100

int main(int argc , char *argv[])
{
    int fd1 = 0, fd2 = 0, iRet = 0, iCnt = 2, iSize = 0;
    char Buffer[SIZE_BUFFER];
    int iLimit = 0;

    memset(Buffer , '\0' , SIZE_BUFFER);

    while(argv[iCnt] != '\0')
    {
        fd1 = open(argv[iCnt],O_RDWR);

        if(fd1 == -1)
        {
            printf("Unable to open file ~ for reading (file %d)\n",iCnt);
            perror("Error encountered  ");
        }
        else
        {
            printf("File opened successfully ~ for reading (file %d)\n",iCnt);
        }

        while((iRet = read(fd1,Buffer,SIZE_BUFFER)) > 0 )
        {
            iSize = iSize + iRet;
        }

        iCnt++;
    }

    fd2 = open(argv[1] , O_RDWR | O_CREAT , 0777);

    if(fd2 == -1)
    {
        printf("Unable to open file ~ for writing\n");
        perror("Error encountered : ");
    }
    else
    {
        printf("File opened successfully ~ for writing\n");
    }

    iRet = write(fd2,Buffer,iSize);

    if(iRet == -1)
    {
        printf("Unable to write into the destination file\n");
        perror("Error encountered ");
    }
    else
    {
        printf("Number of bytes written into the destination file : %d\n",iRet);
    }


    return 0;
}