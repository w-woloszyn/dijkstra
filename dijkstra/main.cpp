#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<utility>
#include<set>

using namespace std;

int main()
{
	int n; //number of vertices
	string line;
	int tail;
	int head;
	int length;

	cin >> n;
	cin.ignore();

	vector<vector< pair<int, int> > > neighbours(n); // index - vertex id, first int - neighbour, second id - edge length

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

	return 0;
}