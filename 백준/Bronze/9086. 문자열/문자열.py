T = int(input())
test = []

for i in range(T):
  s = input()
  test.append(s[0]+s[-1])

for j in range(T):
  print(test[j])