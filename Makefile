TARGET=mfcode

default: build

build:
	gcc main.c keeloq.c -o $(TARGET)

run:
	./$(TARGET) DFFACD26 5143BDD8

