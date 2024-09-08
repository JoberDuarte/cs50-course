SELECT movies.title, rating.ratings
FROM movies, ratings
JOIN movies ON movies.id = ratings.movie_id
WHERE year = 2012;

