# SQL 핵심 키워드 정리(Oracle 기준)

코딩 테스트에서 자주 사용되는 SQL 핵심 문법을 정리한 문서입니다.


## 1. 조건부 출력 (`CASE` 문)

특정 조건에 따라 값을 분기하여 출력할 때 사용합니다.

```sql
SELECT 
    CASE 
        WHEN score >= 90 THEN 'A'
        WHEN score >= 80 THEN 'B'
        ELSE 'C'
    END AS grade -- 별칭 지정 권장
FROM RESULTS;

```

> **주의**: `NULL` 판별은 `=`이 아닌 `IS NULL` 또는 `IS NOT NULL`을 사용해야 합니다.

---

## 2. 날짜 및 시간 함수 (`Date`)

### 2-1. 날짜 데이터 추출 및 변환

| 함수 | 용도 | 예시 |
| --- | --- | --- |
| **`EXTRACT`** | 날짜에서 특정 단위 추출 | `EXTRACT(YEAR FROM HIRE_DATE) = 2024` |
| **`TO_CHAR`** | 날짜를 문자열로 포맷팅 | `TO_CHAR(SYSDATE, 'YYYY-MM-DD HH24:MI:SS')` |

---

## 3. 필터링 연산자 (`WHERE` & `IN`)

### 3-1. 기본 비교 연산자

* `=` (같음), `<>` (다름), `>`, `<`, `>=`, `<=`

### 3-2. 다중 선택 연산자 (`IN`)

`OR` 조건을 여러 번 나열하는 대신, 목록 중 하나라도 일치하는 데이터를 찾을 때 사용합니다.

```sql
-- 가독성 좋은 IN 연산자 활용
WHERE FLAVOR IN ('melon', 'strawberry', 'chocolate')

```

---

## 4. 정렬 (`ORDER BY`)

결과 집합의 순서를 결정합니다.

```sql
ORDER BY 
    SALARY DESC,     -- 1순위: 급여 내림차순
    HIRE_DATE ASC;   -- 2순위: 입사일 오름차순 (ASC 생략 가능)

```

---

## 5. 집계와 필터링 (`WHERE` vs `HAVING`)

두 예약어는 실행 시점과 필터링 대상이 완전히 다릅니다.

| 구분 | WHERE | HAVING |
| --- | --- | --- |
| **실행 시점** | `GROUP BY` 수행 전 | `GROUP BY` 수행 후 |
| **필터링 대상** | 개별 행 (Row) | 그룹화된 결과 (Group) |
| **집계 함수** | 사용 불가 (`AVG`, `SUM` 등) | **사용 가능** |

---

# ⭐6. Oracle 날짜 필터링 (월 조건 처리)

## 6-1. 특정 월 데이터 조회 (가장 안전한 방식)

Oracle에서는 월 조건을 문자열 비교보다 **범위 비교로 처리하는 것이 정석**입니다.

```sql
WHERE CREATED_DATE >= TO_DATE('2022-10-01', 'YYYY-MM-DD')
AND CREATED_DATE <  TO_DATE('2022-11-01', 'YYYY-MM-DD')
```

### 이유

* Oracle DATE는 **시간까지 포함**
* `<= '2022-10-31'` 방식은 시간 때문에 누락 가능
* `< 다음달 1일` 방식이 가장 안전

---

## 6-2. TO_DATE 함수

문자열을 DATE 타입으로 변환할 때 사용합니다.

```sql
TO_DATE('2022-10-01', 'YYYY-MM-DD')
```

| 인자   | 의미       |
| ---- | -------- |
| 첫 번째 | 날짜 문자열   |
| 두 번째 | 날짜 형식 지정 |

Oracle에서는 날짜 비교 시 **명시적 변환 필수**

---

## 6-3. TO_CHAR (날짜 출력 형식 제어)

DATE → 문자열 변환

```sql
TO_CHAR(CREATED_DATE, 'YYYY-MM-DD')
```

자주 쓰는 포맷

| 포맷   | 의미   |
| ---- | ---- |
| YYYY | 연도   |
| MM   | 월    |
| DD   | 일    |
| HH24 | 24시간 |
| MI   | 분    |
| SS   | 초    |

---

## 6-4. DATE 타입 주의사항 (Oracle)

Oracle DATE는 다음을 모두 포함합니다:

```
연도 + 월 + 일 + 시 + 분 + 초
```

따라서 단순 날짜 비교는 주의해야 합니다.

## 6-5 최종 정리

* Oracle 날짜 범위 비교는 `< 다음달 1일`
* DATE는 시간 포함
* TO_DATE는 비교용
* TO_CHAR는 출력용
* JOIN 조건과 WHERE 조건 구분

---

# 7. Oracle vs MySQL 날짜 비교 차이

| 구분        | MySQL       | Oracle       |
| --------- | ----------- | ------------ |
| 문자열 날짜 비교 | 자동 변환 가능    | 명시적 변환 필요    |
| 날짜 타입     | DATE (날짜만)  | DATE (시간 포함) |
| 변환 함수     | STR_TO_DATE | TO_DATE      |
| 포맷 출력     | DATE_FORMAT | TO_CHAR      |

---


## SQL 실행 순서 (반드시 암기!)

컴퓨터가 쿼리를 읽는 실제 순서입니다. 이 순서를 이해하면 오류를 디버깅하기 쉽습니다.

1. **`FROM`** (+ `JOIN`): 어느 표에서 데이터를 가져올지 결정
2. **`WHERE`**: 조건에 맞는 행들만 먼저 걸러냄
3. **`GROUP BY`**: 행들을 그룹으로 묶음
4. **`HAVING`**: 그룹화된 결과 중 필요한 그룹만 남김
5. **`SELECT`**: 어떤 컬럼을 보여줄지 결정 (**여기서 윈도우 함수 및 별칭 생성**)
6. **`ORDER BY`**: 최종 결과를 정렬하여 출력

