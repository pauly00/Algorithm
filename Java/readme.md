# Java 핵심 문법 정리 (입출력, 자료구조 중심)


## 1. 입력 기본 형태 (BufferedReader)

```java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    }
}
```

핵심

- `throws IOException` 반드시 작성
- Scanner보다 빠름 (코테 기본 입력 방식)

출력은 보통

```java
System.out.println();
```

출력이 많으면

```java
StringBuilder sb = new StringBuilder();
```

사용 권장 (시간 절약)

---

## 2. 한 줄 입력 받기

```java
String line = br.readLine();
```

- 한 줄 전체를 문자열로 입력
- 공백 포함 그대로 저장됨

---

## 3. 공백 기준 여러 값 입력 (split)

```java
String[] arr = br.readLine().split(" ");

int a = Integer.parseInt(arr[0]);
int b = Integer.parseInt(arr[1]);
```

핵심
- 간단하지만 반복 사용 시 느릴 수 있음
- 대량 입력에서는 StringTokenizer 권장

---

## 4. StringTokenizer (권장 방식)

```java
StringTokenizer st = new StringTokenizer(br.readLine());

int a = Integer.parseInt(st.nextToken());
int b = Integer.parseInt(st.nextToken());
```

핵심
- 기본 구분자는 공백
- 반복 입력에서 빠름
- `hasMoreTokens()`로 남은 값 확인 가능

---

## 5. 문자열 처리

```java
String s = br.readLine();

char ch = s.charAt(i);
int len = s.length();
```

자주 사용하는 메서드

```java
s.substring(start, end);
s.indexOf("a");
s.lastIndexOf(".");
```

---

## 6. 스택 (Stack)

```java
Stack<Integer> stack = new Stack<>();

stack.push(10);   // 삽입
stack.pop();      // 제거 + 반환
stack.peek();     // 최상단 조회
stack.isEmpty();  // 비었는지 확인
```

특징
- LIFO 구조

실전에서는 `ArrayDeque`로 스택 구현하는 경우도 많음 (더 빠름)

---

## 7. 큐 (Queue)

```java
Queue<Integer> q = new ArrayDeque<>();

q.add(10);    // 삽입
q.poll();     // 제거 + 반환
q.peek();     // 맨 앞 조회
q.isEmpty();
```

특징
- FIFO 구조
- BFS에서 필수

---

## 8. 우선순위 큐 (PriorityQueue)

```java
PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.add(10);
pq.poll();
pq.peek();
```

특징
- 기본은 최소 힙 (오름차순)

최대 힙

```java
PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
```

시간복잡도
- 삽입 / 삭제 O(log N)

---

## 9. Map

### HashMap

```java
HashMap<String, Integer> map = new HashMap<>();

map.put("apple", 1);
map.get("apple");
map.getOrDefault("banana", 0);
map.containsKey("apple");
```

특징
- 순서 보장 없음
- 평균 O(1)

---

### TreeMap

```java
TreeMap<Integer, String> map = new TreeMap<>();
```

특징
- key 기준 자동 정렬
- O(log N)

---

## 10. 배열 초기화

```java
int[] arr = new int[n];
Arrays.fill(arr, 0);
```

2차원 배열

```java
int[][] arr = new int[n][m];
```

---

## 11. 그래프 (인접 리스트)

```java
List<List<Integer>> graph = new ArrayList<>();

for (int i = 0; i <= n; i++) {
    graph.add(new ArrayList<>());
}

graph.get(a).add(b);
```

무방향 그래프

```java
graph.get(a).add(b);
graph.get(b).add(a);
```

정렬이 필요한 경우

```java
Collections.sort(graph.get(i));
```

---

## 12. 자주 쓰는 import

```java
import java.io.*;
import java.util.*;
```

코테에서는 거의 이 두 줄이면 충분
