#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int N; //N Operands
	string s; //Postfix notation s
	stack<float> st; //stack -> Due to division, the type is float

	cin >> N;
	cin >> s;
	vector<int> v(N, 0);
	//Dynamic array vector v
	//vector v with a size of N, and it initializes all elements of the vetor to 0

	//각각의 피연산자에 대응하는 숫자 값을 벡터 v 에 입력
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int j = 0; j < s.size(); j++)
	{
		if (s[j] >= 'A' && s[j] <= 'Z') //후위표기식의 문자가 피연산자라면
		{
			st.push((float)v[s[j] - 'A']);
			//후위표기식의 operands 문자가 차례로 대입된 ch를 이용해서 벡터의 인덱스에 접근
			//벡터를 인덱스로 접근했을 때 해당 숫자 값, 즉 operands에 대응되는 숫자를 스택에 push
		}
		else //후위표기식 문자가 연산자라면
		{
			if (!st.empty()) //스택이 비어있지 않다면
			{
				double tmp = st.top(); //임시로 스택의 맨 위에 피연산자를 tmp에 넣어둠
				st.pop(); //맨 위에 피연산자를 pop

				//연산자별로 계산법
				//그 다음 피연산자는 스택에 그대로 둔 채, 맨 위에 있던 피연산자가 들어있는 tmp와 계산 후 다시 tmp에 대입
				if (s[j] == '+')
					tmp = st.top() + tmp;
				else if (s[j] == '-')
					tmp = st.top() - tmp;
				else if (s[j] == '*')
					tmp = st.top() * tmp;
				else if (s[j] == '/')
					tmp = st.top() / tmp;


				//연산을 수행한 뒤
				st.pop(); //그 다음 피연산자도 빼내고
				st.push(tmp); //연산 결과값을 다시 스택에 삽입
			}
		}
	}

	cout << fixed; // 고정 소수점 표기법 (<->지수 표기법)
	cout.precision(2); //소수점 둘째 자리까지 출력
	cout << st.top() << '\n'; //스택에 넣어져있는 연산 결과값 출력

	return 0;
}