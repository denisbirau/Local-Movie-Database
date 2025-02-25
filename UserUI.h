#pragma once
#include "UserService.h"
#include <iostream>

class UserUI
{
private:
	UserService service;
	void printMenu();
	void printSearchMenu();
	// Functionality
	void searchMovieByGenreUI();
	void deleteMovieFromWatchListUI();
	void printWatchList();
public:
	UserUI(UserService& service);
	void run();
};