#!/usr/bin/bash

HELP=1
NO_CLEAN=1

parse_options()
{
    for arg in $@; do
        shift
        case $arg in
            --help)
                HELP=0
                continue
                ;;
            --no-clean)
                NO_CLEAN=0
                continue
                ;;
            *) CONTAINERS+=("$arg")
            ;;
        esac
    done
}

print_help()
{
    echo "//To do: print help"
}