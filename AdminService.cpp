#include "AdminService.h"

AdminService::AdminService()
{
}

AdminService::AdminService(MovieRepository& movieRepository)
{
	this->movieRepository = movieRepository;
}


int AdminService::getLastId()
{
	return this->movieRepository.getNrOfMovies();
}

// Administrators can add or delete movies
void AdminService::addNewMovie(Movie& newMovie)
{
	this->movieRepository.addNewMovie(newMovie);
}

void AdminService::deleteMovie(int movieId)
{
	this->movieRepository.deleteMovie(movieId);
}

// Administrators can change information about movies
void AdminService::updateMovieTitle(int movieId, std::string newTitle)
{
	this->movieRepository.getMovie(movieId).setTitle(newTitle);
}

void AdminService::updateMovieGenre(int movieId, std::string newGenre)
{
	this->movieRepository.getMovie(movieId).setGenre(newGenre);
}

void AdminService::updateMovieTrailer(int movieId, std::string newTrailer)
{
	this->movieRepository.getMovie(movieId).setTrailer(newTrailer);
}

void AdminService::updateMovieYearOfRelease(int movieId, int newYearOfRelease)
{
	this->movieRepository.getMovie(movieId).setYearOfRelease(newYearOfRelease);
}

void AdminService::updateMovieNumberOfLikes(int movieId, int newNumberOfLikes)
{
	this->movieRepository.getMovie(movieId).setNumberOfLikes(newNumberOfLikes);
}

// Administrators can see all movies
std::vector<Movie> AdminService::getAllMovies()
{
	return this->movieRepository.getMovies();
}
