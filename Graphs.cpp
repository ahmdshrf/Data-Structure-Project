#include <iostream>
#include <vector> 
#include <list>
#include <queue> 

using namespace std;
class Graph
{
	int nodes_no;
	list<pair<int, int>> *nodes;

public:

	Graph(int n) {
		this->nodes_no = n;
		nodes = new list<pair<int, int>>[n];
	}

	void add_node(int from, int to, int weight) {
		nodes[from].push_back(make_pair(to, weight));
		nodes[to].push_back(make_pair(from, weight));
	}
};
