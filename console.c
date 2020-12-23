#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <errno.h>

int main () {

	int fd, buffer, total;
	mkfifo ("mario", 0644);
	printf ("This program will sum up the numbers you type in\nPlease enter only one number at a time\n");
	
	while (1) {
		fd = open ("mario", O_WRONLY);
		scanf("%d", &buffer);
		write (fd, &buffer, sizeof(buffer));
		close(fd);
		
		fd = open ("mario", O_RDONLY);
		read (fd, &total, sizeof(total));
		printf ("Total so far: %d\n", total);
		close(fd);
	}
	
	return 0;
}
