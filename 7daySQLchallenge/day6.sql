-- 아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일을 조회하는 SQL문을 작성해주세요. 
-- 이때 결과는 보호 시작일 순으로 조회해야 합니다.
SELECT *
FROM (
    SELECT AI.NAME, AI.DATETIME
    FROM ANIMAL_INS AS AI LEFT JOIN ANIMAL_OUTS AS AO
    ON AI.ANIMAL_ID = AO.ANIMAL_ID
    WHERE AO.DATETIME IS NULL
    ORDER BY AI.DATETIME
) AS A
LIMIT 0, 3;
-- LIMIT A, B -> A부터 B개를 뽑는다(A는 0부터 시작)



-- 보호소에 들어올 당시에는 중성화1되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 
-- 이름을 조회하는 아이디 순으로 조회하는 SQL 문을 작성해주세요.
SELECT *
FROM (
    SELECT AI.ANIMAL_ID, AI.ANIMAL_TYPE, AI.NAME
    FROM ANIMAL_INS AS AI LEFT JOIN ANIMAL_OUTS AO
    ON AI.ANIMAL_ID = AO.ANIMAL_ID
    WHERE AI.SEX_UPON_INTAKE LIKE "Intact%" AND (AO.SEX_UPON_OUTCOME LIKE "Spayed%" OR AO.SEX_UPON_OUTCOME LIKE "Neutered%")
) AS A
