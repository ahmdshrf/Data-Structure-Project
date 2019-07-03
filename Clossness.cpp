#include <iostream>
#include <vector> 
#include <list>
#include <queue> 
#include <functional>
#include <iomanip>
# define INF 0x3f3f3f3f 

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
	// Recursive Function that sum an array elements
	int findSum(vector<int> A, int N)
	{
		if (N <= 0)
			return 0;
		return (findSum(A, N - 1) + A[N - 1]);
	}

	// Function that Find the Shortest path from a source to every node in the graph 
	// using the Dijkstra Method (Priority queue O(e log n))
	vector<int> dijkstra(int src) {
		priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;
		vector<int> dist(nodes_no, INF);
		pq.push(make_pair(0, src));
		dist[src] = 0;

		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();

			list< pair<int, int> >::iterator i;
			for (i = nodes[u].begin(); i != nodes[u].end(); ++i)
			{
				int v = (*i).first;
				int weight = (*i).second;

				if (dist[v] > dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
		return dist;
	}

	void Closeness_c(list<double>(&result)) {
		for (int i = 0; i < nodes_no; i++)
		{
			int sum = findSum(dijkstra(i), nodes_no);
			double c = (nodes_no - 1) / (double)sum;
			result.push_back(c);
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
	
	// Run the Closeness Centrailty
	g.Closeness_c(result);

	for (auto v : result)
		cout << setprecision(8) << v << "\n";
}
