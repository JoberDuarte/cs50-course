SELECT *
FROM passengers
JOIN flights ON flights.id = passengers.flight_id
WHERE (passport_number = 1988161715
OR passport_number = 3592750733
OR passport_number = 5773159633
OR passport_number = 2438825627
OR passport_number = 3592750733)

AND origin_airport_id = 8;





