#include <iostream>
#include <cmath>

using namespace std;

// Estrutura para armazenar um ponto no plano cartesiano
struct Ponto {
    double x;
    double y;
};

// Função para calcular a distância entre dois pontos
double calcularDistancia(Ponto p1, Ponto p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Criando dois pontos
    Ponto p1, p2;

    cout << "Digite o valor do eixo x: ";
    cin >> p1.x;
    cout << "Digite o valor do eixo y: ";
    cin >> p1.y;

    cout << "Agora digite o segundo valor para o eixo x: ";
    cin >> p2.x;
    cout << "Agora digite o segundo valor para o eixo y: ";
    cin >> p2.y;
    // Calculando a distância entre os pontos
    double distancia = calcularDistancia(p1, p2);

    // Exibindo o resultado
    cout << "A distancia entre os pontos (" << p1.x << ", " << p1.y << ") e (" << p2.x << ", " << p2.y << ") eh " << distancia << endl;

    return 0;
}
