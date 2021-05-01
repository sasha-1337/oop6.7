#pragma once
#include "Array.h"
template<class T> 
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template <class T>                                               
class Zero : public Predicate<T>    
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};

template<class T>						
class Positive : public Predicate<T>    
{
public:
	virtual bool operator () (int x)
	{
		return x > 0;
	}
};

template<class T>						
class Negative : public Predicate<T>	
{
public:
	virtual bool operator () (int x)
	{
		return x < 0;
	}
};

template<class T>					
class Even : public Predicate<T>   
{
public:
	virtual bool operator () (int x)
	{
		return (int)x % 2 == 0;
	}
};

template<class T>		
class Odd : public Predicate<T>    
{
public:
	virtual bool operator () (int x)
	{
		return (int)x % 2 != 0;
	}
};

template<class T>
void unique_copy(T* begin, T* end)
{
	for (int i = 0; i < 10; i++)
		for (int j = i+1; j < 10; j++)
			if (begin[i] == begin[j])
				begin[i] = 777;
}

template<class T>
void unique_copy_if(T* begin, T* end, Predicate<T>& predicate)
{
	for (int i = 0; i < 10; i++)
		for (int j = i; j < 10; j++)
			if (predicate(begin[i]))
				begin[i] = 777;
}