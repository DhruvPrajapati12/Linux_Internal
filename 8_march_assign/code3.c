// 3. Write program that returns “ls -l ” kind of structure of information from an existing file
// or opend file.

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat st;

    stat("code1.c", &st);

    printf("file size: %lu\n", st.st_size);
    printf("file inode: %lu\n", st.st_ino);
    printf("size disc of blocks = %lu\n", st.st_blksize);
    printf("No. of 512 byte blocks allocated = %d\n", st.st_blocks);
    printf("Permissions = %o\n", st.st_mode);
    printf("Owner id = %lu\n", st.st_uid);
    printf("Group id = %lu\n", st.st_gid);
    printf("Last modified time = %s\n", ctime(&st.st_mtime));
    printf("Last accessed time = %s\n", ctime(&st.st_atime));

    printf("\n");
    return 0;
}