#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp8 > outm
diff outm $srcdir/script/basic/out/outg8
if [ $? -ne 0 ]; then
    exit 1
fi
