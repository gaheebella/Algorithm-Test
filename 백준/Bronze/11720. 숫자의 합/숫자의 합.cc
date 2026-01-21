#include <iostream>
using namespace std;

int main(){
int n;
cin >> n;

string numbers;
cin >> numbers;
    
int sum = 0;

for(int i = 0; i < n; i++)
{
    sum += numbers[i] - '0';
}

cout << sum;
}
