#include <linux/gpio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
void *eventPushBtn(void *fd0){
	//Event Push button
        struct gpioevent_request req_pb;
        struct gpioevent_data event;
	req_pb.lines = 1;
        req_pb.lineoffset[0] = 11;
        req_pb.handleflags = GPIOHANDLE_REQUEST_INPUT;
        req_pb.eventflags = GPIOEVENT-REQUESR_RISING_EDGE;
        strcpy(req_pb.consumer_label, "Push Button Event");

	ioctl(fd0, GPIO_GET_LINEEVENT_IOCTL, &req_pb);
	read(req_pb.fd, &event, sizeof(event));
	printf("Event occur @ %\"PRIu64\"\n", event.timestamp);
}*/

void *pushBtn(void *fd0){
	//Push Button
	struct gpiohandle_request req_pb;
	struct gpiohandle_data data_pb;
	//Red LED
	struct gpiohandle_request req_R;
	struct gpiohandle_data data_R;


	req_pb.lines = 1;
	req_pb.lineoffsets[0] = 11; //Pushbutton
	req_R.lines = 1;
	req_R.lineoffsets[0] = 27; //RED LED

	//configure red LED
	req_R.flags = GPIOHANDLE_REQUEST_OUTPUT;
	data_R.values[0] = 0; //default off
	ioctl(fd0, GPIO_GET_LINEHANDLE_IOCTL, &req_R);

	//configure push btn
	req_pb.flags = GPIOHANDLE_REQUEST_INPUT;
	ioctl(fd0, GPIO_GET_LINEHANDLE_IOCTL, &req_pb);
	data_pb.values[0] = 0; //default off

	for(int j = 0; j < 90; ++j){
		ioctl(req_pb.fd, GPIOHANDLE_GET_LINE_VALUES_IOCTL, &data_pb);
		//data_R.values[0] = data_pb.values[0];
		if(data_pb.values[0]){ //if pushbutton is pressed
			printf("Button is pressed\n");
			data_R.values[0] = !data_R.values[0];//toggle red led
		}
		else data_R.values[0] = 0; //make sure value is 0 when pb is not pressed
		ioctl(req_R.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data_R);
		usleep(1000000);
	}
	close(req_R.fd);
	close(req_pb.fd);
}


int main(int argc, char *argv[]){
	pthread_t thread1;

	int fd0 = open("/dev/gpiochip0", O_RDWR);
	struct gpiochip_info cinfo;
	ioctl(fd0, GPIO_GET_CHIPINFO_IOCTL, &cinfo);
	fprintf(stdout, "GPIO chip 0 : %s, \"%s\", %u lines\n", cinfo.name, cinfo.label,
	cinfo.lines);

	//Green and Yellow LED
	struct gpiohandle_request req_GY;
	struct gpiohandle_data data_GY;
	req_GY.lines = 2;
	req_GY.lineoffsets[0] = 4;
	req_GY.lineoffsets[1] = 17;
	req_GY.flags = GPIOHANDLE_REQUEST_OUTPUT;
	data_GY.values[0] = 1;
	data_GY.values[1] = 0;
	ioctl(fd0, GPIO_GET_LINEHANDLE_IOCTL, &req_GY);

	pthread_create(&thread1, NULL, pushBtn, (void*)fd0);

	for(int i = 0; i < 100; ++i){
		ioctl(req_GY.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data_GY);
		usleep(1000000);
		data_GY.values[0] = !data_GY.values[0];
		data_GY.values[1] = !data_GY.values[1];
	}
	close(req_GY.fd);
	pthread_join(thread1, NULL);
	close(fd0);
	exit(EXIT_SUCCESS);
}
