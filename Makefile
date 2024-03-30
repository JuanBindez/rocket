CC = gcc
CFLAGS = -Wall -O2

TARGET = rocket
INSTALL_DIR = /usr/local/bin

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/exe_commands.c $(SRC_DIR)/help.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	cp $(TARGET) $(INSTALL_DIR)

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
