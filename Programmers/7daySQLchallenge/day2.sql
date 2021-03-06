-- 동물 보호소에 들어온 동물 중 아픈 동물1의 아이디와 이름을 조회하는 SQL 문을 작성해주세요. 
-- 이때 결과는 아이디 순으로 조회해주세요.
SELECT A.ANIMAL_ID, A.NAME
FROM ANIMAL_INS A
WHERE A.INTAKE_CONDITION = "SICK"
ORDER BY A.ANIMAL_ID ASC;

-- 동물 보호소에 들어온 동물 중 젊은 동물1의 아이디와 이름을 조회하는 SQL 문을 작성해주세요. 
-- 이때 결과는 아이디 순으로 조회해주세요.
SELECT A.ANIMAL_ID, A.NAME
FROM ANIMAL_INS A
WHERE A.INTAKE_CONDITION != "Aged"
ORDER BY A.ANIMAL_ID ASC;
