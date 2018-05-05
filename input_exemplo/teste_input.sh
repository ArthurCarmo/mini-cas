#!/bin/bash

echo Teste1
../mini-cas < inp > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg
echo Teste2
../mini-cas < inp2 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg2
echo Teste3
../mini-cas < inp3 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg3
echo Teste4
../mini-cas < inp4 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg4
echo Teste5
../mini-cas < inp5 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg5
echo Teste5_inv
../mini-cas < inp5_inv > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg5_inv
echo Teste6
../mini-cas < inp6 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg6
echo Teste7
../mini-cas < inp7 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg7
echo Teste8
../mini-cas < inp8 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg8
echo Teste9
../mini-cas < inp9 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg9
