-- Selecionando os dados de todas as pessoas que deixaram a padaria ate 20 minutos depois do roubo
-- e fizeram uma ligacao com duracao de menos de 1 minuto

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



