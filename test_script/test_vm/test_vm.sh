#!/bin/sh

corewar_cor1_cor2()
{
    declare -i count=0
    echo "\033[1;33m$1 vs $2 :\033[0m\c "
    ../../ASM_/asm $1.s > /dev/null 2>&1
    ../../ASM_/asm $2.s > /dev/null 2>&1
    echo " [2] \c"
    ./cor_zaz/corewar -v 31 $1.cor $2.cor > output2
    echo "[1]\c"
    total=$(ls -la | grep "output2" | awk '{print $5}')
    ../../VM_/corewar -v 31 $1.cor $2.cor > output1 & pid=$!
    trap "kill $pid 2> /dev/null" EXIT
    echo ""
    while kill -0 $pid 2> /dev/null; do
        current_size=$(ls -la | grep "output1" | awk '{print $5}')
        update=$(echo "scale=2;100 * $current_size / $total" | bc)
        printf "\rLoading [%.f%%]" $update
    done
    printf "\rLoading [100%%] >>"
    trap - EXIT
    diff output1 output2 > output_diff
    if [[ -s output_diff ]]
    then echo "\033[0;31m FAILURE\033[0m"
    diff output1 output2
    else echo "\033[0;32m SUCCESS\033[0m"
    rm output1
    rm output2
    rm output_diff
    fi
}

make -C ../../ASM_/
make -C ../../VM_/
for one in $@
do
    for two in $@
    do
        corewar_cor1_cor2 ${one%.*} ${two%.*}
    done
done
# corewar_cor1_cor2 ../../champs/jumper ../../VM_/amric_player
# corewar_cor1_cor2 ../../champs/jumper ../../VM_/l
# corewar_cor1_cor2 ../../VM_/amric_player ../../VM_/l
# corewar_cor1_cor2 ../../VM_/l ../../champs/jumper
# # # corewar_cor1_cor2 ../../champs/Car ../../VM_/l
# # corewar_cor1_cor2 ../../champs/mortel ../../VM_/l
# # corewar_cor1_cor2 ../../champs/toto ../../VM_/l
# # corewar_cor1_cor2 ../../VM_/l ../../VM_/toto
# # corewar_cor1_cor2 ../../champs/car ../../champs/gagnant
# # corewar_cor1_cor2 ../../champs/jumper ../../champs/car
# # corewar_cor1_cor2 ../../champs/jumper ../../champs/ex
# corewar_cor1_cor2 ../../champs/Octobre_Rouge_V4.2 ../../VM_/a
# corewar_cor1_cor2 ../../champs/Octobre_Rouge_V4.2 ../../champs/jumper
# corewar_cor1_cor2 ../../champs/slider2 ../../champs/maxidef
# corewar_cor1_cor2 ../../champs/mortel ../../champs/maxidef
# corewar_cor1_cor2 ../../champs/toto ../../champs/slider2
# corewar_cor1_cor2 ../../champs/Octobre_Rouge_V4.2 ../../champs/maxidef

#car gagnant -barriere jumper lde maxidef mat mortel slider2 toto"
