#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<string.h>

int LargestFile(char *Dir)
{
    int iRet = 0;
    struct stat sobj;
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char fName[50];
    int iSize = 0;

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
            iRet = lstat(ptr->d_name,&sobj);

            if(sobj.st_size > iSize)
            {
                iSize = sobj.st_size;
                strcpy(fName , ptr->d_name);
            }
    }

    printf("Largest file name : %s\n",fName);
    printf("Size in bytes : %d\n" , iSize);

    closedir(dp);

    return 0;

    if(iRet == -1)
    {
        printf("Error encountered");
    }
}

int main()
{
    char file[50];

    printf("Enter Dir name : \n");
    scanf("%s",file);

    LargestFile(file);

    return 0;
}