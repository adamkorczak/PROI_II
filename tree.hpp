#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>


#ifndef display_hpp
#define display_hpp


template <class typ>
class treeNode
{
public:

	typ *keys;
	int minDegree;
	int index;
	int currDeg;
	bool leaf;
	
	treeNode *up;
	treeNode **child;

	typ *data;



	treeNode(int _d = 1, bool _leaf = true, int _index = 1)
		:	minDegree(_d), leaf(_leaf), index(_index)
		{	keys = new typ [2*_d - 1];
			data = new typ [2*_d - 1];
			child = new treeNode *[2*_d]; 
			currDeg = 0;
		//std::cout <<"konstruktor" << std::endl;
		}
	

	treeNode *search(typ _k);
	void traverse();
	void traverseCopy();
	void copy(treeNode<typ> *b);
	void insertInEmptySlots(typ _data, typ _k);
	void split(int m, treeNode<typ> *ptr);

};


template <class typ>
class bTree
	:	public treeNode<typ>
{
public:
	treeNode<typ> *root;
	int minDeg;



	bTree(int _minDeg = 1)
		: minDeg(_minDeg) { root = NULL; }
	bTree(const bTree<typ> &t);

	void traverse();
	void traverseInsert(bTree<typ> &t, treeNode<typ> *s);
	bTree<typ> &operator=(const bTree<typ> &t);
	void copyRoot(treeNode<typ> *b);
	treeNode<typ>* getNodeThruTraverse(); 
	treeNode<typ>* search(typ _k);
	void insert(typ _data, typ _k);
	bTree operator+(const bTree<typ> &t);
		
};


template<class typ>
bTree<typ> &bTree<typ>::operator=(const bTree<typ> &t)
{
	if(this->root == t.root)
	return *this;

	if(t.root == NULL)
	root = NULL;
	else
	{
		minDeg = t.minDeg;
		copyRoot(t.root);
	}
	return *this;
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
		t.insert(s->data[i],s->keys[i]);
		
	std::cout<< s->keys[i]<<std::endl;
	}

	for(i = 0; i <s->currDeg; i++)
	{
	
		if(s->leaf == false)
		{
			traverseInsert(t,s->child[i]);;
		}
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

	temp->traverseInsert(*this,temp->root);

	delete temp;
	return  *this;
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
			//std::cout<< "wstawiam do pustych" << std::endl;
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
