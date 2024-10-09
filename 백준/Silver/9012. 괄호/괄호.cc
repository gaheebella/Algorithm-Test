#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	vector<string> v;
	
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;

		stack<string> st; //각 테스트 케이스마다 새로운 스택 생성

		bool isValid = true; //괄호 유효성을 추적하는 변수
		//초기 상태에서는 괄호가 유효하다고 가정하고 시작
		//각 테스트 케이스마다 새롭게 초기화됨
		
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '(')
			{
				st.push("(");
			}
			else if(s[j] == ')')
			{
				if (!st.empty())
				{
					st.pop();
				}
				else //스택이 비어있는데 닫는 괄호가 나왔을 때
				{
					isValid = false;
					break; //반복 중단
				}
			}
		}
		if (isValid && st.empty())
		{
			v.push_back("YES");
		}
		else
		{
			v.push_back("NO");
		}
	}


	for (int k = 0; k < v.size(); k++)
	{
		cout << v[k] << '\n';
	}

	return 0;
}