#!/bin/bash
# atm.sh - a wrapper for two programs

while true
do
    echo "do a transaction"
    if play_again.run
    then
        continue
    fi
    break
done
