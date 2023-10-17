#include <iostream>
#include "red.h"
using namespace std;

int main()
{
    red* RED = new red();
    RED->cargarRedDesdeArchivo("red.txt");
    cout << "ingresa el origen y el destino";
    string origen, destino;
    cin >> origen;
    cin >> destino;
    RED->Dijkstra(origen, destino);
}