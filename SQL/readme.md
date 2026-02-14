# SQL 핵심 키워드 정리

## 1. CASE 문

```sql
CASE
    WHEN 조건 THEN 결과
    WHEN 조건 THEN 결과
    ELSE 결과
END
```

• SELECT 절에서 조건에 따라 다른 값을 출력할 때 사용
• 비교 연산자(`=`, `>=`, `<` 등) 사용
• NULL 비교는 `IS NULL`, `IS NOT NULL` 사용

예시

```sql
CASE
    WHEN score >= 90 THEN 'A'
    ELSE 'B'
END
```

---

## 2. 날짜 관련 함수

### 2-1. 연도 추출

```sql
EXTRACT(YEAR FROM 컬럼명) = 2024
```

• 날짜 타입(Date, Timestamp)에서 연도만 추출

---

### 2-2. 날짜 형식 변환 (Oracle 기준)

```sql
TO_CHAR(컬럼명, 'YYYY-MM-DD')
```

• 날짜를 문자열 형식으로 변환
• 반드시 작은따옴표 사용

예시

```sql
SELECT TO_CHAR(SYSDATE, 'YYYY-MM-DD')
FROM DUAL;
```

---

## 3. ORDER BY

```sql
ORDER BY 컬럼1, 컬럼2 DESC;
```

• 여러 컬럼 정렬 시 콤마로 구분
• ASC (기본값), DESC 사용 가능

---

## 4. WHERE 절

```sql
WHERE 조건
```

• 데이터 조회 전 필터링
• 비교 연산자 사용 가능
==============

>

<

> =
> <=
> <>

• NULL 비교는 반드시
IS NULL
IS NOT NULL

---

## 5. WHERE vs HAVING 차이

### WHERE

• GROUP BY 이전에 실행
• 개별 행(row)을 필터링
• 집계 함수 사용 불가

예시

```sql
SELECT *
FROM EMP
WHERE SALARY >= 3000;
```

---

### HAVING

• GROUP BY 이후 실행
• 그룹 단위 결과를 필터링
• 집계 함수 사용 가능

예시

```sql
SELECT DEPTNO, AVG(SALARY)
FROM EMP
GROUP BY DEPTNO
HAVING AVG(SALARY) >= 3000;
```

---

## 실행 순서 정리

FROM
WHERE
GROUP BY
HAVING
SELECT
ORDER BY
