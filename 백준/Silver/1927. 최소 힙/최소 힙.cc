#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq; //최소힙
	vector<int> v; //결과값 한 번에 출력

	int N, x;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x > 0) {
			pq.push(x);
		}
		else if (x == 0) {
			if (pq.empty()) {
				v.push_back(0);
			}
			else {
				v.push_back(pq.top());
				pq.pop();
			}
		}
	}

	for (int j = 0; j < v.size(); j++) {
		cout << v[j] << '\n';
	}

	return 0;
}