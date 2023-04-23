#ifndef _DNODE
#define _DNODE

//First let's declare a single node in the list
template<typename T>
class DNode
{
private:
	T item;	// A data item (can be any complex sturcture)
	DNode<T>* next;	// Pointer to next node
	DNode<T>* prev;  // Pointer to prev node
public:

	DNode() //default constructor
	{
		next = nullptr;
		prev = nullptr;
	}

	DNode(T newItem) //non-default constructor
	{
		item = newItem;
		next = nullptr;
		prev = nullptr;

	}

	void setItem(T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(DNode<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} // end setNext
	void setPrev(DNode<T>* prevNodePtr)
	{
		prev = prevNodePtr;
	} // end setNext
	T getItem() const
	{
		return item;
	} // end getItem

	DNode<T>* getNext() const
	{
		return next;
	}
	DNode<T>* getPrev() const
	{
		return prev;
	}
}; // end DNode

#endif	

#ifndef _DOUBLYLINKEDLIST
#define _DOUBLYLINKEDLIST

template <typename T>
class DoublyLinkedList
{
private:
	DNode<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:

	friend bool FoldBiotonic(const DoublyLinkedList<T>& L, DoublyLinkedList<T>& Res);

	DoublyLinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~DoublyLinkedList()
	{
		DeleteAll();
	}
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	///////////////////////////////////////////
	void DeleteAll()
	{
		DNode<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}
	///////////////////////////////////////////
	/*
	* prints the values of all nodes in a doubly linked list starting from the Head.
	*/
	void DisplayForward()	const
	{
		DNode<T>* p = Head;
		while (p)
		{
			cout << p->getItem();
			p = p->getNext();
			if (p)
				cout << " ";
		}
		cout << "NULL\n";
	}

	////////////////////////////////////////////////////////////////////////
	/////////////////////  Requirements  //////////////////////
	/*
	You are supposed to implement the following member functions:
	-----------------------------------------------------------------
		InsertBeg −> Adds an element at the beginning of the DLL.           *******Done

		DeleteBeg −> Deletes an element at the beginning of the DLL.        *******Done

		InsertLast −> Adds an element at the end of the DLL.                *******Done     

		DeleteLast −> Deletes an element from the end of the DLL.           *******Done    
		 
		InsertAfter −> Adds an element after the first occurance of an item in the DLL.     *******Done still need handling if not found

		Delete −> Deletes an element from the list using the item,if the item exists more than once, all copies should be deleted .  *******Done still need handling if not found

		DisplayBackward −> Displays the complete list in a backward manner.
	*/
	////////////////////////////////////////////////////////////////////////

	void InsertBeg(const T& data)
	{
		DNode<T>* R = new DNode<T>(data);
		if (!Head)
		{
			R->setPrev(nullptr);
			R->setNext(nullptr);
			Head = R;
		}
		else
		{
			Head->setPrev(R);
			R->setPrev(nullptr);
			R->setNext(Head);
			Head = R;
		}
	}

	void DeleteBeg()
	{
		if (Head && Head->getNext())
		{
			Head = Head->getNext();
			delete Head->getPrev();
			Head->setPrev(nullptr);
		}
		else if (Head && !Head->getNext())
		{
			delete Head;
			Head = nullptr;
		}
	}

	void InsertLast(const T& data)
	{
		DNode<T>* R = new DNode<T>(data);
		if (!Head)
		{
			R->setPrev(nullptr);
			R->setNext(nullptr);
			Head = R;
		}
		else
		{
			DNode<T>* current = Head;
			while (current->getNext())
				current = current->getNext();
			current->setNext(R);
			R->setPrev(current);
			R->setNext(nullptr);
		}
	}

	void DeleteLast()
	{
		if (Head && Head->getNext())
		{
			DNode<T>* current = Head;
			while (current->getNext())
				current = current->getNext();
			current->getPrev()->setNext(nullptr);
			delete current;
		}
		else if (Head && !Head->getNext())
		{
			delete Head;
			Head = nullptr;
		}
	}

	void InsertAfter(const T& x , const T& y)
	{
		DNode<T>* R = new DNode<T>(y);
		DNode<T>* current = Head;
		while (current->getItem() != x)
			current = current->getNext();
		R->setNext(current->getNext());
		current->setNext(R);
		R->setPrev(current);
	}

	void Delete(const T& x)
	{
		DNode<T>* current = Head;
		while (current)
		{
			if (current->getItem() == x)
			{
				DNode<T>* temp = current;
				current->getPrev()->setNext(current->getNext());
				current = current->getPrev();
				delete temp;
			}
			current = current->getNext();
		}
	}

	void DisplayBackward()
	{
		if (Head && Head->getNext())
		{
			DNode<T>* current = Head;
			while (current->getNext())
				current = current->getNext();
			while (current)
			{
				cout << current->getItem() << " ";
				current = current->getPrev();
			}
			cout << "NULL\n";
		}
	}
};
#endif