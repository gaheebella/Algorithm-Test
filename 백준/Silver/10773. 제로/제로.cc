#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int k;
	cin >> k;
	stack<int> st;
	int sum = 0;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;

		if (num != 0) {
			st.push(num);
		}
		else {
			if (!st.empty()) {
				st.pop();
			}
			else {
				break;
			}
		}
	}

	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum << endl;

	return 0;
}