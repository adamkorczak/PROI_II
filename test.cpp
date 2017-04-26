#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include "display.h"
#include "tree.hpp"
#include "header.hpp"

#define NO_ELEMENTS 20

template <class type>
void test(type wsk[])
{
int i;
int n;

bTree<type> A(3);
bTreePrinter<type> printer;
bIterator<type> I(A);


//Dodanie losowych wartosci do drzewa//
	std::cout << "Dodanie losowych elementów do drzewa A" << std::endl;
	for(i = 0; i < NO_ELEMENTS; i++)
	A.insert(wsk[i], wsk[i]);
	std::cout << "Wygenerowane drzewo A" << std::endl;
	printer.print(A);
	std::cout << std::endl;

//Pobranie losowego wezla//
	I.begin();
	n = rand()%I.noNode();
	std::cout << "Pobieram wezel nr: " << n << std::endl;	
	for(i = 0; i < I.currDe(); i++)
	std::cout << "Komorka :" << *I(n,i)<< "\t";
	std::cout << std::endl << std::endl;

//Dodawanie drzew do siebie//
//Generowanie drzewa//
bTree<type> B(3);

	std::cout << "Dodanie losowych elementów do drzewa B" << std::endl;
	for(i = 10; i < NO_ELEMENTS; i++)
	B.insert(wsk[i], wsk[i]);
	std::cout << "Wygenerowane drzewo B" << std::endl;
	printer.print(B);
	std::cout << std::endl;
	std::cout << " Suma drzew A+B " << std::endl;
	printer.print(A+B);
//Kopiowanie drzewa konstruktorem//

	std::cout << "Kopiowanie drzewa B konstruktorem" << std::endl;
	bTree<type> C(B);
	std::cout << "Skopiowane drzewo C" << std::endl;
	printer.print(C);
	std::cout << std::endl;

//Kopiowanie drzewa operatorem przypisania//
	std::cout << "Kopiowanie drzewa B operatore" << std::endl;
	bTree<type> D;
	D = B;
	std::cout << "Skopiowane drzewo D" << std::endl;
	printer.print(D);
	std::cout << std::endl;

//Sprawdzenie wielkosc drzew//

	int t1,t2;
	A.getSize(t1,t2);
	std::cout << "Drzewo A posiada " << t1 << "wezlow oraz " << t2 << "komorek"<<std::endl;
	B.getSize(t1,t2);
	std::cout << "Drzewo B posiada " << t1 << "wezlow oraz " << t2 << "komorek"<<std::endl;
	C.getSize(t1,t2);
	std::cout << "Drzewo C posiada " << t1 << "wezlow oraz " << t2 << "komorek"<<std::endl;
	D.getSize(t1,t2);
	std::cout << "Drzewo D posiada " << t1 << "wezlow oraz " << t2 << "komorek"<<std::endl;
	std::cout <<std::endl;
//Porownanie drzewa B  z drzewami A i C//

	if(B == A)
	std::cout << "Rownosc (B == A) spelniona" <<std::endl;
	else
	std::cout << "Rownosc (B == A) niespelniona" <<std::endl;
	
	if(B != A)
	std::cout << "Nierownosc (B != A) spelniona" <<std::endl;
	else
	std::cout << "Nierownosc (B != A) niespelniona" <<std::endl;
	if(B == C)
	std::cout << "Rownosc (B == C) spelniona" <<std::endl;
	else
	std::cout << "Rownosc (B == C) niespelniona" <<std::endl;
	if(B != C)
	std::cout << "Nierownosc (B != C) spelniona" <<std::endl;
	else
	std::cout << "Nierownosc (B != C) niespelniona" <<std::endl;
	std::cout <<std::endl;

//Iteracja po drzewie  B za pomoca iteratora//

	bIterator<type>	In(B);
	In.begin();
			for(i = 0; i < In.noNode(); i++)
			{
				std::cout << "Wezel nr: "  << i <<"\t";
				for(n = 0; n < In.currDe(); n++)
				std::cout <<"Kom: " << *(In(i,n)) <<"\t";
				In++;
				std::cout << std::endl << std::endl;
			}

}


void generateRandomInt(int *wsk, int size)
{
int j;
	for(j =0; j<size; j++)
	{
		*(wsk+j) = rand()%50;
	}
}


void generateRandomIntSet(intSet *wsk, int size)
{
int i,j;
	for(j=0;j<size;j++)
	{
	
		for(i =0; i < rand()%3 +1; i++)
		(wsk+j)->addNodeAtTheEnd(rand()%50);

	}
}


void generateRandomString(std::string *str, int size)
{
int i,j;
	
	for(j=0; j <size; j++)
	{
	  std::string s = "";
	  const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  for(i =0; i < (rand()%5 +1); i++)
	  {
		s = s + *(charmap + rand()%26);
	  }
	*(str+j) = s;
	}	
  
}


int main()
{
srand(time(NULL));

int i;
int *intTab = new int[NO_ELEMENTS];
std::string *stringTab = new std::string[NO_ELEMENTS];
intSet *intSetTab = new intSet[NO_ELEMENTS];

//Fill arrays
	generateRandomString(stringTab, NO_ELEMENTS);
	generateRandomIntSet(intSetTab, NO_ELEMENTS);
	generateRandomInt(intTab, NO_ELEMENTS);
	
	test(intTab);
	test(stringTab);
	test(intSetTab);

	
};
