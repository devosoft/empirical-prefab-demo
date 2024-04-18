#!/bin/bash

# Get the emsdk repo
git clone https://github.com/emscripten-core/emsdk.git

# Enter that directory
cd emsdk

# Fetch the latest version of the emsdk (not needed the first time you clone)
git pull

# Download and install the latest SDK tools.
./emsdk install 3.1.57

# Make the "latest" SDK "active" for the current user. (writes ~/.emscripten file)
./emsdk activate 3.1.57

# Activate PATH and other environment variables in the current terminal
source ./emsdk_env.sh
