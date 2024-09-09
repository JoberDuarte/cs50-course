-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Saber a descricao da cena do crime
SELECT description
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = 'Humphrey Street';


-- Verificar as atividades das pessoas entre as 10 e 11 na padaria
SELECT * FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28
AND hour = 10;

-- Verificar o depoimento das pessoas que estavam na cena do crime
SELECT * FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28;



SELECT * FROM people
WHERE license_plate = '1106N58'
OR license_plate = '0NTHK55';
