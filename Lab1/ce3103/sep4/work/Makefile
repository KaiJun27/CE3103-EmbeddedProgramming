#Defining a variable 'objects'
OBJECTS = hello-main.o hello-funct1.o hello-funct2.o
CFLAGS = -Wall -g -c

TARGET = helloworld
CC = gcc
DTARGET = helloworld-d

all:$(TARGET) $(DTARGET)

#Linking Rules
$(TARGET):$(OBJECTS)
	$(CC) $^ -pg -o $@

$(DTARGET): $(OBJECTS)
	$(CC) -o $(DTARGET) $^

#Compiling Rules
hello-main.o: hello-main.c
	$(CC) $(CFLAGS) hello-main.c

hello-funct1.o: hello-funct1.c
	$(CC) $(CFLAGS) hello-funct1.c

hello-funct2.o: hello-funct2.c
	$(CC) $(CFLAGS) hello-funct2.c


#Remove executable &object files
clean:
	rm -f ./$(TARGET) $(OBJECTS) $(DTARGET) gmon.out
