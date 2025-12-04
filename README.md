🎲 BINGO — Gerador de Cartões + Sistema de Sorteio








Este repositório contém dois programas em C++:

🟦 generatecards.cpp → Gera cartões de Bingo únicos (5×5)

🔴 bingodraw.cpp → Simula o sorteio manual das bolas de 1 a 100

O projeto segue as regras formais do jogo e foi desenvolvido para um trabalho prático de C++.

📁 Conteúdo do Repositório
📦 TrabalhoBingo/
 ┣ 📜 generatecards.cpp      → Gerador de cartões
 ┣ 📜 bingodraw.cpp          → Sistema de sorteio
 ┣ 📜 README.md              → Documentação

🟦 1. Gerador de Cartões (generatecards)
▶ Como executar

O programa recebe o número de cartões como argumento:

./generatecards [numero_de_cartoes]


❗ Valores válidos: 1 a 500

Exemplo:

./generatecards 20

🧩 Regras dos Cartões

Cada cartão segue a grelha clássica 5×5:

 B   I   N   G   O


Cada coluna contém números de um intervalo específico:

Coluna	Intervalo
B	1 – 20
I	21 – 40
N	41 – 60
G	61 – 80
O	81 – 100
✔ Garantias do programa:

Cada coluna tem números únicos

A posição centro (linha 3, coluna N) fica marcada como **

Todos os cartões são diferentes entre si

Cartões são impressos com formatação legível

📝 Exemplo de Saída
Carta 1:

 B     I     N     G     O
 5    21    46    62    81
10    35    59    79    92
 3    27    **    70    88
12    40    53    75    99
19    33    44    67   100

🔴 2. Sorteio de Bolas (bingodraw)
▶ Execução
./bingodraw

🎰 Funcionalidades

Sorteio manual (pressione ENTER para cada bola)

Mostra:

Bola atual

Última bola

Histórico das últimas 5 bolas

Números não se repetem nunca

O sorteio termina automaticamente após as 100 bolas

🔧 Compilação
Windows (MinGW)
g++ generatecards.cpp -o generatecards.exe
g++ bingodraw.cpp -o bingodraw.exe

Linux / MacOS
g++ generatecards.cpp -o generatecards
g++ bingodraw.cpp -o bingodraw

💡 Tecnologias Utilizadas

C++ (Vetores, randomização, estrutura de dados, I/O)

Geração de números pseudo-aleatórios

Manipulação de argumentos da linha de comandos

Garantia de unicidade e validação de dados

👤 Autor

Projeto desenvolvido como trabalho prático de programação em C++.
