/*
 * Developer.h
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */
#ifndef DEVELOPER_H_
#define DEVELOPER_H_


#include <string>
#include "App.h"

using namespace std;

class App;

class Developer {
	string name;
	string address;
	int nif;
	vector<App*> appsPublished;// Todas as apps publicadas pelo developer
public:
	Developer();
	Developer(string name, string adress, int nif);
	~Developer();

	/////////////////////
	string getName();
	string getAddress();
	int getNif();
	vector<App*> getApps();

	void setName(string name);
	void setAddress(string address);
	void setNif(int nif);
	void setApps(vector<App*> apps);
	/////////////////////

	void addApp(App* app);
	void removeApp(App* app);
	void displayInfo();
	void displayAllSales();
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
