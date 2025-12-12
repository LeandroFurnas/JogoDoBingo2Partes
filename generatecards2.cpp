#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <fstream>   
#include <random>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: ./generatecards [numero_de_cartoes]\n";
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1 || n > 500) {
        cout << "Numero de cartoes deve ser entre 1 e 500\n";
        return 1;
    }

    srand(time(NULL));

    vector<pair<int,int>> limites = {{1,20},{21,40},{41,60},{61,80},{81,100}};

    for (int c = 1; c <= n; c++) {
        vector<vector<int>> card(5, vector<int>(5));

        for (int col = 0; col < 5; col++) {
            vector<int> numeros;
            for (int i = limites[col].first; i <= limites[col].second; i++)
                numeros.push_back(i);

             std::shuffle(numeros.begin(), numeros.end(), std::mt19937(std::random_device{}()));

            for (int row = 0; row < 5; row++)
                card[row][col] = numeros[row];
        }

        
        card[2][2] = 0;

        
        string fileName = "carta_" + to_string(c) + ".txt";

        /
        ofstream file(fileName);
        if (!file) {
            cout << "Erro ao criar arquivo: " << fileName << "\n";
            continue;
        }

        
        file << "Carta " << c << ":\n\n";
        file << " B\t I\t N\t G\t O\n";

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (row == 2 && col == 2)
                    file << " **\t";
                else
                    file << setw(3) << card[row][col] << "\t";
            }
            file << "\n";
        }

        file.close();
        cout << "Criado: " << fileName << "\n";
    }

    return 0;
}
