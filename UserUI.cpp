#include "UserUI.h"

void UserUI::printMenu()
{
	std::cout << std::endl;
	std::cout << "0 - Exit." << std::endl;
	std::cout << "1 - Search movie by genre." << std::endl;
	std::cout << "2 - Delete movie from watch list." << std::endl;
	std::cout << "3 - See the watch list." << std::endl;
	std::cout << std::endl;
}

void UserUI::printSearchMenu()
{
	std::cout << std::endl;
	std::cout << "0 - Exit." << std::endl;
	std::cout << "1 - Play trailer." << std::endl;
	std::cout << "2 - Add movie to watch list." << std::endl;
	std::cout << "3 - Show next movie." << std::endl;
	std::cout << std::endl;
}

void UserUI::searchMovieByGenreUI()
{
	std::string genre;
	std::cout << "Enter genre: ";
	std::cin.ignore();
	std::getline(std::cin, genre);

	try
	{
		this->service.getMoviesByGenre(genre);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		return;
	}

	int option;
	do
	{
		std::cout << this->service.getCurrentMovie() << std::endl;
		this->printSearchMenu();
		std::cout << "Enter option: ";
		std::cin >> option;
		switch (option)
		{
		case 0:
			return;
		case 1:
			this->service.playTrailer();
			break;
		case 2:
			this->service.addCurrentMovieToWatchList();
			break;
		case 3:
			this->service.nextMovie();
			break;
		default:
			std::cout << "Invalid option!" << std::endl;
			break;
		}
	} while (true);

}

void UserUI::deleteMovieFromWatchListUI()
{
	int movieID;
	std::cout << "Enter movie id: ";
	std::cin >> movieID;

	bool like;
	std::cout << "Like the movie(1/0): ";
	std::cin >> like;
	try
	{
		this->service.deleteMovieFromWatchList(movieID, like);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void UserUI::printWatchList()
{
	std::vector<Movie> watchList = this->service.getWatchList();
	for (auto movie : watchList)
		std::cout << movie << std::endl;
}

UserUI::UserUI(UserService& service)
{
	this->service = service;
}

void UserUI::run()
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
			this->searchMovieByGenreUI();
			break;
		case 2:
			this->deleteMovieFromWatchListUI();
			break;
		case 3:
			this->printWatchList();
			break;
		default:
			std::cout << "Invalid option!" << std::endl;
			break;
		}
	} while (true);
}
