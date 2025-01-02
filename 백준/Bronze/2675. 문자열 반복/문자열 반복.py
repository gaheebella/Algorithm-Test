T = int(input())
result = []

for i in range(T):
  test = input().split()
  R = int(test[0])
  S = test[1]
  repeated = "".join(x * R for x in S)
  result.append(repeated)

for output in result:
  print(output)