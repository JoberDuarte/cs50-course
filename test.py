SELECT *
        FROM phone_calls
        WHERE year = 2023
        AND month = 7
        AND day = 28
        AND duration < 60
        AND (caller = '(286) 555-6063'
        OR caller = '(770) 555-1861'
        OR caller = '(367) 555-5533');




