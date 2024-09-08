SELECT DISTINCT name
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.years = 2004
ORDER BY people.birth ASC;
