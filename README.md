🎲 Bingo Generator & Roller
Sistema de geração de cartões de Bingo + sorteador manual

Este repositório contém dois programas independentes escritos em C++, projetados para funcionar juntos num jogo de Bingo:

generatecards.cpp → Gera cartões de Bingo totalmente aleatórios e todos diferentes.

rollnumbers.cpp → Sorteia bolas de 1 a 100 em modo manual (pressionando ENTER).

Ambos foram pensados para terminal/linha de comandos e funcionam em Linux, macOS e Windows (com MinGW).

📌 1. generatecards.cpp — Gerador de Cartões de Bingo
🔍 O que faz:

Gera entre 1 e 500 cartões automaticamente.

Cada cartão contém uma grelha 5×5.

Cada coluna tem um intervalo fixo:

B: 1–20

I: 21–40

N: 41–60

G: 61–80

O: 81–100

A posição central (linha 3, coluna 3) é FREE SPACE.

Todos os cartões gerados são diferentes entre si.

Utiliza std::vector em vez de arrays.

▶️ Como compilar
g++ generatecards.cpp -o generatecards

▶️ Como executar
./generatecards [numero_de_cartoes]


Exemplo:

./generatecards 20

🎱 2. rollnumbers.cpp — Sorteador Manual
🔍 O que faz:

Sorteia números de 1 a 100 sem repetição.

O jogador pressiona ENTER para sortear a próxima bola.

Mostra:

bola atual

última bola

últimas 5 bolas sorteadas

Usa vector<int> em vez de arrays.

Interface limpa (limpa o ecrã entre jogadas com quebras de linha).

▶️ Como compilar
g++ rollnumbers.cpp -o rollnumbers

▶️ Como executar
./rollnumbers


Depois é só carregar ENTER para sortear bolas uma a uma.

📁 Estrutura do Projeto
📦 Bingo-Project
 ├── generatecards.cpp
 ├── rollnumbers.cpp
 └── README.md

📜 Requisitos

Compilador C++ (g++)

Sistema operativo:

Linux (recomendado)

macOS

Windows (MinGW / WSL)

🧩 Exemplos
Cartão gerado:
 B     I     N     G     O
 12    33    44    71    88
  5    22    57    76    91
 18    28    **    69    99
  7    39    55    63    87
 14    31    59    72    94

Sorteador:
Bola atualmente sorteada: 57
Última bola sorteada: 12
Últimas 5 bolas sorteadas: 12, 88, 43, 99, 57
