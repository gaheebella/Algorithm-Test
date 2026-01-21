#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int scores[1000];
    
    for (int i = 0; i < N; i++)
    {
        cin >> scores[i];
    }
    
    long sum = 0;
    long max = 0;
    
    for (int i = 0; i < N; i ++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }
        sum += scores[i];
    }
    
    double average = sum * 100.0 / max / N;
    cout << average;
    

}