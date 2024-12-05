#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;

void unionFunc(int a, int b);
bool checkSame(int a, int b); //두 원소가 같은 집합인지 확인
int findFunc(int a); //대표노드 찾기

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n, m;
	cin >> n >> m;
	parent.resize(n + 1);
	
	//대표노드 배열을 자기 자신으로 초기화
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int k, a, b;
		cin >> k >> a >> b;
		if (k == 0) //union
		{
			unionFunc(a, b);
		}
		else //k==1
		{
			if (checkSame(a, b)) { //두 원소가 같은 집합 안에 속했는지 확인
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
		
	}
}

void unionFunc(int a, int b) {
	a = findFunc(a); //a의 대표노드
	b = findFunc(b); //b의 대표노드
	
	if (a != b) //대표노드가 다를 때
	{
		parent[b] = a; //대표노드끼리 연결
	}
}

int findFunc(int a) { //find연산: 자신이 속한 집합의 대표노드 찾기
	if (a == parent[a])
	{
		return a;
	}
	else
	{ 
		return parent[a] = findFunc(parent[a]); //재귀함수
	}
}

bool checkSame(int a, int b) { 
	a = findFunc(a);
	b = findFunc(b);

	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}