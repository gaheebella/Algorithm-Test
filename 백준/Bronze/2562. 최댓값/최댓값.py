myList = []

for i in range(9):
  x = int(input())
  myList.append(x)

for i in range(len(myList)):
  if (myList[i] == max(myList)):
    print(max(myList))
    print(i+1)
  else:
    continue