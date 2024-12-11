CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lws2_32 -ljson-c

SRCS = src/main.c src/routes.c src/server.c src/user.c
OBJS = $(SRCS:.c=.o)

TARGET = restapic

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f $(OBJS) $(TARGET)

.PHONY: all clean
