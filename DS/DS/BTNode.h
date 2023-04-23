#pragma once
template<typename T>
class BTNode
{
private:
	T data;
	BTNode<T>* Left;
	BTNode<T>* Right;
public:
	BTNode();
	BTNode<T>* getLeft();
	BTNode<T>* getRight();
	T getData();
	void setLeft(BTNode<T>* p);
	void setRight(BTNode<T>* p);
	void setData(T);
};

template<typename T>
inline BTNode<T>::BTNode()
{
	Left = nullptr; Right = nullptr;
}

template<typename T>
inline BTNode<T>* BTNode<T>::getLeft()
{
	return Left;
}

template<typename T>
inline BTNode<T>* BTNode<T>::getRight()
{
	return Right;
}

template<typename T>
inline T BTNode<T>::getData()
{
	return data;
}

template<typename T>
inline void BTNode<T>::setLeft(BTNode<T>* p)
{
	Left = p;
}

template<typename T>
inline void BTNode<T>::setRight(BTNode<T>* p)
{
	Right = p;
}

template<typename T>
inline void BTNode<T>::setData(T d)
{
	data = d;
}
