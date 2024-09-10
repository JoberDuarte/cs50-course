SELECT * FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2023
AND month = 7
AND day = 28
AND hour BETWEEN 9 AND 11;
