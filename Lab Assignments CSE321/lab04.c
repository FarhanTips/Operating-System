#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  

char teststr[] = "The quick brown fox jumps over the lazy dog.\n";

int main() {
    int fd;     
    int len;    
    ssize_t r; 

  
    fd = open("C:\\Users\\User\\Pictures\\testfile.txt", O_WRONLY);


    if (fd < 0) {
        perror("File open failed"); 
        exit(1);  
    }

    len = strlen(teststr); 
    printf("Attempting to write %d bytes\n", len);

   
    r = write(fd, teststr, len);

   
    if (r < 0) {
        perror("File write failed"); 
        close(fd); 
        exit(1);  
    }

 
    printf("Wrote %d bytes\n", (int) r);

   
    close(fd);

    return 0; 
}