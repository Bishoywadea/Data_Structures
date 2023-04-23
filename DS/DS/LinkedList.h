#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include<iostream>
using namespace std;
template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	
public:


	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll(); 
	}
	
	void PrintList() const {
		Node<T>* p = Head; while (p) {
			cout << p->getItem(); p = p->getNext(); if (p)
				cout << " ";
		} cout << "NULL\n";
	}
	
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	void InsertEnd(const T& data)
	{
		Node<T>* p = Head;
		Node<T>* newNode=new Node<T>;
		newNode->setItem(data);
		newNode->setNext(nullptr);
		if (!p)
		{
			Head = newNode;
			return;
		}
		while (p->getNext())
		{
			p = p->getNext();
		}
		p->setNext(newNode);
		return;
	}

	bool DeleteElements(const LinkedList<T>& l)
	{
		Node<T>* currentList = Head;
		Node<T>* currentFreq = l.Head;
		Node<T>* prev = nullptr;
		if (currentFreq == nullptr && currentList != nullptr)
			return 0;
		else if (currentList == nullptr)
			return 1;
		else
		{
			while (currentFreq != nullptr && currentList != nullptr)
			{
				int f = currentFreq->getItem();
				int e = currentList->getItem();
				while (f>0)
				{
					if (currentList == Head)
					{
						prev = Head->getNext();
						delete currentList;
						Head = prev;
						currentList = Head;
						prev = nullptr;
					}
					else
					{
						prev->setNext(currentList->getNext()) ;
						delete currentList;
						currentList = prev->getNext();
					}
					f--;
				}
				while (currentList && e == currentList->getItem())
				{
					prev = currentList;
					currentList = currentList->getNext();
				}	
				currentFreq = currentFreq->getNext();
			}
			if (currentFreq == nullptr && currentList != nullptr)
				return 0;
			else
				return 1;
		}
	}

	bool RepeatElements(const LinkedList<T>& frq1, const LinkedList<T>& frq2)
	{
		Node<T>* cur = Head;
		Node<T>* f1 = frq1.Head;
		Node<T>* f2 = frq2.Head;
		Node<T>* temp = nullptr;
		bool turn = 0;
		while (cur && f1 && f2)
		{
			if (!turn)
			{
				while(f1 && f1->getItem()<0)
					f1 = f1->getNext();
				if (f1)
				{
					for (int i = 0; i < f1->getItem(); i++)
					{
						temp = new Node<T>(cur->getItem());
						temp->setNext(cur->getNext());
						cur->setNext(temp);
						cur = cur->getNext();
					}
					f1 = f1->getNext();
					cur = cur->getNext();
					turn = !turn;
				}	
			}
			else
			{
				while (f2 && f2->getItem() < 0)
					f2 = f2->getNext();
				if (f2)
				{
					for (int i = 0; i < f2->getItem(); i++)
					{
						temp = new Node<T>(cur->getItem());
						temp->setNext(cur->getNext());
						cur->setNext(temp);
						cur = cur->getNext();
					}
					f2 = f2->getNext();
					cur = cur->getNext();
					turn = !turn;
				}
			}
		}
		while (cur&&f1)
		{
			while (f1 && f1->getItem() < 0)
				f1 = f1->getNext();
			if (f1)
			{
				for (int i = 0; i < f1->getItem(); i++)
				{
					temp = new Node<T>(cur->getItem());
					temp->setNext(cur->getNext());
					cur->setNext(temp);
					cur = cur->getNext();
				}
				f1 = f1->getNext();
				cur = cur->getNext();
			}
		}
		while (cur && f2)
		{
			while (f2 && f2->getItem() < 0)
				f2 = f2->getNext();
			if (f2)
			{
				for (int i = 0; i < f2->getItem(); i++)
				{
					temp = new Node<T>(cur->getItem());
					temp->setNext(cur->getNext());
					cur->setNext(temp);
					cur = cur->getNext();
				}
				f2 = f2->getNext();
				cur = cur->getNext();
			}
		}
		if (((!f1) && (!f2)) && cur)
			return 0;
		return 1;
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key);

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T &value);

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst();


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast();

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T &value);	

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T &value);	

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L);

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse();

};

#endif	
