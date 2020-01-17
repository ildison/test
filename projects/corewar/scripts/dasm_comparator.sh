#!/bin/bash
MY_DASM="../asm -d"
MY_ASM="../asm"
if [ -z "$1" ] ; then
	echo "Usage: dasm_comparator.sh dirname"
	exit 1
fi
if [ ! -f "$MY_ASM" ]; then
	echo "File $MY_ASM does not exist"
	exit 1
fi
if [ ! -f "$MY_ASM" ]; then
	echo "File $MY_ASM does not exist"
	exit 1
fi
GREEN="\e[32m"
RED="\e[31m"
YELLOW="\e[1;33m"
EOC="\e[0m"
for S_FILE in $( find ${1} -type f -name "*.s" ); do
	COR_1="${S_FILE%".s"}.cor"
	${MY_ASM} ${S_FILE} &>/dev/null
	if [[ -e ${COR_1} ]]; then
		cp ${COR_1} my_champ_1.cor
	fi
	S_FILE_2="my_champ_1.s"
	${MY_DASM} my_champ_1.cor &>/dev/null
	${MY_ASM} my_champ_1.s &>/dev/null
	if [[ -e my_champ_1.cor ]] && [[ -e ${COR_1} ]]; then
		if diff my_champ_1.cor ${COR_1} &>/dev/null;
			then printf "${GREEN}OK${EOC}\t${COR_1}\n"
			else printf "${RED}KO${EOC}\t${COR_1}\n"
		fi
		rm my_champ_1.cor
		rm my_champ_1.s
		rm ${COR_1}
	elif [[ -e my_champ_1.cor ]]; then
		printf "${YELLOW}ERROR${EOC}\t(my_champ_1.cor was not created)\n"
		rm my_champ_1.cor ;
	elif [[ -e my_champ_1.s ]]; then
		printf "${YELLOW}ERROR${EOC}\t(my_champ_1.s was not created)\n"
		rm my_champ_1.s
	else
		printf "${YELLOW}ERROR${EOC}\t(incorrect file) ${S_FILE}\n"
	fi
done