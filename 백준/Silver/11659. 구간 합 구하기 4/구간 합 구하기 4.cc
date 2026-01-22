#include <iostream>
using namespace std;

int main()
{
    //시간단축
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    int S[100001] = {};
    S[0] = 0; //초기값

    //i부터 j까지 누적합을 미리 계산
    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        //1번째부터 (i-1)번째까지의 합 S[i-1] + i번째 수 temp = 1번째부터 i번째까지의 합 S[i]
        //S[i] = (1 ~ i-1까지의 합) + (i번째 수)
        //S[0] = 0 이고, 배열의 1번째 인덱스부터 누적합이 N개 채워짐
        //S[1] = S[0] + temp;
        S[i] = S[i-1] + temp; //누적합
    }
    
    for (int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start - 1] << '\n';
    }
    
    
    return 0;
}