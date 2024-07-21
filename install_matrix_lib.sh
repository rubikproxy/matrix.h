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

# Step 3: Create the static library
echo "Creating the static library..."
ar rcs $LIBRARY_NAME $SOURCE_DIR/matrix.o

# Step 4: Install the library
echo "Installing the library..."
sudo cp $LIBRARY_NAME $INSTALL_LIB_DIR/
sudo cp $INCLUDE_DIR/matrix.h $INSTALL_INCLUDE_DIR/
sudo ldconfig

# Step 5: Verify the installation
echo "Verifying the installation..."
ls $INSTALL_LIB_DIR/$LIBRARY_NAME
ls $INSTALL_INCLUDE_DIR/matrix.h

echo "Matrix library installed successfully!"
