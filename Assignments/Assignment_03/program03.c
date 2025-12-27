#include<stdio.h>
#include<errno.h>
#include<fcntl.h>

void MoveFiles(char *sName, char *dName)
{
    int iRet = 0;

    iRet = rename(sName , dName);

    if(iRet == -1)
    {
        printf("Unable to rename the files\n");
        perror("Error encountered");
    }
    else
    {
        printf("Rename Successful\n");
    }
}

int main()
{
    char SourceDir[50];
    char DestDir[50];

    printf("Enter Source Directory Name : \n");
    scanf("%s",SourceDir);

    printf("Enter Destination Directory Name : \n");
    scanf("%s",DestDir);

    MoveFiles(SourceDir , DestDir);

    return 0;
}