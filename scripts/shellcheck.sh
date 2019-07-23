#!/bin/sh
set -euf

### NAVIGATE TO THE TESTS FOLDER ###
cd "$(dirname "$0")"

### COLORING SCHEME ###
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
printf "%sCHECKING SCRIPTS VALIDITY%s\\n" "${ORANGE}" "${NOCOLOR}"
shellcheck ../tests/setup.sh
shellcheck ../tests/build.sh
shellcheck ../tests/run.sh
