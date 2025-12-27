#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>

int DisplayDir(char *Dirname)
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;

    dp = opendir(Dirname);

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
        printf("%s\n",ptr->d_name);
    }

    closedir(dp);

    return 0;
}

int main()
{
    char Dirname[50];

    printf("Enter Directory Name: \n");
    scanf("%s",Dirname);

    DisplayDir(Dirname);

    return 0;

}