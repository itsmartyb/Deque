#include<iostream> 

using namespace std;

// Maximum size of the array deque
#define MAX_SIZE 10'001

template <typename T>
class Deque
{
	T arr[MAX_SIZE];
	int front;
	int back;
	int cap;
	int size;

public:

	Deque();
	Deque(int);
	void  pushFront(const T&);
	void  pushBack(const T&);
	void  popFront();
	void  popBack();
	bool  isFull() const;
	bool  isEmpty() const;
	int getSize() const { return size; }
	int getCap() const { return cap; }
	void printDeque();
	const T& getFront() const;
	T& getFront();
	const T& getBack() const;
	T& getBack();
};

template <typename T>
Deque<T>::Deque()
{
	front = -1;
	back = 0;
	size = 0;
	this->cap = MAX_SIZE;
}

template <typename T>
Deque<T>::Deque(int cap)
{
	if (cap > MAX_SIZE)
		cap = MAX_SIZE;
	front = -1;
	back = 0;
	this->cap = cap;
	size = 0;
}

template <typename T>
bool Deque<T>::isFull() const
{
	return (size == cap);
}

template <typename T>
bool Deque<T>::isEmpty() const
{
	return (front == -1 && size == 0);
}

template <typename T>
void Deque<T>::pushFront(const T& element)
{

	if (isFull())
		throw std::logic_error("Deque is full!");

	if (front == -1)
	{
		front = 0;
		back = 0;
	}

	else if (front == 0)
		front = cap - 1;

	else
		front -= 1;

	arr[front] = element;
	size++;
}

template <typename T>
void Deque<T>::pushBack(const T& element)
{
	if (isFull())
		throw std::logic_error("Deque is full!");
 
	if (front == -1)
	{
		front = 0;
		back = 0;
	}
	else if (back == cap - 1)
		back = 0;

	else
		back += 1;

	arr[back] = element;
	size++;
}

template <typename T>
void Deque<T>::popFront()
{
	
	if (isEmpty())
		throw std::logic_error("Deque is empty!");

	if (front == back)
	{
		front = -1;
		back = -1;
	}
	else if (front == cap - 1)
			front = 0;
	else 
		front += 1;
	
	size--;
}

template <typename T>
void Deque<T>::popBack()
{
	if (isEmpty())
		throw std::logic_error("Deque is empty!");

	if (front == back)
	{
		front = -1;
		back = -1;
	}
	else if (back == 0)
		back = size - 1;
	else
		back -= 1;

	size--;
}

template <typename T>
T& Deque<T>::getFront()
{
	if (isEmpty())
		throw std::logic_error("Deque is empty!");

	return const_cast<T&>(
		static_cast<const Deque<T>&>(*this).getFront()
		);
}

template<typename T>
void Deque<T>::printDeque()
{
	if (front == -1)
	{
		cout << "Deque is empty";
	}
	else
	{
		for (int i = front; i < cap; i++)
		{
			cout << arr[i] << " ";
		}

		for (int i = back; i >= 0; --i)
		{
			cout << arr[i] << " ";
		}
	}
	cout << std::endl;
}

template <typename T>
const T& Deque<T>::getFront() const
{
	if (isEmpty())
		throw std::logic_error("Deque is empty!");

	return arr[front];
}

template <typename T>
const T& Deque<T>::getBack() const
{
	if (isEmpty() || back < 0)
			throw std::logic_error("Deque is empty!");

	return arr[back];
}

template <typename T>
T& Deque<T>::getBack() {

	if (isEmpty() || back < 0)
		throw std::logic_error("Deque is empty!");

	return const_cast<T&>(
		static_cast<const Deque<T>&>(*this).getBack()
		);
}

