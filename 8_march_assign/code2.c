// 2.Write a program that demonstrates repositioning of file offset using SEEK_SET,
// SEEK_END and SEEK_CUR.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void main()
{
    int fd1, fd2;

    char write_buffer[50] = "Hello how are you dhruv...";
    char read_buffer[50];

    fd1 = open("one.txt", O_RDWR | O_CREAT | O_TRUNC, 777);
    fd2 = open("two.txt", O_RDWR | O_CREAT | O_TRUNC, 777);
    printf("File created fd: %d\n", fd1);
    printf("File created fd: %d\n", fd2);

    write(fd1, write_buffer, 50);

    // Implementation of SEEK_SET 
    lseek(fd1, 0, SEEK_SET);
    // lseek(fd1, 4, SEEK_SET);

    // lseek(fd1, -50, SEEK_END);
    // lseek(fd1, -45, SEEK_END);   //DOUBT

    // lseek(fd1, 4, SEEK_CUR);     // DOUBT


    read(fd1, read_buffer, 50);
    printf("data: %s\n", read_buffer);
    write(fd2, read_buffer, 50);

}

// SEEK_SET -> It moves file pointer position to the beginning of the file.

// SEEK_CUR -> It moves file pointer position to given location.

// SEEK_END -> It moves file pointer position to the end of file.

// int main(){
//     int fd, len;
//     char write_buf[11]="Hello om..!";
//     char read_buf[50];

//     fd = open("linux_kernel.txt", O_CREAT | O_RDWR, 777);
//     len = write(fd,write_buf,50);
//     //printf("Return value from write buffer is %d \n", len);
//     printf("Seek set at start position of file\n");
//     lseek(fd,0,SEEK_SET);
//     read(fd,read_buf,len);
//     printf("Data in file is:\n%s",read_buf);
//     printf("\nSeek set at end position of file\n");
//     lseek(fd,-50,SEEK_END);
//     read(fd,read_buf,len);
//     printf("Data in file is:\n%s",read_buf);
//     printf("\nSeek set at current position of file\n");
//     lseek(fd,-45,SEEK_CUR);
//     read(fd,read_buf,len);
//     printf("Data in file is:\n%s",read_buf);
//     close(fd);
//     return 0;
// }