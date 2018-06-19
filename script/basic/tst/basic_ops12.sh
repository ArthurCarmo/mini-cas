#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp12 > outm
diff outm $srcdir/script/basic/out/outg12
if [ $? -ne 0 ]; then
    exit 1
fi
