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
private:
	aghContainer<T> * container;
	unsigned int currentIndex;

public:

     //\brief The class constructor
     //
     //\param _container - container with which the iterator works
     //\param _currentIndex - current element pointed by iterator
	aghIterator(aghContainer<T> * _container, unsigned int _currentIndex = 0);

     //\brief The class copying constructor
     //
     //\param _right - source object
	aghIterator(const aghIterator<T> & _right);
     
     //\brief Method to return iterator pointing to the first element of the container
     //\return iterator pointing to the first element of the container
	aghIterator<T> first();
     
     //\brief Method to return iterator pointing to the last element of the container
     //\return iterator pointing to the last element of the container
	aghIterator<T> last();
     
     //\brief Method to move iterator to next element of the container	
	void next();
	
	//\brief Method to move iterator to next element of the container
	void prev();
	
	//\brief Method to return current pointed element
	//\return current pointed element of the container
	T& current();
	
	//\brief Method to change value of current pointed element
	//\param _value - new value to set
	void current(T const& _value);
	
	//\brief Method to set iterator to point to the first element of the container
	void atFirst();

	//\brief Method to set iterator to point to the last element of the container
	void atLast();
	
	//\brief Method to return ammount of elements after current pointed (including current)
	//\return number of elements
	unsigned int size();
	
	//\brief Overload of * operator
	//
	//\return value of the current pointed element
	T& operator*();
	
	//\brief Overload of [] operator
	//
	//\param n - index
	//return value of the element which is n spots to the right
	T& operator[](int n);
	
	//\brief Overload of = operator
	//
	//\param _right - container
	//\return reference to this iterator
	aghIterator<T> & operator=(aghContainer<T> * _right);
	
	//aghIterator<T> operator=(aghIterator<T> const & _right);
	
	//\brief Overload of + operator
	//
	//\param n - index
	//\return iterator moved n spots right
	aghIterator<T> operator+(int n);
	
     //\brief Overload of + operator. Moving iterator to the right
	//
	//\param n - number of spots to move
	//\return reference to this iterator
	aghIterator<T> & operator+=(int n);
	
	//\brief Overload of - operator
	//
	//\param n - index
	//\return iterator moved n spots left
	aghIterator<T> operator-(int n);
	
     //\brief Overload of - operator. Moving iterator to the left
	//
	//\param n - number of spots to move
	//\return reference to this iterator
	aghIterator<T> & operator-=(int n);
	
	//\brief Overload of postincrement operator. Moves iterator to next element
	//
     //\return iterator pointing to the current element
	aghIterator<T> operator++(int);
	//\brief Overload of preincrement operator. Moves iterator to next element
	//
     //\return iterator pointing to the next element
	aghIterator<T> & operator++();
	
	//\brief Overload of postdecrement operator. Moves iterator to previous element
	//
     //\return iterator pointing to the current element
	aghIterator<T> operator--(int);
	
	//\brief Overload of predecrement operator. Moves iterator to previous element
	//
     //\return iterator pointing to the previous element
	aghIterator<T> & operator--();
	
	//\brief Overload of == operator
	//
	//\param _rigth - iterator to compare
	//\return TRUE if comparison is positive
	bool operator==(const aghIterator<T>& _right) const;
	
	//\brief Overload of != operator
	//
	//\param _right - iterator to compare
	//\return TRUE if comparison is negative
	bool operator!=(const aghIterator<T>& _right) const;
	
	
	operator int();
};

template <class T>
aghIterator<T>::aghIterator(aghContainer<T> * _container, unsigned int _currentIndex):container(_container), currentIndex(_currentIndex)
{
     if( _currentIndex >= _container->size() )
          currentIndex = 0;
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
	return aghIterator(container, container->size()-1);
}

template <class T>
void aghIterator<T>::next()
{
	if ( container && currentIndex < container->size()-1 )
	     currentIndex++;
}

template <class T>
void aghIterator<T>::prev()
{
	if ( container && currentIndex > 0 )
	     currentIndex--;
}

template <class T>
T& aghIterator<T>::current()
{
     if ( container )
     	return (*container)[currentIndex];
     //TODO: co ma zwrócić
}

template <class T>
void aghIterator<T>::current(T const& _value)
{
     if ( container )
	     container->replace(currentIndex, _value);
}

template <class T>
void aghIterator<T>::atFirst()
{
	currentIndex = 0;
}

template <class T>
void aghIterator<T>::atLast()
{
	if ( container )
	     currentIndex = container->size() - 1;
	else
	     currentIndex = 0;
}

template <class T>
unsigned int aghIterator<T>::size()
{
     if ( container )
	     return container->size() - currentIndex;
	else
	     return 0;
}

template <class T>
T& aghIterator<T>::operator*()
{
	//return (*container)[currentIndex];
	return this->current();
}

template <class T>
T& aghIterator<T>::operator[](int n)
{
     if ( currentIndex + n < container->size() )
	     return (*container)[currentIndex + n];
	else
	     throw aghException(0, "Index out of range", __FILE__, __LINE__);
}

template <class T>
aghIterator<T> & aghIterator<T>::operator=(aghContainer<T> * _right)
{
     
	container = _right;
	currentIndex = 0;
	
	return *this;
}
/*
template <class T>
aghIterator<T> aghIterator<T>::operator=(aghIterator<T> const& _right)
{
	container = ;
	currentIndex = ;
	
	return *this;
}*/

template <class T>
aghIterator<T> aghIterator<T>::operator+(int n)
{
     //TODO: currentIndex+n >= container->size() ---> n >= size()  // sprawdzić działanie
	if ( currentIndex+n >= container->size()  )
          throw aghException(0, "Index out of range", __FILE__, __LINE__);
     else
     	return aghIterator(container, currentIndex - n);
}

template <class T>
aghIterator<T> & aghIterator<T>::operator+=(int n)
{
	//currentIndex += n;
	for ( int i=0; i<n; i++ ) next();
	return *this;
}

template <class T>
aghIterator<T> aghIterator<T>::operator-(int n)
{
     if ( currentIndex-n < 0 )
          throw aghException(0, "Index out of range", __FILE__, __LINE__);
     else
     	return aghIterator(container, currentIndex - n);
}

template <class T>
aghIterator<T> & aghIterator<T>::operator-=(int n)
{
	//currentIndex -= n;
	for ( int i=0; i<n; i++ ) prev();
	return *this;
}

template <class T>
aghIterator<T> aghIterator<T>::operator++(int)
{
	aghIterator<T> temp = *this;
	next();
	return temp;
}

template <class T>
aghIterator<T> & aghIterator<T>::operator++()
{
	next();
	aghIterator<T> temp = *this;
	return temp;
}

template <class T>
aghIterator<T> aghIterator<T>::operator--(int)
{
	aghIterator<T> temp = *this;
	prev();
	return temp;
}

template <class T>
aghIterator<T> & aghIterator<T>::operator--()
{
	prev();
	aghIterator<T> temp = *this;
	return temp;
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
	
}

#endif
