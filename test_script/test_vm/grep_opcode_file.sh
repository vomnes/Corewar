#!/bin/sh

grep_check()
{
    grep "\s$1\s\|$1\s\|\s$1" $2 > output
    if [[ -s output ]]
    then echo "$1 : \033[0;32m [YES]\033[0m"
    else echo "$1 : \033[0;31m [NO]\033[0m"
    fi
    rm -Rf output
}
    echo "Check opcode in $1"
    grep_check "live" $1
    grep_check "ld" $1
    grep_check "st" $1
    grep_check "add" $1
    grep_check "sub" $1
    grep_check "and" $1
    grep_check "or" $1
    grep_check "xor" $1
    grep_check "zjmp" $1
    grep_check "ldi" $1
    grep_check "sti" $1
    grep_check "fork" $1
    grep_check "lld" $1
    grep_check "lldi" $1
    grep_check "lfork" $1
    grep_check "aff" $1
