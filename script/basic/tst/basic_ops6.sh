#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp6 > outm
diff outm $srcdir/script/basic/out/outg6
if [ $? -ne 0 ]; then
    exit 1
fi
