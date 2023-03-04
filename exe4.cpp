#include <iostream>
#include <cmath>

using namespace std;

struct Ponto {
    float x;
    float y;
};

struct Triangulo {
    Ponto vertices[3];
};

enum TipoTriangulo {
    Equilatero,
    Isosceles,
    Escaleno
};

float distanciaEntrePontos(Ponto p1, Ponto p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

TipoTriangulo classificaTriangulo(Triangulo t) {
    float lados[3];
    lados[0] = distanciaEntrePontos(t.vertices[0], t.vertices[1]);
    lados[1] = distanciaEntrePontos(t.vertices[1], t.vertices[2]);
    lados[2] = distanciaEntrePontos(t.vertices[2], t.vertices[0]);

    if (lados[0] == lados[1] && lados[1] == lados[2]) {
        return Equilatero;
    } else if (lados[0] == lados[1] || lados[1] == lados[2] || lados[2] == lados[0]) {
        return Isosceles;
    } else {
        return Escaleno;
    }
}

int main() {
    Triangulo t1, t2;

    cout << "Digite as coordenadas dos pontos do primeiro triangulo:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Ponto " << i + 1 << " (x, y): ";
        cin >> t1.vertices[i].x >> t1.vertices[i].y;
    }

    cout << "\nDigite as coordenadas dos pontos do segundo triangulo:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Ponto " << i + 1 << " (x, y): ";
        cin >> t2.vertices[i].x >> t2.vertices[i].y;
    }

    TipoTriangulo tipoT1 = classificaTriangulo(t1);
    TipoTriangulo tipoT2 = classificaTriangulo(t2);

    cout << "\nO primeiro triangulo e " << (tipoT1 == Equilatero ? "equilatero" : (tipoT1 == Isosceles ? "isosceles" : "escaleno")) << endl;
    cout << "O segundo triangulo e " << (tipoT2 == Equilatero ? "equilatero" : (tipoT2 == Isosceles ? "isosceles" : "escaleno")) << endl;

    return 0;
}
