#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<long> S(N, 0); // S : 누적합 배열의 입력 숫자가 N개 (0, 1, 2,..., N-1)
    vector<long> C(M, 0); // C : 누적합을 M으로 나눈 나머지의 개수를 저장하는 배열 (0, 1, 2,..., M-1) 
    
    long answer = 0;
    
    cin >> S[0];
    
    // 입력값(temp)을 받음과 동시에 합배열S 생성
    for (int i = 1; i < N; i++)
    {
        int temp = 0;
        cin >> temp;
        S[i] = S[i-1] + temp;
    }
    
    for (int i = 0; i < N; i++)
    {
        // 미리 구간합 배열의 원소들을 M으로 나눈 나머지로 각각 업데이트
        int remainder = S[i] % M;
        
        // 구간합배열S의 원소(0~i)가 이미 0이라면 정답에 더하기 
        if (remainder == 0)
        {
            answer++;
        }
        
        // 나머지가 같은 인덱스의 수 세기
        C[remainder]++;
    }
    
    // 같은 나머지를 갖는 누적합 쌍의 개수
    // 두 누적합 S[i] 와 S[j] 가 같은 나머지를 가지면, (S[i] - S[j]) % M == 0 이 됨
    // 즉, 같은 나머지를 가진 두 인덱스를 고르면, 그 사이 구간의 합은 M으로 나누어 떨어짐
    
    // M으로 나누므로, 나머지는 (0 ~ M-1)까지 존재 > 각 나머지 i 에 대해, 그 나머지를 가진 누적합이 각각 몇 개 있는지 확인
    for (int i = 0; i < M; i++) 
    {
        if(C[i] > 1) //같은 나머지가 2개 이상 있어야, 두 개를 골라 쌍을 만들 수 있음
        {
            // 조합공식(n개 중에서 2개를 고르는 경우의 수 -> nC2) : C[i] * (C[i] - 1) / 2
            // 조합공식 : nCr = n!/(r! * (n-r)!)
            answer = answer + (C[i] * (C[i] - 1) / 2); 
        }
    }
    
    cout << answer << "\n";
    
    // 전체 로직 흐름
    // 1. 누적합 S 계산
    // 2. S[i] % M 계산
    // 3. 나머지별 개수 카운트 > C 배열에 저장
    // 4. 같은 나머지들끼리 2개씩 묶는 조합 계산
    // 5. 모두 더해서 answer에 누적
    
    
}