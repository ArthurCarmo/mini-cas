#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp11 > outm
diff outm $srcdir/script/basic/out/outg11
if [ $? -ne 0 ]; then
    exit 1
fi
