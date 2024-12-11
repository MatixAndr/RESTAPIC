CC = g++
CFLAGS = -Wall -Wextra
LDFLAGS = -lws2_32

SRCS = src/main.cpp src/routes.cpp src/server.cpp src/user.cpp
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