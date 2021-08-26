#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

//pthread_mutex_t mutexA;

void error(char *m){
	perror(m);
}

void* multifive(void *newsockfd){

	//pthread_mutex_lock(&mutexA);
	int result, temp;
	char buffer[256];
	int n = read(newsockfd, buffer, 255);
        if (n<0) error ("ERROR reading from socket");
        printf("Message received\n");
	temp = atoi(buffer);
	result = temp*5;
	sprintf(buffer, "Result is : %d", result);
        n = write(newsockfd, buffer, 21);
        if(n<0)
                error("ERROR writing back to socket");
	//pthread_mutex_unlock(&mutexA);


}

int main(int argc, char *argv[]){
	int sockfd, newsockfd, port, clilen, n;
	struct sockaddr_in serv_addr, cli_addr;
	pthread_t TA;
	int TA_ret;
	char* retmsg;


	if (argc < 2)
		error("ERROR, no port provided\n");
	port = atoi(argv[1]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		error("ERROR opening socket");
	memset((char*) &serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port); //host to network

	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR binding to socket");

	listen(sockfd, 2);
	clilen = sizeof(cli_addr);
	while(1){
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

	if(newsockfd < 0) error("ERROR on accept");

	//if(pthread_mutex_init(&mutexA, NULL)) error("ERROR initiating mutex\n");
	if(pthread_create(&TA, NULL, multifive, (void*) newsockfd))
		error("ERROR creating thread\n");
	pthread_join(TA,NULL);
	}
	return 0;

}
