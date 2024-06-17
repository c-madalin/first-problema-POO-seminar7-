#include "Multime.h"
#include <vector>
#include <iostream>

Multime::Multime()
{
	n = 0;
	vec = nullptr;
}
Multime::Multime(const Multime& m)
{
	n = m.n;
	vec = new int[n];
	for (int i = 0; i < n; i++)
		vec[i] = m.vec[i];
}
Multime& Multime::operator-=(const int numar)
{

	if (find(numar))
	{	
		int* aux = new int[this->n - 1];
		int j = 0;
		for (int i = 0; i < this->n; i++)
		{
			if (this->vec[i] != numar)
				aux[++j] = this->vec[i];
		}
		delete[] this->vec;
		this->vec = aux;
		delete[]aux;
	}
	return *this;
}
Multime Multime::operator+(const int numar)
{
	Multime aux = *this;
	aux += numar;
	return aux;
}
Multime& Multime::operator+=(const int numar)
{	
	if (find(numar) != 0)
	{
		this->n++;
		int* aux = new int[n];
		for (int i = 0; i < n; i++)
			aux[i] = this->vec[i];
		delete[] this->vec;
		aux[n] = numar;
		this->vec = aux;
		delete[]aux;
	}
	return *this;
}
bool Multime::find(int numar)
{	
	for(int i=0;i<n;i++)
		if(this->vec[i]==numar)
			return false;
	return true;
}
Multime& Multime::operator+=(const Multime &m)
{	
	for (int i = 0; i < m.n; i++)
		*this += m.vec[i];
	return *this;
}
Multime::Multime(int n)
{
	
	this->n = n;
	vec = new int[n];
}




Multime::~Multime()
{
	n = 0;
	delete[] vec;
}