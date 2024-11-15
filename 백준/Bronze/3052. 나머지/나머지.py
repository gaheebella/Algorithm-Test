remain = []

for _ in range(10):
  x = int(input())
  remain.append(x % 42)

print(len(set(remain)))