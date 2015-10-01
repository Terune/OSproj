#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
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

	// iterator for syscalls list that i should figure out
		
		for(i=0; i<20; i++){
			
			rdtsc(&edx, &eax);
			syscall(165, "/dev/hda1", "/mnt/win", "ext2", 0, NULL);
			//syscall(165, "/dev/hda1", "/mnt/win");
			rdtsc(&edx2, &eax2);

            umount("/mnt/win");
			// elapsed
			delta = (double)(eax2-eax) / (double)CPUHZ;
			printf("time delta(usec): %lf\n", delta*1000.0);

            syscall(166, "/mnt/win");
		}

	return 0;
}
