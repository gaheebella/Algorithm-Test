#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N;
	cin >> N;
	int count[10001] = { 0 }; //0~10000 사이의 숫자를 입력가능하므로, 총 10001개의 요소가 필요함
	int A;

	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		count[A]++;
	}

	for (int j = 0; j <= 10000; j++)
	{
		if (count[j] != 0)
		{
			for (int k = 0; k < count[j]; k++)
			cout << j << "\n";
		}
	}

	return 0;
}