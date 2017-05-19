#!/bin/sh

grep_check()
{
    grep "\s$1\s" $2 > output
    printf "%-*s" 20 "${2##*/}"
    if [[ -s output ]]
    then echo " >> \033[0;32m [YES]\033[0m"
    else echo " >> \033[0;31m [NO]\033[0m"
    fi
    rm -Rf output
}
    echo "=======LIVE======="
    for it in $@
    do
        grep_check "live" $it
    done
    echo "========LD========"
    for it in $@
    do
        grep_check "ld" $it
    done
    echo "========ST========"
    for it in $@
    do
        grep_check "st" $it
    done
    echo "========ADD======="
    for it in $@
    do
        grep_check "add" $it
    done
    echo "========SUB======="
    for it in $@
    do
        grep_check "sub" $it
    done
    echo "========AND======="
    for it in $@
    do
        grep_check "and" $it
    done
    echo "========OR========"
    for it in $@
    do
        grep_check "or" $it
    done
    echo "=======XOR========"
    for it in $@
    do
        grep_check "xor" $it
    done
    echo "=======ZJMP======="
    for it in $@
    do
        grep_check "zjmp" $it
    done
    echo "=======LDI========"
    for it in $@
    do
        grep_check "ldi" $it
    done
    echo "========STI======="
    for it in $@
    do
        grep_check "sti" $it
    done
    echo "=======FORK======="
    for it in $@
    do
        grep_check "fork" $it
    done
    echo "========LLD======="
    for it in $@
    do
        grep_check "lld" $it
    done
    echo "=======LLDI======="
    for it in $@
    do
        grep_check "lldi" $it
    done
    echo "======LFORK======="
    for it in $@
    do
        grep_check "lfork" $it
    done
    echo "=======AFF========"
    for it in $@
    do
        grep_check "aff" $it
    done
