#!/bin/bash



./t_basic < $srcdir/script/basic/in/inp10 > outm
diff outm $srcdir/script/basic/out/outg10
if [ $? -ne 0 ]; then
    exit 1
fi
