#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// definição da struct para armazenar o nome e número sorteado
struct Jogador {
    string nome;
    int numero;
};

// função que sorteia um número aleatório e preenche a struct do jogador
int sortearNumero(Jogador& jogador) {
    srand(time(NULL));
    jogador.numero = rand() % 10 + 1;
    return jogador.numero;
}

int main() {
    // declaração do vetor com os jogadores
    Jogador jogadores[3];

    // leitura do nome dos jogadores
    for (int i = 0; i < 3; i++) {
        cout << "Digite o nome do jogador " << i+1 << ": ";
        cin >> jogadores[i].nome;
    }

    // sorteio do número aleatório para cada jogador e exibição do resultado
    for (int i = 0; i < 3; i++) {
        cout << "O jogador " << jogadores[i].nome << " sorteou o número " << sortearNumero(jogadores[i]) << endl;
    }

    return 0;
}
