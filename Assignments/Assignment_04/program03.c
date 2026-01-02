#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define SIZE_BUFFER 100

int main(int argc , char *argv[])
{
    int fd1 = 0, fd2 = 0, iRet = 0;
    char Buffer[SIZE_BUFFER];

    memset(Buffer , '\0' , SIZE_BUFFER);

    fd1 = open(argv[1], O_RDONLY);

    if(fd1 == -1)
    {
        printf("Unable to open the file ~ for reading(pread)\n");
        perror("Error encountered ");
    }
    else
    {
        printf("File opened succesfully ~ for reading(pread)\n");
    }

    iRet = pread(fd1, Buffer, 4, 11);

    if(iRet == -1)
    {
        printf("Unable to pread the file.\n");
        perror("Error encountered ");
    }
    else
    {
        printf("File read succesfully without changing the offset\n");
    }

    fd2 = open(argv[2], O_RDWR | O_CREAT , 0777);

    if(fd2 == -1)
    {
        printf("Unable to open the file ~ for reading(pread)\n");
        perror("Error encountered ");
    }
    else
    {
        printf("File opened succesfully ~ for writing(pwrite)\n");
    }

    iRet = pwrite(fd2, Buffer, 4, 12);

    if(iRet == -1)
    {
        printf("Unable to pwrite into the  destination file.\n");
        perror("Error encountered ");
    }
    else
    {
        printf("Written successfully into the destination file without changint the offset\n");
        printf("Nubmer of Bytes written into the file : %d\n",iRet);
    }

    return 0;
}