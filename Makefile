CC = g++
CFLAGS = -Wall -Wextra -w
LDFLAGS = -lws2_32

SRCS = src/main.cpp src/routes.cpp src/server.cpp src/user.cpp tests/unit_tests.cpp tests/integration_tests.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = restapic

GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo -e "$(BLUE)Linking $(TARGET)...$(RESET)"
	$(CC) -o $@ $^ $(LDFLAGS)
	@echo -e "$(GREEN)Build successful!$(RESET)"

%.o: %.cpp
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo -e "$(YELLOW)Cleaning up...$(RESET)"
	cmd /C "del /Q $(subst /,\,$(OBJS)) $(TARGET).exe"
	@echo -e "$(GREEN)Clean complete!$(RESET)"

.PHONY: all clean