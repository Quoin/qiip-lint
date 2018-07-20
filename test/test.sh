#! /bin/sh

### test.sh ###

testMakeFileList () {
    cd ..
    cd check
    ls 1> ../testlist.txt
    cd ..
}

testForErrorDetection () {
    while read p; do
        echo "Test for $p:"
        rm -f check/"$p"/noncompliant.o && make check/"$p"/noncompliant.o 2>temp.txt
        occurance=$(grep -c "\-W$p" temp.txt)
        printf "Occurance: $occurance\n"

    done <testlist.txt
    return 0
}

## Call and Run all Tests
. "../shunit2/shunit2"
