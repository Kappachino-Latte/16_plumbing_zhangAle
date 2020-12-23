#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <errno.h>

int main () {

	int fd, buffer;
	int total = 0;
	mkfifo ("mario", 0644);
	
	while (1) {
		fd = open ("mario", O_RDONLY);
		read (fd, &buffer, sizeof(buffer));
		close(fd);
		total += buffer;
		
		fd = open ("mario", O_WRONLY);
		write (fd, &total, sizeof(total));
		close(fd);
	}
	
	return 0;
}
