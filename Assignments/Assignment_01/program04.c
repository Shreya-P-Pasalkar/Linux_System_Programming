#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>

int Metadata(char *fName)
{
    struct stat sobj;

    stat(fName,&sobj);

    printf("Inode Number : %ld\n",sobj.st_ino);
    printf("Total Size : %ld\n",sobj.st_size);
    printf("Block Size : %ld\n",sobj.st_blksize);
    printf("User ID : %d\n",sobj.st_uid);
    printf("Group ID : %d\n",sobj.st_gid);
    printf("Link Count: %ld\n",sobj.st_nlink);
    printf("Last file access time : %s\n",ctime(&sobj.st_atime));
    printf("Last file Modification time : %s\n",ctime(&sobj.st_mtime));

    printf("File Type is : %d\n",sobj.st_mode);

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
int main()
{
    int iRet = 0;
    char file[50];

    printf("Enter file name ; \n");
    scanf("%s",file);

    iRet = Metadata(file);

    if(iRet == 0)
    {
        printf("stat successful\n");
    }
    else
    {
        perror("Error encountered");
    }

    return 0;
}