#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include "display.h"
#include "tree.hpp"





int main()
{

srand(time(NULL));

bTree<int> A(3),B(3);
bTree<int> C;
bTreePrinter<int> printer;
int a;
bool run = false;
char in;



	while(!run)
	{
		

		std::cin >> in;
		
		switch(in)
		{
			case 'b':
			for(a = 0; a < 9; a++)
			{
				B.insert(rand()%100,rand()%100);
		
			}			
			std::cout << "Drzewo B" << std::endl;
			printer.print(B);
			C = A;
printer.print(C);
			break;
			case 'a':
			for(a = 0; a < 9; a++)
			{
				A.insert(rand()%100,rand()%100);
		
			}
			std::cout << "Drzewo A" << std::endl;
			printer.print(A);
			break;

			case 'c':
			std::cin >> a;
			C.insert(a,a);
			printer.print(C);
			break;

			case 'p':
			run = true;
			break;			
		
		}
	//system("clear");	

	}
	/*for(a = 0; a < 40; a++)
	{
		A.insert(a,a);
		
	}*/
	//printer.print(A);
	//if(B.root !=NULL)
	//printer.print(B);
	//bTree<int> *C = new bTree<int>(A);
	//C->traverse();
	//std::cout <<"konstruktor pomyslny"<< std::endl;
	
	C = (A+B);
printer.print(C);
printer.print(A);
	C = A;
std::cout<<"operator kopiowania done" <<std::endl;
	printer.print(C);
	std::cout << C.minDeg <<std::endl;
std::cout << C.root->minDegree <<std::endl;
	if(B.root != NULL)
	printer.print(A+B);
	//A.traverse();
	std::cout << std::endl;

	return 0;
}
