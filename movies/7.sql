SELECT movies.title, rating.ratings
   ...> FROM movies, ratings
   ...> WHERE year = 2012
   ...> JOIN movies.id = ratings.movie_id;
