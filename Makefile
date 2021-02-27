
CC=gcc
CFLAGS=-g -Wall
SOURCE_DIR=asciible
BUILD_DIR=build
BIN_NAME=asciible

all: $(BUILD_DIR)/$(BIN_NAME)
	chmod a+x $^

$(BUILD_DIR)/$(BIN_NAME): $(SOURCE_DIR)/main.c $(BUILD_DIR)/util.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf build

install: $(BUILD_DIR)/$(BIN_NAME)
	cp $^ /usr/bin/


test: $(BUILD_DIR)/$(BIN_NAME)
	./tests/run $(realpath $^)