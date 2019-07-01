#!/bin/sh
set -euf

### NAVIGATE TO THE TESTS FOLDER ###
cd "$(dirname "$0")"

### COLORING SCHEME ###
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
printf "%sBUILDING TESTS%s\\n" "${ORANGE}" "${NOCOLOR}"
if [ ! -d build ]; then
	printf "\\n%sNo build folder found: maybe you forgot to launch setup.sh first.%s\\n" "${ORANGE}" "${NOCOLOR}"
	exit 1
fi
cd build

if [ -n "${SONAR_SCANNER_HOME:-}" ]; then
	build-wrapper-linux-x86-64 --out-dir . cmake --build .
else
	cmake --build .
fi
