#pragma once
#include <iostream>

template<typename T>
class Vector
{
private:
	T* elements;
	size_t size;

	void copy(const Vector<T>& others);
	void destroy();
public:
	Vector();
	Vector(const Vector<T>& others);
	Vector<T>& operator=(const Vector<T>& others);
	~Vector();

	Vector<T> operator+(const Vector<T>& others) const;
	Vector<T>& operator+=(const Vector<T>& others);
	T& operator[] (size_t i);
	void push(const T& others);
	void push_back(const T& others);
	void print() const;
	size_t capacity() const;

	//new methods
	T& pop_front(); //removes first element
	T& pop_back(); //removes last element
	void swap(size_t first, size_t second); //swaps two elements
	void insert(size_t place, const T& others); //insert element on "place" position
	void clear(); //remove all elements
	void erase(size_t n); //remove all elements after n-th one
	void memory();
//	std::ostream& operator << (std::ostream& stream, Vector<T> vector);
};



template<typename T>
void Vector<T>::copy(const Vector<T>& others)
{
	this->elements = new T[others.size];
	for (int i = 0; i < others.size; i++)
	{
		this->elements[i] = others.elements[i];
	}
	this->size = others.size;
}

template<typename T>
void Vector<T>::destroy()
{
	delete[] elements;
}

template<typename T>
Vector<T>::Vector()
{
	this->elements = nullptr;
	this->size = 0;
}

template<typename T>
Vector<T>::Vector(const Vector& others)
{
	this->copy(others);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& others)
{
	if (this != &others)
	{
		this->destroy();
		this->copy(others);
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	this->destroy();
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& others) const
{
	Vector<T> result;
	result.size = this->size + others.size;
	result.elements = new T[result.size];
	for (size_t i = 0; i < this->size; i++)
	{
		result.elements[i] = this->elements[i];
	}
	for (size_t i = 0; i < others.size; i++)
	{
		result.elements[this->size + i] = others.elements[i];
	}

	return result;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& others)
{
	T* newBuffer;
	newBuffer = new T[this->size + others.size];
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->elements[i];
	}
	for (size_t i = 0; i < others.size; i++)
	{
		newBuffer[this->size + i] = others.elements[i];
	}
	this->destroy();
	this->size += others.size;
	this->elements = newBuffer;
	return *this;
}

template<typename T>
T& Vector<T>::operator[](size_t i)
{
	return this->elements[i];
}

template<typename T>
void Vector<T>::push(const T& others)
{
	T* newBuffer;
	newBuffer= new T[this->size+1];
	newBuffer[0] = others;
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i + 1] = this->elements[i];
	}
	this->destroy();
	this->size++;
	this->elements = newBuffer;
}

template<typename T>
inline void Vector<T>::push_back(const T& others)
{
	T* newBuffer;
	newBuffer = new T[this->size + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->elements[i];
	}
	newBuffer[this->size] = others;
	this->destroy();
	this->size++;
	this->elements = newBuffer;
}

template<typename T>
void Vector<T>::print() const
{
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << this->elements[i];
	}
}

template<typename T>
size_t Vector<T>::capacity() const
{
	return this->size;
}
//new methods
template<typename T>
T& Vector<T>::pop_front()
{
	T* newBuffer = new T[this->size - 1];
	for (size_t i = 0; i < this->size - 1; i++)
	{
		newBuffer[i] = this->elements[i + 1];
	}
	T popped = this->elements[0];
	this->size--;
	this->destroy();
	this->elements = newBuffer;

	return popped;
}

template<typename T>
T& Vector<T>::pop_back()
{
	T* newBuffer = new T[this->size - 1];
	
	for (size_t i = 0; i < this->size - 1; i++)
	{
		newBuffer[i] = this->elements[i];
	}
	T popped = this->elements[size-1];
	this->size--;
	this->destroy();
	this->elements = newBuffer;

	return popped;
}

template<typename T>
void Vector<T>::swap(size_t first, size_t second)
{
	T temp = this->elements[first];
	this->elements[first] = this->elements[second];
	this -> elements[second] = temp;
}

template<typename T>
void Vector<T>::insert(size_t place, const T& others)
{
	T* newBuffer = new T[this->size + 1];
	this->size++;
	newBuffer[place] = others;
	for (size_t i = 0; i < place; i++)
	{
		newBuffer[i] = this->elements[i];
	}
	for (size_t i = place; i < this->size; i++)
	{
		newBuffer[i + 1] = this->elements[i];
	}
	this->destroy();
	this->elements = newBuffer;
}

template<typename T>
void Vector<T>::clear()
{
	this->destroy();
	this->size = 0;
	this->elements = nullptr;
}

template<typename T>
void Vector<T>::erase(size_t n)
{
	this->size = n;
	T* newBuffer = new T[this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->elements[i];
	}
	this->destroy();
	this->elements = newBuffer;
}
template<typename T>
void Vector<T>::memory()
{
	std::cout << sizeof(*this) << std::endl;
}

template<typename T>
std::ostream& operator << (std::ostream& stream, Vector<T> vector)
{
	vector.print();
	return stream;
}

