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
	int currentIndex;

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
     //
     //\return reference to this iterator
	aghIterator<T> & next();
	
	//\brief Method to move iterator to next element of the container
     //
     //\return reference to this iterator
     aghIterator<T> & prev();
	
	//\brief Method to return current pointed element
	//\return current pointed element of the container
	T& current();
	
	//\brief Method to change value of current pointed element
	//\param _value - new value to set
	void current(T const& _value);
	
	//\brief Method to set iterator to point to the first element of the container
     //
     //\return reference to this iterator	
	aghIterator<T> & atFirst();

	//\brief Method to set iterator to point to the last element of the container
	//
     //\return reference to this iterator
	aghIterator<T> & atLast();
	
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
	
	//\brief Overload of cast to int operator. Checks if iterator points to correct element in any container.
	//
	//\return 1 if true, 0 otherwise
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
	return aghIterator(container, container->size()-1);
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
	currentIndex--;
	return *this;	     
}

template <class T>
T& aghIterator<T>::current()
{
     if ( container )
     {
          if (currentIndex >= 0 && currentIndex < container->size() )
          {
	          return (*container)[currentIndex];
	     }
	     else
	     {
	          throw aghException(0, "Index out of range", __FILE__, __LINE__);
	     }
	}
	else
	{
	     throw aghException(1, "Iterator doesn't point to any container.", __FILE__, __LINE__);
	}
}

template <class T>
void aghIterator<T>::current(T const& _value)
{
     if ( container )
     {
          if (currentIndex >= 0 && currentIndex < container->size() )
          {
	          container->replace(currentIndex, _value);
	     }
	     else
	     {
	          throw aghException(0, "Index out of range", __FILE__, __LINE__);
	     }
	}
	else
	{
	     throw aghException(1, "Iterator doesn't point to any container.", __FILE__, __LINE__);
	}
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
     if ( container )
     {
          if ( currentIndex >= 0 )
	          return container->size() - currentIndex;
	     if ( currentIndex < 0 )
	          return container->size();
	}
	else
	{
	     throw aghException(1, "Iterator doesn't point to any container.", __FILE__, __LINE__);
	}
}

template <class T>
T& aghIterator<T>::operator*()
{
	return this->current();
}

template <class T>
T& aghIterator<T>::operator[](int n)
{
     return aghIterator(container, currentIndex+n).current();
     /*if ( container && currentIndex + n < (int)container->size() )
	     return (*container)[currentIndex + n];
	else
	     throw aghException(0, "Index out of range", __FILE__, __LINE__);*/
}

template <class T>
aghIterator<T> & aghIterator<T>::operator=(aghContainer<T> * _right)
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
	if ( container == _right.container && currentIndex == _right.currentIndex )
		return true;
	else
		return false;
}

template <class T>
bool aghIterator<T>::operator!=(const aghIterator<T>& _right) const
{
	return !( this->operator==(_right) );
}

template <class T>
aghIterator<T>::operator int()
{  
	if ( container )
	{
	     if ( container->size() )
	     {
	          if ( currentIndex >=0 && currentIndex < (int)container->size() )
	               return 1;
	     }
	}
	return 0;
}

#endif
