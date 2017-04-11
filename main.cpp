#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

template <class typ>
class treeNode
{
	typ *keys;
	int minDegree;
	int index;
	int curr_d;
	bool leaf;
	
	treeNode *up;
	treeNode **child;

	typ data;

public:

	treeNode(int _d = 1, bool _leaf = true, int _index = 1)
		:	minDegree(_d), leaf(_leaf), index(_index)
		{	keys = new typ [2*_d - 1];
			child = new treeNode *[2*_d]; 
			curr_d = 0;
		}
	

	treeNode *search(int _k);
	void traverse();

};

template <class typ>
class bTree
	:	public treeNode<typ>
{
	treeNode<typ> *root;
	int minDeg;

public:

	bTree(int _minDeg = 1)
		: minDeg(_minDeg) { root = NULL; }

	void traverse();
	treeNode<typ>* search(int _k);
	
	
	
};

template <class typ>
treeNode<typ>* bTree<typ>::search(int _k)
{
	if(root == NULL)
	return NULL;

	else
	return root->treeNode<typ>::search(_k);

}

template <class typ>
void bTree<typ>::traverse()
{
	if(root != NULL)
	root->treeNode<typ>::traverse();
}

template <class typ>
void treeNode<typ>::traverse()
{
	int i;
	for(i= 0; i < curr_d; i++)
	{
		if(leaf == false)
		child[i] ->traverse();
		
		std::cout << " " << keys[i];
	
	}

	if(leaf = false)
	child[i] -> traverse();

}
template <class typ>
treeNode<typ> *treeNode<typ>::search(int _k)
{
	int i = 0;
	while( i < curr_d && _k > keys[i])
		i++;

	if(keys[i] == _k)
	return this;

	if (leaf == true)
		return NULL;

	return child[i] ->search(_k);
}


int main()
{


	return 0;
}
