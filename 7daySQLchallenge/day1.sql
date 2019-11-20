-- 동물 보호소에 들어온 모든 동물의 정보를 ANIMAL_ID순으로 조회하는 SQL문을 작성
SELECT *
FROM ANIMAL_INS A
ORDER BY A.ANIMAL_ID ASC;


-- 동물 보호소에 들어온 모든 동물의 이름과 보호 시작일을 조회하는 SQL문을 작성
-- 결과는 ANIMAL_ID 역순
SELECT A.NAME, A.DATETIME
FROM ANIMAL_INS A
ORDER BY A.ANIMAL_ID DESC;
