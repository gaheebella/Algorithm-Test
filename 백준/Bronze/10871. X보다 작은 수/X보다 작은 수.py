N, X = map(int, input().split())

myList = list(map(int, input().split()))

for i in range(len(myList)):
  if(myList[i] < X):
    print(myList[i], end=" ")