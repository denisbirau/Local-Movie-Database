#include "MovieRepository.h"

MovieRepository::MovieRepository()
{
}

MovieRepository::MovieRepository(std::vector<Movie>& movies)
{
	this->movies = movies;
}

Movie& MovieRepository::getMovie(int movieID)
{
	auto it = std::find_if(this->movies.begin(), this->movies.end(), [movieID](Movie& movie) { return movie.getID() == movieID; });
	if (it == this->movies.end())
		throw std::exception("Error: Movie ID doesn't exist!");
	return *it;
}


int MovieRepository::getNrOfMovies()
{
	return (int)this->movies.size();
}

// Add/Delete movies in repository
void MovieRepository::addNewMovie(Movie& newMovie)
{
	this->movies.push_back(newMovie);
}

void MovieRepository::deleteMovie(int movieID)
{
	auto it = std::remove_if(this->movies.begin(), this->movies.end(), [movieID](Movie& movie) { return movie.getID() == movieID; });
	if (it == this->movies.end())
		throw std::exception("Error: Movie ID doesn't exist!");
	this->movies.erase(it);
}

// Get all movies
std::vector<Movie> MovieRepository::getMovies()
{
	return this->movies;
}