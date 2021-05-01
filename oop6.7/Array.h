#pragma once
#include "Functors.h"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <Windows.h>

using namespace std;

class Array
{
public:
	// ����
	typedef unsigned int UINT;
	typedef int value_type;
	typedef int* iterator;
	typedef const int* const_iterator;
	typedef int& reference;
	typedef const int& const_reference;
	typedef std::size_t size_type;
private:
	static const size_type minsize = 10; // ��������� ����� ������
	size_type Size; // ������� ����� ��� ��������
	size_type Count; // ������� �������� � �����
	size_type First; // �������� ������� ������� �������� � �����
	value_type* elems; // �������� �� ���
public:
	// ������������/���������/����������
	Array(const size_type& n = minsize)
		throw(bad_alloc, invalid_argument);
	Array(const Array&) throw(bad_alloc);
	Array(const iterator first, const iterator last)
		throw(bad_alloc, invalid_argument);
	Array(const size_type first, const size_type last)
		throw(bad_alloc, invalid_argument);
	~Array();
	Array& operator=(const Array&);

	// ���������
	iterator begin() { return elems; }
	const_iterator begin() const { return elems; }
	iterator end() { return elems + Count; }
	const_iterator end() const { return elems + Count; }

	// ������
	size_type size() const { return Count; } // �������� �����
	bool empty() const { return Count == 0; } // ���� � ��������
	size_type capacity() const { return Size; } // ����������� �����
	void resize(size_type newsize) throw(bad_alloc);  // ������ ����� 

	// ������ �� ��������
	reference operator[](size_type) throw(out_of_range);
	const_reference operator[](size_type) const throw(out_of_range);
	reference front() { return elems[0]; }
	const_reference front() const { return elems[0]; }
	reference back() { return elems[size() - 1]; }
	const_reference back() const { return elems[size() - 1]; }

	// ������-������������
	void push_back(const value_type& v); // �������� ������� � �����
	void pop_back(); // �������� ������� ������� � ���������� ���������
	void clear() { Count = 0; } // �������� �����
	void swap(Array& other); // ������� � ������ �������

	// ����� ������� �����/������
	friend ostream& operator <<(ostream& out, const Array& a);
	friend istream& operator >>(istream& in, Array& a);

	// ������ ������ ������
	void Read(Array& a);
	void Print();
};

