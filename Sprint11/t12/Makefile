CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I./inc

SOURCE_FILES = *.c
OBJECT_FILES = *.o
OBJECT_DIR = ./obj
SOURCE_DIR = ./src

SRC_PATH = $(wildcard $(SOURCE_DIR)/$(SOURCE_FILES))
OUTPUT_FILE = playlist

all: clean obj playlist

obj:
	if [ ! -d $(OBJECT_DIR) ]; then mkdir $(OBJECT_DIR); fi
	$(CC) $(CFLAGS) -c $(SRC_PATH)
	mv $(OBJECT_FILES) $(OBJECT_DIR)

playlist:
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) $(OBJECT_DIR)/$(OBJECT_FILES)

uninstall:
	if [ -d $(OBJECT_DIR) ]; then rm -rf $(OBJECT_DIR); fi
	if [ -f $(OUTPUT_FILE) ]; then rm $(OUTPUT_FILE); fi

clean:
	if [ -d $(OBJECT_DIR) ]; then rm -rf $(OBJECT_DIR); fi

reinstall: uninstall all
