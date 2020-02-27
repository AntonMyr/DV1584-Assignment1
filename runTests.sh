#!/bin/bash
COUNT=$(ls testcases -1 | wc -l)
echo $COUNT
if (( $1 > 0 && $1 <= $COUNT));
then
    COUNT=$1
fi

for (( it = 1; it <= $COUNT; it++ ))
do
    echo $it
    make && ./int "testcases/testcase_$it.lua" > /dev/null
    dot -T pdf source.dot -o testcases_results/tree_$it.pdf
    google-chrome testcases_results/tree_$it.pdf
done

