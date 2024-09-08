SELECT id, TRIM(name) AS name
FROM people
WHERE TRIM(name) = 'Craig T. Nelson';


SELECT TRIM(p.name) AS name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
WHERE m.year = 2004 AND TRIM(p.name) = 'Craig T. Nelson';


SELECT DISTINCT TRIM(name) AS name
FROM people
WHERE id IN
(
    SELECT person_id
    FROM stars
    WHERE movie_id IN
    (
        SELECT id
        FROM movies
        WHERE year = 2004
    )
)
ORDER BY TRIM(name) ASC;
