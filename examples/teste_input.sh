#!/bin/bash

for i in {1..13};
do
echo Teste$i
./exemplo < inp$i > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg$i
done
