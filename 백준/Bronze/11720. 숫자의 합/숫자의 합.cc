#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	string s;
	int sum = 0;

	cin >> N;
	cin >> s;
	//getline(cin, s)를 사용 시 바로 위에 cin>>N 이 개행문자 \n을 남기기 때문에 입력 버퍼에 개행문자가 남아있음
	//이후에 getline이 호출되면 입력 버퍼에 남아있던 개행 문자를 읽어서 빈 문자열을 반환함 -> s에 아무 값도 들어가지 않게 됨
	//공백이 있는 문자열을 입력받는게 아닌 단일 단어를 입력받으므로 cin>>s사용하기

	for (int i = 0; i < N; i++)
	{
		sum += s[i] - '0'; 
		//문자형 숫자의 아스키코드에서 '0'의 아스키코드를 빼서 실제 숫자를 얻음
	}

	cout << sum << endl;

	return 0;
}