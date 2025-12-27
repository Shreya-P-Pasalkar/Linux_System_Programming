#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>

void CheckFile(char *dName, char *fName)
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    int iCount = 0;

    dp = opendir(dName);

    if(dp == NULL)
    {
        printf("Unabled to open directory\n");
        perror("Error encountered");
    }
    else
    {
        printf("Directory opened successfully\n");
    }

    while((ptr = readdir(dp)) != NULL)
    {
        if(ptr->d_name == fName)
        {
            iCount++;
            printf("File is present in the directory\n");
            printf("Name of the file is %s\n",fName);
        }
    }

    if(iCount == 0)
    {
        printf("File match not found.\n");
    }
}

int main()
{
    char DirName[50];
    char FileName[50];

    printf("Enter Directory Name : \n");
    scanf("%s",DirName);

    printf("Enter File Name : \n");
    scanf("%s",FileName);

    CheckFile(DirName , FileName);
    
    return 0;
}