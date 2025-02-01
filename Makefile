TARGET=mfcode

default: build

build:
	gcc ./KeeLoq/keeloq.c -c
	gcc main.c keeloq.o -o $(TARGET) -I ./KeeLoq $(DEFINES)

run:build
	./$(TARGET) A9C2E0E1 CFD85AA5

clean:
	rm -f $(TARGET) *.o

