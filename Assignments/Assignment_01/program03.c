#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int Permission(char *fName , char Mode)
{
    if(Mode == 'R')
    {
        return R_OK;
    }
    else if(Mode == 'W')
    {
        return W_OK;
    }
    else if(Mode == 'X')
    {
        return X_OK;
    }
    else
    {
        printf("Invalid Mode\n");
    }
}

int AccessFile(char *file,int flag)
{
    if(access(file,flag) == 0)
    {
        printf("File is Accessible\n");
    }
    else
    {
        printf("File in Unaccesssible\n");
        perror("Error encountered");
    }
}


int main()
{
    char fName[50];
    char Mode;
    int flag = 0;

    printf("Enter file name : \n");
    scanf("%s",fName);

    printf("Enter access permission for read-R|write-W|execute-X: \n");
    scanf(" %c",&Mode);

    flag = Permission(fName,Mode);

    AccessFile(fName,flag);

    return 0;
}