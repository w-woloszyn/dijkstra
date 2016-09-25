#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<utility>
#include<set>
using namespace std;

const int infty = 1000000;
using graph = vector<vector< pair<int, int> > >;
vector<int> dist;

struct cmp
{
	bool operator() (const int &a, const int &b) const
	{
		if (dist[a] < dist[b])
		{
			return true;
		}
		if (dist[a] > dist[b])
		{
			return false;
		}
		return a < b;
	}
};

vector<int> Dijkstry(graph G, int s)
{
	int u, v, length, alt;
	int size = G.size();
	set<int, cmp> Q; // cmp implies that Q is a heap
	dist.clear();
	dist.resize(size, infty);
	dist[s] = 0;
	
	for (int i = 0; i < size; i++)
	{
		Q.insert(i);
	}

	while (!Q.empty())
	{
		u = *Q.begin();
		Q.erase(Q.begin());
		for (int i = 0; i < G[u].size(); i++)
		{
			v = G[u][i].first;
			length = G[u][i].second;
			alt = dist[u] + length;
			if (alt < dist[v])
			{
				Q.erase(Q.find(v));
				dist[v] = alt;
				Q.insert(v);
			}

		}
	}

	return dist;
}

int main()
{
	int n; //number of vertices
	string line;
	int tail;
	int head;
	int length;

	cin >> n;
	cin.ignore();

	graph neighbours(n); // index - vertex id, first int - neighbour, second id - edge length

	while(getline(cin, line))
	{
		stringstream stream;
		stream << line;
		stream >> tail;
		tail--; // becase C counts from 0
		while(stream >> head)
		{
			stream >> length;
			head--; //beacause C counts from 0
			neighbours[tail].push_back(pair<int,int>(head, length));
		}
	}

	Dijkstry(neighbours, 0);

	return 0;
}