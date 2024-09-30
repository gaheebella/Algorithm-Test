#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	cin >> S;

	//소문자 a~z까지 처음 등장하는 위치 출력 -> loop사용
	for (char i = 'a'; i <= 'z'; i++)
	{
		//find함수: 소문자 i가 문자열 S에 있는지 찾고, 있다면 처음 등장하는 위치 반환
		if (S.find(i) != string::npos) //문자열에 문자가 포함 되었을 때
		{
			cout << (int)S.find(i) << " ";
		}
		else //포함 안 되었을 때
		{
			cout << "-1" << " ";
		}
	}

	return 0;
}