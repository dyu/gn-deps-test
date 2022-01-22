#!/bin/sh

TESTS=`ls gn-out/*_test`

for T in $TESTS; do
    echo '\n# =================================================='
    echo "# $T"
    ./$T
done
