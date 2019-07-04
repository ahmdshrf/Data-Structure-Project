#include <iostream>
#include <vector> 
#include <list>
#include <queue> 
#include <functional>
#include <iomanip>

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
	void Degree_c(list<double>(&result)) {
		for (size_t i = 0; i < nodes_no; i++)
		{
			result.push_back(nodes[i].size());
		}
	}
};
int main()
{
	list<double> result;
	// read number of nodes and edges 
	int n; long e;
	cin >> n >> e;
	
	// create the graph 
	Graph g(n);
	int a, b, c;
	for (size_t i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		g.add_node(a, b, c);
	}
	
	// Run the Degree Centrailty
	g.Degree_c(result); 

	for (auto v : result)
		cout << setprecision(8) << v << "\n";
}