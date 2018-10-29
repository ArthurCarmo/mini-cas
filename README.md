# mini-cas

Projeto de TCC.

Biblioteca para matemática simbólica em C++11

## Classes que já funcionam

* num_z      : números inteiros de precisão arbitrária
* num_q      : números racionais de precisão arbitrária
* num_zm     : números inteiros para aritmética modular
* monomial   : monômios de variáveis arbitrárias e coeficiente racional
* polynomial : polinômios de variáveis arbitrárias e coeficientes racionais

## Instalação

Extrair o arquivo minicas-beta.tar.gz e ir para a pasta descompactada
```  
tar -xzf minicas-beta.tar.gz
cd minicas-beta/
```
Definir a pasta de instalação (padrão /usr/local)
Por exemplo, para instalar em /home/arthur/local:
```
export MINICAS_DIR=/home/arthur/local
```
E executar o configure e make para instalação (make pode precisar de acesso de super user)
```
./configure --prefix=${MINICAS_DIR}
make check install
```
## Uso
O cabeçalho a ser incluído no programa é
```
#include <mini-cas>
```
Se a biblioteca estiver em uma pasta que não é padrão
é preciso adicionar os caminhos para as pastas include e lib
```
g++ -std=c++11 exemplo.cpp -o exemplo -I${MINICAS_DIR}/include -L${MINICAS_DIR}/lib -lminicas
```
ou
```
g++ -std=c++11 -static exemplo.cpp -o exemplo -I${MINICAS_DIR}/include -L${MINICAS_DIR}/lib -lminicas
```
Se o programa for compilado sem a opção static, ainda é preciso
adicionar o caminho da biblioteca no loader dinâmico
```
export LD_LIBRARY_PATH=${MINICAS_DIR}/lib:$LD_LIBRARY_PATH
./exemplo
```
ou
```
LD_LIBRARY_PATH=${MINICAS_DIR}/lib:$LD_LIBRARY_PATH ./exemplo
```
