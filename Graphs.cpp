#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;


/*int v = 1000;
int e = 20000;

vector <vector <int>> adj_mat(v, vector<int>(v));
*/



/*void dfs(vector < list<int>> & adjacency_list, vector<bool>visited, int source)
{
	visited[source] = true;
	for (auto itr = adjacency_list[source].begin(); itr != adjacency_list[source].end(); itr++)
	{
		if (!visited[*itr])
			dfs(adjacency_list, visited, *itr);
	}
}*/

void dfs(vector<list<int>>& adjacency_list, int source)
{
	stack <int> to_be_visited;
	vector<bool> visited(adjacency_list.size());
	to_be_visited.push(source);
	visited[source] = true;
	while (!to_be_visited.empty())
	{
		int current_node = to_be_visited.top();
		to_be_visited.pop();
		for (auto itr = adjacency_list[current_node].begin(); itr !=
			adjacency_list[current_node].end(); itr++)
		{
			if (!visited[*itr])
			{
				to_be_visited.push(*itr);
				visited[*itr] = true;
			}
		}
	}
	cout << to_be_visited.top() << " ";
}
void bfs(vector<list<int>>& adjacency_list, int source)
{
	queue<int> to_be_visited;
	vector<bool> visited(adjacency_list.size());
	to_be_visited.push(source);
	visited[source] = true;
	while (!to_be_visited.empty())
	{
		int current_node = to_be_visited.front();
		to_be_visited.pop();
		for (auto itr = adjacency_list[current_node].begin();
			itr != adjacency_list[current_node].end(); itr++)
		{
			if (!visited[*itr])
			{
				to_be_visited.push(*itr);
				visited[*itr] = true;
			}
		}
	}
}
int main()
{
	vector <list <int>> adj_list(5);
	adj_list[0].push_back(1);
	adj_list[0].push_back(2);
	adj_list[0].push_back(3);
	adj_list[1].push_back(0);
	adj_list[1].push_back(2);
	adj_list[2].push_back(3);
	adj_list[2].push_back(0);
	adj_list[2].push_back(1);
	adj_list[2].push_back(4);
	adj_list[3].push_back(0);
	adj_list[3].push_back(2);
	adj_list[3].push_back(4);
	adj_list[4].push_back(3);
	adj_list[4].push_back(2);
	dfs(adj_list, 1);
}

