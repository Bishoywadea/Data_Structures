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
	int CountNodes( BTNode<T>* Root);
	int NodesSum(BTNode<T>* root);
	int LeavesSum(BTNode<T>* root);
public:
	BST();
	void add(T d);
	BTNode<T>* newNode(T d);
	void BFSTransverse();
	void DFS();
	int NumOfNodes();
	int SumOfNodes();
	int SumOfLeaves();
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

template<typename T>
inline int BST<T>::CountNodes( BTNode<T>* root)
{
	if (!root->getLeft() && !root->getRight())
		return 1;
	else if(root->getLeft() && root->getRight())
		return 1 + CountNodes(root->getLeft()) + CountNodes(root->getRight());
	else if (root->getLeft())
		return 1 + CountNodes(root->getLeft());
	else if (root->getRight())
		return 1 + CountNodes(root->getRight());
}

template<typename T>
inline int BST<T>::NodesSum(BTNode<T>* root)
{
	if (!root->getLeft() && !root->getRight())
		return root->getData();
	else if (root->getLeft() && root->getRight())
		return root->getData() + NodesSum(root->getLeft()) + NodesSum(root->getRight());
	else if (root->getLeft())
		return root->getData() + NodesSum(root->getLeft());
	else if (root->getRight())
		return root->getData() + NodesSum(root->getRight());
}

template<typename T>
inline int BST<T>::LeavesSum(BTNode<T>* root)
{
	if (!root->getLeft() && !root->getRight())
		return root->getData();
	else if (root->getLeft() && root->getRight())
		return LeavesSum(root->getLeft()) + LeavesSum(root->getRight());
	else if (root->getLeft())
		return LeavesSum(root->getLeft());
	else if (root->getRight())
		return LeavesSum(root->getRight());
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
inline int BST<T>::NumOfNodes()
{
	return CountNodes(Root);
}

template<typename T>
inline int BST<T>::SumOfNodes()
{
	return NodesSum(Root);
}

template<typename T>
inline int BST<T>::SumOfLeaves()
{
	return LeavesSum(Root);
}

template<typename T>
BST<T>::~BST()
{
}