#pragma once
class Multime
{
	int n;
	int* vec;

public:

	Multime();
	Multime(int n);
	Multime(const Multime& m);
	Multime &operator+=(int numar);
	Multime &operator+=(const Multime & m);
	Multime &operator-=(int numar);
	Multime operator+(int numar);
	Multime operator+(const Multime& m);
	bool find(int numar);
	~Multime();

};

