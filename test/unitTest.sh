#! /bin/bash

### unitTest.sh ###

    
function testForBitShift () {
    cd ..
    rm -f check/"div-by-zero"/noncompliant.o && make check/"div-by-zero"/noncompliant.o 2>temp.txt
    occurance=$(grep -c "\-Wdiv-by-zero" temp.txt)
    printf "Occurance: $occurance\n"
    
}

## Call and Run all Tests
. "../shunit2/shunit2"
