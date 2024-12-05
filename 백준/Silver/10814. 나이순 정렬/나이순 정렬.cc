#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first; //나이 오름차순
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, string>> p;

	for (int i = 0; i < N; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		p.push_back({age, name});
	}

	stable_sort(p.begin(), p.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << p[i].first << ' ' << p[i].second << "\n";
	}

	return 0;
}