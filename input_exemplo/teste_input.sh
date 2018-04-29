#!/bin/bash

../../TCC/exemplo_gmp/teste_gmp < inp > out_exemplo/outg
../../TCC/exemplo_gmp/teste_gmp < inp2 > out_exemplo/outg2
../../TCC/exemplo_gmp/teste_gmp < inp3 > out_exemplo/outg3
../../TCC/exemplo_gmp/teste_gmp < inp4 > out_exemplo/outg4
../../TCC/exemplo_gmp/teste_gmp < inp5 > out_exemplo/outg5
../../TCC/exemplo_gmp/teste_gmp < inp5_inv > out_exemplo/outg5_inv

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
