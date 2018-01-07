#include <iostream>
#include <cstdlib>
#include <stdio.h>

template <typename T>
class Equations{
private:
	T** a;
	T* x;
public:
	Equations(int g);
	~Equations();
	void enterData(int g);
	void solveEquation(int g);
	void showResult(int g);
};