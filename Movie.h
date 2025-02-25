#pragma once
#include <string>
#include <ostream>

class Movie 
{
private:
	std::string title, genre, trailer;
	int id, yearOfRelease, numberOfLikes;
public:
	Movie(int id, std::string title, std::string genre, std::string trailer, int yearOfRelease, int numberOfLikes);

	// Getters
	int getID();
	std::string getTitle();
	std::string getGenre();
	std::string getTrailer();
	int getYearOfRelease();
	int getNumberOfLikes();
	
	// Setters
	// id does not have a setter since it can't be changed
	void setTitle(std::string title);
	void setGenre(std::string genre);
	void setTrailer(std::string trailer);
	void setYearOfRelease(int yearOfRelease);
	void setNumberOfLikes(int numberOfLikes);

	bool operator==(const Movie& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
};