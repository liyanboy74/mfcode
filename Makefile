TARGET=mfcode

default: build

build:
	gcc main.c keeloq.c -o $(TARGET)

run:build
	./$(TARGET) DFFACD26 5143BDD8

