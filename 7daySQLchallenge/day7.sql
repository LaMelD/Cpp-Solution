-- 동물 보호소에 들어온 동물 중 이름이 
-- Lucy, Ella, Pickle, Rogan, Sabrina, Mitty인 동물의 아이디와 이름, 성별을 조회하는 SQL 문을 작성해주세요.
-- 이때 결과는 아이디 순으로 조회해주세요
SELECT a.ANIMAL_ID, a.NAME, a.SEX_UPON_INTAKE
from ANIMAL_INS a
where a.NAME = "Lucy" or
    a.NAME = "Ella" or
    a.NAME = "Pickle" or
    a.NAME = "Rogan" or
    a.NAME = "Sabrina" or
    a.NAME = "Mitty"
order by a.ANIMAL_ID;



-- 동물 보호소에 들어온 동물 이름 중, 이름에 EL이 들어가는 개의 아이디와 이름을 조회하는 SQL문을 작성해주세요. 
-- 이때 결과는 이름 순으로 조회해주세요. 단, 이름의 대소문자는 구분하지 않습니다.
SELECT A.ANIMAL_ID, A.NAME
from ANIMAL_INS A
WHERE A.NAME LIKE "%EL%"
AND A.ANIMAL_TYPE = "Dog"
ORDER BY A.NAME;
