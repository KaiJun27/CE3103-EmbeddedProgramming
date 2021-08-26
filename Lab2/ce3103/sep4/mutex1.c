#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g_var1 = 0;                         //global variable
pthread_mutex_t mutexA;


void *inc_gv(){
	pthread_mutex_lock(&mutexA);
        int i, j;
        for(i = 0; i < 10; i++){
                g_var1++;
                for(j = 0; j < 5000000; j++);  //increment the global variable
                printf(" %d", g_var1);          //delay the loop
                fflush(stdout);                 //print the value
        }
	pthread_mutex_unlock(&mutexA);
}

int main(){
        pthread_t TA, TB;
        int TAret, TBret;

	if(pthread_mutex_init(&mutexA, NULL)!=0){
		printf("\n mutex init failed\n");
		return 1;
	}

        TAret = pthread_create(&TA, NULL, inc_gv, NULL);
        TBret = pthread_create(&TB, NULL, inc_gv, NULL);

        pthread_join(TA, NULL);
        pthread_join(TB, NULL);

        printf("\n mutex1 completed \n");

	pthread_mutex_destroy(&mutexA);
	return 0;
}


