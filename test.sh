#!/bin/bash

#==============Colors
COLOR_NC='\e[0m' # No Color
COLOR_WHITE='\e[37;1m'
COLOR_BLACK='\e[30;1m'
COLOR_BLUE='\e[34;1m'
COLOR_LIGHT_BLUE='\e[34;1m'
COLOR_GREEN='\e[32;1m'
COLOR_LIGHT_GREEN='\e[32;1m'
COLOR_CYAN='\e[36;1m'
COLOR_LIGHT_CYAN='\e[36;1m'
COLOR_RED="\e[31;1m"
COLOR_LIGHT_RED='\e[31;1m'
COLOR_PURPLE='\e[35;1m'
COLOR_LIGHT_PURPLE='\e[35;1m'
COLOR_BROWN='\e[33;1m'
COLOR_YELLOW='\e[33;1m'
COLOR_GRAY='\e[30;1m'
COLOR_LIGHT_GRAY='\e[37;1m'

#==============Files to include
PATH_HEADER="includes"
HEADER="push_swap.h"

#==== Test a effectuer =====
let "valgrind_install = 0"
let "leaks = 0"
let "test_basic = 0"
CYCLE=5

#==============Dossier de test


OPTION=
ARRAY_CHECKER=(
"./checker $OPTION 1 2 3"
"./checker $OPTION 1 2"
"./checker $OPTION 1 2 3 3"
"./checker $OPTION"
"./checker $OPTION - 1 - 3 - 5 - 6"
"./checker $OPTION -1 -"
"./checker $OPTION 0000000000000000001"
"./checker $OPTION 1 2 3"
"./checker $OPTION 1 2 3"
"./checker $OPTION 2147483648"
"./checker $OPTION -2147483648 2147483647 0"
"./checker $OPTION 2147483647")

ARRAY_CHECKER_VALIDE=(
"VALIDE"
"VALIDE"
"ERROR"
"VALIDE"
"ERROR"
"ERROR"
"VALIDE"
"ERROR"
"VALIDE"
"VALIDE")

ARRAY_INPUT=(
"sa\npb\npb\npb\npb\npb\nsa\nsa\npa\npa\nra\nrr\nrr\nrrr\nrrr\nrrr\nrrr"
)

#==============Install Valgrin
if [ $valgrind_install -eq 1 ]; then
	brew update
	brew install valgrind
	alias valgrind="~/.brew/bin/valgrind"
	source ~/.bashrc
fi

#============== Lancement des tests ==============
#..................Tests de forme.................
clear
if [ $test_basic -eq 1 ]; then
	printf "${COLOR_GREEN}====Norminette====\n${COLOR_NC}"
	norminette | grep Error
	sleep 2s ; clear ; make
	printf "${COLOR_GREEN}write \nread\nmalloc\nfree\nexit\n${COLOR_NC}"
	printf "${COLOR_GREEN}====checker====\n${COLOR_NC}"
	nm -u ./checker
	printf "${COLOR_GREEN}====push_swap====\n${COLOR_NC}"
	nm -u ./push_swap
	sleep 15s
else
	clear && make
fi

#============== Tests  ===================
if [ $leaks -eq 1 ]; then
	LEAKS='valgrind'
else
	LEAKS=""
fi

printf "==== Test des leaks ====="
for i in ${!ARRAY_CHECKER[*]}; 	do
	for a in `seq 1 $CYCLE`; do
		printf "\n${COLOR_YELLOW}Test %d: $LEAKS %s${COLOR_NC} || array_input = %s || \
		Solution %s \n" $a "${ARRAY_CHECKER[$i]}" "${ARRAY_INPUT[$i]}" "${ARRAY_CHECKER_VALIDE[$i]}"
		TMP="`echo ${ARRAY_INPUT[$i]} | $LEAKS ${ARRAY_CHECKER[$i]} 2>&1 | grep -E "definitely lost|indirectly lost" | grep -E "==[1-9]*==[a-zA-Z :]*[1-9]"`"
		printf "${COLOR_RED}%s${COLOR_NC}" $TMP
		printf "\n${COLOR_PURPLE}Fonction: %s${COLOR_NC}\n" "${ARRAY_CHECKER[$i]}"
		echo ${ARRAY_INPUT[$i]} | ${ARRAY_CHECKER[$i]}
	done
	printf "\n\n"
done
