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






