#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void clear();
	void insert(T data,int index);
	void pop_front();
	void push_back(T data);
	void push_front(T data);
	void remove(int index);
	void pop_back();
	int Size() { return size; }

	T& operator[](const int &index);

private:

	template<typename T>
	class Node 
	{
	public:
		Node* pNext;
		T data;
		Node(T data=T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T> *head;
	int size;
};


template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::insert(T data,int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* tmp = head;

		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->pNext;
		}

		Node<T>* newNode = new Node<T>(data, tmp->pNext);

		tmp->pNext = newNode;
		size++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;

	delete temp;
	size--;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}

	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::remove(int index)
{
	if (index == 0)
	{
		pop_front();
	}

	else
	{
		Node<T>* tmp = head;
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->pNext;
		}
		Node<T> *to_del = tmp->pNext;

		tmp->pNext = to_del->pNext;

		delete to_del;
		size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	remove(size - 1);
}

template<typename T>
T& List<T>::operator[](const int &index)
{
	Node<T>* current = this->head;
	int counter = 0;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		else
		{
			current = current->pNext;
			counter++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	List<int> arr;
	int size_t = 10;
	
	for (int i = 0; i < size_t; i++)
	{	
		arr.push_back(rand() % 10);
		cout << arr[i] << " | ";
	}

	return 0;
}
