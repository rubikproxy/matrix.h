#!/bin/bash

# Define variables
LIBRARY_NAME="libmatrix.a"
SOURCE_DIR="src"
INCLUDE_DIR="include"
INSTALL_LIB_DIR="/usr/local/lib"
INSTALL_INCLUDE_DIR="/usr/local/include"

# Step 1: Clean up previous builds
echo "Cleaning up previous builds..."
rm -f $LIBRARY_NAME
rm -f $SOURCE_DIR/*.o

# Step 2: Compile the library
echo "Compiling the library..."
gcc -I$INCLUDE_DIR -Wall -Wextra -fPIC -c $SOURCE_DIR/matrix.c -o $SOURCE_DIR/matrix.o
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

# Step 3: Create the static library
echo "Creating the static library..."
ar rcs $LIBRARY_NAME $SOURCE_DIR/matrix.o
if [ $? -ne 0 ]; then
    echo "Failed to create static library. Exiting."
    exit 1
fi

# Step 4: Install the library
echo "Installing the library..."
sudo cp $LIBRARY_NAME $INSTALL_LIB_DIR/
if [ $? -ne 0 ]; then
    echo "Failed to install library. Exiting."
    exit 1
fi

sudo cp $INCLUDE_DIR/matrix.h $INSTALL_INCLUDE_DIR/
if [ $? -ne 0 ]; then
    echo "Failed to install header file. Exiting."
    exit 1
fi

sudo ldconfig
if [ $? -ne 0 ]; then
    echo "Failed to run ldconfig. Exiting."
    exit 1
fi

# Step 5: Verify the installation
echo "Verifying the installation..."
if [ -f $INSTALL_LIB_DIR/$LIBRARY_NAME ] && [ -f $INSTALL_INCLUDE_DIR/matrix.h ]; then
    echo "Matrix library installed successfully!"
else
    echo "Installation verification failed."
    exit 1
fi
