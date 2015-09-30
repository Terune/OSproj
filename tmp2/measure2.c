#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#define CPUHZ	(2.4*1024*1024*1024) //2.8GHz
static inline void rdtsc(unsigned int* upper, unsigned int* lower){
	asm volatile("rdtsc"
		:"=a"(*lower), "=d"(*upper));
}

double spendtime(int num);
int main(){
	//char sys[100];
//	unsigned int eax, edx, eax2, edx2;
	double delta=0;
	double sum=0;
	int i=0;
	//time check
//	rdtsc(&edx, &eax);

	//system call
	//syscall(SYS_mkdir);
	for(i=20;i<24;i++)
	{
		int j=0;
		for(j=0;j<20;j++)
			sum+=spendtime(i);
		
		delta=sum/20;
	//time check2
//	rdtsc(&edx2, &eax2);

	//calculate time in seconds
//	delta = (double)(eax2-eax) / (double)CPUHZ;

	//time consumed.
		printf("%d: time delta(msec, usec): %lf, %lf\n",i, delta, delta*1000.0);
		sum=0;
	}
	return 0;
	/*int fd;	
	struct timeval	start,	now;	
	gexmeofday(	&start,	NULL	);	
	fd=open(“/home/cs530/tmp\0”,O_RDWR);	
	gexmeofday(	&now,	NULL	);	
	print_time_gap(	&start,	&now	);	
*/
}

double spendtime(int num)
{
	unsigned int eax, edx, eax2, edx2;
	double delta=0;

	//time check
	//system call
	switch(num)
	{
		case 20:
			rdtsc(&edx, &eax);
			syscall(SYS_fstatfs);
			rdtsc(&edx2, &eax2);
			break;

		case 21:			
            long id;
            char buf[MAXLOGNAME];
            id= getentry(buf,quotatype)
			rdtsc(&edx, &eax);
			syscall(SYS_quotactl,"/data", QCMD(Q_SETQUOTA,USRQUOTA),id,(void*)&qp);
			rdtsc(&edx2, &eax2);
			break;
		case 22:			
			rdtsc(&edx, &eax);
			syscall(SYS_select);
			rdtsc(&edx2, &eax2);
			break;
		case 23:			
			rdtsc(&edx, &eax);
			syscall(SYS_quotactl);
			rdtsc(&edx2, &eax2);
			break;
	}

	//time check2

	//calculate time in seconds
	delta = (double)(eax2-eax) / (double)CPUHZ;
	//printf("%lf",delta);
	//time consumed.
	return delta;
}
