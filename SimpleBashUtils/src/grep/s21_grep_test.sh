#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0

testing(){
    ./s21_grep $var -ea  1.txt 2.txt> test_s21_grep.log 
    grep $var -ea  1.txt 2.txt> test_grep.log
    if cmp -s test_s21_grep.log test_grep.log
    then
    (( SUCCESS++ ))
    (( COUNTER++ ))

    echo "Test  №$COUNTER SUCCESS $var";
    else
    (( FAIL++ ))
    (( COUNTER++ ))

    echo "Test  №$COUNTER FAIL $var"
    fi
    rm test_s21_grep.log test_grep.log
}

testing2(){
    ./s21_grep $var -ea -eb  1.txt 2.txt> test_s21_grep.log 
    grep $var -ea -eb  1.txt 2.txt> test_grep.log
    if cmp -s test_s21_grep.log test_grep.log
    then
    (( SUCCESS++ ))
    (( COUNTER++ ))

    echo "Test  №$COUNTER SUCCESS $var";
    else
    (( FAIL++ ))
    (( COUNTER++ ))

    echo "Test  №$COUNTER FAIL $var"
    fi
    rm test_s21_grep.log test_grep.log
}

testing3(){
    ./s21_grep $var -f3.txt  1.txt 2.txt> test_s21_grep.log 
    grep $var -f3.txt  1.txt 2.txt> test_grep.log
    if cmp -s test_s21_grep.log test_grep.log
    then
    (( SUCCESS++ ))
    (( COUNTER++ ))

    echo "Test  №$COUNTER SUCCESS $var";
    else
    (( FAIL++ ))
    (( COUNTER++ ))

    echo "Test  №$COUNTER FAIL $var"
    fi
    rm test_s21_grep.log test_grep.log
}

testing4(){
    valgrind --tool=memcheck --leak-check=yes ./s21_grep $var -f3.txt  1.txt 2.txt> test_s21_grep.log     
}

testing

for v1 in v c l n i h s o
do  
    var="-$v1"
    testing $var
done

for v1 in v c l n i h s o
do  
    for v2 in v c l n i h s o
    do  
        if [ $v1 != $v2 ]
        then
            var="-$v1 -$v2"
            testing $var
        fi
    done
done

for v1 in v c l n i h s o
do  
    for v2 in v c l n i h s o
    do  
        for v3 in v c l n i h s o
        do
            if [ $v1 != $v2 ] && [ $v2 != $v3 ] && [ $v1 != $v3 ]
            then  
                var="-$v1 -$v2 -$v3"
                testing $var
            fi
        done
    done
done

for v1 in v c l n i h s o
do   
    for v2 in v c l n i h s o
    do  
        for v3 in v c l n i h s o
        do
            for v4 in v c l n i h s o
            do
                if [ $v1 != $v2 ] && [ $v1 != $v3 ] && [ $v1 != $v4 ] && [ $v2 != $v3 ] && [ $v2 != $v4 ] && [ $v3 != $v4 ]
                then  
                    var="-$v1 -$v2 -$v3 -$v4"
                    testing $var
                fi
            done
        done
    done
done

for v1 in v c l n i h s o
do  
    for v2 in v c l n i h s o
    do  
        for v3 in v c l n i h s o
        do
            for v4 in v c l n i h s o
            do  
                for v5 in v c l n i h s o
                do
                    if [ $v1 != $v2 ] && [ $v1 != $v3 ] && [ $v1 != $v4 ] && [ $v1 != $v5 ] && [ $v2 != $v3 ] && [ $v2 != $v4 ] && [ $v2 != $v5 ] && [ $v3 != $v4 ] && [ $v3 != $v5 ] && [ $v4 != $v5 ]
                    then  
                        var="-$v1 -$v2 -$v3 -$v4 -$v5"
                        testing $var
                    fi
                done
            done
        done
    done
done

for v1 in v c l n i h s o
do  
    for v2 in v c l n i h s o
    do  
        for v3 in v c l n i h s o
        do
            for v4 in v c l n i h s o
            do  
                for v5 in v c l n i h s o
                do
                    for v6 in v c l n i h s o
                    do
                        if [ $v1 != $v2 ] && [ $v1 != $v3 ] && [ $v1 != $v4 ] && [ $v1 != $v5 ] && [ $v1 != $v6 ] && [ $v2 != $v3 ] && [ $v2 != $v4 ] && [ $v2 != $v5 ] && [ $v2 != $v6 ] && [ $v3 != $v4 ] && [ $v3 != $v5 ] && [ $v3 != $v6 ] && [ $v4 != $v5 ] && [ $v4 != $v6 ] && [ $v5 != $v6 ]
                        then
                            var="-$v1 -$v2 -$v3 -$v4 -$v5 -$v6"
                            testing $var
                        fi
                    done
                done
            done
        done
    done
done

for v1 in v c l n i h s o
do  
    for v2 in v c l n i h s o
    do  
        for v3 in v c l n i h s o
        do
            for v4 in v c l n i h s o
            do  
                for v5 in v c l n i h s o
                do
                    for v6 in v c l n i h s o
                    do
                        for v7 in v c l n i h s o
                        do
                            if [ $v1 != $v2 ] && [ $v1 != $v3 ] && [ $v1 != $v4 ] && [ $v1 != $v5 ] && [ $v1 != $v6 ] && [ $v1 != $v7 ] && [ $v2 != $v3 ] && [ $v2 != $v4 ] && [ $v2 != $v5 ] && [ $v2 != $v6 ] && [ $v2 != $v7 ] && [ $v3 != $v4 ] && [ $v3 != $v5 ] && [ $v3 != $v6 ] && [ $v3 != $v7 ] && [ $v4 != $v5 ] && [ $v4 != $v6 ] && [ $v4 != $v7 ] && [ $v5 != $v6 ] && [ $v5 != $v7 ] && [ $v6 != $v7 ]
                            then
                                var="-$v1 -$v2 -$v3 -$v4 -$v5 -$v6 -$v7"
                                testing $var
                            fi
                        done
                    done
                done
            done
        done
    done
done

for v1 in v c l n i h s o
do  
    for v2 in v c l n i h s o
    do  
        for v3 in v c l n i h s o
        do
            for v4 in v c l n i h s o
            do  
                for v5 in v c l n i h s o
                do
                    for v6 in v c l n i h s o
                    do
                        for v7 in v c l n i h s o
                        do
                            for v8 in v c l n i h s o
                            do
                                if [ $v1 != $v2 ] && [ $v1 != $v3 ] && [ $v1 != $v4 ] && [ $v1 != $v5 ] && [ $v1 != $v6 ] && [ $v1 != $v7 ] && [ $v1 != $v8 ] && [ $v2 != $v3 ] && [ $v2 != $v4 ] && [ $v2 != $v5 ] && [ $v2 != $v6 ] && [ $v2 != $v7 ] && [ $v2 != $v8 ] && [ $v3 != $v4 ] && [ $v3 != $v5 ] && [ $v3 != $v6 ] && [ $v3 != $v7 ] && [ $v3 != $v8 ] && [ $v4 != $v5 ] && [ $v4 != $v6 ] && [ $v4 != $v7 ] && [ $v4 != $v8 ] && [ $v5 != $v6 ] && [ $v5 != $v7 ] && [ $v5 != $v8 ] && [ $v6 != $v7 ] && [ $v6 != $v8 ] && [ $v7 != $v8 ]
                                then
                                    var="-$v1 -$v2 -$v3 -$v4 -$v5 -$v6 -$v7 -$v8"
                                    testing $var
                                fi
                            done
                        done
                    done
                done
            done
        done
    done
done

echo "SUCCESS  $SUCCESS from $COUNTER ";
echo "FAILED  $FAIL from $COUNTER ";