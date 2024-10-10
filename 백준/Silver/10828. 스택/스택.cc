#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;

	stack<int> st;

	for (int i = 0; i < N; i++)
	{
		cin >> s;

		if (s == "push") {
			int num; //push 연산 시, 스택에 넣을 정수
			cin >> num;
			st.push(num);
		}
		else if (s == "pop") {
			if (!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (s == "size") {
			cout << st.size() << '\n';
		}
		else if (s == "empty") {
			if (!st.empty()) {
				cout << "0" << '\n';
			}
			else {
				cout << "1" << '\n';
			}
		}
		else if (s == "top") {
			if (st.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << st.top() << '\n';
			}
		}
	}


	return 0;
}