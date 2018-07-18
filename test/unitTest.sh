#! /bin/bash

### unitTest.sh ###

    
function testForBitShift () {
    cd ..
    cd itc-benchmarks/01.w_Defects
    gcc -c bit_shift.c 2> ./temp
    occurance=$(grep "Wshift" ./temp | wc -l)
    echo "gcc detection:"
    assertEquals '17' $occurance
    clang -c bit_shift.c 2> ./temp
    occurance=$(grep "Wshift" ./temp | wc -l)
    echo "clang detection:"
    assertEquals '17' $occurance
    cppcheck bit_shift.c 2> ./temp 1> /dev/null
    occurance=$(grep "error" ./temp | wc -l)
    echo "cppcheck detection:"
    assertEquals '17' $occurance
    return 0
    
}
function testForBufferOverrunDynamic () {
    gcc -c buffer_overrun_dynamic.c 2> ./temp
    occurance=$(grep "Wshift" ./temp | wc -l)
    echo "gcc detection:"
    assertEquals '17' $occurance
    clang -c buffer_overrun_dynamic.c 2> ./temp
    occurance=$(grep "Wshift" ./temp | wc -l)
    echo "clang detection:"
    assertEquals '17' $occurance
    cppcheck buffer_overrun_dynamic.c 2> ./temp 1> /dev/null
    occurance=$(grep "error" ./temp | wc -l)
    echo "cppcheck detection:"
    assertEquals '17' $occurance
    return 0
}
## Call and Run all Tests
. "../shunit2/shunit2"
