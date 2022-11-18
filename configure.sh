#!/bin/bash

set -e
set -o pipefail

SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

export BUILD_TYPE=Debug

cmake \
  -B "$SCRIPT_DIR/build/$BUILD_TYPE" \
  -S "$SCRIPT_DIR" \
  -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -DCMAKE_CXX_COMPILER=dpcpp

