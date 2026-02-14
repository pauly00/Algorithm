# Java 핵심 문법 정리 (입출력, 자료구조 중심)

## 1. 입력 기본 형태 (BufferedReader)

```java
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    }
}

```

핵심
• `main`에서 `throws IOException` 필요
• 빠른 입력 처리용으로 자주 사용

---

## 2. 한 줄 입력 받기

```java
String line = br.readLine();
```

• 한 줄 전체를 문자열로 입력받음

---

## 3. 공백 기준으로 여러 값 입력

```java
String[] arr = br.readLine().split(" ");

int a = Integer.parseInt(arr[0]);
int b = Integer.parseInt(arr[1]);
```

핵심
• `split(" ")`으로 문자열 분리
• 숫자는 `Integer.parseInt()` 사용

---

## 4. 문자열 토큰 분리 (StringTokenizer)

```java
import java.util.StringTokenizer;

StringTokenizer st = new StringTokenizer(br.readLine());

int a = Integer.parseInt(st.nextToken());
int b = Integer.parseInt(st.nextToken());
```

핵심
• 공백 기준 분리 기본 동작
• 반복적으로 값 꺼낼 때 편리

---

## 5. 문자열에서 문자 하나 가져오기

```java
String s = br.readLine();
char ch = s.charAt(i);
```

핵심
• 인덱스는 0부터 시작

---

## 6. 스택 (Stack)

```java
import java.util.Stack;

Stack<Integer> stack = new Stack<>();

stack.push(10);
stack.pop();
stack.peek();
```

핵심
• 후입선출 (LIFO)

---

## 7. 우선순위 큐 (PriorityQueue)

```java
import java.util.PriorityQueue;

PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.add(10);
pq.poll();
pq.peek();
```

핵심
• 기본은 최소값 기준 정렬

---

## 8. 맵 (Map)

### HashMap

```java
import java.util.HashMap;

HashMap<String, Integer> map = new HashMap<>();

map.put("apple", 1);
map.get("apple");
```

특징
• 순서 보장 없음
• 평균적으로 가장 빠름

---

### TreeMap

```java
import java.util.TreeMap;

TreeMap<Integer, String> map = new TreeMap<>();
```

특징
• key 기준 자동 정렬

---

## 자주 쓰는 import 정리

```java
import java.io.*;
import java.util.*;
```