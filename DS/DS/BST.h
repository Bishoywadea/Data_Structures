#pragma once
#include"BTNode.h";
#include"LinkedQueue.h"
#include<iostream>
using namespace std;
template<typename T>
class BST
{
private:
	BTNode<T>* Root;

	void addRight(BTNode<T>* p, T d);
	void addLeft(BTNode<T>* p, T d);
	void findPlace(BTNode<T>* cur,T d);
	BTNode<T>* PrintDfs(BTNode<T>* R);
	
public:
	BST();
	void add(T d);
	BTNode<T>* newNode(T d);
	void BFSTransverse();
	void DFS();
	~BST();
};

/************************
**  utillity functions
************************/

template<typename T>
inline void BST<T>::addRight(BTNode<T>* p, T d)
{
	BTNode<T>* R = new BTNode<T>;
	R->setData(d);
	p->setRight(R);
}

template<typename T>
inline void BST<T>::addLeft(BTNode<T>* p, T d)
{
	BTNode<T>* R = new BTNode<T>;
	R->setData(d);
	p->setLeft(R);
}

template<typename T>
inline void BST<T>::findPlace(BTNode<T>* cur, T d)
{
	if (cur->getData() > d)
	{
		if (!cur->getLeft())
			addLeft(cur, d);
		else
			findPlace(cur->getLeft(), d);
	}
	else if (cur->getData() < d)
	{
		if (!cur->getRight())
			addRight(cur, d);
		else
			findPlace(cur->getRight(), d);
	}
}

template<typename T>
inline void BST<T>::BFSTransverse()
{
	LinkedQueue<BTNode<T>*> q;
	q.enqueue(Root);
	while (!q.isEmpty())
	{
		cout << q.peekFront()->getData()<<" ";
		if(q.peekFront()->getLeft())
			q.enqueue(q.peekFront()->getLeft());
		if (q.peekFront()->getRight())
			q.enqueue(q.peekFront()->getRight());
		q.dequeue();
	}
}

template<typename T>
inline BTNode<T>* BST<T>::PrintDfs(BTNode<T>* R)
{
	if (R)
	{
		cout << R->getData() << " ";
		PrintDfs(R->getLeft());
		PrintDfs(R->getRight());
	}
	return nullptr;
}

/************************
**  public functions
************************/

template<typename T>
BST<T>::BST()
{
	Root = nullptr;
}

template<typename T>
inline void BST<T>::add(T d)
{
	if (!Root)
	{
		BTNode<T>* R = new BTNode<T>;
		R->setData(d);
		Root = R;
	}
	else
	{
		findPlace(Root,d);
	}
}

template<typename T>
inline BTNode<T>* BST<T>::newNode(T d)
{
	BTNode<T>* N = new BTNode<T>();
	N->setData(d);
	N->setLeft(nullptr);
	N->setRight(nullptr);
	return N;
}

template<typename T>
void BST<T>::DFS()
{
	PrintDfs(Root);
}

template<typename T>
BST<T>::~BST()
{
}