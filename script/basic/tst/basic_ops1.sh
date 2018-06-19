#!/bin/bash


./t_basic < $srcdir/script/basic/in/inp1 > outm
diff outm $srcdir/script/basic/out/outg1
if [ $? -ne 0 ]; then
    exit 1
fi
