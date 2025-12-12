#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>

using namespace std;


#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[93m"
#define BLUE    "\033[34m"
#define WHITE   "\033[97m"

struct grid {
    int num;
    bool marcado;
};

class BingoSorteio {
private:
    vector<int> numeros;
    vector<int> historico;
    int pos;

public:
    vector<grid> tabela;

    BingoSorteio() {
        for (int i = 1; i <= 100; i++) {
            numeros.push_back(i);
            tabela.push_back({i, false});
        }

        srand(time(NULL));
        shuffle(numeros.begin(), numeros.end(), mt19937(random_device{}()));
        pos = 0;
    }

    int sortear() {
        if (pos >= 100)
            return -1;

        int bola = numeros[pos];
        pos++;

        historico.push_back(bola);
        if (historico.size() > 5) {
            historico.erase(historico.begin());
        }

        tabela[bola - 1].marcado = true;
        return bola;
    }

    void mostrarTabela(int bolaAtual, int ultimaBola) {
        cout << "\n=== Tabela do Bingo ===\n\n";

        for (int i = 0; i < 100; i++) {
            int n = tabela[i].num;

            
            if (n == bolaAtual)
                cout << YELLOW;

            
            else if (n == ultimaBola)
                cout << BLUE;

            
            else if (tabela[i].marcado)
                cout << GREEN;

            
            else
                cout << WHITE;

            
            cout << "[" << (n < 10 ? "0" : "") << n << "] " << RESET;

            if ((i + 1) % 10 == 0)
                cout << "\n";
        }
    }

    void mostrar(int bolaAtual, int ultimaBola) {
        cout << string(40, '\n');

        cout << "Bola atual: "
             << (bolaAtual == -1 ? string("(nenhuma)") : YELLOW + to_string(bolaAtual) + RESET)
             << "\n";

        cout << "Última bola: "
             << (ultimaBola == -1 ? string("(nenhuma)") : BLUE + to_string(ultimaBola) + RESET)
             << "\n";

        cout << "Últimas 5: ";
        if (historico.empty()) cout << "(nenhuma)";
        else {
            for (int i = 0; i < historico.size(); i++) {
                cout << GREEN << historico[i] << RESET;
                if (i < historico.size() - 1) cout << ", ";
            }
        }
        cout << "\n";

        mostrarTabela(bolaAtual, ultimaBola);
    }
};

int main() {
    BingoSorteio jogo;

    int bolaAtual = -1;
    int ultimaBola = -1;

    cout << "=== Bingo Manual (Colorido) ===\n";
    cout << "ENTER para sortear a próxima bola.\n\n";

    cin.ignore();

    while (true) {
        cout << "(ENTER para sortear próxima bola)";
        cin.ignore();

        ultimaBola = bolaAtual;
        bolaAtual = jogo.sortear();

        jogo.mostrar(bolaAtual, ultimaBola);

        if (bolaAtual == -1) {
            cout << "\nTodos os números foram sorteados!\n";
            break;
        }
    }
    return 0;
}
