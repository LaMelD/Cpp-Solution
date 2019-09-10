SELECT a.ANIMAL_ID, a.NAME, a.SEX_UPON_INTAKE
FROM ANIMAL_INS a
WHERE a.NAME = "Lucy" OR
    a.NAME = "Ella" OR
    a.NAME = "Pickle" OR
    a.NAME = "Rogan" OR
    a.NAME = "Sabrina" OR
    a.NAME = "Mitty"
ORDER BY a.ANIMAL_ID;
