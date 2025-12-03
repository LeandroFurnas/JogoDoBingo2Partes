#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class BingoSorteio {
private:
    vector<int> numeros;
    vector<int> historico;
    int pos;

public:
    BingoSorteio() {
        for (int i = 1; i <= 100; i++) {
            numeros.push_back(i);
        }
        srand(time(NULL));
        random_shuffle(numeros.begin(), numeros.end());
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

        return bola;
    }

    void mostrar(int bolaAtual, int ultimaBola) {
        cout << string(40, '\n');

        cout << "Bola atualmente sorteada: ";
        if (bolaAtual == -1) cout << "(nenhuma)\n";
        else cout << bolaAtual << "\n";

        cout << "Última bola sorteada: ";
        if (ultimaBola == -1) cout << "(nenhuma)\n";
        else cout << ultimaBola << "\n";

        cout << "Últimas 5 bolas sorteadas: ";
        if (historico.empty()) {
            cout << "(nenhuma)";
        } else {
            for (int i = 0; i < historico.size(); i++) {
                cout << historico[i];
                if (i < historico.size() - 1) cout << ", ";
            }
        }
        cout << "\n";
    }
};

int main() {
    BingoSorteio jogo;

    int bolaAtual = -1;
    int ultimaBola = -1;

    cout << "=== Bingo Manual ===\n";
    cout << "Carrega ENTER para sortear a próxima bola.\n\n";

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
