N , M = map(int, input().split())
balls = [0] * (N + 1)

for _ in range(M):
  i, j, k = map(int, input().split())
  for w in range(i, j+1):
    balls[w-1] = k #만약 값이 이미 있다면 덮어쓰기

for w in range(N):
  print(balls[w], end= " ")