#include <iostream>
#include <string>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Pessoa {
    string nome;
    Data dataNascimento;
};

Pessoa buscaPessoaMaisVelha(Pessoa pessoas[], int numPessoas) {
    Pessoa pessoaMaisVelha = pessoas[0];

    for (int i = 1; i < numPessoas; i++) {
        if (pessoas[i].dataNascimento.ano < pessoaMaisVelha.dataNascimento.ano) {
            pessoaMaisVelha = pessoas[i];
        } else if (pessoas[i].dataNascimento.ano == pessoaMaisVelha.dataNascimento.ano) {
            if (pessoas[i].dataNascimento.mes < pessoaMaisVelha.dataNascimento.mes) {
                pessoaMaisVelha = pessoas[i];
            } else if (pessoas[i].dataNascimento.mes == pessoaMaisVelha.dataNascimento.mes) {
                if (pessoas[i].dataNascimento.dia < pessoaMaisVelha.dataNascimento.dia) {
                    pessoaMaisVelha = pessoas[i];
                }
            }
        }
    }

    return pessoaMaisVelha;
}

int main() {
    const int NUM_PESSOAS = 5;
    Pessoa pessoas[NUM_PESSOAS];

    for (int i = 0; i < NUM_PESSOAS; i++) {
        cout << "Digite o nome da pessoa " << i + 1 << ": ";
        getline(cin, pessoas[i].nome);

        cout << "Digite a data de nascimento da pessoa " << pessoas[i].nome << " (DD/MM/AAAA): ";
        scanf("%d/%d/%d", &pessoas[i].dataNascimento.dia, &pessoas[i].dataNascimento.mes, &pessoas[i].dataNascimento.ano);
        cin.ignore();  // descarta o caractere '\n' 
    }

    Pessoa pessoaMaisVelha = buscaPessoaMaisVelha(pessoas, NUM_PESSOAS);

    cout << "\nA pessoa mais velha e:\n";
    cout << "Nome: " << pessoaMaisVelha.nome << endl;
    cout << "Data de nascimento: " << pessoaMaisVelha.dataNascimento.dia << "/" << pessoaMaisVelha.dataNascimento.mes << "/" << pessoaMaisVelha.dataNascimento.ano << endl;

    return 0;
}
