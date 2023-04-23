#include<iostream>
#include "LinkedList.h"
#include"DoublyLinkedList.h"
#include"LinkedStack.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"BST.h"
using namespace std;

int main()
{
	BST<int> tree;
	tree.add(40);
	tree.add(50);
	tree.add(45);
	tree.add(30);
	tree.add(35);
	tree.add(25);
	tree.add(60);
	tree.add(100);
	tree.BFSTransverse();
	cout<<tree.SumOfLeaves();
}

