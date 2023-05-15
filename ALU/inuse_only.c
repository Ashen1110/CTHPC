#include "main/main.c"

// InUse is defined in atomic_int in public.h and it is initialized to 0
void spin_init(){

}
void spin_lock(){
	while(1){
		while(InUse!=0){
			asm("pause");
			//thrd_yield();
		}
		if(unlikely(InUse==0)){
            if(atomic_compare_exchange_weak_explicit(&InUse, &flag, 1, memory_order_acq_rel, memory_order_relaxed)){
                return ;
            }
        }
		flag =0;
	}
}
void spin_unlock(){
	atomic_store_explicit(&InUse, 0, memory_order_release);
}
void note_message(int thread_num, int nCS_size, int run_second){
    file_init();
	fprintf(fp,"=======================\n");
	fprintf(fp,"only inuse\n");
	fprintf(fp,"threads: %d\n",thread_num);
	fprintf(fp,"user_num: %d\n",user_num);
	fprintf(fp,"nCS_size: %d\n",nCS_size);
	fprintf(fp,"run_second: %d\n",run_second);
}
