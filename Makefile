TARGET  = harry9409
CCFLAGS = -Wall -std=c99 -g

default: main.c
	gcc -o $(TARGET) $(CCFLAGS) main.c

clean:
	rm -f $(TARGET)
