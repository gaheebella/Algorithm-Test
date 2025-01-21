P = [1, 1, 2, 2, 2, 8]
I = list(map(int, input().split()))

for i in range(6):
    print(P[i]-I[i], end = " ")