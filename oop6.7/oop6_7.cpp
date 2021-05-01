#include "Array.h"
template<typename T>
Array DynamicArray(T arr[], const int size)
{
	Array DynArr = Array(size);
	for (int i = 0; i < size; i++)
		DynArr[i] = arr[i];
	return DynArr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int A = -5, B = 5;

	const int size = 10;
	int a[size];
	for (int i = 0; i < size; i++)
		a[i] = A + rand() % int(B - A + 1);

	Array b = DynamicArray(a, size);
	b.Print();
	unique_copy(b.begin(), b.end());
	b.Print();


	int arr[10] = { 1, -2, -1, -2, 5, 6, -8, 5, 1, 6 };
	cout << endl << "--- Demonstrate Functors ---" << endl;
	Predicate<int>* zero = new Zero<int>();
	Predicate<int>* positive = new Positive<int>();
	Predicate<int>* negative = new Negative<int>();
	Predicate<int>* even = new Even<int>();
	Predicate<int>* odd = new Odd<int>();

	Array q = DynamicArray(arr, size);
	q.Print();
	cout << "--- (without if) ---" << endl;
	unique_copy(q.begin(), q.end());
	q.Print();

	Array w = DynamicArray(arr, size);
	cout << "--- (zero) --- " << endl;
	unique_copy_if(w.begin(), w.end(), *zero);
	w.Print();

	Array e = DynamicArray(arr, size);
	cout << "--- (positive) --- " << endl;
	unique_copy_if(e.begin(), e.end(), *positive);
	e.Print();

	Array r = DynamicArray(arr, size);
	cout << "--- (negative) --- " << endl;
	unique_copy_if(r.begin(), r.end(), *negative);
	r.Print();

	Array t = DynamicArray(arr, size);
	cout << "--- (even) --- " << endl;
	unique_copy_if(t.begin(), t.end(), *even);
	t.Print();

	Array y = DynamicArray(arr, size);
	cout << "--- (odd) --- " << endl;
	unique_copy_if(y.begin(), y.end(), *odd);
	y.Print();

	return 0;
}
