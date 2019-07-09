#!/bin/sh
#shellcheck disable=SC1091
set -euf

### NAVIGATE TO THE ROOT FOLDER ###
cd "$(dirname "$0")/.."
#. ./scripts/exportVulkanVariables.sh
### NAVIGATE TO THE TESTS FOLDER ###
cd tests

### COLORING SCHEME ###
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
printf "%sSETTING UP TESTS%s\\n" "${ORANGE}" "${NOCOLOR}"
if [ -d build ]; then 
	rm -rf build 
fi
mkdir build
cd build

if [ -n "${COVERAGE:-}" ]; then
	cmake .. -DCOVERAGE_FLAG=--coverage	
else
	cmake ..
fi
