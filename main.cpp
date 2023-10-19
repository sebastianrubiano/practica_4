#include <iostream>
#include "red.h"
using namespace std;

int main()
{
    red* Red = new red();
    int opc = 0;
    string archivo = "red.txt";
    while (opc != 10)
	{   

		
        cout << "*** menu de la practica ***" << endl;
        cout << "1. Insertar vertice" << endl;
		cout << "2. Insertar arista" << endl;
		cout << "3. Eliminar vertice" << endl;
        cout << "4. Eliminar arista" << endl;
		cout << "5. Eliminar todo" << endl;
		cout << "6. Mostrar lista de adyacencia" << endl;
		cout << "7. Camino mas corto entre dos enrutadores" << endl;
		cout << "8. Generar red aliatoria" << endl;
		cout << "9. Salir" << endl;

		cout << endl;
		cout << "Ingrese una opcion del menu: ";
		cin >> opc;

		
        
        Red->cargarRedDesdeArchivo(archivo);

		switch (opc)
		{
            case 1:
            {
                string nombre;
			    cout << "Ingrese el nombre del enrutador: ";
			    cin >> nombre;
                Red->Inserta_enrutador(nombre);
                break;
            }
            case 2:
            {
                if (Red->Esta_Vacio())
                {
                    cout<<"No hay Emrutadores para insertar aristas."<<endl;
                }
                else
			    {
                    string ori, dest;
                    int precio;
                    cout << "Ingrese el nombre del vertice origen: ";
                    cin >> ori;
                    cout << "Ingrese el nombre del vertice destino: ";
                    cin >> dest;
                    cout << "Ingrese el precio: ";
                    cin >> precio;
                    Red->Inserta_arista(ori, dest, precio);
                }
                break;
            }
            case 3:
            {
                if (Red->Esta_Vacio())
                {
                    cout<<"No hay Emrutadores."<<endl;
                }
                else
                {
                    string ori;
                    cout << "Ingrese el nombre del vertice origen: ";
                    cin >> ori;
                    Red->eliminar_vertice(ori);
                }
                break;
            }
            case 4:
            {
                if (Red->Esta_Vacio())
                {
                    cout<<"No hay Emrutadores para eliminar aristas."<<endl;
                }
                else
                {
                    string ori, dest;
                    cout << "Ingrese el nombre del vertice origen: ";
                    cin >> ori;
                    cout << "Ingrese el nombre del vertice destino: ";
                    cin >> dest;
                    Red->eliminar_arista(ori, dest);
                }
                break;
            }
            case 5:
            {
                if (Red->Esta_Vacio())
                {
                    cout<<"No hay Emrutadores para eliminar todo."<<endl;
                }
                else
                {
                    Red->eliminar_todo();
                }
                break;
            }
            case 6:
            {
                if (Red->Esta_Vacio())
                {
                    cout<<"No hay Emrutadores para mostrar lista de adyacencia."<<endl;
                }
                else
                {
                    Red->MostrarLista();
                }
                break;
            }
            case 7:
            {
                if (Red->Esta_Vacio())
                {
                    cout<<"No hay Emrutadores para generar camino mas corto."<<endl;
                }
                else
                {
                    string origen, destino;
                    cout << "Ingrese el nombre del vertice origen: ";
                    cin >> origen;
                    cout << "Ingrese el nombre del vertice destino: ";
                    cin >> destino;
                    Red->Dijkstra(origen, destino);
                }
                break;
            }
            case 8:
            {
                int N_ruters, probabilidad;
                cout << "Ingrese el numero de ruters: ";
                cin >> N_ruters;
                cout << "Ingrese la probabilidad: ";
                cin >> probabilidad;
                Red->Erdos_renyi(N_ruters, probabilidad);
                break;
            }
            case 9:
            {
                Red->MostrarMatris();
            }
        }
        Red->guardarRedEnArchivo(archivo);
    } 
    return 0;
}