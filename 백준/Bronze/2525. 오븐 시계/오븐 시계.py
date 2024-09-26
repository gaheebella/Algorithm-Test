A , B = map(int, input().split())
C = int(input()) #분단위

A = A + (C // 60) #몫
B = B + (C % 60) #나머지

if (B >= 60):
    A = A + 1
    B = B - 60

if (A >= 24):
    A = A - 24


print(f"{A} {B}")