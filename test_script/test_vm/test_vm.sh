#!/bin/sh

corewar_cor1_cor2()
{
    echo "\033[1;33m$1 vs $2 :\033[0m\c "
    ../../ASM_/asm $1.s > /dev/null
    ../../ASM_/asm $2.s > /dev/null
    echo "#\c"
    ./cor/corewar -v 31 $1.cor $2.cor > output1
    echo "#\c"
    ./cor_zaz/corewar -v 31 $1.cor $2.cor > output2
    diff output1 output2 > output_diff
    if [[ -s output_diff ]]
    then echo "\033[0;32mFAILURE\033[0m"
    diff output1 output2 > ./diff/$1$2_diff
    else echo "\033[0;32mSUCCESS\033[0m"
    fi
}

rm -r diff
mkdir diff
corewar_cor1_cor2 ../../champs/Octobre_Rouge_V4.2 ../../champs/toto
# corewar_cor1_cor2 ../../champs/car ../../champs/gagnant
corewar_cor1_cor2 ../../champs/barriere ../../champs/car
corewar_cor1_cor2 ../../champs/jumper ../../champs/ex
corewar_cor1_cor2 ../../champs/Octobre_Rouge_V4.2 ../../champs/jumper
corewar_cor1_cor2 ../../champs/lde ../../champs/maxidef
corewar_cor1_cor2 ../../champs/mortel ../../champs/mat
corewar_cor1_cor2 ../../champs/toto ../../champs/slider2
corewar_cor1_cor2 ../../champs/Octobre_Rouge_V4.2 ../../champs/maxidef

#car gagnant barriere jumper lde maxidef mat mortel slider2 toto"
