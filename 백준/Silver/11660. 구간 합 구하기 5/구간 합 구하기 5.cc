#include <iostream>
#include <vector>
using namespace std;

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> A(N+1, vector<int>(N+1, 0));
    vector<vector<int>> D(N+1, vector<int>(N+1, 0));
    //vector<int> : int를 여러개 담는 1차원 동적 배열
    //vector<vector<int>> : vector<int> 를 여러개 담는 2차원 구조
    //즉, A는 행들의 모음, 각 행은 vector<int>
    //A(개수, 초기값) : 원소를 개수만큼 만들고, 각 원소를 초기값으로 채움
    // vector<int>(N+1,0) : 길이가 N+1인 vector<int> 1개를 만들고, 모든칸을 0으로 채운 1차원 벡터 생성
    //A는 (N+1) x (N+1) 크기의 2차원 배열
    
// i와 j가 1부터 시작하지 않으면, 음수 인덱스 접근 발생
    for(int i= 1; i <= N; i++)
    {   
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            D[i][j] = D[i][j-1] + A[i][j] +D[i-1][j] - D[i-1][j-1];
        }
    }
   
    for (int i = 0; i < M; i++)
    {
       int x1, y1, x2, y2;
       cin >> x1 >> y1 >> x2 >> y2;
       
       int sum = D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1];
        
       cout << sum <<"\n";
    }
}