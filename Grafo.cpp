#include "Grafo.h"
using namespace std;

Grafo::Grafo()
{
	primero = NULL;
	tamano = 0;
}

bool Grafo::EstaVacio()
{
	return tamano == 0;
}

int Grafo::ObtenerTamano()
{
	return tamano;
}

Vertice* Grafo::ObtenerVertice(string nombre)
{
	Vertice* i = primero;

	while (i != NULL)
	{
		if (i->nombre == nombre)
			return i;

		i = i->sig;
	}

	return NULL;
}

void Grafo::InsertaVertice(string nombre)
{
	if (ObtenerVertice(nombre) == NULL)
	{
		Vertice* nuevo = new Vertice(nombre);

		if (EstaVacio())
			primero = nuevo;
		else
		{
			Vertice* i = primero;

			while (i->sig != NULL)
				i = i->sig;

			i->sig = nuevo;
		}

		tamano++;
	}
	else
		cout << "Ese Producto/Provedor ya existe" << endl;
}

void Grafo::InsertaArista(string ori, string dest, int precio)
{
	Vertice* vori = ObtenerVertice(ori);
	Vertice* vdest = ObtenerVertice(dest);

	if (vori == NULL)
		cout << "El Provedor no existe" << endl;

	if (vdest == NULL)
		cout << "El Producto no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		Arista* nueva = new Arista(vdest, precio);

		if (vori->ari == NULL)
			vori->ari = nueva;
		else
		{
			Arista* j = vori->ari;

			while (j->sig != NULL)
				j = j->sig;

			j->sig = nueva;
		}
	}
}

void Grafo::MostrarListaAdyacencia()
{
	Vertice* i = primero;
	
	while (i != NULL)
	{
		Arista* j = i->ari;
		if (j != NULL) {
			cout << i->nombre << " = ";

			while (j != NULL)
			{
				cout << j->dest->nombre << "->" << j->precio << ",";
				j = j->sig;
			}

			cout << endl;
			
		}
		i = i->sig;
			
	}
}

void Grafo::EliminarAristas(Vertice* vertice)
{
	if (vertice == NULL)
		return;

	Arista* i = vertice->ari;

	while (vertice->ari != NULL)
	{
		i = vertice->ari;
		vertice->ari = vertice->ari->sig;
		cout << "Pedido " << vertice->nombre << "->" << i->dest->nombre << " eliminado" << endl;
		delete(i);
	}
}

void Grafo::EliminarAristasDestino(string dest)
{
	Vertice* i = primero;

	while (i != NULL)
	{
		if (i->nombre == dest || i->ari == NULL)
		{
			i = i->sig;
			continue;
		}

		if (i->ari->dest->nombre == dest)
		{
			Arista* j = i->ari;
			i->ari = i->ari->sig;
			cout << "Producto: " << i->nombre << "->" << dest << " eliminado" << endl;
			delete(j);
		}
		else
		{
			Arista* x = i->ari;
			Arista* y = x->sig;

			while (y != NULL)
			{
				if (y->dest->nombre == dest)
				{
					x->sig = y->sig;
					cout << "Producto: " << i->nombre << "->" << dest << " eliminado" << endl;
					delete(y);
				}

				x = y;
				y = y->sig;
			}
		}

		i = i->sig;
	}
}

void Grafo::EliminarVertice(string nombre)
{
	if (primero->nombre == nombre)
	{
		Vertice* i = primero;
		primero = primero->sig;
		EliminarAristas(i);
		EliminarAristasDestino(i->nombre);
		cout << "El elemento " << nombre << " fue eliminado" << endl;
		delete(i);
		tamano--;
	}
	else
	{
		Vertice* i = primero;
		Vertice* j = i->sig;
		bool existe = false;

		while (j != NULL)
		{
			if (j->nombre == nombre)
			{
				i->sig = j->sig;
				EliminarAristas(j);
				EliminarAristasDestino(j->nombre);
				cout << "El elemento" << nombre << " fue eliminado" << endl;
				delete(j);
				tamano--;
				existe = true;
				break;
			}

			i = j;
			j = j->sig;
		}

		if (!existe)
			cout << "El elemento especificado no existe en este inventario" << endl;
	}
}

void Grafo::EliminarArista(string ori, string dest)
{
	Vertice* vori = ObtenerVertice(ori);
	Vertice* vdest = ObtenerVertice(dest);

	if (vori == NULL)
		cout << "El Provedor no existe" << endl;

	if (vdest == NULL)
		cout << "El Producto no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		if (vori->ari->dest == vdest)
		{
			Arista* i = vori->ari;
			vori->ari = vori->ari->sig;
			cout << "Pedido al provedor: " << ori << "del producto:" << dest << " fue eliminado" << endl;
			delete(i);
		}
		else
		{
			Arista* i = vori->ari;
			Arista* j = i->sig;

			while (j != NULL)
			{
				if (j->dest == vdest)
				{
					i->sig = j->sig;
					cout << "Pedido al provedor: " << ori << "del producto:" << dest << " fue eliminado" << endl;
					delete(j);
					break;
				}

				i = j;
				j = j->sig;
			}
		}
	}
}

void Grafo::EliminarTodo()
{
	Vertice* i = primero;

	while (primero != NULL)
	{
		i = primero;
		primero = primero->sig;
		EliminarAristas(i);
		EliminarAristasDestino(i->nombre);
		cout << "Pedidos al Provedor: " << i->nombre << " eliminados" << endl;
		delete(i);
		tamano--;
	}
}