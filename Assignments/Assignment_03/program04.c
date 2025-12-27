#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<string.h>

int DeleteEmpty(char *dName)
{
    int iRet = 0;
    struct stat sobj;
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char fName[50];
    int iSize = 0;

    dp = opendir(dName);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        perror("Error encountered");
        return -1;
    }
    else
    {
        printf("Directory file opened successfully\n");
    }

    while((ptr = readdir(dp)) != NULL)
    {
            iRet = lstat(ptr->d_name,&sobj);

            if(sobj.st_size == 0)
            {
                remove(ptr->d_name);
                printf("File Name : %s\n",ptr->d_name);
            }
    }
}

int main()
{
    char Dir[50];

    printf("Enter Directory Name : \n");
    scanf("%s",Dir);

    DeleteEmpty(Dir);

    return 0;
}