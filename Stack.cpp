#include <iostream>
#include <cassert>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
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

stackType<int> insertion(string str) // a method for inserting each character into a stack
{
	stackType<int> stack1(50);
	stack1.initializeStack();
	for (char c : str)
	{
		int element;
		if (c >= '0' && c <= '9' && c != '.')
		{
			element = c - '0';
			stack1.push(element);
		}
	}
	return stack1;
}
int intconvert(stackType<int> stack1) // a method to assemble and convert to integer
{
	int num = 0;
	int digit = 1;
	while (!stack1.isEmptyStack())
	{
		num = (stack1.top() * digit) + num;
		stack1.pop();
		digit = digit * 10;
	}
	return num;
}
double decconvert(stackType<int> stack1, string str, int pts) // a method to assemble and convert the decimal number
{
	int n = str.length();
	double dec = 0;
	int dplace = pow(10, (n - pts));
	for (int i = 1; i <= (n - pts); i++)
	{
		dec = ((double)stack1.top() / dplace) + dec;
		stack1.pop();
		dplace = dplace / 10;
	}
	//integer conversion
	double digit = 1;
	while (!stack1.isEmptyStack())
	{
		dec = (stack1.top() * digit) + dec;
		stack1.pop();
		digit = digit * 10;
	}
	return dec;
}

int main()
{   //Program Header
	cout << "Project 2" << endl;
	cout << "Long Beach City College" << endl;
	cout << "Author: Chandaralong Phe" << endl;
	cout << "Mar. 25, 2020" << endl;
	cout << "======================================================================" << endl;

	stackType<int> stacknum(50);
	stacknum.initializeStack();
	bool wnum = true;
	string str;
	int n = str.length();
	int pts = 1;
	cout << "Please Enter a string consist of a positive integer or a positive decimal number: " ;
	cin >> str;
	//identify the location of the decimal point and check if the user enter an int or a decimal number
	for (char c : str)
	{
		if (c != '.')
		{
			pts++;
		}
		else
		{
			wnum = false; //user entered a decimal number
			break;
		}
	}
	if (wnum) // if user input a positive integer
	{
		//putting every digit of number into a stack
		stacknum = insertion(str);
		cout << "\nThe positive integer you've entered is  " << intconvert(stacknum) << endl;
		return 0;
	}
	else // if user input a positive decimal number
	{
		int wholenum = 0;
		double dec = 0;
		//putting every digit of number into a stack
		stacknum = insertion(str);
		//decimal conversion
		dec = decconvert(stacknum, str, pts);
		cout << setprecision(str.length() - pts); 
		cout << "\nThe decimal number you've entered (after conversion) is " << dec << endl;
		return 0;
	}
}


