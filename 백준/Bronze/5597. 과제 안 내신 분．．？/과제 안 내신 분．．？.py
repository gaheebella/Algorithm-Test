students = [i for i in range(1, 31)]

for _ in range(28):
  x = int(input())
  students.remove(x)

print(min(students))
print(max(students))