//Topological Sort Using DFS
#include<iostream>
#include<list>
#include<stack>
#include<cstring>
#include<iomanip> // for setting precision
#include<sys/time.h> //for implementing timeval
#include<cstring>
using namespace std;

class Graph
{
public:
  int numV; //number of vertices in graph
  list<int> *prtArr;//pointer to an array of adjacency list
public:
  Graph(int numV);
  void insertEdge(int v, int w);
  void topologicalSort();
  void topologicalSortProcedure(int v, bool visited[], stack<int> &stack); //procedure which uses DFS
};

//initialize graph
Graph::Graph(int numV){
  this->numV = numV;
  prtArr = new list<int>[numV]; //array of adjacency list
}

void Graph::insertEdge(int v, int w){
  prtArr[v].push_back(w);
}

void Graph::topologicalSort()
{
  stack<int> stack;
  bool *visited = new bool[numV];
  for(int i=0;i<numV;i++){
    visited[i] = false;
  }
  for(int i=0;i<numV;i++){
    if(visited[i] == false){
      topologicalSortProcedure(i,visited,stack);
    }
  }
  while(stack.empty() == false){
    cout << stack.top() << " ";
    stack.pop();
  }
  cout << "\n";
}

void Graph::topologicalSortProcedure(int v, bool visited[], stack<int> &stack)
{
  visited[v] = true;
  list<int>::iterator itr;
  for(itr = prtArr[v].begin(); itr != prtArr[v].end(); itr++){
    if(visited[*itr] == false){
      topologicalSortProcedure(*itr, visited, stack);
    }
  }
  stack.push(v);//push the vertex only after applying topologicalSort on all its adjacent vertices
}


int main(void)
{
        int n;
	cout<<"enter the number of edges you want to enter\n";
	cin>>n;
        Graph G(n); //initialize graph with number of vertices
	for(int i=0;i<n;i++){
	int v1,v2;
	cout<<"enter the vertex1---->vertex2 note:-start edge with zero\n "; 
	cin>>v1>>v2;
	G.insertEdge(v1,v2); 
	}
  	/*G.insertEdge(0, 1); //add the edges to form adjacency list
  	G.insertEdge(0, 2);
  	G.insertEdge(1, 3);
  	G.insertEdge(1, 4);
  	G.insertEdge(3, 4);
  	G.insertEdge(2, 4); */
    cout << "Topological Sort of the Given Graph \n";
    struct timeval tvalStart, tvalEnd; //create struct timeval type variables
    gettimeofday(&tvalStart,NULL);
    G.topologicalSort();
    gettimeofday(&tvalEnd,NULL);
    double time_taken = (tvalEnd.tv_sec - tvalStart.tv_sec) * 1e6;
    time_taken =  (time_taken + tvalEnd.tv_usec - tvalStart.tv_usec) * 1e-6;
    cout << "Using timeval, Elapsed Time: " << fixed << (time_taken * 1e6) << " micro seconds\n" << setprecision(6);
    return 0;
}
