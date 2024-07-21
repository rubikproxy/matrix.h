# Compiler and Flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -fPIC
AR = ar
ARFLAGS = rcs
LIBRARY = libmatrix.a
OBJECTS = src/matrix.o
LIBS = -lm

# Default target
all: $(LIBRARY)

# Build static library
$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

# Compile object files
src/matrix.o: src/matrix.c include/matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

# Install the library and headers
install: all
	sudo cp $(LIBRARY) /usr/local/lib/
	sudo cp include/matrix.h /usr/local/include/
	sudo ldconfig

# Uninstall the library and headers
uninstall:
	sudo rm -f /usr/local/lib/$(LIBRARY)
	sudo rm -f /usr/local/include/matrix.h

# Clean object files and library
clean:
	rm -f src/matrix.o $(LIBRARY)

.PHONY: all install uninstall clean
