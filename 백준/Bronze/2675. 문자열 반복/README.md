# [Bronze II] 문자열 반복 - 2675

[문제 링크](https://www.acmicpc.net/problem/2675)

### 성능 요약

메모리: 32412 KB, 시간: 32 ms

### 분류

구현, 문자열

### 제출 일자

2025년 1월 2일 20:27:35

### 문제 설명

<p>문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오. 즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다. S에는 QR Code "alphanumeric" 문자만 들어있다.</p>

<p>QR Code "alphanumeric" 문자는 <code>0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:</code> 이다.</p>

### 입력

 <p>첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 각 테스트 케이스는 반복 횟수 R(1 ≤ R ≤ 8), 문자열 S가 공백으로 구분되어 주어진다. S의 길이는 적어도 1이며, 20글자를 넘지 않는다. </p>

### 출력

 <p>각 테스트 케이스에 대해 P를 출력한다.</p>

---

---

### 1. 문제분석 & 이유

중첩 for문

### 2. Pseudo Code

```python
T번의 테스트케이스 입력

for T번 반복:
  반복횟수R, 문자열 S 입력
  for x를 S자체에서 순회:
    x * int(R번) 반복, end="" 출력
  줄넘김 출력
```

---

### 3. 문제점 & 해결방안

1. 정수와 문자열을 한 번에 입력받기
   -> 입력된 데이터를 공백 기준으로 분리한 후, 각 데이터를 필요한 타입으로 변환 (입력값의 개수는 제한이 없음)

data = input().split()

//공백 기준 입력-> data는 문자열 리스트 ex) ['42', 'hello'] 로 저장됨
-> 리스트의 각 요소에 접근

num = int(data[0])

// 첫 번째 입력값을 문자열에서 정수로 변환

text = data[1]

// 두 번째 입력값을 문자열 그대로 사용

2. 리스트는 인덱스를 미리 초기화하지 않으면 특정 인덱스에 값을 바로 할당 불가
   ->값을 추가할 시 append() 사용

3. 문자열의 각 문자를 R번 반복하고 난 결과는 리스트임. 이걸 다시 join()으로 하나의 문자열로 합침.

ex)

```python
R = 2
S = "Hello"
repeated = "".join(x * R for x in S)
print(repeated)
--------------
HHeelllloo
```

### 4. 최종 코드

```python
#1. 문자열리스트와  join() 활용
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


#2. R을 정수가 아닌 문자열로 그냥 받고, 반복 출력할 때 int()를 씌우기
T = int(input())

for _ in range(T):
  R, S = input().split()
  for x in S:
    print(x * int(R), end = "")
  print()

```

### 5. 배운점

join()을 사용하여 반복된 결과를 하나의 문자열로 합치기

repeated = "".join(x \* R for x in S)
