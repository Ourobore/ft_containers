#!/usr/bin/bash
source format.sh
source compile.sh

# TO-DO: help command and error output

main()
{
    # Remove executable and log files
    if [ $# -eq 1 ] && [ $1 = "clean" ]; then
        rm -rf a.out logs/*
        echo "Cleaned!"
        exit 0
    fi
    
    test_container $1
}

main $@