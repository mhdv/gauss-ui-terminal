#include <iostream>
#include <stdio.h>
#include <cstdlib>

#include "equations.h"

template <typename T>
Equations<T>::Equations(int g){
	a = new T*[g];
	for(int i=0; i<g+1; i++){
		a[i-1] = new T[i];
	}
	x = new T[g];
}

template <typename T>
Equations<T>::~Equations(){}

template <typename T>
void Equations<T>::enterData(int g){
	int n=g;
	std::cout << "Prosze wprowadzic macierz A (2 na 3, pierw wiersze, potem kolumny): \n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n+1; j++){
			if(j==n){
				std::cout << "Podaj wyraz wolny rownania: ";
			}else{
				std::cout << "Podaj [" << i+1 << "][" << j+1 << "] element macierzy: ";
			}
			while(!(std::cin >> a[i][j])) { std::cin.clear(); std::cin.ignore(); std::cout << "Bledne dane wejsciowe.\n";}
		}
	}
}

template <typename T>
void Equations<T>::solveEquation(int g){
	int n=g;
	for(int i=0; i<n; i++){
		for(int k=i+1; k<n; k++){
			if(a[i][i]<a[k][i]){
				for(int j=0; j<=n; j++){
					T** tmp = new T*[n];
					for(int i=0; i<n+1; i++){
						tmp[i-1] = new T[i];
					}
					tmp[k][j] = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = tmp[k][j];
				}
			}
		}
	}
	for(int i=0; i<n-1; i++){
		for(int k=i+1; k<n; k++){
			T t=a[k][i]/a[i][i];
			for(int j=0; j<=n; j++){
				a[k][j]=a[k][j]-t*a[i][j];
			}
		}
	}
	for(int i=n-1; i>=0; i--){
		x[i]=a[i][n];
		for(int j=i+1; j<n; j++){
			if(j!=i){
				x[i]=x[i]-a[i][j]*x[j];
			}
		}
		x[i]=x[i]/a[i][i];
	}
}

template <typename T>
void Equations<T>::showResult(int g){
	int n=g;
	system("clear");
	std::cout << "Wynik to:\n(";
	for(int i=0; i<n; i++){
		if(i!=n-1)
		std::cout << x[i] << "; ";
		else std::cout << x[i] << ")";
	}
	std::cout << "\n";
}


template class Equations<int>;
// template class Equations<long int>;
// template class Equations<short int>;
// template class Equations<unsigned int>;
template class Equations<float>;
// template class Equations<long float>;
// template class Equations<short float>;
template class Equations<double>;
// template class Equations<long double>;
// template class Equations<short double>;