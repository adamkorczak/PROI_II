#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <queue>


#ifndef display_hpp
#define display_hpp


template <class typ>
class treeNode
{


	typ *keys;
	int minDegree;
	int index;
	int currDeg;
	bool leaf;
	
	treeNode *up;
	treeNode **child;

	typ *data;
public:


	treeNode(int _d = 1, bool _leaf = true, int _index = 1)
		:	minDegree(_d), leaf(_leaf), index(_index)
		{	keys = new typ [2*_d - 1];
			data = new typ [2*_d - 1];
			child = new treeNode *[2*_d]; 
			currDeg = 0;
		}

	treeNode(const treeNode<typ> &t);

	treeNode *search(typ _k);
	treeNode *traverseToEnd();
	void traverse();
	void traverseCopy();
	void copy(treeNode<typ> *b);
	void insertInEmptySlots(typ _data, typ _k);
	void split(int m, treeNode<typ> *ptr);
	void checkSize(int tabSize[]);
	void compareTree(treeNode<typ> &t, bool *pointer);


template <class T> friend class bTree;
template <class T> friend class  bTreePrinter;
template <class T> friend class bIterator;
};


template <class typ>
class bTree
{
	int noCells;
	int noNodes;
	int minDeg;
public:

	treeNode<typ> *root;
	

	//typedef bIterator<typ> bIt;


	bTree(int _minDeg = 1)
		: minDeg(_minDeg) { root = NULL; }
	bTree(const bTree<typ> &t);

	void traverse();
	void traverseInsert(bTree<typ> &t, treeNode<typ> *s);
	void copyRoot(treeNode<typ> *b);
	void insert(typ _data, typ _k);
	void checkSize();

	bool checkCoData(typ _k);

	treeNode<typ>* getNodeThruTraverse(); 
	treeNode<typ>* search(typ _k);
	treeNode<typ>* returnEnd();	

	bool operator==(const bTree<typ> &t);
	bool operator!=(const bTree<typ> &t);
	
	bTree<typ> operator+(const bTree<typ> &t);
	bTree<typ> &operator=(const bTree<typ> &t);	


template <class T> friend class bIterator;
};

template <class typ>
class bIterator
{

	treeNode<typ> *currPtr;
	bTree<typ> &it;
	std::queue < treeNode<typ>* > Q;
	
public:
	
	bIterator(bTree<typ> &t) : it(t)
	{ currPtr = it.root; Q.push(it.root); }
	
	bIterator & end()
	{	
		currPtr = NULL;

		return *this;	
	}
	bIterator & back()
	{
		currPtr = it.returnEnd();		
		return *this;	
	}
	bIterator & begin()
	{
		currPtr = it.root;
		return *this;
	}
	
	int currDe()
	{
		return currPtr->currDeg;
	}
	int noNode()
	{
		it.checkSize();
		return it.noNodes;
	}


	typ *operator*()
	{
		return (currPtr->data);
	}

	typ *operator()(int i, int j)
	{
	 int k;
	 	while(!Q.empty())
		Q.pop();
		Q.push(it.root);
		begin();
		for(k = 0; k < i; k++, ++(*this));
		return (currPtr->data + j);
	}
	bIterator<typ> operator[](int i)
	{int j;
		while(!Q.empty())
		Q.pop();
		Q.push(it.root);
		begin();
		for( j  = 0; j < i; j++, ++(*this));
		return *this;
	}

	bIterator<typ> &operator++();	
	bIterator<typ> operator++(int)
	{
		bIterator old = *this;
		++(*this);
		return old;
	}

	bool operator!=(const bIterator &R)
	{
		if(this->currPtr != R.currPtr)
		return true;
		else
		return false;
	}

	bool operator==(const bIterator &R)
	{
		if(*this != R)
		return false;
		else
		return true;
	}

};

template <class typ>
bIterator<typ> &bIterator<typ>::operator++()
{
int i;
		if(currPtr->leaf == false)
		{
			for(i = 0; i <= currPtr->currDeg; i++)
			Q.push(currPtr->child[i]);
			currPtr = NULL;
			Q.pop();
			currPtr = Q.front();
			return *this;
		}
		else
		{
			currPtr = NULL;
			Q.pop();
			currPtr = Q.front();
			return *this;
		}

}


template <class typ>
treeNode<typ> *bTree<typ>::returnEnd()
{
treeNode<typ> *s;

	if(root == NULL || root->leaf == true)
	return this->root;
	else
	{
		s = root->treeNode<typ>::traverseToEnd();
		return s;	
	}
}


template <class typ>
treeNode<typ>* treeNode<typ>::traverseToEnd()
{
	int i;
	for(i= 0; i < currDeg; i++)
	{
		if(leaf == false)
		{
			child[i] ->traverseToEnd();
		}
		else if(leaf == true && i == (currDeg - 1))
		{
			return this;
		}	
	}

	if(leaf == false)
	{
		child[i] -> traverseToEnd();
	}
}





template <class typ>
void treeNode<typ>::compareTree(treeNode<typ> &t, bool *pointer)
{
int i;

	if(currDeg == t.currDeg)
	{
		for(i = 0; i < currDeg; i++)
		{
			if(keys[i] != t.keys[i])
			{
				*pointer = false;
				return;
			}
		}

	}
	else
	{
		*pointer = false;
		return;
	}

	if(leaf == false&& t.leaf == false)
	{
	for( i = 0; i < currDeg; i++)
	child[i]->compareTree(*(t.child[i]), pointer);
	}
	else if(leaf == true && t.leaf == true)
	{
		*pointer = true;
		return;
	}
	else
	{
		*pointer = false;
	}
}


template <class typ>
bool bTree<typ>::operator!=(const bTree<typ> &t)
{
	if(*this == t)
	return false;
	else
	return true;
}


template <class typ>
bool bTree<typ>::operator==(const bTree<typ> &t)
{
bool *ptr = new bool;
	bTree<typ> *temp = new bTree<typ>(t);
	treeNode<typ> *s = temp->root;

	this->checkSize();
	temp->checkSize();

	if(this->root == NULL && s == NULL)
	return true;
	
	if(this->noCells != temp ->noCells || this->noNodes != temp->noNodes)
	{
		delete temp;
		delete ptr;
		return false;
	}
	else
	{
//traverse thru all cells
		(this->root)->compareTree(*s,ptr);
		delete temp;

		if(*ptr)
		{
			delete ptr;
			return true;
		}
		else
		{
			delete ptr;
			return false;
		}
		
	} 

}


template<class typ>
void treeNode<typ>::checkSize(int tabSize[])
{
int i;
tabSize[0]++;
tabSize[1] = tabSize[1] + (currDeg);

	if(leaf == false)
	{
		for( i = 0; i <= currDeg; i++)
		child[i] -> checkSize(tabSize);
	}

}


template <class typ>
void bTree<typ>::checkSize()
{
int tabSize[2];
tabSize[0] = 0;
tabSize[1] = 0;
//traverse thru Tree
//size defined as number of nodes and cells

//size ++
	if(root == NULL)
	{
		noNodes = 0;
		return;
	}

	if(root->leaf == true)
	{
		noNodes = 1;
		noCells = (root->currDeg + 1);
	}
	else
	{		
		root->treeNode<typ>::checkSize(tabSize);	
	}
//std::cout << "currDeg" << root->currDeg<< std::endl;
	noNodes = tabSize[0];
	noCells = tabSize[1];
	return;
}



template<class typ>
bTree<typ> &bTree<typ>::operator=(const bTree<typ> &t)
{
	if(this->root == t.root)
	return *this;

	if(t.root == NULL)
	root = NULL;
	else
	{
		root = NULL;
		minDeg = t.minDeg;
		copyRoot(t.root);
	}
	return *this;
}


template <class typ>
treeNode<typ>::treeNode(const treeNode<typ> &t)
{
int i;
	minDegree = t.minDegree;
	leaf = t.leaf;
	index = t.index;
	currDeg = t.currDeg;
	keys = new typ [2*minDegree - 1];
	data = new typ [2*minDegree - 1];
	child = new treeNode *[2*minDegree];
	for(i = 0; i < currDeg; i++)
	{
		keys[i] = t.keys[i];
		data[i] = t.data[i];
		child[i] = t.child[i];
	} 
	child[i] = t.child[i];

}


template <class typ>
bTree<typ>::bTree(const bTree<typ> &t)
{
int i;
root = NULL;

	minDeg = t.minDeg;
	if(t.root == NULL)
	{
		return;
	}
	else
	{	
		copyRoot(t.root);			
	}
		
}

template<class typ>
void bTree<typ>::copyRoot(treeNode<typ> *b)
{
int i;
int j;
			if(root == NULL)
			{
				root = new treeNode<typ>(b->minDegree,b->leaf,b->index);
				root->currDeg = b->currDeg;
				for(i = 0; i < b->currDeg; i++)
				root->keys[i] = b->keys[i];
			}
	
			if(b->leaf == true)
			return;
			else
			{
				for(j = 0; j <= b->currDeg; j++)
				{				
					treeNode<typ> *p = new treeNode<typ>(b->minDegree,true,b->index);
					root->child[j] = p;
					
					p->copy(b->child[j]);
				}
				
			}
			
}


template<class typ>
void treeNode<typ>::copy(treeNode<typ> *b)
{
int i;
int j;
		
		
		currDeg = b->currDeg;

		for(i = 0; i < b->currDeg; i++)
		keys[i] = b->keys[i];

		leaf = b->leaf;
		
		if(b->leaf == true)
		{			
			return;
		}
		else
			{
				for(j = 0; j <= b->currDeg; j++)
				{				
					treeNode<typ> *p = new treeNode<typ>(b->minDegree,true,b->index);
					child[j] = p;
					p->copy(b->child[j]);
				
				}
			}

}			

template <class typ>
void bTree<typ>::traverseInsert(bTree<typ> &t, treeNode<typ> *s)
{
	
	int i;

	for(i= 0; i < s->currDeg; i++)
	{
		if(s->leaf == false)
		{
			traverseInsert(t,s->child[i]);
		}
		t.insert(s->data[i],s->keys[i]);	
	}

	if(s->leaf == false)
	{
		traverseInsert(t,s->child[i]);
	}

}

template <class typ>
bTree<typ> bTree<typ>::operator+(const bTree<typ> &t)
{
bTree<typ> *temp = new bTree<typ>(t);

	if(t.root != NULL)
	temp->traverseInsert(*this,t.root);

	delete temp;
	return *this;

}


template <class typ>
void bTree<typ>::insert(typ _data, typ _k)
{
	if(root == NULL)
	{
		root = new treeNode<typ>(minDeg,true,0);
		root ->keys[0] = _k;
		root ->data[0] = _data;
		root ->currDeg = 1;

	}
	else
	{
		if(root->currDeg == (2*minDeg - 1))
		{
				treeNode<typ> *p = new treeNode<typ>(minDeg,false,0);
				
				p ->child[0] = root;
				p ->split(0, root);

				int i = 0;
				if(p->keys[0] < _k)
					i++;

				p->child[i]->insertInEmptySlots(_data,_k);		
				root = p;						
		}
		else
		{
			root->insertInEmptySlots(_data, _k);
		}
		
	
	}


}

template <class typ>
void treeNode<typ>::insertInEmptySlots(typ _data, typ _k)
{
int i = currDeg-1;

	if(leaf == true)
	{
		while( i >= 0 && keys[i] > _k)
		{
			keys[i+1] = keys[i];
			i--;
		} 
		
		keys[i+1] = _k;
		data[i+1] = _data;
		currDeg = currDeg + 1;

	}
	else
	{
		while( i >= 0 && keys[i] > _k)
		i--;

		if(child[i+1]->currDeg == (2*minDegree - 1))
		{
			split(i+1, child[i+1]);

			if(keys[i+1] < _k)
			i++;
		}
		child[i+1]->insertInEmptySlots(_data, _k);
	}

}


template <class typ>
void treeNode<typ>::split(int m, treeNode<typ> *ptr)
{

	treeNode<typ> *s = new treeNode<typ>(ptr->minDegree,  ptr->leaf,0);
	s->currDeg = (minDegree - 1);

	for(int j = 0; j < (minDegree - 1); j++)
	{
		s->keys[j] = ptr->keys[j+minDegree];
		s->data[j] = ptr->data[j+minDegree];
	}

	if(ptr->leaf == false)
	{
		for(int j = 0; j < minDegree; j++)
		s->child[j] = ptr->child[j+minDegree];
	}
	
	ptr->currDeg = (minDegree - 1);

	for(int j = currDeg; j >= (m + 1); j--)
	{
		child[j+1] = child[j];
	}

	child[m+1] = s;

	for(int j = (currDeg - 1); j >= m; j--)
	{
		keys[j+1] = keys[j];
		data[j+1] = data[j];
	}

	keys[m] = ptr->keys[minDegree - 1];
	data[m] = ptr->data[minDegree - 1];

	currDeg = currDeg + 1;
}


template <class typ>
bool bTree<typ>::checkCoData(typ _k)
{
	if(root->treeNode<typ>::search(_k) != NULL)
	return true;
	else
	return false;

}


template <class typ>
treeNode<typ>* bTree<typ>::search(typ _k)
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
	for(i= 0; i < currDeg; i++)
	{
		if(leaf == false)
		{
			child[i] ->traverse();
		}
		std::cout << " " << keys[i];	
	}

	if(leaf == false)
	{
		child[i] -> traverse();
	}

}


template <class typ>
treeNode<typ> *treeNode<typ>::search(typ _k)
{
	int i = 0;
	while( i < currDeg && _k > keys[i])
		i++;

	if(keys[i] == _k)
	return this;

	if (leaf == true)
		return NULL;

	return child[i] ->search(_k);
}

#endif
