# Linx Challange 

Projeto implementado utilizando a linguagem de programação C++ e aplicando o algoritmo de busca de padrões em strings [KMP (Knuth-Morris-Pratt)](https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/kmp.html). 

### Estrutura do projeto

Este projeto contém duas pastas principais:

* **data**: Contém o arquivo Json a ser processado
* **include**: Contém todas as bibliotecas do projeto

```
|-- README.md
|
|-- data
|   |-- catalogo_produtos.json
|-- include
|   |-- processing.h
|   |-- kmp.h
|   |-- json.hpp   
|   index.cpp
```

### Instalação
Para a leitura do arquivo Json, foi empregado a biblioteca [SimpleJSON](https://github.com/nbsdx/SimpleJSON).

```bash
$ git clone https://github.com/julianyraiol/challenge-linx.git
$ cd challenge-linx
```

### Executar
```bash
$ g++ index.cpp -o processador; ./processador
$ Digite aqui sua consulta: 
```

### Exemplo de Consulta
```bash
$ Digite aqui sua consulta: Notebook

#1 - 16298 - Notebook Acer Predator Triton 700, Intel® Core™ i7-7700HQ, 32GB, SSD 512GB, NVIDIA® GeForce® GTX 1080 - PT715-51-77DD
#2 - 16688 - Notebook Acer Aspire 5, Intel® Core™ i7-7500U, 8GB, 1TB, Tela de 15,6'', Nvidia GeForce
#3 - 2147447116 - Notebook Acer® Aspire 3, Intel® Core™ i5-7200U, 4GB, 1TB, Tela de 15,6\", Intel® HD Graphics 620 - A315-53-55DD
#4 - 2147448565 - Notebook Acer, Intel CoreT i5-7200U, 4GB, 1TB, Tela de 15,6\", Intel® HD Graphics 620, Aspire 3 - A315-53-5100
#5 - 2147449890 - Notebook Acer, Intel Core i5-7200U, 4GB, 1TB, Tela de 15,6\", Gráficos HD Intel® 620, Preto - Aspire 5 - A515-51-58DG
#6 - 2147450193 - Notebook Acer, Intel Core i3-8130U, 4GB, 1TB, Tela de 15,6\", Gráficos HD Intel® 620 - Aspire 5 - A515-51-37LG
#7 - 2147453060 - Notebook Acer Aspire 3, AMD Ryzen™ 3 2200U, 4GB, 1TB, Tela de 15.6”, Preto - A315-41-R790
#8 - 2147453303 - Notebook Acer®, Intel Core i7-8550U, 8GB, 1TB, Tela de 15,6\", Cinza - Aspire 5 - A515-51-C0ZG
#9 - 2147453304 - Notebook Acer®, Intel Core i7-8550U, 8GB, 1TB, Tela de 15,6\", Gráficos HD Intel® 620, Preto - Aspire 5 - A515-51-C2TQ
#10 - 2147453305 - Notebook Acer® Spin 3, Intel® Core™ i7-8550U, 8GB, 256GB SSD, Tela de 14\", Intel® UHD Graphics 620 - SP314-51-C3ZZ
#11 - 2147453400 - Notebook Acer, Intel® Core i5-8265U, 16GB, 1TB, Tela de 15,6\", Prata, Aspire 5 - A515-52G-57NL
#12 - 2147453825 - Notebook Asus, Intel® Core™ i3-7020U, 4GB, 1TB, Tela 15,6\", Cinza - X543UA-GO2196T
#13 - 2147453827 - Notebook Asus VivoBook 15, Intel® Core™ i5-8265U, 4GB, 1TB, Tela de 15,6\", Cinza Escuro - X512FA-BR566T
#14 - 2147453829 - Notebook Asus VivoBook 15, Intel® Core i5, 8GB, 1TB, Tela de 15,6\", Prata - X512FA-BR569T
#15 - 2147453832 - Notebook Asus, Intel® Celeron® N4000, 4GB, 500GB, Tela de 15.6\", Cinza Escuro - X543MA-GO594T
#16 - 2147453833 - Notebook Asus, Intel® Celeron® N4000, 4GB, 500GB, Tela de 15.6\", Prata Metálico - X543MA-GO595T
#17 - 2147453835 - Notebook Asus, Intel® Core™ i3 7020U, 4GB, 1TB, Tela de 15,6\", Cinza - X543UA-GO2194T
#18 - 2147454447 - Notebook Aspire 3 Acer, Intel® Core™ i3-7020U, 4GB, 1TB, Tela de 15.6\" - A315-53-333H
#19 - 2147454467 - Notebook Aspire 3 Acer®, AMD Ryzen™ 3-2200U, 4GB, 1TB, Tela de 15,6'' - A315-41-R790 + Mochila Green
#20 - 2147454515 - Notebook Acer®, Intel Core i5-7200U, 4GB, 1TB, Tela de 15.6'', Gráficos HD Intel® 620, Aspire 5 - A515-51-52M7

```






