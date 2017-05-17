#!/bin/sh

corewar_cor1_cor2()
{
    ./asm $1.s
    ./asm $2.s
    echo "\x1b[38;5;214m--> Corewar $1\033[0m"
    ./cor/corewar -v 31 $1.cor $2.cor > output1
    echo "\x1b[38;5;214m--> Corewar $2\033[0m"
    ./cor_zaz/corewar -v 31 $1.cor $2.cor > output2
    diff output1 output2 > output_diff
    if [[ -s output_diff ]]
    then echo "\033[1;33m$it: \033[0;31mFAILURE\033[0m"
    diff output1 output2 > ./diff/$1$2_diff
    else echo "\033[1;33m$it: \033[0;32mSUCCESS\033[0m"
    fi
}

rm -r diff
mkdir diff
corewar_cor1_cor2 ../../champs/Octobre_Rouge_V4.2 ../../champs/ex
