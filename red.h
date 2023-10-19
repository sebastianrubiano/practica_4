#ifndef RED_H
#define RED_H
#pragma once
#include "enrutador.h"
#include "arista.h"
#include <map>
#include <limits>
#include <algorithm>
#include <random>
#include <ctime>
#include <set>


class red
{
private:
    enrutador* primero;
    int tamaño;
public:
    red();
    bool Esta_Vacio();
    int Obtener_tamaño();
    enrutador *Obtenerenrutador(string _nombre);
    void Inserta_enrutador(string nombre);
    void Inserta_arista(string ori, string destino, int distancia);
    void MostrarLista();
    void MostrarMatris();
    void eliminar_vertice(string nombre);
    void eliminar_aristas(enrutador* ruter);
    void eliminar_arista(string ori, string destino);
    void eliminar_aristadestino(string destino);
    void eliminar_todo();
    void cargarRedDesdeArchivo(const string& nombreArchivo);
    void guardarRedEnArchivo(const string &nombreArchivo);
    void Dijkstra(string origen, string destino);
    void Erdos_renyi(int N_enrutadores, int Probabilidad);
};

#endif // RED_H