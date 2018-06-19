#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp4 > outm
diff outm $srcdir/script/basic/out/outg4
if [ $? -ne 0 ]; then
    exit 1
fi
