#pragma once
#include "Movie.h"
#include <vector>

class MovieRepository
{
private:
	std::vector<Movie> movies;
public:
	MovieRepository();
	MovieRepository(std::vector<Movie>& movies);

	Movie& getMovie(int movieID);
	int getNrOfMovies();

	// Add/Delete movies in repository
	void addNewMovie(Movie& newMovie);
	void deleteMovie(int movieID);

	// Get all movies
	std::vector<Movie> getMovies();
};