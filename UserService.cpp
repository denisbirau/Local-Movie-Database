#include "UserService.h"
#include <algorithm>
#include <Windows.h>
#include <shellapi.h>

UserService::UserService()
{
}

UserService::UserService(MovieRepository& movieRepository)
{
	this->movieRepository = movieRepository;
}

void UserService::playTrailer()
{
	std::string s = this->moviesOfInterests[this->moviesOfInterestsIndex].getTrailer();
	std::wstring stemp = std::wstring(s.begin(), s.end());
	LPCWSTR sw = stemp.c_str();
	ShellExecute(0, 0, sw, 0, 0, SW_SHOW);
}

void UserService::getMoviesByGenre(std::string genre)
{
	this->moviesOfInterests.clear();
	std::vector<Movie> movies = this->movieRepository.getMovies();
	if (genre != "")
	{
		std::copy_if(movies.begin(), movies.end(), std::back_inserter(this->moviesOfInterests), [genre](Movie movie) { return movie.getGenre() == genre; });
		if (this->moviesOfInterests.size() == 0)
			throw std::exception("Error: There are no movies with the given genre!");
	}
	else
		this->moviesOfInterests = movies;
	this->moviesOfInterestsIndex = 0;
}

// Users can add/delete movies from watchlist
void UserService::addCurrentMovieToWatchList()
{
	this->watchList.push_back(this->moviesOfInterests[this->moviesOfInterestsIndex]);
}

void UserService::deleteMovieFromWatchList(int movieID, bool like)
{
	auto it = std::find_if(this->watchList.begin(), this->watchList.end(), [movieID](Movie& movie) { return movie.getID() == movieID; });
	if (it == this->watchList.end())
		throw std::exception("Error: Movie ID is not in watchlist!");

	this->watchList.erase(it);

	if (like) {
		int nrOfLikes = this->movieRepository.getMovie(movieID).getNumberOfLikes();
		this->movieRepository.getMovie(movieID).setNumberOfLikes(nrOfLikes + 1);
		auto it = std::find_if(this->moviesOfInterests.begin(), this->moviesOfInterests.end(), [movieID](Movie& movie) { return movie.getID() == movieID; });
		if (it != this->moviesOfInterests.end())
			it->setNumberOfLikes(nrOfLikes + 1);
	}
}


Movie UserService::getCurrentMovie()
{
	return this->moviesOfInterests[this->moviesOfInterestsIndex];
}

void UserService::nextMovie()
{
	if (this->moviesOfInterestsIndex + 1 == this->moviesOfInterests.size())
		this->moviesOfInterestsIndex = 0;
	else
		this->moviesOfInterestsIndex++;
}

std::vector<Movie> UserService::getWatchList()
{
	return this->watchList;
}
