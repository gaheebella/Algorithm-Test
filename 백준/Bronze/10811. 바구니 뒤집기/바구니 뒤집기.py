N, M = map(int, input().split())

bags = []

for i in range(N):
  bags.append(i+1)

for k in range(M):
  i, j = map(int, input().split())
  bags[i-1:j] = bags[i-1 : j][::-1]

print(*bags)