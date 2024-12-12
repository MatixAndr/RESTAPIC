CC = g++
CFLAGS = -Wall -Wextra
LDFLAGS = -lws2_32

SRCS = src/main.cpp src/routes.cpp src/server.cpp src/user.cpp tests/unit_tests.cpp tests/integration_tests.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = restapic

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

cleaner:
	rm -f src/*.o tests/*.o

.PHONY: all clean cleaner