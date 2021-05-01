#include "Array.h"
Array::Array(const Array::size_type& n) throw(bad_alloc, invalid_argument)
{
	First = 0;
	Count = Size = n;
	elems = new value_type[Size];
	for (UINT i = 0; i < Size; i++)
		elems[i] = 0;
}
Array::Array(const iterator first, const iterator last)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	if (first <= last) {
		Count = Size = (last - first) + 1;
		elems = new value_type[Size];
		for (UINT i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const size_type first, const size_type last) throw(bad_alloc, invalid_argument)
{
	if (first <= last) {
		First = first;
		Count = Size = (last - first) + 1;
		elems = new value_type[Size];
		for (UINT i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const Array& t) throw(bad_alloc)
	: Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
	for (UINT i = 0; i < Size; ++i)
		elems[i] = t.elems[i];
}
Array::~Array()
{
	delete[]elems;
	elems = 0;
}

Array& Array::operator =(const Array& t)
{
	Array tmp(t);
	swap(tmp);
	return *this;
}
Array::reference Array::operator [](size_type index) throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}
Array::const_reference Array::operator [](size_type index) const throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

void Array::push_back(const value_type& v)
{
	if (Count == Size) // місця нема
		resize(Size * 2); // збільшили "місткість"
	elems[Count++] = v; // присвоїли
}
void Array::pop_back()
{
	if (size() > 0)
	{
		value_type* tmp = new value_type[size() - 1];
		for (size_type i = 0; i < size() - 1; ++i)
			tmp[i] = elems[i];   
		delete[] elems;
		elems = tmp;
		Size = size() - 1;
	}
}
void Array::swap(Array& other)
{
	std::swap(elems, other.elems); // стандартна функція обміну
	std::swap(Size, other.Size);
}
void Array::resize(size_type newsize) throw(bad_alloc)
{
	if (newsize > capacity())
	{
		value_type* data = new value_type[newsize];
		for (size_type i = 0; i < Count; ++i)
			data[i] = elems[i];
		delete[] elems;
		elems = data;
		Size = newsize;
	}
}

ostream& operator <<(ostream& out, const Array& tmp)
{
	for (size_t j = 0; j < tmp.Count; j++)
		cout << tmp[j] << " ";
	cout << endl;
	return out;
}
istream& operator >>(istream& in, const Array& tmp)
{
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << "arr[" << i << "] = ";
		in >> tmp[i];
	}
	return in;
}

void Array::Read(Array& a)
{
	cout << "--- Заповніть массив №1 ---" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << " arr[" << i << "] - ? "; cin >> a[i];
	}
	cout << endl;
}
void Array::Print()
{
	cout << "--- Array №1 ---" << endl;
	for (int i = 0; i < size(); i++)
		cout << "arr[" << i << "] = " << elems[i] << endl;
	cout << endl;
}