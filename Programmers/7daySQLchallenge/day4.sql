-- 동물 보호소에 들어온 동물 중 고양이와 개가 각각 몇 마리인지 조회하는 SQL문을 작성해주세요. 
-- 이때 고양이가 개보다 먼저 조회해주세요.
SELECT A.ANIMAL_TYPE, COUNT(A.ANIMAL_TYPE) AS "count"
FROM ANIMAL_INS A
WHERE A.ANIMAL_TYPE = "Cat" OR A.ANIMAL_TYPE = "Dog"
GROUP BY A.ANIMAL_TYPE
ORDER BY A.ANIMAL_TYPE ASC;

-- 동물 보호소에 들어온 동물 이름 중 두 번 이상 쓰인 이름과 해당 이름이 쓰인 횟수를 조회하는 SQL문을 작성해주세요.
-- 이때 결과는 이름이 없는 동물은 집계에서 제외하며, 결과는 이름 순으로 조회해주세요.
SELECT A.NAME, COUNT(A.NAME) AS "COUNT"
FROM ANIMAL_INS A
WHERE A.NAME IS NOT NULL
GROUP BY A.NAME
HAVING COUNT > 1
ORDER BY A.NAME;
