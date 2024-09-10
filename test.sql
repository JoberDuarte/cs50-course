SELECT * FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2023
AND month = 7
AND day = 28
AND hour = 10
AND activity = 'exit'

