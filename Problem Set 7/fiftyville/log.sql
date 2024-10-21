-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Know the description of the crime scene
SELECT description
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- Verify the testimony of the people who were at the crime scene
SELECT * FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28;


-- Selecting data for all people who left the bakery within 20 minutes after the theft
-- and made a call lasting less than 1 minute
-- and made a withdrawal at the ATM

SELECT people.*, phone_calls.*,atm_transactions.* FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute < 26
AND bakery_security_logs.activity = 'exit'
AND phone_calls.duration < 60
AND phone_calls.day = 28
AND atm_transactions.year = 2023
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';


-- Check the people who received the calls and make the matches:
-- BRUCE - ROBIN
-- BRUCE - CHARLOTTE
-- DIANA - PHILI

SELECT * FROM people
WHERE phone_number = '(375) 555-8161'
OR phone_number = '(455) 555-5315'
OR phone_number = '(725) 555-3243';


-- Check the flights that left Fiftyville on the 29th before 12 AM where the suspects were
-- Find the Thief

SELECT * FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
JOIN airports AS origin_airport ON origin_airport.id = flights.origin_airport_id
JOIN airports AS destination_airport ON destination_airport.id = flights.destination_airport_id
WHERE (passengers.passport_number = 5773159633
OR passengers.passport_number = 3592750733
OR passengers.passport_number = 7226911797
OR passengers.passport_number = 3391710505
OR passengers.passport_number IS NULL)
AND flights.origin_airport_id = 8
AND flights.year = 2023
AND flights.month = 7
AND flights.day = 29
AND flights.hour < 12;
