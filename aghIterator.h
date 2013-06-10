//
//  aghIterator.h
//  Kontenery-Iteratory
//
//  Created by Wojtek on 6/8/13.
//  Copyright (c) 2013 Wojtek. All rights reserved.
//

#ifndef Kontenery_Iteratory_aghIterator_h
#define Kontenery_Iteratory_aghIterator_h

template <class T>
class aghIterator {
	
	aghContainer<T> * container;
	unsigned int currentIndex;

public:
	aghIterator(aghContainer<T> * _container, unsigned int _currentIndex = 0);
	aghIterator(const aghIterator<T> & _right);
	aghIterator<T> first();
	aghIterator<T> last();
	aghIterator<T> & next();
	aghIterator<T> & prev();
	T& current();
	aghIterator<T> & atFirst();
	aghIterator<T> & atLast();
	unsigned int size();
	
	T& operator*();
	T& operator[](int n);
	aghIterator<T> operator=(aghContainer<T> * _right);
	aghIterator<T> operator+(int n);
	aghIterator<T> & operator+=(int n);
	aghIterator<T> operator-(int n);
	aghIterator<T> & operator-=(int n);
	aghIterator<T> operator++(int);
	aghIterator<T> & operator++();
	aghIterator<T> operator--(int);
	aghIterator<T> & operator--();
	bool operator==(const aghIterator<T>& _right) const;
	bool operator!=(const aghIterator<T>& _right) const;
	operator int();
};

template <class T>
aghIterator<T>::aghIterator(aghContainer<T> * _container, unsigned int _currentIndex):container(_container), currentIndex(_currentIndex)
{
}

template <class T>
aghIterator<T>::aghIterator(const aghIterator<T> & _right)
{
	container = _right.container;
	currentIndex = _right.currentIndex;
}

template <class T>
aghIterator<T> aghIterator<T>::first()
{
	return aghIterator(container, 0);
}

template <class T>
aghIterator<T> aghIterator<T>::last()
{
	return aghIterator(container, container->size() -1);
}

template <class T>
aghIterator<T> & aghIterator<T>::next()
{
	currentIndex++;
	return *this;
}

template <class T>
aghIterator<T> & aghIterator<T>::prev()
{
	/*
	if (currentIndex == 0)
		throw aghException(0, "Index out of range.", __FILE__, __LINE__);
	 */
	
	currentIndex--;
	return *this;
}

template <class T>
T& aghIterator<T>::current()
{
	return (*container)[currentIndex];
}

template <class T>
aghIterator<T> & aghIterator<T>::atFirst()
{
	currentIndex = 0;
	return *this;
}

template <class T>
aghIterator<T> & aghIterator<T>::atLast()
{
	currentIndex = container->size() - 1;
	return *this;
}

template <class T>
unsigned int aghIterator<T>::size()
{
	return container->size() - currentIndex;
}

template <class T>
T& aghIterator<T>::operator*()
{
	return (*container)[currentIndex];
}

template <class T>
T& aghIterator<T>::operator[](int n)
{
	return (*container)[currentIndex + n];
}

template <class T>
aghIterator<T> aghIterator<T>::operator=(aghContainer<T> * _right)
{
	container = _right;
	currentIndex = 0;
	
	return *this;
}

template <class T>
aghIterator<T> aghIterator<T>::operator+(int n)
{
	return aghIterator(container, currentIndex + n);
}

template <class T>
aghIterator<T> & aghIterator<T>::operator+=(int n)
{
	currentIndex += n;
	return *this;
}

template <class T>
aghIterator<T> aghIterator<T>::operator-(int n)
{
	return aghIterator(container, currentIndex - n);
}

template <class T>
aghIterator<T> & aghIterator<T>::operator-=(int n)
{
	currentIndex -= n;
	return *this;
}

template <class T>
aghIterator<T> aghIterator<T>::operator++(int)
{
	currentIndex++;
	return aghIterator(container, currentIndex - 1);
}

template <class T>
aghIterator<T> & aghIterator<T>::operator++()
{
	currentIndex++;
	return *this;
}

template <class T>
aghIterator<T> aghIterator<T>::operator--(int)
{
	currentIndex--;
	return aghIterator(container, currentIndex + 1);
}

template <class T>
aghIterator<T> & aghIterator<T>::operator--()
{
	currentIndex--;
	return *this;
}

template <class T>
bool aghIterator<T>::operator==(const aghIterator<T>& _right) const
{
	if (container == _right.container && currentIndex == _right.currentIndex)
		return true;
	else
		return false;
}

template <class T>
bool aghIterator<T>::operator!=(const aghIterator<T>& _right) const
{
	return !(this->operator==(_right));
}

template <class T>
aghIterator<T>::operator int()
{
	// ?!?!
}

#endif
