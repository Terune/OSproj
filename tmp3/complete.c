#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include <sys/time.h>

#define CPUHZ	(2.4*1024*1024*1024) //2.8GHz

				// '//' parts are NIF.
unsigned int sysclist[] = {	SYS_fsync,
				SYS_quotactl,
				SYS_fchdir,
				// SYS_bdflush,
				SYS_sysfs,
				// SYS_llseek,
				SYS_getdents,
				SYS_select,
				SYS_flock,
				SYS_readv,
				SYS_writev,
				SYS_fdatasync,
				SYS_poll,
				SYS_nfsservctl,
				// SYS_pread,
				// SYS_pwrite,
				SYS_chown,
				SYS_getcwd 	};

static inline void rdtsc(unsigned int* upper, unsigned int* lower){
	asm volatile("rdtsc"
		:"=a"(*lower), "=d"(*upper));
}

int main(){
	unsigned int eax, edx, eax2, edx2;
	double delta = 0;
	int j = 0, i = 0;
	double sum = 0;

    // select
    /*
    fd_set rfds;
    struct timeval tv;
    int retval;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    
    printf("dasdasdasdasdasdasdasdasdadadasd");

    retval = select(1, &rfds, NULL, NULL, &tv);
   
    if (retval == -1)
        perror("select()");
    else if (retval)
        printf("Data is available now.\n");
    else
        printf("No data within five seconds.\n");

    */

    // Origin
	// iterator for syscalls list that i should figure out
		for(i=0; i<3; i++){
			
			// 1. start_time
			rdtsc(&edx, &eax);

			// - system call
			syscall(SYS_chmod, "/home/ubuntu/cs530/tmp3/du", 0777);

			// 2. end_time
			rdtsc(&edx2, &eax2);

			// elapsed
			delta = (double)(eax2-eax) / (double)CPUHZ;
			printf("time delta(usec): %lf\n", delta*1000.0);
			sum += delta;	
		}
 


	return 0;
}
