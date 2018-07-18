#! /bin/sh

### test.sh ###

testMakeFileList () {
    cd ..
    cd itc-benchmarks/01.w_Defects
    ls 1> filelist.txt
    grep "\.c" filelist.txt 1> testlist.txt
}

testForErrorDetection () {
    while read p; do
        echo "Test for $p:"
        gcc -f'no-diagnostics-color' -f'no-diagnostics-show-caret' -f'no-show-column' -c "$p" 2> ./temp
        occurance=$(expr "$(grep -c "$p" ./temp)" / 2)
        printf "gcc detection: %s cases.\n" "$occurance"
        clang -f'no-diagnostics-color' -f'no-caret-diagnostics' -f'no-show-column' -c "$p" 2> ./temp
        occurance=$(grep -c "$p" ./temp)
        printf "clang detection: %s cases.\n" "$occurance"
        cppcheck "$p" 2> ./temp 1> /dev/null
        occurance=$(grep -c "error" ./temp)
        printf "cppcheck detection: %s cases.\n" "$occurance"
    done <testlist.txt
    return 0
}

## Call and Run all Tests
. "../shunit2/shunit2"
