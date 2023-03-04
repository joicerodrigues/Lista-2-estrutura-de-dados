#include <iostream>
#include <string>
using namespace std;

// Definição das structs
struct Voo {
    int origem;
    int destino;
};

struct Aeroporto {
    int codigo;
    string nome;
    int num_voos_saida;
    int num_voos_chegada;
    int voos_saida[10];
    int voos_chegada[10];
};

int main() {
    // Criação do vetor de voos e leitura dos dados do usuário
    Voo voos[10];
    for (int i = 0; i < 10; i++) {
        cout << "Voo " << i + 1 << endl;
        cout << "Código do aeroporto de origem: ";
        cin >> voos[i].origem;
        cout << "Código do aeroporto de destino: ";
        cin >> voos[i].destino;
    }
    
    // Criação do vetor de aeroportos
    Aeroporto aeroportos[6] = {
        {0, "Aeroporto Internacional de São Paulo - Guarulhos", 0, 0, {}, {}},
        {1, "Aeroporto Internacional do Rio de Janeiro - Galeão", 0, 0, {}, {}},
        {2, "Aeroporto Internacional de Brasília - Presidente Juscelino Kubitschek", 0, 0, {}, {}},
        {3, "Aeroporto Internacional de Belo Horizonte - Confins", 0, 0, {}, {}},
        {4, "Aeroporto Internacional de Porto Alegre - Salgado Filho", 0, 0, {}, {}},
        {5, "Aeroporto Internacional de Recife - Guararapes", 0, 0, {}, {}}
    };
    
    // População do vetor de aeroportos com os dados dos voos
    for (int i = 0; i < 10; i++) {
        int origem = voos[i].origem;
        int destino = voos[i].destino;
        
        // Verificação se os códigos de aeroporto são válidos
        if (origem < 0 || origem > 5 || destino < 0 || destino > 5) {
            cout << "Código de aeroporto inválido.\n";
            continue;
        }
        
        // Verificação se o limite de voos de saída foi atingido
        if (aeroportos[origem].num_voos_saida == 10) {
            cout << "Limite de voos de saída do aeroporto " << aeroportos[origem].nome << " atingido.\n";
            continue;
        }
        
        // Verificação se o limite de voos de chegada foi atingido
        if (aeroportos[destino].num_voos_chegada == 10) {
            cout << "Limite de voos de chegada do aeroporto " << aeroportos[destino].nome << " atingido.\n";
            continue;
        }
        
        // Inclusão do voo no aeroporto de origem
        aeroportos[origem].voos_saida[aeroportos[origem].num_voos_saida] = i;
        aeroportos[origem].num_voos_saida++;
        
        // Inclusão do voo no aeroporto de destino
        aeroportos[destino].voos_chegada[aeroportos[destino].num_voos_chegada] = i;
        aeroportos[destino].num_voos_chegada++;
      }
    // Exibição dos dados dos aeroportos
    for (int i = 0; i < 6; i++) {
        cout << "Aeroporto " << aeroportos[i].nome << " (código " << aeroportos[i].codigo << "):\n";
        cout << "Voos de saída:\n";
        for (int j = 0; j < aeroportos[i].num_voos_saida; j++) {
            int voo_index = aeroportos[i].voos_saida[j];
            cout << "  " << aeroportos[voos[voo_index].origem].nome << " - " << aeroportos[voos[voo_index].destino].nome << endl;
        }
        cout << "Voos de chegada:\n";
        for (int j = 0; j < aeroportos[i].num_voos_chegada; j++) {
            int voo_index = aeroportos[i].voos_chegada[j];
            cout << "  " << aeroportos[voos[voo_index].origem].nome << " - " << aeroportos[voos[voo_index].destino].nome << endl;
        }
        cout << endl;
    }

    return 0;
}