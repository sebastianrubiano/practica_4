#include "red.h"

red::red()
{
    primero = NULL;
    tamaño = 0;
}

bool red::Esta_Vacio()
{
    return tamaño == 0;
}

int red::Obtener_tamaño()
{
    return tamaño;
}

enrutador* red::Obtenerenrutador(string _nombre)
{
    enrutador* i = primero;
    while (i != NULL)
	{
		if (i->nombre == _nombre)
			{
                return i;
            }
		i = i->sig;
	}

	return NULL;
}

void red::Inserta_enrutador(string nombre)
{
    if (Obtenerenrutador(nombre)== NULL)
    {
        enrutador* nuevo = new enrutador(nombre);
        if (Esta_Vacio())
        {
            primero = nuevo;
        }
        else
        {
            enrutador* i = primero;
            while ( i ->sig != NULL)
            {
                i = i ->sig;
            }
            i->sig = nuevo;
        }
        tamaño++;
    }

    else
    {
        cout << "Ese enrutador ya existe en el grafo" << endl;
    }
}

void red::Inserta_arista(string ori, string destino, int distancia)
{
    enrutador* Ruter_ori = Obtenerenrutador(ori);
    enrutador* Ruter_destino = Obtenerenrutador(destino);

    if (Ruter_ori == NULL or Ruter_destino == NULL)
    {
        cout << "El enrutador no existe" << endl;
    }
    if (Ruter_ori != NULL &&Ruter_destino != NULL)
    {
        arista* nueva = new arista(Ruter_destino, distancia);

        if (Ruter_ori->ari == NULL)
        {
            Ruter_ori->ari = nueva;
        }
        else
        {
            arista* j = Ruter_ori->ari;
            while (j->sig != NULL)
            {
                    j = j->sig;
            }
            j->sig = nueva;
        }
    }
}

void red::MostrarLista()
{
    enrutador* i = primero;
    while (i != NULL)
    {
        arista* j = i->ari;

        while (j != NULL)
        {
            cout << i ->nombre << "->" << j->distancia << "->" << j->destino->nombre << "," ;
            j = j->sig;
        }
        cout << endl;
        i = i->sig;
    }
}

void red::eliminar_aristas(enrutador *ruter)
{
    if (ruter == NULL)
    {
        return;
    }

    arista* i = ruter->ari;
    while ( ruter->ari != NULL)
    {
        i = ruter->ari;
        ruter->ari = ruter->ari->sig;
        cout << "enrutador" << ruter->nombre << "->" << i->destino->nombre << "eliminada" << endl;
        delete(i);
        break;
    }
}

void red::eliminar_aristadestino(string destino)
{
    enrutador* i = primero;
    while (i != NULL)
    {
        if (i->nombre == destino)
        {
            continue;
        }
        if (i->ari->destino->nombre == destino)
        {
            arista* j = i->ari;
            i->ari = i->ari->sig;
            cout << "arista" << destino << "->" << j->destino->nombre << "fue eliminada" << endl;
            delete(j);
        }
        else
        {
            arista* x = i->ari;
            arista* y = x->sig;
            while(y != NULL)
            {
                if (y->destino->nombre == destino)
                {
                    x->sig = y->sig;
                    cout << "arista" << i->nombre << "->" << destino << "fue eliminada" << endl;
                    delete(y);
                    break;
                }
                x = y;
                y = y->sig;
            }
        }
    }
}

void red::eliminar_vertice(string nombre)
{
    if (primero->nombre == nombre)
    {
        enrutador* i = primero;
        primero = primero->sig;
        eliminar_aristas(i);
        eliminar_aristadestino(i->nombre);
        cout << "enrutador" << nombre << "fue eliminado" << endl;
        delete(i);
        tamaño--;
    }
    else
    {
        enrutador* i = primero;
        enrutador* j = i->sig;
        bool existe = false;
        while (j != NULL)
        {
            if (j->nombre == nombre)
            {
                eliminar_aristas(j);
                eliminar_aristadestino(j->nombre);
                i->sig = j->sig;
                cout << "enrutador" << nombre << "fue eliminado" << endl;
                delete(j);
                tamaño--;
                existe = true;
                break;
            }
            i= j;
            j = j->sig;
        }
        if (!existe)
        {
            cout << "el enrutador no existe";
        }


    }
}

void red::eliminar_arista(string ori, string destino)
{
    enrutador* Ruter_ori = Obtenerenrutador(ori);
    enrutador* Ruter_destino = Obtenerenrutador(destino);

    if (Ruter_ori == NULL or Ruter_destino == NULL)
    {
        cout << "El enrutador no existe" << endl;
    }
    if (Ruter_ori != NULL &&Ruter_destino != NULL)
    {
        if (Ruter_ori->ari->destino == Ruter_destino)
        {
            arista* i = Ruter_ori->ari;
            Ruter_ori->ari = Ruter_ori->ari->sig;
            cout << "arista" << ori << "->" << destino << "fue eliminada" << endl;
            delete(i);
        }
        else
        {
            arista* i = Ruter_ori->ari;
            arista* j = i->sig;
            while (j != NULL)
            {
                if (j->destino == Ruter_destino)
                {
                    i->sig = j->sig;
                    cout << "arista" << ori << "->" << destino << "fue eliminada" << endl;
                    delete(j);
                    break;
                }
                i = j;
                j = j ->sig;
            }
        }
    }
}

void red::eliminar_todo()
{
    enrutador* i = primero;
    while (primero != NULL)
    {
        i = primero;
        primero = primero->sig;
        eliminar_aristas(i);
        eliminar_aristadestino(i->nombre);
        cout << "Vertice " << i->nombre << " eliminado" << endl;
        delete(i);
        tamaño--;
    }
}

void red::cargarRedDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    string nombre, destino;
    int distancia;
    while (archivo >> nombre >> destino >> distancia)
    {
        Inserta_enrutador(nombre);
        Inserta_enrutador(destino);

        Inserta_arista(nombre,destino,distancia);
        Inserta_arista(destino,nombre,distancia);
    }
    archivo.close();
}

void red::guardarRedEnArchivo(const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    enrutador* i = primero;
    while (i != NULL)
    {
        arista* j = i->ari;

        while (j != NULL)
        {
            archivo << i ->nombre << " " << j->destino->nombre  << " " << j->distancia;
            j = j->sig;
        }
        i = i->sig;
    }


    archivo.close();
    cout << "Red guardada en el archivo " << nombreArchivo << endl;
}

bool CostoMinimo(const pair<enrutador*, int>& a, const pair<enrutador*, int>& b)
{
    return a.second < b.second;
}


void red::Dijkstra(string origen, string destino)
{
    enrutador* Ruter_ori = Obtenerenrutador(origen);
    enrutador* Ruter_des = Obtenerenrutador(destino);
    if (Ruter_ori == NULL or Ruter_des == NULL)
    {
        cout << "El enrutador no existe" << endl;
    }
    else
    {
        map<enrutador*, map<enrutador*, int>> matriz;
        map<enrutador*, bool>visitados;
        map<enrutador*, enrutador*> rutas;
        map<enrutador*, int> cola;
        map<enrutador*, int> distancias;

        enrutador* vi = primero;
        while (vi != NULL)
        {
            visitados[vi] = false;
            rutas[vi] = NULL;
            distancias[vi] = numeric_limits<int>::max();
            enrutador* vj = primero;

            while (vj != NULL)
            {
                matriz[vi][vj] = numeric_limits<int>::max();
                vj = vj->sig;
            }

            arista* aj = vi->ari;

            while (aj != NULL)
            {
                matriz[vi][aj->destino] = aj->distancia;
                aj = aj->sig;
            }

            vi = vi->sig;
        }

        distancias[Ruter_ori] = 0;
        visitados[Ruter_ori] = true;
        cola[Ruter_ori] = distancias[Ruter_ori];

        while (!cola.empty())
        {
            map<enrutador*, int>::iterator iter = min_element(cola.begin(), cola.end(), CostoMinimo);
            visitados[iter->first] = true;
            arista* ai = iter->first->ari;
            while (ai != NULL)
            {
                if (!visitados[ai->destino])
                {
                    if (distancias[ai->destino] > distancias[iter->first] + matriz[iter->first][ai->destino])
                    {
                        distancias[ai->destino] = distancias[iter->first] + matriz[iter->first][ai->destino];
                        rutas[ai->destino] = iter->first;
                        cola[ai->destino] = distancias[ai->destino];
                    }
                }

                ai = ai->sig;
            }

            cola.erase(iter->first);
        }
        cout << "Distancia mínima desde " << origen << " a " << destino << ": " << distancias[Ruter_des] << endl;
        cout << "Ruta desde " << origen << " a " << destino << ": ";
        enrutador* vActual = Ruter_des;
        while (vActual != NULL)
        {
            cout << vActual->nombre;
            if (vActual != Ruter_ori) 
            {
                cout << "<-";
            }
            vActual = rutas[vActual];
        }
        cout << endl;
    }
    
}

int GenerarCadenaAleatoria(int min, int max) {
    random_device rd;
    mt19937 generador(rd());
    uniform_int_distribution<int> distribucion(min, max);
    int numero = distribucion(generador);
    return numero;
}

void red::Erdos_renyi(int N_enrutadores, int Probabilidad)
{
    map<enrutador*, map<enrutador*, int>> matriz;

    map<string, map<string, int>> distancias;
    
    int j = 1;
        for (int i = 1; i <= N_enrutadores; ++i)
        {
            string nodeName = "";
            for (int k = 1; i <= j; ++i) 
            {
                string cadena = string(1, static_cast<char>(GenerarCadenaAleatoria(65, 90)));
                nodeName += cadena;
            }
            if (i == 25*j)
                {
                    j= j +1;
                }
            
            Inserta_enrutador(nodeName);
        }
        
        default_random_engine generator(time(0));
        uniform_real_distribution<double> distribution(0.0, 1.0);
        uniform_int_distribution<int> weight_distribution(1, 100);

        enrutador* i = primero;
        while (i != NULL)
        {
            arista* j = i->ari;

            while (j != NULL)
            {
                if (i ->nombre == j->destino->nombre ) {
                    continue;  // No se permiten bucles
                }
                double random_value = distribution(generator);
                if (random_value < Probabilidad) {
                    int distancia = weight_distribution(generator);
                    Inserta_arista(i ->nombre, j->destino->nombre, distancia);
                    Inserta_arista(j->destino->nombre, i ->nombre, distancia);
                }
            }
        }
}
