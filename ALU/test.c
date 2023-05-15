#include "main/public.h"

atomic_int counter = {0};
atomic_long cmp_xchg_count = ATOMIC_VAR_INIT(0);

double time_diff(struct timespec t1, struct timespec t2){
	struct timespec diff;
	if(t2.tv_nsec - t1.tv_nsec < 0){
		diff.tv_sec = t2.tv_sec - t1.tv_sec -1;
		diff.tv_nsec = t2.tv_nsec + 1000000000 - t1.tv_nsec;
	}
	else{
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
		diff.tv_sec = t2.tv_sec - t1.tv_sec;
	}
	double naro = diff.tv_nsec + diff.tv_sec*1000000000;
	return naro;
}

void *dothread(void *arg){
	int num = atomic_fetch_add_explicit(&counter, 1, memory_order_release);
   // printf("num:%d\t thread_num:%d\n", num, thread_num);
	num %= thread_num;
	cpu_set_t cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(num, &cpuset);
	sched_setaffinity(0, sizeof(cpuset), &cpuset);

    if(num!=sched_getcpu()){
		printf("false.\n");
	}
    
    long int tmp=0, tmp_1=0;
    double rnd;
    
    double dif_naro;
    struct timespec start, current, rs_start;

	clock_gettime(CLOCK_MONOTONIC, &start);
	clock_gettime(CLOCK_MONOTONIC, &current);
    while(running_flag=1){
        if(time_diff(start, current)> run_seconds*1000000000.0) break;
        tmp = cmp_xchg_count;
        atomic_compare_exchange_weak_explicit(&cmp_xchg_count, &tmp, tmp+1, memory_order_acq_rel, memory_order_relaxed);

        rnd=((drand48())*0.3-0.15);
        //printf("rnd:%lf\n", rnd);
        int rs = (int)(nCS_size*(rnd+1.0));
        //printf("rs:%d\n", rs);
        clock_gettime (CLOCK_MONOTONIC, &rs_start) ; //nCS
		
		do{
			clock_gettime(CLOCK_MONOTONIC, &current);
			dif_naro = time_diff(rs_start, current);
		}while(dif_naro < rs);
    }
    //pthread_exit(NULL);
    return (NULL);
}

void print_all(){
    printf("cmp xchg count:%ld\n", cmp_xchg_count);
}

int main(int argc, char* argv[]){
    if(argc<2){
		printf("usage: <number of threads> <nCS_size>\n");
		return 0;
	}

    thread_num=atoi(argv[1]);
	nCS_size=atoi(argv[2]);
	clock_gettime (CLOCK_MONOTONIC, &begin_time);
	
    int err;
	pthread_t* thread1 = (pthread_t*)malloc(sizeof(pthread_t) * thread_num);
	for(int i=0;i<thread_num;i++){
		err=pthread_create(&(thread1[i]), NULL, dothread, NULL);
		if(err!=0){
			printf("error in pthread create\n");
		}
	}
	printf("They are running.\n");
	for (int i=0; i<thread_num; i++) pthread_join(thread1[i], NULL);

	clock_gettime(CLOCK_MONOTONIC, &end_time);
	running_flag=0;
	
	sleep(2);
    print_all();
    //if(print_all() >= 0) fprintf(fp,"correct.\n");
	//else fprintf(fp,"data error.\n");
	
	printf("One round finish.\n");
    return 0;
}
