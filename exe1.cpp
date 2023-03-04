#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct ContaCorrente {
    string nome;
    string cpf;
    double valor;
};

bool comparaContas(const ContaCorrente &a, const ContaCorrente &b) {
    return a.valor > b.valor;
}

void cadastraContas(ContaCorrente contas[], int numContas) {
    for (int i = 0; i < numContas; i++) {
        cout << "Digite o nome do titular da conta " << i + 1 << ": ";
        getline(cin, contas[i].nome);

        cout << "Digite o CPF do titular da conta " << i + 1 << ": ";
        getline(cin, contas[i].cpf);

        cout << "Digite o valor na conta do titular " << contas[i].nome << ": ";
        cin >> contas[i].valor;
        cin.ignore();  // descarta o caractere '\n' do buffer de entrada
    }
}

void exibeContasOrdenadas(ContaCorrente contas[], int numContas) {
    sort(contas, contas + numContas, comparaContas);

    cout << "\nContas ordenadas por valor em ordem decrescente:\n\n";
    for (int i = 0; i < numContas; i++) {
        cout << "Titular: " << contas[i].nome << endl;
        cout << "CPF: " << contas[i].cpf << endl;
        cout << "Valor na conta: " << contas[i].valor << endl << endl;
    }
}

int main() {
    const int NUM_CONTAS = 5;
    ContaCorrente contas[NUM_CONTAS];

    cadastraContas(contas, NUM_CONTAS);
    exibeContasOrdenadas(contas, NUM_CONTAS);

    return 0;
}
