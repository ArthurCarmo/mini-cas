#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp3 > outm
diff outm $srcdir/script/basic/out/outg3
if [ $? -ne 0 ]; then
    exit 1
fi
