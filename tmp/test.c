#include <stdio.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct timeval start, now;

void print_time_gap(struct timeval* start, struct timeval* now);

int main(void){
	int fd;
    int i;
    char *temp = "forum, falinux.comn";

    fd = open("./test.txt", O_WRONLY | O_CREAT, 0644);
        for(i=0; i<20; i++){
            gettimeofday(&start, NULL);
            write(fd, temp, strlen(temp));
            gettimeofday(&now, NULL);

            print_time_gap(&start, &now);
        }
    close(fd); 

	return 0;
}


void measure_open(){
    int fd;

	gettimeofday(&start, NULL);
	fd = open("/home/ubuntu/cs530/tmp\0", O_RDWR);
	gettimeofday(&now, NULL);
	
	print_time_gap(&start, &now);
}


void print_time_gap(struct timeval* start, struct timeval* now){
	printf("%lf\n", (double)(now->tv_sec - start->tv_sec) + (double)1.0e-6*(now->tv_usec - start->tv_usec));
}
