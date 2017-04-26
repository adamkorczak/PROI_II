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



int main()
{

srand(time(NULL));

bTree<intSet> A(3),B(3);
bTree<intSet> C;
bIterator<intSet> I(A);
intSet X;

bTreePrinter<intSet> printer;
int a,b;
bool run = false;
char in;
int sizeTree[2];
std::string s = "a";
int value = 2;
int val_ref;

	while(!run)
	{
		std::cin >> in;
		
		switch(in)
		{
			case 'b':
			/*for(a = 0; a < 10; a++)
			{
				//B.insert(rand()%100,rand()%100);
		
			}*/
			B = A;			
			std::cout << "Drzewo B" << std::endl;
			printer.print(B);
			break;

			case 'a':
			for(a = 0; a < 10; a++)
			{	value = rand()%3+1;
				while(value--)
				X.addNodeAtTheEnd(rand()%20);
				A.insert(X,X);
				X.clear();				
			}
			std::cout << "Drzewo A" << std::endl;
			printer.print(A);
			break;

			case 'c':
			//for(bIterator<int> i = I.begin(); i != I.end(); i++)
			I.begin();
			for(a = 0; a < I.noNode(); a++){
			for(b = 0; b < I.currDe(); b++)
			std::cout <<"print " << *(I(a,b));
			I++;
			std::cout << std::endl;}
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
	/*std::string h = "aa";
	if(A.checkCoData(h))
	std::cout << h <<" nalezy" << std::endl;
	else
	std::cout << h <<" nie nalezy" << std::endl;*/
/*
	for(h = 0; h < 60; h=h+5){
	a = rand()%100;
	if(A.checkCoData(a))
	std::cout << a <<" nalezy" << std::endl;
	else
	std::cout << a <<" nie nalezy" << std::endl;
}*/

	/*for(bIterator<int> i = I.begin(); i != I.end(); i++)
	std::cout <<"print " << i.currPtr->keys[0] << std::endl; 
*/

	

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
