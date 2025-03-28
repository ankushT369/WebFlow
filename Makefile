# Compiler and Flags
CXX = g++
#CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
CXXFLAGS = -std=c++17 -Iinclude
LDFLAGS = -lpthread -lfmt  # Add -lfmt here

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# Source Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cc) $(SRC_DIR)/main.cpp
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES)))
MAIN_OBJ = $(OBJ_DIR)/main.o

# Output Binary
TARGET = $(BIN_DIR)/webflow

# Default rule (Compile and Build)
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJ_FILES) $(MAIN_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)  # Add LDFLAGS here

# Compile .cc files into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp separately
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create necessary directories
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the server
run: all
	./$(TARGET)

