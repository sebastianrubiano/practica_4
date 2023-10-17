#include <iostream>
#include "red.h"
using namespace std;

int main()
{
    red* RED = new red();
    RED->cargarRedDesdeArchivo("red,txt");
    RED->MostrarLista();

    return 0;
}