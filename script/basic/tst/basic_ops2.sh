#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp2 > outm
diff outm $srcdir/script/basic/out/outg2
if [ $? -ne 0 ]; then
    exit 1
fi
