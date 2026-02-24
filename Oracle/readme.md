# SQL 핵심 키워드 정리 (Oracle 기준)

코딩 테스트에서 자주 사용되는 Oracle SQL 핵심 문법을 정리한 문서입니다.

---

## 1. 조건부 출력 (`CASE`)

조건에 따라 값을 분기하여 출력할 때 사용합니다.

```sql
SELECT 
    CASE 
        WHEN score >= 90 THEN 'A'
        WHEN score >= 80 THEN 'B'
        ELSE 'C'
    END AS grade
FROM RESULTS;
```

주의
`NULL` 비교는 `=` 사용 불가
반드시 `IS NULL`, `IS NOT NULL` 사용

---

## 2. 날짜 및 시간 함수

### 2-1. 날짜 데이터 추출 및 변환

| 함수      | 용도            | 예시                                          |
| ------- | ------------- | ------------------------------------------- |
| EXTRACT | 날짜에서 특정 단위 추출 | `EXTRACT(YEAR FROM HIRE_DATE) = 2024`       |
| TO_CHAR | 날짜를 문자열로 변환   | `TO_CHAR(SYSDATE, 'YYYY-MM-DD HH24:MI:SS')` |

---

## 3. 필터링 연산자

### 3-1. 기본 비교 연산자

`=` 같음
`<>` 다름
`>` `<` `>=` `<=`

### 3-2. 다중 조건 (`IN`)

여러 개의 OR 조건을 간결하게 표현할 때 사용합니다.

```sql
WHERE FLAVOR IN ('melon', 'strawberry', 'chocolate')
```

---

## 4. 정렬 (`ORDER BY`)

결과 집합의 정렬 기준을 지정합니다.

```sql
ORDER BY 
    SALARY DESC,
    HIRE_DATE ASC;
```

ASC는 기본값이므로 생략 가능합니다.

---

## 5. 집계와 필터링 (`WHERE` vs `HAVING`)

| 구분    | WHERE       | HAVING      |
| ----- | ----------- | ----------- |
| 실행 시점 | GROUP BY 이전 | GROUP BY 이후 |
| 대상    | 개별 행        | 그룹          |
| 집계 함수 | 사용 불가       | 사용 가능       |

---

# 6. Oracle 날짜 필터링

## 6-1. 특정 월 조회 (권장 방식)

```sql
WHERE CREATED_DATE >= TO_DATE('2022-10-01', 'YYYY-MM-DD')
  AND CREATED_DATE <  TO_DATE('2022-11-01', 'YYYY-MM-DD')
```

이유

Oracle DATE는 시간까지 포함
`<= 2022-10-31` 방식은 시간 때문에 누락 가능
`< 다음달 1일` 방식이 가장 안전

---

## 6-2. TO_DATE

문자열을 DATE 타입으로 변환

```sql
TO_DATE('2022-10-01', 'YYYY-MM-DD')
```

첫 번째 인자: 날짜 문자열
두 번째 인자: 날짜 형식

Oracle에서는 날짜 비교 시 명시적 변환이 안전합니다.

---

## 6-3. TO_CHAR

DATE → 문자열 변환

```sql
TO_CHAR(CREATED_DATE, 'YYYY-MM-DD')
```

자주 사용하는 포맷

| 포맷   | 의미   |
| ---- | ---- |
| YYYY | 연도   |
| MM   | 월    |
| DD   | 일    |
| HH24 | 24시간 |
| MI   | 분    |
| SS   | 초    |

---

## 6-4. Oracle DATE 타입 특징

Oracle DATE는 다음 정보를 모두 포함합니다.

연도
월
일
시
분
초

따라서 단순 날짜 비교 시 항상 시간 포함 여부를 고려해야 합니다.

---

## 6-5. 핵심 정리

Oracle 날짜 범위 비교는 `< 다음달 1일` 방식 사용
DATE는 시간 포함
TO_DATE는 비교용
TO_CHAR는 출력용
JOIN 조건과 WHERE 조건을 구분할 것

---

# 7. Oracle vs MySQL 날짜 비교 차이

| 구분        | MySQL       | Oracle    |
| --------- | ----------- | --------- |
| 문자열 날짜 비교 | 자동 변환 가능    | 명시적 변환 필요 |
| DATE 타입   | 날짜만 저장      | 시간 포함     |
| 변환 함수     | STR_TO_DATE | TO_DATE   |
| 출력 포맷     | DATE_FORMAT | TO_CHAR   |

---

# 8. LIKE

문자열 일부 일치 검색 시 `LIKE` 사용

## 8-1. 기본 개념

`=` 는 완전 일치 비교

```sql
WHERE ADDRESS = '강원도%'
```

문자열이 정확히 `강원도%` 인 경우만 조회
`%` 는 와일드카드로 동작하지 않음

---

## 8-2. LIKE 사용

```sql
WHERE ADDRESS LIKE '강원도%'
```

강원도로 시작하는 모든 데이터 조회

---

## 8-3. 와일드카드

| 기호 | 의미      |
| -- | ------- |
| %  | 0글자 이상  |
| _  | 정확히 1글자 |

---

## 8-4. 예시

시작 조건

```sql
WHERE NAME LIKE '김%'
```

끝 조건

```sql
WHERE NAME LIKE '%수'
```

포함 조건

```sql
WHERE NAME LIKE '%민%'
```

한 글자 패턴

```sql
WHERE NAME LIKE '박_'
```

---

## 핵심 정리

부분 검색은 반드시 LIKE 사용
`%`, `_`는 LIKE에서만 동작
`=` 는 항상 완전 일치 비교

---

# SQL 실행 순서

실제 SQL 내부 실행 순서

1. FROM (+ JOIN)
2. WHERE
3. GROUP BY
4. HAVING
5. SELECT
6. ORDER BY
