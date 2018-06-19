#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp7 > outm
diff outm $srcdir/script/basic/out/outg7
if [ $? -ne 0 ]; then
    exit 1
fi
