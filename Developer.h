/*
 * Developer.h
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#include <string>
#include "App.h"

using namespace std;

#ifndef DEVELOPER_H_
#define DEVELOPER_H_

class Developer {
	string name;
	string adress;
	// Todas as apps publicadas pelo developer
	vector<App> appsPublished;
public:
	Developer();
	~Developer();
};


class Individual: public Developer
{
public:
	Individual();
};

class Business: public Developer
{
	string business_name;
	int code;

public:
	Business();
	Business(string business_name, int code);
};

#endif /* DEVELOPER_H_ */
