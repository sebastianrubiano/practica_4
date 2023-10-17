#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class arista;
class enrutador
{
public:
    enrutador(string nombre );
    ~enrutador();

private:
    string nombre;
    enrutador* sig;
    arista* ari;
    friend class red;
};

#endif
