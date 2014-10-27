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
	int nif;
	vector<App> appsPublished;// Todas as apps publicadas pelo developer
public:
	Developer();
	Developer(string name, string adress, int nif);
	~Developer();

	/////////////////////
	string getName();
	string getAdress();
	int getNif();
	/////////////////////
};


class Individual: public Developer
{
public:
	Individual();
};

class Company: public Developer
{
	string business_name;
	int code;

public:
	Company();
	Company(string business_name, int code, string name, string address);
};

#endif /* DEVELOPER_H_ */
