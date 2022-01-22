#!/bin/sh

set -e

UNAME=`uname`
EXE_SUFFIX=""
[ "$UNAME" != "Linux" ] && [ "$UNAME" != "Darwin" ] && EXE_SUFFIX='.exe'
TESTS=`ls gn-out/*_test$EXE_SUFFIX`

for T in $TESTS; do
    echo '\n# =================================================='
    echo "# $T"
    ./$T
done
