SELECT DISTINCT name
FROM people
WHERE id IN =
(
    SELECT person_id
    FROM directors
    WHERE movie_id IN =
    (
        SELECT rating > 9.0
        FROM ratings
        WHERE movie_id IN =
        (
            SELECT id
        )
    )
)
