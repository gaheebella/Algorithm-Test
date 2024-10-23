#include <iostream>
#include <queue>
using namespace std;

int main() 
{
	//입출력 속도 높이기용
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	int N, K, A; //N개의 수 중에서 K번째 수 구하기
	cin >> N >> K;
	
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		pq.push(A);
	}

	for (int j = 0; j < K-1; j++)
	{
		pq.pop();
	}

	cout << pq.top() << endl;

	return 0;
}