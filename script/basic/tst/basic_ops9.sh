#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp9 > outm
diff outm $srcdir/script/basic/out/outg9
if [ $? -ne 0 ]; then
    exit 1
fi
