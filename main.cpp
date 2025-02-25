#include "AdminUI.h"
#include "UserUI.h"
#include "Tests.h"
#include <iostream>

/*int main()
{
	bool admin;
	std::cout << "Admin(1/0): ";
	std::cin >> admin;

	std::vector<Movie> movies;
	movies.push_back(Movie(1, "The Shawshank Redemption", "Thriller", "https://www.youtube.com/watch?v=NmzuHjWmXOc", 1994, 15000));
	movies.push_back(Movie(2, "The Godfather", "Gangster", "https://www.youtube.com/watch?v=UaVTIH8mujA", 1972, 67000));
	movies.push_back(Movie(3, "The Dark Knight", "Action", "https://www.youtube.com/watch?v=LDG9bisJEaI", 2008, 20000));
	movies.push_back(Movie(4, "Schindler's List", "War", "https://www.youtube.com/watch?v=mxphAlJID9U", 1993, 25000));
	movies.push_back(Movie(5, "The Godfather Part II", "Gangster", "https://www.youtube.com/watch?v=9O1Iy9od7-A", 1974, 60000));
	movies.push_back(Movie(6, "The Lord of the Rings: The Return of the King", "Action", "https://www.youtube.com/watch?v=r5X-hFf6Bwo", 2003, 31000));
	movies.push_back(Movie(7, "12 Angry Men", "Drama", "https://www.youtube.com/watch?v=TEN-2uTi2c0", 1957, 4900));
	movies.push_back(Movie(8, "The Lord of the Rings: The Fellowship of the Ring", "Action", "https://www.youtube.com/watch?v=_nZdmwHrcnw", 2001, 11000));
	movies.push_back(Movie(9, "Pulp Fiction", "Comedy", "https://www.youtube.com/watch?v=tGpTpVyI_OQ", 1994, 18000));
	movies.push_back(Movie(10, "Inception", "Action", "https://www.youtube.com/watch?v=LifqWf0BAOA", 2010, 4200));
	
	MovieRepository repository(movies);
	if (admin)
	{
		AdminService service(repository);
		AdminUI ui(service);
		ui.run();
	}
	else
	{
		UserService service(repository);
		UserUI ui(service);
		ui.run();
	}
	return 0;
}*/

int main()
{
	Tests test;
	test.testAll();
}