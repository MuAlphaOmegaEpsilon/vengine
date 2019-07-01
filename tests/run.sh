#!/bin/sh
set -euf

### NAVIGATE TO THE TESTS FOLDER ###
cd "$(dirname "$0")"

### COLORING SCHEME ###
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
printf "%sRUNNING TESTS%s\\n" "${ORANGE}" "${NOCOLOR}"
if [ ! -d build ]; then
	printf "\\n%sNo build folder found: maybe you forgot to launch setup.sh first.%s\\n" "${ORANGE}" "${NOCOLOR}"
	exit 1
fi
cd build

ctest -j2
