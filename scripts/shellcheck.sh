#!/bin/sh
set -euf

### NAVIGATE TO THE TESTS FOLDER ###
cd "$(dirname "$0")"

### COLORING SCHEME ###
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
printf "%sCHECKING SCRIPTS VALIDITY%s\\n" "${ORANGE}" "${NOCOLOR}"
shellcheck -x installVulkan.sh
shellcheck -x exportVulkanVariables.sh

cd ../tests
shellcheck -x setup.sh
shellcheck -x build.sh
shellcheck -x run.sh
