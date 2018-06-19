#!/bin/bash


./t_basic < $srcdir/script/basic/in/inp13 > outm
diff outm $srcdir/script/basic/out/outg13
if [ $? -ne 0 ]; then
    exit 1
fi
rm outm
