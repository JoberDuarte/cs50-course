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


-- Selecionando os dados de todas as pessoas que deixaram a padaria ate 20 minutos depois do roubo
-- e fizeram uma ligacao com duracao de menos de 1 minuto
-- e fizeram levantamento na rua Legget

SELECT * FROM people
WHERE license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 16 AND 35
)
    AND phone_number IN
    (
        SELECT caller
        FROM phone_calls
        WHERE year = 2023
        AND month = 7
        AND day = 28
        AND duration < 60

    )
    AND id IN
    (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2023
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'

    )
    );

-- verifica as pessoas que receberam as ligacoes das pessoas que atendem os criterios acima
SELECT *
FROM people
WHERE phone_number IN
(
    SELECT receiver
    FROM phone_calls
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND duration < 60
    AND (caller = '(286) 555-6063'
    OR caller = '(770) 555-1861'
    OR caller = '(367) 555-5533')
);

-- verifica os pares Bruce/Robin(NULL)
-- Taylor/James  Diana/Philip

SELECT *
FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration < 60
AND (caller = '(286) 555-6063'
OR caller = '(770) 555-1861'
OR caller = '(367) 555-5533');

SELECT *
FROM passengers
WHERE passport_number = 2438825627
OR passport_number = 3391710505
