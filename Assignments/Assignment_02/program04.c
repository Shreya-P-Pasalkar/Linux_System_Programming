#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>

int DisplayType(char *Dir)
{
    int iRet = 0;
    struct stat sobj;
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char path[50];

    dp = opendir(Dir);

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

        printf("%s\t",ptr->d_name);

        iRet = lstat(ptr->d_name,&sobj);

            if(S_ISBLK(sobj.st_mode))
            {
                printf("Block Device\n");
            }
            else if(S_ISCHR(sobj.st_mode))
            {
                printf("Character Device\n");
            }
            else if(S_ISDIR(sobj.st_mode))
            {
                printf("Directory File\n");
            }
            else if(S_ISLNK(sobj.st_mode))
            {
                printf("Symbolic Link\n");
            }
            else if(S_ISREG(sobj.st_mode))
            {
                printf("Regular File\n");
            }      
            else if(S_ISSOCK(sobj.st_mode))
            {
                printf("Socket File\n");
            }
    }

    closedir(dp);

    return 0;

    if(iRet == -1)
    {
        printf("Error encountered");
    }
}

int main()
{
    char DirName[50];

    printf("Enter Directory name : \n");
    scanf("%s" , DirName);

    DisplayType(DirName);

    return 0;
}