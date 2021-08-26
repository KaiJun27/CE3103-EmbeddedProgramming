#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g_var1 = 0;				//global variable

void *inc_gv(){

	int i, j;
	for(i = 0; i < 10; i++){
		g_var1++;
		for(j = 0; j < 50000000; j++);	//increment the global variable
		printf(" %d", g_var1);		//delay the loop
		fflush(stdout);			//print the value
	}
}

int main(){
	pthread_t TA, TB;
	int TAret, TBret;

	TAret = pthread_create(&TA, NULL, inc_gv, NULL);
	TBret = pthread_create(&TB, NULL, inc_gv, NULL);

	pthread_join(TA, NULL);
	pthread_join(TB, NULL);

	printf("\n pthread2 completed \n");

}
