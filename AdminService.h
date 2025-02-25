#pragma once
#include "MovieRepository.h"

class AdminService
{
private:
	MovieRepository movieRepository;
public:
	AdminService();
	AdminService(MovieRepository& movieRepository);

	int getLastId();
	
	// Administrators can add or delete movies
	void addNewMovie(Movie& newMovie);
	void deleteMovie(int movieId);

	// Administrators can change information about movies
	void updateMovieTitle(int movieId, std::string newTitle);
	void updateMovieGenre(int movieId, std::string newGenre);
	void updateMovieTrailer(int movieId, std::string newTrailer);
	void updateMovieYearOfRelease(int movieId, int newYearOfRelease);
	void updateMovieNumberOfLikes(int movieId, int newNumberOfLikes);

	// Administrators can see all movies
	std::vector<Movie> getAllMovies();
};