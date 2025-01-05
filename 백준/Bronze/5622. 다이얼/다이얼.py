dial = ["ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"]
S = input()
total = 0

for i in range(len(S)):
  for alpha in dial:
    if S[i] in alpha:
      total += dial.index(alpha) + 3

print(total)