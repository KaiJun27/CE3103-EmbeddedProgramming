//**********************************************************************************
//This program will create two threads, each print its own message
// onto the screen

//**********************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *ptr){

	char *text;
	text = (char *) ptr;
	printf("%s \n", text);
	return  NULL;
}

int main(){

	pthread_t thread1, thread2;
	char *str1 = "I an thread 1";
	char *str2 = "I am thread 2";
	int T1ret, T2ret;

	//Create two threads
	T1ret = pthread_create(&thread1, NULL, print_message, (void*) str1);
	T2ret = pthread_create(&thread2, NULL, print_message, (void*) str2);

	//main() thread now waits for both thread to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("T1 & T2 return: %d, %d\n", T1ret, T2ret);
	return 0;
}
