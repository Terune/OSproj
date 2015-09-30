#include <stdio.h>
#include <sys/time.h>
#include <fcntl.h>

struct timeval start, now;

void print_time_gap(struct timeval* start, struct timeval* now);

int main(void){
	int fd;


	return 0;
}

void measure_mknod(){
	char path[] = "/home/ubuntu/cs530/tmp/"
}

void measure_open(){
	gettimeofday(&start, NULL);
	fd = open("/home/ubuntu/cs530/tmp\0", O_RDWR);
	gettimeofday(&now, NULL);
	
	print_time_gap(&start, &now);
}

void measure_close(){
	gettimeofday(&start, NULL);
	close(fd);
	gettimeofday(&now, NULL);

	print_time_gap(&start, &now);
}

void print_time_gap(struct timeval* start, struct timeval* now){
	printf("%lf\n", (double)(now->tv_sec - start->tv_sec) + (double)1.0e-6*(now->tv_usec - start->tv_usec));
}
