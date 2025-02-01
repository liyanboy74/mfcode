TARGET=mfcode

default: build

build:
	gcc ./KeeLoq/keeloq.c -c
	gcc main.c keeloq.o -o $(TARGET) -I ./KeeLoq $(DEFINES)

run:build
	./$(TARGET) A9C2E0E1 22F892D9

clean:
	rm -f $(TARGET) *.o

