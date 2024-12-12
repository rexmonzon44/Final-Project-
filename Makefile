# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Output directory
OUTPUT_DIR = output

# Target executable name
TARGET = $(OUTPUT_DIR)/main

# Object files
OBJS = main.o AllCustomers.o AllPurchases.o

# Default target
all: $(TARGET)

# Link the program
$(TARGET): $(OBJS)
	mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
main.o: main.cpp AllCustomers.h AllPurchases.h
	$(CXX) $(CXXFLAGS) -c main.cpp

AllCustomers.o: AllCustomers.cpp AllCustomers.h
	$(CXX) $(CXXFLAGS) -c AllCustomers.cpp

AllPurchases.o: AllPurchases.cpp AllPurchases.h
	$(CXX) $(CXXFLAGS) -c AllPurchases.cpp

# Clean up
clean:
	rm -f *.o
	rm -rf $(OUTPUT_DIR)

# Phony targets
.PHONY: all clean



