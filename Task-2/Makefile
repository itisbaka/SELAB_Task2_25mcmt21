# Makefile for Student Result Processing System
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = student_result_system
SRCDIR = .
OBJDIR = obj

# Source files
SOURCES = main.cpp student.cpp validation.cpp grade_calculator.cpp \
          file_handler.cpp statistics.cpp student_result_system.cpp

# Object files
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

# Header files
HEADERS = constants.h student.h validation.h grade_calculator.h \
          file_handler.h statistics.h student_result_system.h

# Default target
all: $(OBJDIR) $(TARGET)

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build successful! Run ./$(TARGET) to execute."

# Compile source files to object files
$(OBJDIR)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET) *.exe
	@echo "Clean complete."

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  make          - Build the project"
	@echo "  make clean    - Remove build artifacts"
	@echo "  make run      - Build and run the program"
	@echo "  make help     - Show this help message"

.PHONY: all clean run help

