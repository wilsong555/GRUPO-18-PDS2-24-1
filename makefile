# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Iinclude

# Directories
BINDIR = bin
INCLUDEDIR = include
OBJDIR = obj
SRCDIR = src

# Target executable
TARGET = $(BINDIR)/main

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Default target
all: $(TARGET)
	@echo "Build complete!"

# Rule to build the target
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build files
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean
