import queue

N, X = map(int, input().split())

myList = list(map(int, input().split()))

q = queue.Queue()

for i in range(len(myList)):
  a = int(myList[i])
  if(a < X):
    q.put(a)

while not q.empty():
  print(q.get(), end=" ")