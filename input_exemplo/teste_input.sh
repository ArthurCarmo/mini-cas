#!/bin/bash

../../TCC/exemplo_gmp/teste_gmp < inp > out_exemplo/outg
../../TCC/exemplo_gmp/teste_gmp < inp2 > out_exemplo/outg2
../../TCC/exemplo_gmp/teste_gmp < inp3 > out_exemplo/outg3
../../TCC/exemplo_gmp/teste_gmp < inp4 > out_exemplo/outg4
../../TCC/exemplo_gmp/teste_gmp < inp5 > out_exemplo/outg5
../../TCC/exemplo_gmp/teste_gmp < inp5_inv > out_exemplo/outg5_inv

../mini-cas < inp > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg
../mini-cas < inp2 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg2
../mini-cas < inp3 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg3
../mini-cas < inp4 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg4
../mini-cas < inp5 > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg5
../mini-cas < inp5_inv > out_exemplo/outm
diff out_exemplo/outm out_exemplo/outg5_inv
