#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template <class Type>
class queueADT
{
public: 
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initializeQueue() = 0;
	virtual void addQueue(const Type& newElement) = 0;
	virtual void deleteQueue() = 0;
	virtual Type front() const = 0;
	virtual Type back() const = 0;
};
template <class Type>
class stackADT
{
public:
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual Type top() const = 0;
	virtual void initializeStack() = 0;
	virtual void push(const Type& newelement) = 0;
	virtual void pop() = 0;
};

template <class Type>
class queueType : public queueADT<Type>
{
private:
	int maxQueueSize;
	int queueFront;
	int queueRear;
	int count;
	Type* list;
public:
	bool isEmptyQueue() const
	{
		return (count == 0);
	}
	bool isFullQueue() const
	{
		return (count == maxQueueSize);
	}
	void initializeQueue() 
	{
		count = 0;
		queueFront = 0;
		queueRear = maxQueueSize - 1;
	}
	void addQueue(const Type& newElement) //Function to add queueElement to the queue.
	{
		if (!isFullQueue())
		{
			queueRear = (queueRear + 1) % maxQueueSize; 
			count++;
			list[queueRear] = newElement;
		}
		else
			cerr << "Cannot add to a full queue." << endl;
	}
	void print()
	{
		for (int i = queueFront; i <= queueRear; i = (i+1) % maxQueueSize)
		{
			cout << list[i] << endl;
		}
	}
	void deleteQueue() //Function to delete element 
	{
		if (!isEmptyQueue())
		{
			queueFront = (queueFront + 1) % maxQueueSize; //using % maxQueueSize to make it a circular array
			count--;
		}
		else
		{
			cerr << "Can't delete from an empty queue." << endl;
		}
	}
	Type front() const
	{
		assert(!isEmptyQueue());
		return list[queueFront];
	}
	Type back() const
	{
		assert(!isEmptyQueue());
		return list[queueRear];
	}
	void copyQueue(const queueType<Type>& otherQueue) //Function to copy other queue
	{
		maxQueueSize = otherQueue.maxQueueSize;
		queueFront = otherQueue.queueFront;
		queueRear = otherQueue.queueRear;

		delete[] list;
		list = new Type[maxQueueSize];

		if (count != 0)
		{
			for (int i = queueFront; i <= queueRear; i = (i+1) % maxQueueSize)
			{
				list[i] = otherQueue.list[i];
			}
		}
	}
	queueType(int queueSize = 100) //constructor...creating queue with maxsize = 100 by default if not initialize
	{
		if (queueSize <= 0)
		{
			cerr << "The size of the array must be positive and bigger than zero.\nCreating an queue of size 100 by default" << endl;
			maxQueueSize = 100;
		}
		else 
		{
			maxQueueSize = queueSize;
		}
		queueFront = 0;
		count = 0;
		queueRear = maxQueueSize - 1;
		list = new Type[maxQueueSize];
	}
	queueType(const queueType<Type>& otherQueue)//copy constructor
	{
		list = NULL;
		copyQueue(otherQueue);
	}
	~queueType() //deconstrutor
	{
		delete[] list;
	}
	const queueType<Type>& operator=(const queueType<Type>& otherQueue) //overloading assignment operator
	{
		if (this != &otherQueue)
		{
			copyQueue(otherQueue);
		}
		return *this;
	}
};

template <class Type>
class stackType : public stackADT<Type>
{
private:
	int maxStackSize;
	int stackTop;
	Type* list;
public:
	void initializeStack()
	{
		stackTop = 0;
	}
	bool isEmptyStack() const
	{
		return(stackTop == 0);
	}
	bool isFullStack() const
	{
		return(stackTop == maxStackSize);
	}
	void push(const Type& newitem)
	{
		if (!isFullStack())
		{
			list[stackTop] = newitem;
			stackTop++;
		}
		else
		{
			cout << "Cannot add an element to a full stack" << endl;
		}
	}
	void pop()
	{
		if (!isEmptyStack())
		{
			stackTop--;
		}
		else
		{
			cout << "Cannot remove an element from an empty stack" << endl;
		}
	}
	Type top() const
	{
		assert(stackTop != 0); //Terminate if stack is empty
		return list[stackTop - 1];

	}
	void print()
	{
		for (int i = 0; i < stackTop; i++)
		{
			cout << list[i] << endl;
		}
	}
	void copyStack(const stackType<Type>& otherstack)
	{
		delete[] list;
		stackTop = otherstack.stackTop;
		maxStackSize = otherstack.maxStackSize;

		list = new Type[maxStackSize];
		for (int i = 0; i < stackTop; i++)
		{
			list[i] = otherstack.list[i];
		}
	}
	stackType(int stackSize = 100) //first constructor
	{
		if (stackSize <= 0)
		{
			cout << "Stack size cannot be negative.\nCreating a stack with a default size of 100" << endl;
			maxStackSize = 100;
		}
		else
		{
			maxStackSize = stackSize;
		}

		stackTop = 0;
		list = new Type[maxStackSize];
	}
	stackType(const stackType<Type>& otherstack) //second constructor of stack from another stack
	{
		list = NULL;
		copyStack(otherstack);
	}
	~stackType() //deconstructor
	{
		delete[] list;
	}

	const stackType<Type>& operator=(const stackType<Type>& otherStack)
	{
		if (this != &otherStack)
		{
			copyStack(otherStack);
		}
		return *this;
	}

	bool operator==(const stackType<Type>& otherStack) const
	{
		if (this == &otherStack)
		{
			return true;
		}
		else
		{
			if (stackTop != otherStack.stackTop)
			{
				return false;
			}
			else
			{
				for (int i = 0; i < stackTop; i++)
				{
					if (list[i] != otherStack.list[i])
					{
						return false;
					}
					return true;
				}
			}
		}
	}
};

int main()
{
	//Program Header
	cout << "Project 3" << endl;
	cout << "Long Beach City College" << endl;
	cout << "Author: Chandaralong Phe" << endl;
	cout << "Apr. 2nd, 2020" << endl;
	cout << "======================================================================" << endl;

	string line;
	cout << "Please Enter a line of texts:" << endl;
	getline(cin, line);

	//Convert each character in string line to lowercase
	for (int i = 0 ; i < line.length(); i++)
	{
		line[i] = tolower(line[i]);
	}
	cout << "\nThe line of text you've entered is: "<< line << endl;

	queueType<char> queue1;
	stackType<char> stack1;

	//add each character into a queue and onto a stack
	for (char c : line)
	{
			stack1.push(c);
			queue1.addQueue(c);
	}


	//Determine whether the line of text is palindrome or not
	bool ispalindrome = true;
	for (int i = 0; i <= (line.length() / 2); i++)
	{
		if (stack1.top() != queue1.front()) //compare between last character on stack with the first character in the queue 
		{
			ispalindrome = false; //if it is not the same set the flag to false
		}
		stack1.pop(); //increment stacktop (delete element from stack)
		queue1.deleteQueue(); //increment queueFront (delete element from queue)
	}
	if (ispalindrome)
	{
		cout << "\nThe line of texts you've entered IS Palindrome." << endl;
	}
	else
	{
		cout << "\nThe line of texts you've entered IS NOT Palindrome." << endl;
	}
	////another way to do it
	//for (int i = 0; i < line.length(); i++)
	//{
	//	if (line[i] != line[(line.length() - 1) - i])
	//	{
	//		ispalindrome = false;
	//	}
	//}
	//if (ispalindrome)
	//{
	//	cout << "The line of texts you've entered is Palindrome." << endl;
	//}
	//else
	//{
	//	cout << "The line of texts you've entered is not Palindrome." << endl;
	//}
}
