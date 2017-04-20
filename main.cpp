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
bIterator<int> I(A);

bTreePrinter<int> printer;
int a;
bool run = false;
char in;
int sizeTree[2];



	while(!run)
	{
		std::cin >> in;
		
		switch(in)
		{
			case 'b':
			for(a = 0; a < 10; a++)
			{
				B.insert(rand()%100,rand()%100);
		
			}			
			std::cout << "Drzewo B" << std::endl;
			printer.print(B);
			break;

			case 'a':
			for(a = 0; a < 50; a++)
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
	
	//A+B;
	//C = A;
//printer.print(C);
	C = B;
	
//printer.print(C);
//std::cout << "test" << std::endl;

	//C = (A + B);
std::cout<<"operator kopiowania done" <<std::endl;
	//printer.print(C);
	C = A;
	std::cout << C.root << std::endl;
	//printer.print(C);
	
	if(A == B)
	std::cout << "Drzewa przystaja do siebie" << std::endl;
	else
	std::cout << "Drzewa nie przystają do siebie" << std::endl;

	if(A == C)
	std::cout << "Drzewa przystaja do siebie" << std::endl;
	else
	std::cout << "Drzewa nie przystają do siebie" << std::endl;

	I.begin();

	/*A.checkSize(sizeTree);
	std::cout << "No. of nodes: " << sizeTree[0] << "\t" << "No. of cells: " << sizeTree[1] <<std::endl;

	B.checkSize(sizeTree);
	std::cout << "No. of nodes: " << sizeTree[0] << "\t" << "No. of cells: " << sizeTree[1] <<std::endl;

	C.checkSize(sizeTree);
	std::cout << "No. of nodes: " << sizeTree[0] << "\t" << "No. of cells: " << sizeTree[1] <<std::endl;
*/
//bTree<int> *D = new bTree<int> (B);
//std::cout<<"operator kopiowania done" <<std::endl;
	/*printer.print(A+C);
	std::cout << C.minDeg <<std::endl;
std::cout << C.root->minDegree <<std::endl;
std::cout<< C.root->currDeg <<"\t" << A.root->currDeg <<std::endl;
 (A + B);
C=A;
std::cout<< C.root->currDeg <<"\t" << A.root->currDeg <<std::endl;
	if(C.root != NULL)
	printer.print(C);*/
/*printer.print(*D);
	A.traverse();
	std::cout << std::endl;
*/
	return 0;
}
