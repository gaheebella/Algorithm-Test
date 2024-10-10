#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string c;
	
	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		cin >> c;
		
		if (c == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (c == "pop") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (c == "size") {
			cout << q.size() << '\n';
		}
		else if (c == "empty") {
			if (q.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (c == "front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (c == "back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
	}

	return 0;
}