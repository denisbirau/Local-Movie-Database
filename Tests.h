#pragma once
#include "AdminService.h"
#include "UserService.h"
#include <cassert>

class Tests
{
private:
	void testMovie();
	void testRepository();
	void testAdminService();
	void testUserService();
public:
	Tests();
	void testAll();
};