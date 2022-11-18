#!/bin/bash

SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

source /opt/intel/oneapi/setvars.sh
export PATH=$SCRIPT_DIR/build/Debug:$PATH
