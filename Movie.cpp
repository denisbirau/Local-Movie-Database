#include "Movie.h"
#include <chrono>

Movie::Movie(int id, std::string title, std::string genre, std::string trailer, int yearOfRelease, int numberOfLikes)
{
	this->id = id;
	setTitle(title);
	setGenre(genre);
	setTrailer(trailer);
	setYearOfRelease(yearOfRelease);
	setNumberOfLikes(numberOfLikes);
}

// Getters
int Movie::getID()
{
	return this->id;
}

std::string Movie::getTitle()
{
	return this->title;
}

std::string Movie::getGenre()
{
	return this->genre;
}

std::string Movie::getTrailer()
{
	return this->trailer;
}

int Movie::getYearOfRelease()
{
	return this->yearOfRelease;
}

int Movie::getNumberOfLikes()
{
	return this->numberOfLikes;
}

// Setters
void Movie::setTitle(std::string title)
{
	this->title = title;
}

void Movie::setGenre(std::string genre)
{
	this->genre = genre;
}

void Movie::setTrailer(std::string trailer)
{
	this->trailer = trailer;
}

void Movie::setYearOfRelease(int yearOfRelease)
{
	if (yearOfRelease < 0)
		throw std::exception("Error: Year of release can't be negative!");
	this->yearOfRelease = yearOfRelease;
}

void Movie::setNumberOfLikes(int numberOfLikes)
{
	if (numberOfLikes < 0)
		throw std::exception("Error: Number of likes can't be negative!");
	this->numberOfLikes = numberOfLikes;
}

bool Movie::operator==(const Movie& other) const
{
	return this->id == other.id;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie)
{
	os << "\nID: " << movie.id
		<< "\nTitle: " << movie.title
		<< "\nGenre: " << movie.genre
		<< "\nTrailer: " << movie.trailer
		<< "\nYear of Release: " << movie.yearOfRelease
		<< "\nNumber of Likes: " << movie.numberOfLikes << "\n";
	return os;
}
