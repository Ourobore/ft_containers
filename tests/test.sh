#!/usr/bin/bash
source format.sh
source compile.sh

# TO-DO: help command and error output

# Check if every container in the argument list can be tested
check_containers()
{
    tested_containers=(vector stack map set)
    for container in $@; do
        tested=1
        for tested_container in ${tested_containers[@]}; do
            if [ $container = $tested_container ]; then
                tested=0
                break
            fi
        done
        if [ $tested -ne 0 ]; then
            printf "%s\n" "$container cannot be tested."
            #print_help
            exit 1
        fi
    done
}

main()
{
    # Remove executable and log files
    if [ $# -eq 1 ] && [ $1 = "clean" ]; then
        rm -rf a.out logs/*
        echo "Cleaned!"
        exit 0
    fi
    
    if [ $# -eq 0 ]; then
        print_help
    elif [ $# -eq 1 ] && [ $1 = "clean" ]; then
        clean
    else
        check_containers $@
        for container in $@; do
            test_container $container
        done
    fi
}

main $@