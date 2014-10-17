#! /bin/bash

for ex in main*; do
    echo -e "\nExecuting $ex\n"
    ./$ex
done

command -v dot >/dev/null 2>&1 || { echo >&2 "I require dot but it's not installed.  Aborting."; exit 1; }

for df in *.dot; do
    echo -e "\nInterpreting $df"
    dot $df -Tsvg -O
    echo -e "Successfully outputted $df.svg\n"
done

