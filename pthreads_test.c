#include <stdio.h>
#include <pthread.h>

// compilacao: gcc -o pthreads_test -pthread pthreads_test.c (no slide estava "-lthread" ao inves de "-pthread")


void thr_func(int *id); /* codigo threads 1 e 3 */
void thr_yield(int *id); /* codigo thread 2 */

int main(){
	pthread_t t1, t2, t3; /* declara as threads */
	int n1 = 1, n2 = 2, n3 = 3;

	/* cria threads: id, inic, funcao, param funcao */
	pthread_create(&t1,NULL,(void* )thr_func,&n1);
	pthread_create(&t2,NULL,(void* )thr_yield,&n2);
	pthread_create(&t3,NULL,(void* )thr_func,&n3);

	/* espera fim das threads: id, status de saida */
	pthread_join(t3,NULL);
	pthread_join(t2,NULL);
	pthread_join(t1,NULL); 
}

/* codigo das threads 1 e 3 */
void thr_func(int *id){
	printf("Thread nº: %d\n",*id);
}

/* codigo da thread 2 */
void thr_yield(int *id){
	sched_yield();
	printf("Thread nº: %d\n",*id);
}