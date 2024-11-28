#include <iostream>
#include <vector>
using namespace std;

//우선 병합정렬로 오름차순 만들기
//평균, 중앙값 구하기
//주어지는 숫자 갯수는 5개, 인덱스는 1부터 시작 (1~5)
void mergeSort(int s, int e);
static vector <int> v;
static vector <int> temp;


int main()
{
	v = vector<int>(6, 0); //인덱스가 1부터 시작하므로
	temp = vector<int>(6, 0);

	for (int i = 1; i <= 5; i++)
	{
		cin >> v[i];
	}

	mergeSort(1, 5); //오름차순 병합정렬

	int total = 0;

	for (int i = 1; i <= 5; i++)
	{
		total += v[i];
	}

	cout << total / 5 << "\n"; //평균
	cout << v[3]; //중앙값
}


void mergeSort(int s, int e)
{
	// 요소의 개수가 1개 이하인 경우
	if (e - s < 1)
	{
		return;
	}

	// 요소 개수가 1개 이상일 때
	// 분할
	int m = s + (e - s) / 2; //중앙값 먼저 찾고, 중앙값 기준으로 왼,오른쪽으로 분할
	mergeSort(s, m);
	mergeSort(m + 1, e);

	for (int i = s; i <= e; i++)
	{
		temp[i] = v[i];
	}

	//배열의 현재위치들
	int k = s; //v배열
	int index1 = s; //m의 왼쪽배열
	int index2 = m + 1; //m의 오른쪽배열
	

	while (index1 <= m && index2 <= e)
	{
		if (temp[index1] > temp[index2])
		{
			v[k] = temp[index2];
			k++;
			index2++;
		}
		else
		{
			v[k] = temp[index1];
			k++;
			index1++;
		}
	}

	//한쪽 배열이 먼저 다 정렬되었을 때, 남은배열도 마저 정렬
	while (index1 <= m)
	{
		v[k] = temp[index1];
		k++;
		index1++;
	}
	while (index2 <= e)
	{
		v[k] = temp[index2];
		k++;
		index2++;
	}
}