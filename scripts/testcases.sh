#!/bin/bash

echo -e "Executing: ${0}"
set -e
set -o pipefail

# #############################################################################################################
# variables

FILE_SCRIPT="$(readlink -f $0)"
DIR_SCRIPTS="$(dirname "${FILE_SCRIPT}")"


# #############################################################################################################
# run

pushd "${DIR_DEPLOY}"
    ./tests/tests
popd
