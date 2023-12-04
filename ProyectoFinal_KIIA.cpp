#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <locale> 
#include <stack>
#include "Grafo.h"


using namespace std;
//Estructura del nodo de la Cola
struct nodo {
	char dato;
	int prioridad;
	string name;
	int precio;
	int cant;
	int lote;
	struct nodo* sgte;
};


//Estructura de la cola
struct cola {
	nodo* delante;
	nodo* atras;
};
stack < nodo*> pila;
void insertarNodo(const string& nombre, int precio, int cantidad, int numeroLote) {
	nodo* nuevo = new nodo;
	nuevo->name = nombre;
	nuevo->precio = precio;
	nuevo->cant = cantidad;
	nuevo->lote = numeroLote;
	nuevo->sgte = nullptr;

	if (pila.empty()) {
		pila.push(nuevo);
	}
	else {
		nuevo->sgte = pila.top();
		pila.push(nuevo);
	}
}
void mostrarPila() {
	std::cout << "Contenido de la pila:" << std::endl;
	while (!pila.empty()) {
		nodo* actual = pila.top();
		std::cout << "Nombre: " << actual->name << ", Precio: " << actual->precio
			<< ", Cantidad: " << actual->cant << ", Lote: " << actual->lote << std::endl;
		pila.pop();
	}
}

//crear un nuevo nodo
struct nodo* crearNodo(char x, int pr) {
	struct nodo* nuevoNodo = new(struct nodo);
	nuevoNodo->dato = x;
	nuevoNodo->prioridad = pr;
	return nuevoNodo;
};

//Encolar(insertar) un elemtno 

void encolar(struct cola& q, char valor, int prioridad) {
	struct nodo* aux = crearNodo(valor, prioridad);
	aux->sgte = NULL;

	if (q.delante == NULL) {
		q.delante = aux;//encolar el primer elemento
	}
	else {
		(q.atras)->sgte = aux;//en caso de que exista un elemento, apunta al último elemento
	}
	q.atras = aux;
}

//Mostrar Cola

void mostrarColar(struct cola q) {
	struct nodo* aux;
	aux = q.delante;
	cout << "Caracter|Priodidad" << endl;
	cout << "------------------" << endl;
	while (aux != NULL) {
		cout << " " << aux->dato << "  |  " << aux->prioridad << endl;
		aux = aux->sgte;
	}

}

//Ordenar por prioridad (criterio de ordenamiento ->burbuja)

void ordenarPrioridad(struct cola& q) {
	struct nodo* aux1, * aux2;
	int p_aux;
	char c_aux;

	aux1 = q.delante;

	while (aux1->sgte != NULL) {
		aux2 = aux1->sgte;
		while (aux2 != NULL) {
			if (aux1->prioridad > aux2->prioridad) {
				p_aux = aux1->prioridad;
				c_aux = aux1->dato;

				aux1->prioridad = aux2->prioridad;
				aux1->dato = aux2->dato;

				aux2->prioridad = p_aux;
				aux2->dato = c_aux;
			}
			aux2 = aux2->sgte;
		}
		aux1 = aux1->sgte;
	}
}
//encolar (insertar) un elemento al nodo
void insertar(struct cola& q, char c, int pr) {
	//encolar caracteres
	encolar(q, c, pr);
	//Ordenar por prioridad
	ordenarPrioridad(q);
}
char desencolar(struct cola& q) {

	char valor = q.delante->dato;
	struct nodo* temp = q.delante;
	q.delante = q.delante->sgte;
	delete temp;
	return valor;

}
void vaciarCola(struct cola& q) {
	while (q.delante != NULL) {
		struct nodo* temp = q.delante;
		q.delante = q.delante->sgte;
		delete temp;
	}
	q.atras = NULL;

}


int main()
{
	
	Grafo* grafo = new Grafo();
	char c;
	int opc1 = 0, opc2 = 0, opc3 = 0, one = 0, i = 0, pr = 0;
    int num,op=0,cant,lote,precio,ok;
	char band = 'F';
	string name;
	bool bandera = false;
	struct cola q;
	q.delante = NULL;
	q.atras = NULL;



	grafo->InsertaVertice("Lala");
	grafo->InsertaVertice("Yogurt");
	grafo->InsertaVertice("Queso");
	grafo->InsertaVertice("Leche");
	grafo->InsertaVertice("Crema");
	grafo->InsertaVertice("Alpura");
	grafo->InsertaVertice("Sabritas");
	grafo->InsertaVertice("Barcel");
	grafo->InsertaVertice("Takis");
	grafo->InsertaVertice("Papas");
	grafo->InsertaVertice("Doritos");
	grafo->InsertaVertice("Rufles");

	grafo->InsertaArista("Lala", "Yogurt", 24);
	grafo->InsertaArista("Lala", "Queso", 15);
	grafo->InsertaArista("Lala", "Leche", 18);
	grafo->InsertaArista("Lala", "Crema", 12);
	grafo->InsertaArista("Alpura", "Leche", 16);
	grafo->InsertaArista("Alpura", "Crema", 7);
	grafo->InsertaArista("Sabritas", "Papas", 16);
	grafo->InsertaArista("Sabritas", "Rufles", 16);
	grafo->InsertaArista("Sabritas", "Doritos", 16);
	grafo->InsertaArista("Barcel", "Takis", 8);
	grafo->InsertaArista("Barcel", "Papas", 8);

	insertar(q, 'A', 5);
	insertar(q, 'B', 7);
	insertar(q, 'C', 3);
	insertar(q, 'D', 12);
	insertar(q, 'E', 8);
	insertar(q, 'F', 5);
	insertar(q, 'G', 9);
	insertar(q, 'H', 21);


	insertarNodo("Papas", 13, 23, 109);
	insertarNodo("Agua", 15, 50, 167);
	insertarNodo("Cocas", 35, 33, 234);
	insertarNodo("Pepsi", 23, 15, 567);
	insertarNodo("Bubalo", 2, 67, 923);
	insertarNodo("Shamphoo", 30, 23, 124);
	insertarNodo("Totopos", 12, 78, 902);



    do {
        system("cls");
        cout << "Bienvenido al menu de LA MARQUESADA" << endl;
		cout << "------------------------------------------" << endl;
        cout << "Seleccione el apartado que desea Analizar" << endl;
        cout << "1. Inventario" << endl;
        cout << "2. Reportes" << endl;
        cout << "3. Caducidades" << endl;
        cout << "4. Salir" << endl;
		cout << "------------------------------------------" << endl;
        cout << endl;
        cout << "Ingrese una opcion del menu: ";
        cin >> one;

        system("cls");

        switch (one) {
        case 1:
		{
            do {
                system("cls");
                cout << "Bienvenido al inventario de LA MARQUESADA" << endl;
				cout << "-----------------------------------------" << endl;
                cout << "Seleccione la accion que desea Realizar" << endl;
                cout << "1. Agregar Nuevo Proveedor/Producto" << endl;
                cout << "2. Agregar Nuevo Pedido" << endl;
                cout << "3. Lista de Pedidos con Proveedores" << endl;
                cout << "4. Eliminar Proveedor/Producto" << endl;
                cout << "5. Eliminar Pedido de un proveedor" << endl;
                cout << "6. Vaciar Inventario" << endl;
                cout << "7. Salir al menu principal" << endl;
				cout << "-----------------------------------------" << endl;
                cout << endl;
                cout << "Ingrese una opcion del menu: ";
                cin >> opc1;

                system("cls");

                switch (opc1) {
                case 1:
                {
                    string nombre;
                    cout << "Ingrese el nombre del Producto o Proveedor: ";
                    cin >> nombre;

                    grafo->InsertaVertice(nombre);
                    // Agrega aquí la lógica para insertar en el inventario
                    break;
                }
                case 2:
                {
					if (grafo->EstaVacio())
						cout << "No hay Elementos" << endl;
					else
					{
						string ori, dest;
						int precio;
						cout << "Ingrese el nombre del Provedor: ";
						cin >> ori;
						cout << "Ingrese el nombre del Producto: ";
						cin >> dest;
						cout << "Ingrese la cantidad de Productos: ";
						cin >> precio;

						grafo->InsertaArista(ori, dest, precio);
					}
                    // Agrega aquí la lógica para agregar un nuevo pedido
                    break;
                }

                case 3:
                {
					if (grafo->EstaVacio())
						cout << "No hay elementos....." << endl;
					else
						grafo->MostrarListaAdyacencia();
                    // Agrega aquí la lógica para mostrar la lista de pedidos con proveedores
                    break;
                }
                case 4:
                {
					if (grafo->EstaVacio())
						cout << "No hay elementos....." << endl;
					else
					{
						string nombre;
						cout << "----------------------------------------------------------" << endl;
						cout << "Ingrese el nombre del producto/provedor que desea eliminar: ";
						cin >> nombre;

						grafo->EliminarVertice(nombre);
					}
                    // Agrega aquí la lógica para eliminar un proveedor o producto
                    break;
                }
                case 5:
                {
					if (grafo->EstaVacio())
						cout << "No hay elementos....." << endl;
					else
					{
						string ori, dest;
						cout << "Ingrese el nombre del Provedor: ";
						cin >> ori;
						cout << "Ingrese el nombre del Producto: ";
						cin >> dest;

						grafo->EliminarArista(ori, dest);
					}
                    // Agrega aquí la lógica para eliminar un pedido de un proveedor
                    break;
                }
                case 6:
                {
					if (grafo->EstaVacio())
						cout << "No hay elementos...." << endl;
					else
					{
						grafo->EliminarTodo();
					}
                    
                    break;
                }
                case 7:
                {
                    // Salir del submenú
                    break;
                }
                default:
                    cout << "\n\tOpcion no valida...!!!" << endl;


                }

                system("pause");
                system("cls");
            } while (opc1 != 7);
            break;
		}

        case 2:
        {
			do {
				system("cls");
				cout << "Reporte de productos LA MARQUESADA" << endl;
				cout << "----------------------------------" << endl;
				cout << "Seleccione que desea Analizar" << endl;
				cout << "1. Agregar Registros" << endl;
				cout << "2. Inventarios Registrados" << endl;
				cout << "3. Salir al menu principal" << endl;
				cout << "----------------------------------" << endl;
				cout << endl;
				cout << "Ingrese una opcion del menu: ";
				cin >> opc2;

				system("cls");

				switch (opc2) {
				case 1:
				{

					cout << "Nombre producto:" << endl;
					cin >> name;
					cout << "Lote" << endl;
					cin >> lote; 
					cout << "Precio:" << endl;
					cin >> precio;
					cout << "Cantidad Productos:" << endl;
					cin >> cant; 
					insertarNodo(name, precio, cant, lote);
					break;
				}
				case 2:
				{
					do {
						system("cls");
						cout << "Reporte de productos LA MARQUESADA" << endl;
						cout << "-----------------------------------" << endl;
						cout << "Seleccione:" << endl;
						cout << "1. Ver inventarios mas recientes" << endl;
						cout << "2. salir" << endl;
						cout << "-----------------------------------" << endl;

						cout << endl;
						cout << "Ingrese una opcion del menu: ";
						cin >> ok;

						system("cls");

						switch (ok) {
						case 1:
						{
							mostrarPila();
							break;
						}
					
						case 2:
						{
							// Salir del submenú
							break;
						}
						default:
							cout << "\n\tOpcion no valida...!!!" << endl;
                        }
						system("pause");
						system("cls");
					} while (ok != 2);
					break;
				}
				case 3:
				{
					// Salir del submenú
					break;
				}
				default:
					cout << "\n\tOpcion no valida...!!!" << endl;


				}

				system("pause");
				system("cls");
			} while (opc2 != 3);
            break;
        } case 3:
        {
			//char desencolado;
			do {
				system("cls");
				cout << "\n\t Caducidad de los productos (Recomendacion de venta)\n\n";
				cout << "-------------------------------------------------------------------" << endl;
				cout << "1. Agregar a un producto" << endl;
				cout << "2. Mostrar productos en venta" << endl;
				cout << "3. Quitar un producto" << endl;
				cout << "4. Quitar todos los productos" << endl;
				cout << "5. Buscar por caducidad" << endl;
				cout << "6. Salir a menu principal" << endl;
				cout << "-------------------------------------------------------------------" << endl;
				cout << endl;
				cout << "Ingrese una opcion: ";
				cin >> opc3;

				system("cls");

				switch (opc3) {
				case 1:
				{
					cout << "A = Frutas" << endl;
					cout << "B = Sabritas" << endl;
					cout << "C = Refrescos" << endl;
					cout << "D = Leche" << endl;
					cout << "E = Verduras" << endl;
					cout << "F = Yogurt" << endl;
					cout << "G = Galletas" << endl;
					cout << "H = Queso" << endl;
					cout << "\nIngrese un caracter: ";
					cin >> c;
					cout << "Ingrese las semanas que tiene antes de su caducidad: ";
					cin >> pr;
					insertar(q, c, pr);
					cout << "\n\n\tCaracter: " << c << " Guardado...\n\n";
					
					break;
				}
				case 2:
				{
					cout << "\n\nMOSTRANDO LISTA DE CADUCIDADES\n\n";
					if (q.delante != NULL) {
						mostrarColar(q);
					}
					else {
						cout << "\n\nLista vacia.!!!!" << endl;
					}
					
					break;
				}

				case 3:
				{
					if (q.delante != NULL) {
						desencolar(q);
						cout << "\n\nElemento Eliminado ...!!!";
					}
					else {
						cout << "\n\nLista Vacia...!!!!" << endl;
					}

					break;
				}
				case 4:
				{
					vaciarCola(q);
					cout << "\n\nLista eliminada.....!!!!";
					break;
				}
				case 5:
				{
					cout << "Proporcione la fecha de caducidad a buscar";//Busqueda intercambio directo
					cin >> num;
					while ((band == 'F') && (i < 30)) {
						if (pr == num) {
							band = 'V';
						}
						i++;
					}
					if (band == 'F') {
						cout << "No se encontro la fecha indicada";
					}
					else {
						cout << "Se encontro en el lugar:  " << i - 1;
					}
					
					break;
				}
				case 6:
				{
					// Salir del submenú
					break;
				}
				default:
					cout << "\n\tOpcion no valida...!!!" << endl;


				}

				system("pause");
				system("cls");
			} while (opc3 != 6);
            break;
        }case 4:
        {
            cout << "Saliendo del programa. ¡Hasta luego!" << endl;
            break;
        }default:
            cout << "\n\tOpcion no valida...!!!" << endl;
        }

        cin.ignore();
        cin.get();
    } while (one != 4);

    return 0;

}