-- Selecionando os dados de todas as pessoas que deixaram a padaria ate 20 minutos depois do roubo
-- e fizeram uma ligacao com duracao de menos de 1 minuto
-- e fizeram levantamento no caixa eletronico

SELECT people.*, phone_calls.*,atm_transactions.* FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.activity = 'exit'
AND phone_calls.duration < 60
AND atm_transactions.year = 2023
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';


--verificar as pessoas que receberam as ligacoes e fazer os match  BRUCE - ROBIN // BRUCE - CHARLOTTE // DIANA - PHILIP // TAYLOR - JAMES
SELECT * FROM people
WHERE phone_number = '(375) 555-8161'
OR phone_number = '(455) 555-5315'
OR phone_number = '(725) 555-3243'
OR phone_number = '(676) 555-6554';

SELECT * FROM passengers
JOIN flights ON flights.id = passengers.flight_id
WHERE (passengers.passport_number = 5773159633
OR passengers.passport_number = 3592750733
OR passengers.passport_number = 1988161715
OR passengers.passport_number = 2438825627
OR passengers.passport_number = 7226911797
OR passengers.passport_number = 3391710505
OR passport_number IS NULL)
AND flights.origin_airport_id = 8
AND flights.year = 2023
AND flights.month = 7
AND flights.day > 28;
