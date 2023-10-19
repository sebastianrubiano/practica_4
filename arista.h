#ifndef ARISTA_H
#define ARISTA_H

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class enrutador;

class arista
{
private:
    
    long long distancia;
    arista* sig;
    enrutador* destino;
    friend class red;

public:
    arista(enrutador* _destino, int distancia);
    ~arista();
};

#endif