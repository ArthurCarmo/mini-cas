#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp5 > outm
diff outm $srcdir/script/basic/out/outg5
if [ $? -ne 0 ]; then
    exit 1
fi
