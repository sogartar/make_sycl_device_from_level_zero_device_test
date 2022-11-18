#!/bin/bash

set -e
set -o pipefail

SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

export BUILD_TYPE=Debug

nice -n 19 \
cmake --build "$SCRIPT_DIR/build/$BUILD_TYPE" \
  -- \
  all

