# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -lraylib -lm -lGL -lglfw -lpthread -lrt -lX11 -ldl

# Source files
SRCS = main.cpp src/paddle.cpp src/ball.cpp src/player.cpp

# Output executable
TARGET = game

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(SRCS)
	$(CXX) -o $(TARGET) $(SRCS) $(CXXFLAGS)

# Install target
install: $(TARGET)
	mkdir -p ~/bin
	cp $(TARGET) ~/bin

# Clean target
clean:
	rm -f $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run install

