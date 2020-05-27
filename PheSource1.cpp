#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cassert>
using namespace std;

//********************struct nodeType********************
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

//*****************  class linkedListIterator ****************
template <class Type>
class linkedListIterator
{
public:
	linkedListIterator()
	{
		current = nullptr;
	}
	//Default constructor
	//Postcondition: current = nullptr;

	linkedListIterator(nodeType<Type>* ptr)
	{
		current = ptr;
	}
	//Constructor with a parameter.
	//Postcondition: current = ptr;

	Type operator*()
	{
		return current->info;
	}
	//Function to overload the dereferencing operator *.
	//Postcondition: Returns the info contained in the node.

	linkedListIterator<Type> operator++()
	{
		current = current->link;
		return *this;
	}
	//Overload the pre-increment operator.
	//Postcondition: The iterator is advanced to the next 
	//               node.

	bool operator==(const linkedListIterator<Type>& right) const
	{
		return (current == right.current);
	}
	//Overload the equality operator.
	//Postcondition: Returns true if this iterator is equal to 
	//               the iterator specified by right, 
	//               otherwise it returns the value false.

	bool operator!=(const linkedListIterator<Type>& right) const
	{
		return (current != right.current);
	}
	//Overload the not equal to operator.
	//Postcondition: Returns true if this iterator is not  
	//               equal to the iterator specified by  
	//               right; otherwise it returns the value 
	//               false.

private:
	nodeType<Type>* current; //pointer to point to the current 
							 //node in the linked list
};

//*****************  class linkedListType   ****************
template <class Type>
class linkedListType
{
public:
	const linkedListType<Type>& operator=(const linkedListType<Type>& otherList)
	{
		if (this != &otherList) //avoid self-copy
		{
			copyList(otherList);
		}//end else

		return *this;
	}
	//Overload the assignment operator.

	void initializeList()
	{
		destroyList(); //if the list has any nodes, delete them
	}
	//Initialize the list to an empty state.
	//Postcondition: first = nullptr, last = nullptr, count = 0;

	bool isEmptyList() const
	{
		return(first == nullptr);
	}
	//Function to determine whether the list is empty. 
	//Postcondition: Returns true if the list is empty,
	//               otherwise it returns false.

	void print() const
	{
		nodeType<Type>* current; //pointer to traverse the list

		current = first;    //set current so that it points to 
							//the first node
		while (current != nullptr) //while more data to print
		{
			cout << current->info << " ";
			current = current->link;
		}
	}//end print
	//Function to output the data contained in each node.
	//Postcondition: none

	int length() const
	{
		return count;
	}  //end length
	//Function to return the number of nodes in the list.
	//Postcondition: The value of count is returned.

	void destroyList()
	{
		nodeType<Type>* temp;   //pointer to deallocate the memory
								//occupied by the node
		while (first != nullptr)   //while there are nodes in the list
		{
			temp = first;        //set temp to the current node
			first = first->link; //advance first to the next node
			delete temp;   //deallocate the memory occupied by temp
		}
		last = nullptr; //initialize last to nullptr; first has already
						//been set to nullptr by the while loop
		count = 0;
	}
	//Function to delete all the nodes from the list.
	//Postcondition: first = nullptr, last = nullptr, count = 0;

	Type front() const
	{
		assert(first != nullptr);

		return first->info; //return the info of the first node	
	}//end front
	//Function to return the first element of the list.
	//Precondition: The list must exist and must not be 
	//              empty.
	//Postcondition: If the list is empty, the program
	//               terminates; otherwise, the first 
	//               element of the list is returned.

	Type back() const
	{
		assert(last != nullptr);

		return last->info; //return the info of the last node	
	}//end back
	//Function to return the last element of the list.
	//Precondition: The list must exist and must not be 
	//              empty.
	//Postcondition: If the list is empty, the program
	//               terminates; otherwise, the last  
	//               element of the list is returned.

	bool search(const Type& searchItem) const
	{
		nodeType<Type>* current; //pointer to traverse the list
		bool found = false;

		current = first; //set current to point to the first 
						 //node in the list

		while (current != nullptr && !found)    //search the list
			if (current->info == searchItem) //searchItem is found
				found = true;
			else
				current = current->link; //make current point to
										 //the next node
		return found;
	}//end search
	 //Function to determine whether searchItem is in the list.
	 //Postcondition: Returns true if searchItem is in the 
	 //               list, otherwise the value false is 
	 //               returned.

	void insertFirst(const Type& newItem)
	{
		nodeType<Type>* newNode; //pointer to create the new node

		newNode = new nodeType<Type>; //create the new node

		newNode->info = newItem;    //store the new item in the node
		newNode->link = first;      //insert newNode before first
		first = newNode;            //make first point to the
									//actual first node
		count++;                    //increment count

		if (last == nullptr) //if the list was empty, newNode is also the last node in the list
		{
			last = newNode;
		}
	}//end insertFirst
	 //Function to insert newItem at the beginning of the list.
	 //Postcondition: first points to the new list, newItem is
	 //               inserted at the beginning of the list,
	 //               last points to the last node in the  
	 //               list, and count is incremented by 1.

	void insertLast(const Type& newItem)
	{
		nodeType<Type>* newNode; //pointer to create the new node

		newNode = new nodeType<Type>; //create the new node

		newNode->info = newItem;  //store the new item in the node
		newNode->link = nullptr;     //set the link field of newNode
									 //to nullptr

		if (first == nullptr)  //if the list is empty, newNode is 
							   //both the first and last node
		{
			first = newNode;
			last = newNode;
			count++;        //increment count
		}
		else    //the list is not empty, insert newNode after last
		{
			last->link = newNode; //insert newNode after last
			last = newNode; //make last point to the actual 
							//last node in the list
			count++;        //increment count
		}
	}//end insertLast
	 //Function to insert newItem at the end of the list.
	 //Postcondition: first points to the new list, newItem 
	 //               is inserted at the end of the list,
	 //               last points to the last node in the 
	 //               list, and count is incremented by 1.

	void deleteNode(const Type& deleteItem)
	{
		nodeType<Type>* current; //pointer to traverse the list
		nodeType<Type>* trailCurrent; //pointer just before current
		bool found;

		if (first == nullptr)    //Case 1; the list is empty. 
			cout << "Cannot delete from an empty list."
			<< endl;
		else
		{
			if (first->info == deleteItem) //Case 2 
			{
				current = first;
				first = first->link;
				count--;
				if (first == nullptr)    //the list has only one node
					last = nullptr;
				delete current;
			}
			else //search the list for the node with the given info
			{
				found = false;
				trailCurrent = first;  //set trailCurrent to point
									   //to the first node
				current = first->link; //set current to point to 
									   //the second node

				while (current != nullptr && !found)
				{
					if (current->info != deleteItem)
					{
						trailCurrent = current;
						current = current->link;
					}
					else
						found = true;
				}//end while

				if (found) //Case 3; if found, delete the node
				{
					trailCurrent->link = current->link;
					count--;

					if (last == current)   //node to be deleted 
										   //was the last node
						last = trailCurrent; //update the value 
											 //of last
					delete current;  //delete the node from the list
				}
				else
					cout << "The item to be deleted is not in "
					<< "the list." << endl;
			}//end else
		}//end else
	}//end deleteNode
	 //Function to delete deleteItem from the list.
	 //Postcondition: If found, the node containing 
	 //               deleteItem is deleted from the list.
	 //               first points to the first node, last
	 //               points to the last node of the updated 
	 //               list, and count is decremented by 1.

	linkedListIterator<Type> begin()
	{
		linkedListIterator<Type> temp(first);

		return temp;
	}
	//Function to return an iterator at the begining of the 
	//linked list.
	//Postcondition: Returns an iterator such that current is
	//               set to first.

	linkedListIterator<Type> end()
	{
		linkedListIterator<Type> temp(nullptr);

		return temp;
	}
	//Function to return an iterator one element past the 
	//last element of the linked list. 
	//Postcondition: Returns an iterator such that current is
	//               set to nullptr.

	linkedListType()
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	//default constructor
	//Initializes the list to an empty state.
	//Postcondition: first = nullptr, last = nullptr, count = 0; 

	linkedListType(const linkedListType<Type>& otherList)
	{
		first = nullptr;
		copyList(otherList);
	}//end copy constructor
	//copy constructor

	~linkedListType()
	{
		destroyList();
	}//end destructor
	//destructor
	//Deletes all the nodes from the list.
	//Postcondition: The list object is destroyed. 
protected:
	int count;   //variable to store the number of 
				 //elements in the list
	nodeType<Type>* first; //pointer to the first node of the list
	nodeType<Type>* last;  //pointer to the last node of the list

private:
	void copyList(const linkedListType<Type>& otherList)
	{
		nodeType<Type>* newNode; //pointer to create a node
		nodeType<Type>* current; //pointer to traverse the list

		if (first != nullptr) //if the list is nonempty, make it empty
			destroyList();

		if (otherList.first == nullptr) //otherList is empty
		{
			first = nullptr;
			last = nullptr;
			count = 0;
		}
		else
		{
			current = otherList.first; //current points to the 
									   //list to be copied
			count = otherList.count;

			//copy the first node
			first = new nodeType<Type>;  //create the node

			first->info = current->info; //copy the info
			first->link = nullptr;        //set the link field of 
										  //the node to nullptr
			last = first;              //make last point to the
									   //first node
			current = current->link;     //make current point to
										 //the next node

										 //copy the remaining list
			while (current != nullptr)
			{
				newNode = new nodeType<Type>;  //create a node
				newNode->info = current->info; //copy the info
				newNode->link = nullptr;       //set the link of 
											   //newNode to nullptr
				last->link = newNode;  //attach newNode after last
				last = newNode;        //make last point to
									   //the actual last node
				current = current->link;   //make current point 
										   //to the next node
			}//end while
		}//end else
	}//end copyList
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and
	//               assigned to this list.
};
//********************class queueADT********************
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
//********************class queueType********************
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
		for (int i = queueFront; i <= queueRear; i = (i + 1) % maxQueueSize)
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
			for (int i = queueFront; i <= queueRear; i = (i + 1) % maxQueueSize)
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



//********************class graphType********************
class graphType
{
protected:
	int maxSize;    //maximum number of vertices
	int gSize;      //current number of vertices
	linkedListType<int>* graph; //array to create adjacency lists 

public:
	bool isEmpty() const
	{
		return (gSize == 0);
	}
	//Function to determine whether the graph is empty.
	//Postcondition: Returns true if the graph is empty; otherwise, returns false.

	void createGraph()
	{
		ifstream infile;
		infile.open("data.txt");

		int index;
		int vertex;
		int adjacentVertex;

		if (gSize != 0)	//if the graph is not empty, make it empty
			clearGraph();

		if (!infile)
		{
			cout << "Cannot open input file." << endl;
			return;
		}

		infile >> gSize;	//get the number of vertices
		cout << "Number of Vertices: " << gSize << endl;

		for (index = 0; index < gSize; index++)
		{
			infile >> vertex;
			infile >> adjacentVertex;

			cout << "Vertex: " << vertex << "\t";
			if (adjacentVertex != -999)
				cout << "Adjacent Vertex: " << adjacentVertex << " ";

			while (adjacentVertex != -999)
			{
				graph[vertex].insertLast(adjacentVertex);
				infile >> adjacentVertex;
				if (adjacentVertex != -999)
					cout << adjacentVertex << " ";
			} //end while
			cout << endl;
		} // end for

		infile.close();
	} //end createGraph
	  //Function to create a graph.
	  //Postcondition: The graph is created using the  
	  //               adjacency list representation.

	void clearGraph()
	{
		int index;

		for (index = 0; index < gSize; index++)
			graph[index].destroyList();

		gSize = 0;
	} //end clearGraph
	  //Function to clear graph.
	  //Postcondition: The memory occupied by each vertex 
	  //               is deallocated.

	void printGraph() const
	{
		int index;

		for (index = 0; index < gSize; index++)
		{
			cout << index << " ";
			graph[index].print();
			cout << endl;
		}

		cout << endl;
	} //end printGraph
	  //Function to print graph.
	  //Postcondition: The graph is printed.

	void breadthFirstTraversal()
	{
		bool* visited = new bool[gSize]; //pointer to create the array to keep track of the visited vertices
		int index;

		for (index = 0; index < gSize; index++)
			visited[index] = false;

		//For each vertex that is not visited, do a depth first traverssal
		for (index = 0; index < gSize; index++)
		{
			if (!visited[index])
			{
				bft(index, visited);
			}
		}
		delete[] visited;
	}

	void depthFirstTraversal()
	{
		bool* visited = new bool[gSize]; //pointer to create the array to keep track of the visited vertices
		int index;
		for (index = 0; index < gSize; index++)
			visited[index] = false;

		//For each vertex that is not visited, do a depth first traverssal
		for (index = 0; index < gSize; index++)
		{
			if (!visited[index])
			{
				dft(index, visited);
			}
		}
		delete[] visited;
	} //end depthFirstTraversal
	  //Function to perform the depth first traversal of
	  //the entire graph.
	  //Postcondition: The vertices of the graph are printed 
	  //               using depth first traversal algorithm.

	void dftAtVertex(int vertex)
	{
		bool* visited;

		visited = new bool[gSize];

		for (int index = 0; index < gSize; index++)
			visited[index] = false;

		dft(vertex, visited);

		delete[] visited;
	} // end dftAtVertex
	  //Function to perform the depth first traversal of 
	  //the graph at a node specified by the parameter vertex.
	  //Postcondition: Starting at vertex, the vertices are 
	  //               printed using depth first traversal 
	  //               algorithm.

	void bftAtVertex(int vertex)
	{
		bool* visited;

		visited = new bool[gSize];

		for (int index = 0; index < gSize; index++)
			visited[index] = false;

		bft(vertex, visited);

		delete[] visited;
	} // end dftAtVertex
	  //Function to perform the depth first traversal of 
	  //the graph at a node specified by the parameter vertex.
	  //Postcondition: Starting at vertex, the vertices are 
	  //               printed using depth first traversal 
	  //               algorithm.


	graphType(int size = 0)
	{
		maxSize = size;
		gSize = 0;
		graph = new linkedListType<int>[size];
	}
	//Constructor
	//Postcondition: gSize = 0; maxSize = size;
	//               graph is an array of pointers to linked
	//               lists.

	~graphType()
	{
		clearGraph();
	}
	//Destructor
	//The storage occupied by the vertices is deallocated.



private:
	void dft(int v, bool visited[])
	{
		visited[v] = true; //update the status
		cout << " " << v << " ";  //visit the vertex

		linkedListIterator<int> graphIt;

		//for each vertex u adjacent to v
		for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
		{
			int w = *graphIt;
			if (!visited[w])
				dft(w, visited);
		} //end loop
	} //end dft
	  //Function to perform the depth first traversal of 
	  //the graph at a node specified by the parameter vertex.
	  //This function is used by the public member functions
	  //depthFirstTraversal and dftAtVertex.
	  //Postcondition: Starting at vertex, the vertices are 
	  //               printed using depth first traversal 
	  //               algorithm.
	void bft(int v, bool visited[])
	{
		queueType<int> adj;
		adj.initializeQueue();
		visited[v] = true; //update the status
		adj.addQueue(v); //add the vertex to queue

		linkedListIterator<int> graphIt;

		while (!adj.isEmptyQueue()) //recursive
		{
			v = adj.front();
			cout << " " << v << " ";  //visit the vertex
			adj.deleteQueue();
			//for each vertex adjacent to v
			for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
			{
				int w = *graphIt;
				if (!visited[w])
				{
					visited[w] = true; //update the status
					adj.addQueue(w); //add the vertex to queue
				}
			}

		}
	} //end dft
	  //Function to perform the depth first traversal of 
	  //the graph at a node specified by the parameter vertex.
	  //This function is used by the public member functions
	  //depthFirstTraversal and dftAtVertex.
	  //Postcondition: Starting at vertex, the vertices are 
	  //               printed using depth first traversal 
	  //               algorithm.
};

//********************main function********************
int main()
{
	//Program Header
	cout << "Project_7" << endl;
	cout << "Long Beach City College" << endl;
	cout << "Author: Chandaralong" << endl;
	cout << "May. 20, 2020" << endl;
	cout << "======================================================================" << endl;

	cout << "GRAPH Traversal" << endl;
	cout << "===============" << endl;
	graphType myGraph(50);

	myGraph.createGraph();
	cout << endl << endl;

	cout << "Depth First Traversal: ";
	myGraph.depthFirstTraversal();
	cout << endl;

	cout << "Breadth First Traversal: ";
	myGraph.breadthFirstTraversal();
	cout << endl;

	cout << "Breadth First Traversal At Vertex 1: ";
	myGraph.bftAtVertex(3);
	cout << endl;

	return 0;
}