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
	void PrintLessThan(BTNode<T>* root, int V);
	void inverseChildren(BTNode<T>* root, BTNode<T>* original);
public:
	BST();
	void add(T d);
	BTNode<T>* newNode(T d);
	void BFSTransverse();
	void DFS();
	/*
	* member function that counts the number of nodes in a binary tree.
	*/
	int NumOfNodes();
	/*
	* member function that returns the sum of all the nodes in a binary tree.
	*/
	int SumOfNodes();
	/*
	* member function that counts the sum of leaves in a binary tree.
	*/
	int SumOfLeaves();
	/*
	* member function that returns the maximum value of all the nodes in a binary tree.
	* Assume all values are non-negative; return -1 if the tree is empty.
	*/
	int Getmax();
	/*
	* member function that prints all the keys that are less than a given value, V, in a binary tree.
	*/
	void PrintLessThan(int V);
	/*
	* member function that creates a mirror image of a binary tree. All left children become right children and vice versa.
	* The input tree must remain the same.
	*/
	void createMirrorTree(BST*& mirrored);
	/*
	* member function to delete all the leaves from a binary tree, leaving the root and intermediate nodes in place.
	*/
	void DeleteLeaves();
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

template<typename T>
inline void BST<T>::PrintLessThan(BTNode<T>* root ,int V)
{
	if(root->getData()<V)
		cout << root->getData() << " ";
	if (!root->getLeft() && !root->getRight() && root->getData() < V);
	else if (root->getLeft() && root->getRight()) {
		PrintLessThan(root->getLeft(),V);
		PrintLessThan(root->getRight(),V);
	}
	else if (root->getLeft())
		PrintLessThan(root->getLeft(), V);
	else if (root->getRight())
		PrintLessThan(root->getRight(), V);
}

template<typename T>
inline void BST<T>::inverseChildren(BTNode<T>* root , BTNode<T>* original)
{
	if (original)
	{
		root->setData(original->getData());
		if (original->getLeft() && original->getRight())
		{
			BTNode<T>* left=new BTNode<T>;
			BTNode<T>* right = new BTNode<T>;
			left->setData(original->getLeft()->getData());
			right->setData(original->getRight()->getData());
			root->setLeft(right);
			root->setRight(left);
			inverseChildren(root->getLeft(), original->getRight());
			inverseChildren(root->getRight(), original->getLeft());
		}
		else if (original->getLeft() && !original->getRight())
		{
			BTNode<T>* temp = new BTNode<T>;
			temp->setData(original->getLeft()->getData());
			root->setRight(temp);
			inverseChildren(root->getRight(), original->getLeft());
		}
		else if (!original->getLeft() && original->getRight())
		{
			BTNode<T>* temp = new BTNode<T>;
			temp->setData(original->getRight()->getData());
			root->setLeft(temp);
			inverseChildren(root->getLeft(), original->getRight());
		}
	}
	return;
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
inline int BST<T>::Getmax()
{
	if (!Root)
		return -1;
	BTNode<T>* cur = Root;
	while (cur->getRight())
		cur = cur->getRight();
	return cur->getData();
}

template<typename T>
inline void BST<T>::PrintLessThan(int V)
{
	PrintLessThan(Root, V);
	cout << endl;
}

template<typename T>
inline void BST<T>::createMirrorTree(BST*& mirrored)
{
	if (Root) {
		mirrored = new BST<int>;
		mirrored->add(Root->getData());
		inverseChildren(mirrored->Root, this->Root);
	}
}

template<typename T>
inline void BST<T>::DeleteLeaves()
{
	LinkedQueue<BTNode<T>*> q;
	q.enqueue(Root);
	while (!q.isEmpty())
	{
		BTNode<T>* leave = nullptr;
		if (q.peekFront()->getLeft()) {
			if(q.peekFront()->getLeft()->getLeft() || q.peekFront()->getLeft()->getRight())
				q.enqueue(q.peekFront()->getLeft());
			else
			{
				delete q.peekFront()->getLeft();
				q.peekFront()->setLeft(nullptr);
			}
		}
		if (q.peekFront()->getRight()){
			if (q.peekFront()->getRight()->getLeft() || q.peekFront()->getRight()->getRight())
				q.enqueue(q.peekFront()->getRight());
			else
			{
				delete q.peekFront()->getRight();
				q.peekFront()->setRight(nullptr);
			}
		}
		q.dequeue();
	}
}

template<typename T>
BST<T>::~BST()
{
}