#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#define CPUHZ	(2.4*1024*1024*1024) //2.8GHz
static inline void rdtsc(unsigned int* upper, unsigned int* lower){
	asm volatile("rdtsc"
		:"=a"(*lower), "=d"(*upper));
}

int main(){
	unsigned int eax, edx, eax2, edx2;
	double delta=0;
	int i=0;

	for(i=0; i<20; i++){
	//time check
	rdtsc(&edx, &eax);
	syscall(SYS_mount, /dev/hda1, /mnt/win);
	rdtsc(&edx2, &eax2);
	//printf("3-2");

	//calculate time in seconds
	delta = (double)(eax2-eax) / (double)CPUHZ;

	//time consumed.
	printf("time delta(usec): %lf\n", delta*1000);
	}
	return 0;
}
