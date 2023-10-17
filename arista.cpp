#include "arista.h"

arista::arista(enrutador* _destino, int _distancia)
{
    destino = _destino;
    distancia = _distancia;
    sig = NULL;

}

arista::~arista()
{

}