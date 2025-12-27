#include<stdio.h>
#include<unistd.h>
#include<error.h>
#include<fcntl.h>
#include<string.h>

int WriteToFile(char *fName , char *string)
{
    int fd = 0;
    int iBytes = 0;

    fd = open(fName , O_RDWR | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        perror("Error encountered");
    }

    iBytes = write(fd , string , strlen(string));

    close(fd);

    return iBytes;
}

int main()
{
    char file[50];
    char string[50];

    int iRet = 0;

    printf("Enter file name : \n");
    scanf("%s",file);

    printf("Enter string to write : \n");
    scanf("%[^\n]s",string);

    iRet = WriteToFile(file,string);

    if(iRet == -1)
    {
        printf("Unable to write into the file\n");
        perror("Error encountered");
    }
    else
    {
        printf("Number of bytes written to the file : %d\n",iRet);
    }


    return 0;
}