# Variable for the compiler
CC = gcc

# Variable for the compiler flags
CFLAGS = -Wall -Wextra

# The default target, which will be executed when you run 'make' without any arguments
default: all

# The target to compile and execute the binary executable
run: all
	./solutions/$(FILENAME)

# The target to compile the source code
all:
	$(CC) $(CFLAGS) -o solutions/$(FILENAME:.c=) solutions/$(FILENAME).c

# The target to clean the generated files
clean:
	rm -f $(FILENAME)
