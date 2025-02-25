#pragma once
#include "AdminService.h"
#include <iostream>

class AdminUI
{
private:
	AdminService service;

	// Menus
	void printMenu();
	void printUpdateMenu();
	// Functionality
	void addMovieUI();
	void deleteMovieUI();
	void updateMovieUI();
	void printMovies();
public:
	AdminUI(AdminService& service);
	void run();
};