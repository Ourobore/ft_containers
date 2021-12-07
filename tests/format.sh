#!/usr/bin/bash

RESET="\e[0m"
BOLD="\e[1m"
FAINT="\e[2m"
ITALIC="\e[3m"
UNDERLINE="\e[4m"

BLACK="\e[30m"
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGENTA="\e[35m"
CYAN="\e[36m"
LIGHT_GRAY="\e[37m"
GRAY="\e[90m"
LIGHT_RED="\e[91m"
LIGHT_GREEN="\e[92m"
LIGHT_YELLOW="\e[93m"
LIGHT_BLUE="\e[94m"
LIGHT_MAGENTA="\e[95m"
LIGHT_CYAN="\e[96m"
WHITE="\e[97m"

BACK_BLACK="\e[40m"
BACK_RED="\e[41m"
BACK_GREEN="\e[42m"
BACK_YELLOW="\e[43m"
BACK_BLUE="\e[44m"
BACK_MAGENTA="\e[45m"
BACK_CYAN="\e[46m"
BACK_LIGHT_GRAY="\e[47m"
BACK_GRAY="\e[100m"
BACK_LIGHT_RED="\e[101m"
BACK_LIGHT_GREEN="\e[102m"
BACK_LIGHT_YELLOW="\e[103m"
BACK_LIGHT_BLUE="\e[104m"
BACK_LIGHT_MAGENTA="\e[105m"
BACK_LIGHT_CYAN="\e[106m"
BACK_WHITE="\e[107m"

# Transform function return status code to string:
#   $1 -> status code
transform_status()
{
    if [ $1 -eq 0 ]; then
        echo "${GREEN}OK!${RESET}"
    else
        echo "${RED}KO!${RESET}"
    fi

}

# Print test status:
#   $1 -> test path
#   $2 -> std compilation
#   $3 -> ft compilation
#   $3 -> test result
print_test_result()
{
    local std_compiled=$(transform_status $2)
    local ft_compiled=$(transform_status $3)
    local result=$(transform_status $4)

    echo -e "$1:\t\t STD Compiled: [$std_compiled]\tFT Compiled: [$ft_compiled]\tResult: [$result]"
}