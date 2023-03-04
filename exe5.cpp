#include <iostream>
#include <string>

using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
    int quantidade;
};

int main() {
    const int TAMANHO_ESTOQUE = 5;
    Produto estoque[TAMANHO_ESTOQUE];
    int codigoPedido, quantidadePedido;
    bool estoqueVazio = false;
    
    // Preenchimento do estoque
    for (int i = 0; i < TAMANHO_ESTOQUE; i++) {
        cout << "Produto " << i+1 << endl;
        cout << "Código: ";
        cin >> estoque[i].codigo;
        cout << "Nome: ";
        cin >> estoque[i].nome;
        cout << "Preço: R$";
        cin >> estoque[i].preco;
        cout << "Quantidade: ";
        cin >> estoque[i].quantidade;
        cout << endl;
    }
    
    // Realização dos pedidos
    while (!estoqueVazio) {
        cout << "Digite o código do produto que deseja comprar (ou -1 para sair): ";
        cin >> codigoPedido;
        if (codigoPedido == -1) {
            break;
        }
        cout << "Digite a quantidade desejada: ";
        cin >> quantidadePedido;
        bool encontrado = false;
        for (int i = 0; i < TAMANHO_ESTOQUE; i++) {
            if (estoque[i].codigo == codigoPedido) {
                encontrado = true;
                if (estoque[i].quantidade >= quantidadePedido) {
                    estoque[i].quantidade -= quantidadePedido;
                    cout << "Item vendido: " << estoque[i].nome << endl;
                    cout << "Quantidade vendida: " << quantidadePedido << endl;
                    cout << "Quantidade restante no estoque: " << estoque[i].quantidade << endl;
                } else {
                    cout << "Não há quantidade suficiente no estoque. Quantidade disponível: " << estoque[i].quantidade << endl;
                }
                break;
            }
        }
        if (!encontrado) {
            cout << "Código de produto inválido." << endl;
        }
        // Verificação se o estoque está vazio
        estoqueVazio = true;
        for (int i = 0; i < TAMANHO_ESTOQUE; i++) {
            if (estoque[i].quantidade > 0) {
                estoqueVazio = false;
                break;
            }
        }
        if (estoqueVazio) {
            cout << "Estoque esgotado." << endl;
        }
    }
    
    return 0;
}
