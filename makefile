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
TARGET = $(BINDIR)/main.exe

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# OS detection
ifeq ($(OS), Windows_NT)
    MKDIR = if not exist $(1) mkdir $(1)
    RM = powershell -Command "Remove-Item -Force $(OBJDIR)\*.o, $(BINDIR)\main.exe"
else
    MKDIR = mkdir -p $(1)
    RM = rm -rf $(OBJDIR)/*.o $(TARGET)
endif

# Default target
.PHONY: all clean
all: $(TARGET)
	@echo "Build complete!"

# Rule to build the target
$(TARGET): $(OBJECTS)
	$(call MKDIR,$(BINDIR))
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(call MKDIR,$(OBJDIR))
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build files
clean:
	$(RM)

.PHONY: all clean
