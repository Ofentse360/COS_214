# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Directories
SRCDIR = .
OBJDIR = obj

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Executable file
EXEC = farm_simulation

# Main target
all: $(EXEC)

# Linking the final executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compiling .cpp files into .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean object files and executable
clean:
	rm -rf $(OBJDIR) $(EXEC)

# Run the executable
run: $(EXEC)
	./$(EXEC)

# Run Valgrind on the executable
mem: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

.PHONY: all clean run mem
