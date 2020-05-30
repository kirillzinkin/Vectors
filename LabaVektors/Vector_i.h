#include "Vector.h"

template <typename T>
Vector<T>::Vector() {};

template <typename T>
Vector<T>::Vector(const size_t size)
{
	n = size;
	arr = new T[n]{};
}

template <typename T>
T& Vector<T>::operator [](size_t index) const
{
	if (index >= n || index < 0)
		throw  std::runtime_error("wrong index");

	return arr[index];

}

template<class T>
Vector<T>::Vector(int num, int a, int b)
{
	arr = new T[num];
	for (int i = 0; i < num; i++)
		arr[i] = ((double)rand() / (double)RAND_MAX) * (b - a) + a;

	n = num;

}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
	n = other.n;
	arr = new T[other.n]{};
	for (size_t index = 0; index < n; index++)
	{
		arr[index] = other.arr[index];
	}
}
template <typename T>
Vector<T>::~Vector()
{
    arr = nullptr;
	delete[] arr;
}

template <typename T>
bool Vector<T>::operator==(const Vector& other)
{
	if (n != other.n)
		return false;
	for (size_t index = 0; index < n; ++index)
	{
		if (arr[index] != other.arr[index])
			return false;
	}
	return true;
}

template <typename T>
int Vector<T>::GetN() const
{
	return (int)n;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
	delete[] arr;

	arr = new T[other.GetN()];
	n = other.GetN();

	for (int i = 0; i < n; i++)
	{
		arr[i] = other[i];
	}

	return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Vector<T>& self)
{

	for (size_t index = 0; index < self.n; index++)
		stream << self.arr[index] << std::endl;
	return stream;
}

template <typename T>
std::istream& operator>>(std::istream& stream, Vector<T>& self)
{

	size_t size = 0;

	stream >> size;
	Vector <T> v4(size);
	for (size_t index = 0; index < size; index++)
		stream >> v4[index];
	self = v4;
	return stream;
}

template <typename T>
void Vector<T>::insertionsort()
{
	auto start = high_resolution_clock::now();
	int key, j;

	for (int index = 1; index < n; index++) {
		key = arr[index];
		j = index - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by insertion sort: "
		<< duration.count() << " microseconds" << endl;
}

template <typename T>
void Vector<T>::quicksort()
{
	auto start = high_resolution_clock::now();

	qs(0, (int)(*this).n - 1);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by quick sort: "
		<< duration.count() << " microseconds" << endl;
}

template <typename T>
void Vector<T>::qs(int first, int last)
{

	int i = first, j = last;
	T tmp, x = arr[(first + last) / 2];

	do {
		while (arr[i] < x)
			i++;
		while (arr[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		qs(i, last);
	if (first < j)
		qs(first, j);

}

template <typename T>
Vector<T> Vector<T>::operator+ (const Vector<T>& other)
{
	if (n != other.GetN() || n != other.GetN())
		throw "Vectors aren't equal";

	Vector<T> result(this->n);
	for (int i = 0; i < this->n; i++)
	{
		result[i] = this->arr[i] + other[i];
	}
	return result;

}

template <class T>
Vector<T> Vector<T>::operator- (const Vector<T>& other)
{
	if (n != other.GetN() || n != other.GetN())
		throw "Vectors aren't equal";

	Vector<T> newvector(this->n);
	for (int index = 0; index < this->n; index++)
		newvector[index] = this->arr[index] - other.arr[index];
	return newvector;

}

template <typename T>
Vector<T> Vector<T>::operator* (const Vector& other)
{
	//if (n != other.n)
	 // throw "wrong n";
	Vector<T> newvector(this->n);
	for (int index = 0; index < this->n; index++)
		newvector[index] = this->arr[index] * other.arr[index];
	return newvector;

}

template <typename T>
void Vector<T>::bubblesort()
{
	auto start = high_resolution_clock::now();

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				T element;
				element = arr[i];
				arr[i] = arr[j];
				arr[j] = element;
			}
		}
	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by bubble sort: "
		<< duration.count() << " microseconds" << endl;
}

template<typename T>
inline int Vector<T>::Find(T a)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == a)
			return i;
	return -1;
}

template<typename T>
inline void Vector<T>::FindAll(T a)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] == a)
		{
			cout << "Item found at: [" << i << "]" << endl;
			k = 1;
		}
	if (k == 0)
		cout << "item not found" << endl;
}
