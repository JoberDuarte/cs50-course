SELECT AVG(rating)
FROM ratings
JOIN movies ON ratings.movies_id = movies.id
WHERE movies.year = 2012;
