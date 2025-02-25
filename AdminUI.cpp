#include "AdminUI.h"

void AdminUI::printMenu()
{
	std::cout << std::endl;
	std::cout << "0 - Exit." << std::endl;
	std::cout << "1 - Add a new movie to the database." << std::endl;
	std::cout << "2 - Delete a movie from the database." << std::endl;
	std::cout << "3 - Update a movie from the database." << std::endl;
	std::cout << "4 - Print the list of movies from the database." << std::endl;
	std::cout << std::endl;
}

void AdminUI::printUpdateMenu()
{
	std::cout << std::endl;
	std::cout << "0 - Cancel." << std::endl;
	std::cout << "1 - Update title." << std::endl;
	std::cout << "2 - Update genre." << std::endl;
	std::cout << "3 - Update trailer." << std::endl;
	std::cout << "4 - Update year of release." << std::endl;
	std::cout << "5 - Update number of likes." << std::endl;
	std::cout << std::endl;
}

void AdminUI::addMovieUI()
{
	std::string title, genre, trailer;
	int yearOfRelease, numberOfLikes;

	std::cout << "Enter title: ";
	std::cin >> title;

	std::cout << "Enter genre: ";
	std::cin >> genre;

	std::cout << "Enter trailer: ";
	std::cin >> trailer;

	std::cout << "Enter year of release: ";
	std::cin >> yearOfRelease;

	std::cout << "Enter number of likes: ";
	std::cin >> numberOfLikes;
	try
	{
		Movie movie(this->service.getLastId() + 1, title, genre, trailer, yearOfRelease, numberOfLikes);
		this->service.addNewMovie(movie);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AdminUI::deleteMovieUI()
{
	int movieID;

	std::cout << "Enter movie id: ";
	std::cin >> movieID;

	try
	{
		this->service.deleteMovie(movieID);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AdminUI::updateMovieUI()
{
	int movieID;
	std::cout << "Enter movie id: ";
	std::cin >> movieID;

	this->printUpdateMenu();

	int option;
	std::cout << "Enter option: ";
	std::cin >> option;
	try
	{
		switch (option)
		{
		case 0:
			break;
		case 1:
		{
			std::string newTitle;
			std::cout << "Enter new title: ";
			std::cin >> newTitle;
			this->service.updateMovieTitle(movieID, newTitle);
			break;
		}
		case 2:
		{
			std::string newGenre;
			std::cout << "Enter new genre: ";
			std::cin >> newGenre;
			this->service.updateMovieGenre(movieID, newGenre);
			break;
		}
		case 3:
		{
			std::string newTrailer;
			std::cout << "Enter new trailer: ";
			std::cin >> newTrailer;
			this->service.updateMovieTrailer(movieID, newTrailer);
			break;
		}
		case 4:
		{
			int newYearOfRelease;
			std::cout << "Enter new year of release: ";
			std::cin >> newYearOfRelease;
			this->service.updateMovieYearOfRelease(movieID, newYearOfRelease);
			break;
		}
		case 5:
		{
			int newNumberOfLikes;
			std::cout << "Enter new number of likes: ";
			std::cin >> newNumberOfLikes;
			this->service.updateMovieNumberOfLikes(movieID, newNumberOfLikes);
			break;
		}
		default:
			std::cout << "Invalid option!" << std::endl;
			break;
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AdminUI::printMovies()
{
	std::vector<Movie> movies = this->service.getAllMovies();
	for (Movie movie : movies)
		std::cout << movie;
}

AdminUI::AdminUI(AdminService& service)
{
	this->service = service;
}

void AdminUI::run()
{
	int option;
	do
	{
		this->printMenu();
		std::cout << "Enter option: ";
		std::cin >> option;

		switch (option)
		{
		case 0:
			std::cout << "Exiting..." << std::endl;
			return;
		case 1:
			this->addMovieUI();
			break;
		case 2:
			this->deleteMovieUI();
			break;
		case 3:
			this->updateMovieUI();
			break;
		case 4:
			this->printMovies();
			break;
		default:
			std::cout << "Invalid option!" << std::endl;
			break;
		}
	} while (true);
}
