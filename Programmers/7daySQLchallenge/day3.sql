-- 동물 보호소에 가장 먼저 들어온 동물은 언제 들어왔는지 조회하는 SQL 문을 작성해주세요.
SELECT MIN(A.DATETIME) AS "시간"
FROM ANIMAL_INS A;

-- 동물 보호소에 들어온 동물 중, 이름이 없는 채로 들어온 동물의 ID를 조회하는 SQL 문을 작성해주세요. 
-- 단, ID는 오름차순 정렬되어야 합니다.
SELECT A.ANIMAL_ID
FROM ANIMAL_INS A
WHERE A.NAME IS NULL
ORDER BY A.ANIMAL_ID ASC;
