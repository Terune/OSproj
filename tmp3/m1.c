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
	//printf("1-1");
	rdtsc(&edx, &eax);
	//printf("1-2");

	//system call
	//printf("2-1");
	syscall(SYS_getcwd);
	//printf("2-2");

	//time check2
	//printf("3-1");
	rdtsc(&edx2, &eax2);
	//printf("3-2");

	//calculate time in seconds
	delta = (double)(eax2-eax) / (double)CPUHZ;

	//time consumed.
	printf("time delta(msec): %lf\n", delta);
	}
	return 0;
}
