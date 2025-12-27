#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>

#define SIZE_BUFFER 100

int ReadFile(char *fName , int iSize)
{
    int fd = 0;
    char buffer[SIZE_BUFFER];
    int iRead = 0;

    memset(buffer, '\0', SIZE_BUFFER);

    fd = open(fName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        perror("error encountered");
    }
    else
    {
        printf("Successfully opened the file\n");
    }

    iRead = read(fd,buffer,iSize);

    if(iRead == -1)
    {
        printf("Unable to read the file \n");
        perror("Error encountered");
    }
    else
    {
        printf("Number of bytes read from the file : %d\n",iRead);
        printf("Data from the file : %s\n",buffer);
    }
}

int main()
{
    char file[50];
    int iBytes = 0;

    printf("Enter file Name : \n");
    scanf("%s",file);

    printf("Enter number of bytes to read : \n");
    scanf("%d" , &iBytes);

    ReadFile(file,iBytes);

    return 0;
}