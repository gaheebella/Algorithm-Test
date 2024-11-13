N, M = map(int, input().split())
bags = []

for idx in range(N):
  bags.append(idx + 1)

for k in range(M):
  i, j = map(int, input().split())
  temp = bags[i-1]
  bags[i-1] = bags[j-1]
  bags[j-1] = temp

print(*bags)