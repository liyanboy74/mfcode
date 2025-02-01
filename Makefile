TARGET=mfcode
# DEFINES=-DDEBUG

default: build

build:
	gcc ./KeeLoq/keeloq.c -c
	gcc main.c keeloq.o -o $(TARGET) -I ./KeeLoq $(DEFINES)

run:build
	./$(TARGET) 6C46ACA C8768EE8

clean:
	rm -f $(TARGET) *.o

