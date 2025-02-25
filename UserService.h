#pragma once
#include "MovieRepository.h"

class UserService
{
private:
	MovieRepository movieRepository;
	std::vector<Movie> moviesOfInterests;
	int moviesOfInterestsIndex;
	std::vector<Movie> watchList;
	
public:
	UserService();
	UserService(MovieRepository& movieRepository);

	void playTrailer();

	// Users can see movies filtered by genre
	void getMoviesByGenre(std::string genre);
	
	// Users can add/delete movies from watchlist
	void addCurrentMovieToWatchList();
	void deleteMovieFromWatchList(int movieID, bool like);

	Movie getCurrentMovie();
	void nextMovie();
	
	// Users can see their own watchlist
	std::vector<Movie> getWatchList();
};