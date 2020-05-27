#include<iostream>
#include<list>
#include<queue>
#include<string>
#include<vector>
using namespace std;

struct weight
{
	int sv, ev, wt;
};
class Graph
{
	int V;
	list<int>* adj;
	int size = 0;
	vector<weight> wtType;
	void DFSUtil(int v, bool visited[]);
	void BFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int v, int w, int weight);
	void DFS();
	void DFSAtVertex(int v);
	void BFSAtVertex(int v);
	void BFS();
	int calcweight(int v, int w);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int r, int w)
{
	weight wt1;
	wt1.sv = v;
	wt1.ev = r;
	wt1.wt = w;
	wtType.push_back(wt1);
	size++;
	adj[v].push_back(r);
}

int Graph::calcweight(int v, int w)
{
	for (int i = 0; i < size; i++)
	{
		if (wtType[i].sv == v && wtType[i].ev == w)
		{
			return wtType[i].wt;
		}
	}
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i])
		{
			DFSUtil(*i, visited);
		}
	}
}

void Graph::BFSUtil(int v, bool visited[])
{
	visited[v] = true;
	queue<int> vertex;
	while (!vertex.empty())
	{
		vertex.pop();
	}
	vertex.push(v);
	list<int>::iterator i;
	while (!vertex.empty())
	{
		v = vertex.front();
		cout << v << " ";
		vertex.pop();
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				vertex.push(*i);
			}
		}
	}
}

void Graph::BFS()
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			BFSUtil(i, visited);
	}
}

void Graph::DFS()
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			DFSUtil(i, visited);
	}
}

void Graph::DFSAtVertex(int v)
{
	cout << "\nFollowing is Depth First Traversal At Vertex " << v << " \n";
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	DFSUtil(v, visited);
}

void Graph::BFSAtVertex(int v)
{
	cout << "\nFollowing is Depth First Traversal At Vertex " << v << " \n";
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	BFSUtil(v, visited);
}


int main()
{
	Graph g(10);
	int path;
	int head;
	int weight = 0;
	string answer;

	g.addEdge(0, 1, 1);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 4, 3);
	g.addEdge(3, 2, 4);
	g.addEdge(2, 5, 5);
	g.addEdge(5, 7, 6);
	g.addEdge(5, 8, 7);
	g.addEdge(6, 4, 8);
	g.addEdge(6, 7, 9);
	g.addEdge(9, 7, 10);
	g.addEdge(9, 8, 11);

	cout << "Following is Depth First Traversal \n";
	g.DFS();
	cout << endl;
	cout << "Following is Breadth First Traversal \n";
	g.BFS();
	g.DFSAtVertex(0);
	g.BFSAtVertex(0);
	cout << endl;
	cout << "Do you want to calculate the weight of the edges? Please answer Yes or No: ";
	cin >> answer;
	//if the answer is not yes or no
	while (tolower(answer[0]) != 'y' && tolower(answer[0]) != 'n')
	{
		cout << "\nInvalid response! Please enter yes or no: ";
		cin >> answer;
	}
	//if the answer is yes
	if (tolower(answer[0]) == 'y')
	{
		bool cont = true;
		string ans;
		while (cont)
		{
			weight = 0;
			cout << "\nPlease enter the paths of which you want to calculate the total weight of the edges (Enter -999 to stop): \n";
			cin >> head >> path;
			while (path != -999)
			{
				weight += g.calcweight(head, path);
				head = path;
				cin >> path;
			}
			cout << "Weight = " << weight;
			cout << "\nDo you wish to continue? Please answer Yes or No: ";
			cin >> ans;
			//if the answer is not yes or no
			while (tolower(ans[0]) != 'y' && tolower(ans[0]) != 'n')
			{
				cout << "\nInvalid response! Please enter yes or no: ";
				cin >> ans;
			}
			if (tolower(ans[0]) == 'y')
			{
				cont = true;
			}
			else if (tolower(ans[0]) == 'n')
			{
				cont = false;
			}
		}
	}
	else if (tolower(answer[0]) == 'n')
	{
		return 0;
	}
	return 0;
}