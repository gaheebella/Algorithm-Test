#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector <pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first; //정렬될 값들 벡터에 저장
		v[i].second = i; //해당 인덱스 저장
	}

	sort(v.begin(), v.end());
	int Max = 0;

	for (int j = 0; j < N; j++)
	{
		if (Max < v[j].second - j) //정렬 전 인덱스 - 정렬 후 인덱스 
		{
			Max = v[j].second - j;
		}
	}

	cout << Max + 1;

	
	return 0;
}