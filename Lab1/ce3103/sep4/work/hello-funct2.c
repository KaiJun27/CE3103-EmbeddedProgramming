#include <stdio.h>

void keytracker(){
/*	char c;
	int count = 0;
	while(1){
		if(fread(&c, 1, 1, stdin)){
			printf("A key has been pressed %d times\n", ++count);
		}
		if(count >= 30) return;
	}*/

	printf("Hello World from funct2!\n");
	for(long i = 0x0000000; i < 0x7ffffff; i++){
		for(int j = 0x0; j < 0xf; j++){}
	}
}
