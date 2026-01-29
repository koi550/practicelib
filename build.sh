#!/usr/bin/env bash
set -e

BUILD_DIR=build
BUILD_TYPE=Release

cmake -S . -B $BUILD_DIR \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build $BUILD_DIR -j$(nproc)
