#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include "display.h"
#include "tree.h"





int main()
{

srand(time(NULL));

bTree<int> A(4);
bTreePrinter<int> printer;
int a;
	for(a = 0; a < 40; a++)
	{
		A.insert(a,a);
		
	}
	printer.print(A);
	//A.traverse();
	std::cout << std::endl;

	return 0;
}
