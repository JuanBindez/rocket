CC = gcc
CFLAGS = -Wall -O2

TARGET = makegit
INSTALL_DIR = /usr/local/bin

all: $(TARGET)

$(TARGET): src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c

install: $(TARGET)
	cp $(TARGET) $(INSTALL_DIR)

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)

clean:
	rm -f $(TARGET)
