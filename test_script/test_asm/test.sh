#!/bin/sh
if [ "$1" = "-clean" ]
then 
	rm -rf hexa
	rm -rf ./cor_zaz/*.cor
	rm -rf ./cor/*.cor
else
	mkdir hexa
	for it in $@
	do
		./cor_zaz/asm_zaz $it &> /dev/null
		name=${it%.s}
		mv ./${name}.cor ./cor_zaz/
		xxd ./cor_zaz/${name##*/}.cor > ./hexa/${name##*/}_zaz.hex

		./cor/asm $it &> /dev/null
		name=${it%.s}
		mv ./${name}.cor ./cor/
		xxd ./cor/${name##*/}.cor > ./hexa/${name##*/}.hex

		diff ./hexa/${name##*/}_zaz.hex ./hexa/${name##*/}.hex > ./hexa/${name##*/}_diff
		if [[ -s ./hexa/${name##*/}_diff ]]
		then echo "\033[1;33m$it: \033[0;31mFAILURE\033[0m" 
		diff ./hexa/${name##*/}_zaz.hex ./hexa/${name##*/}.hex
		else echo "\033[1;33m$it: \033[0;32mSUCCESS\033[0m"
		fi
	done
fi
