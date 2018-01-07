#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "equations.h"

int main(){

	system("clear");
	int k;
	std::cout << "Podaj wymiary n macierzy [n][n+1](gdzie n+1 kolumna jest wektorem wyrazow wolnych): ";
	while(!(std::cin >> k) || k<0) {std::cin.clear(); std::cin.ignore(); std::cout << "Niepoprawny symbol";}
	Equations<float> rownanie(k);
	rownanie.enterData(k);
	rownanie.solveEquation(k);
	rownanie.showResult(k);




	return 0;
}