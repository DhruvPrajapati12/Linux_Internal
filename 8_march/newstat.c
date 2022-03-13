//  ls -l kind of information through an pg using stat();
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main( )
{
	struct stat st;// st.st_size   st.st_ino  st_blksize
	int fd;
	// fd=open("P1.c", O_RDONLY);//$ ./a.out   P1.c
 	//fstat(fd, &st);
	
	stat("lseek.c", &st);//
	printf("File size 	=%lu\n",(st.st_size));// ls  -l  P1.c
	
	printf("File inode =%lu \n", st.st_ino);// ls -i P1.c
	
	printf("size disc of blocks =%lu \n",st.st_blksize);//stat -fc %s  P1.c
	
	
	printf("\n\n");
	close(fd);
	return 0;
}