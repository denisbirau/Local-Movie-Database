#include "Tests.h"

#include <iostream>

void Tests::testMovie()
{
	// Setters are tested at the creation of the object
	Movie movie1(1, "movie1", "genre1", "trailer1", 1, 1);

	// Testing getters
	assert(movie1.getID() == 1);
	assert(movie1.getTitle() == "movie1");
	assert(movie1.getGenre() == "genre1");
	assert(movie1.getTrailer() == "trailer1");
	assert(movie1.getYearOfRelease() == 1);
	assert(movie1.getNumberOfLikes() == 1);
}

void Tests::testRepository()
{
	Movie movie1(1, "movie1", "genre1", "trailer1", 1, 1);
	MovieRepository movieRepository;

	// Testing add
	movieRepository.addNewMovie(movie1);
	assert(movieRepository.getNrOfMovies() == 1);
	assert(movieRepository.getMovie(1).getTitle() == "movie1");

	// Testing delete
	movieRepository.deleteMovie(1);
	assert(movieRepository.getMovies().size() == 0);
}

void Tests::testAdminService()
{
	Movie movie1(1, "movie1", "genre1", "trailer1", 1, 1);
	MovieRepository movieRepository;
	AdminService adminService(movieRepository);
	std::cout << 5 << std::endl;

	// Testing add
	adminService.addNewMovie(movie1);
	assert(adminService.getAllMovies().size() == 1);
	assert(adminService.getLastId() == 1);

	std::cout << 6 << std::endl;

	// Testing update
	adminService.updateMovieGenre(1, "genre2");
	std::cout << 12 << std::endl;
	assert(movieRepository.getMovie(1).getGenre() == "genre2");

	std::cout << 8 << std::endl;
	
	adminService.updateMovieNumberOfLikes(1, 2);
	assert(movieRepository.getMovie(1).getNumberOfLikes() == 2);

	std::cout << 9 << std::endl;

	adminService.updateMovieTitle(1, "movie2");
	assert(movieRepository.getMovie(1).getTitle() == "movie2");

	std::cout << 10 << std::endl;

	adminService.updateMovieTrailer(1, "trailer2");
	assert(movieRepository.getMovie(1).getTrailer() == "trailer2");

	std::cout << 11 << std::endl;

	adminService.updateMovieYearOfRelease(1, 2);
	assert(movieRepository.getMovie(1).getYearOfRelease() == 2);

	std::cout << 7 << std::endl;

	// Testing delete
	adminService.deleteMovie(1);
	assert(adminService.getAllMovies().size() == 0);
}

void Tests::testUserService()
{
	Movie movie1(1, "movie1", "genre1", "trailer1", 1, 1);
	Movie movie2(2, "movie2", "genre2", "trailer2", 2, 2);
	MovieRepository movieRepository;
	movieRepository.addNewMovie(movie1);
	movieRepository.addNewMovie(movie2);
	UserService userService(movieRepository);

	userService.getMoviesByGenre("genre1");
	assert(userService.getCurrentMovie().getID() == 1);

	userService.addCurrentMovieToWatchList();
	userService.nextMovie();
	userService.addCurrentMovieToWatchList();
	assert(userService.getWatchList().size() == 2);
}

Tests::Tests()
{
}

void Tests::testAll()
{
	std::cout << 1 << std::endl;
	this->testMovie();
	std::cout << 2 << std::endl;
	this->testRepository();
	std::cout << 3 << std::endl;
	this->testAdminService();
	std::cout << 4 << std::endl;
	this->testUserService();
}
