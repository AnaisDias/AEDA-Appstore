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
	static int allIDs;
	int id;
	string name;
	string address;
	int nif;
	float earnings;
	vector<App*> appsPublished;// Todas as apps publicadas pelo developer
	//float earnings;
public:
	Developer();
	Developer(string name, string address, int nif);
	~Developer();

	/////////////////////
	int getID() const;
	string getName() const;
	string getAddress() const;
	int getNif() const;
	vector<App*> getApps() const;

	void setID(int id);
	void setName(string name);
	void setAddress(string address);
	void setNif(int nif);
	void setApps(vector<App*> apps);
	/////////////////////

	void addEarnings(float earn){earnings+=earn;};
	void addApp(App* app);
	bool removeApp(App* app);
	void displayInfo();
	void displayAllSales();
	bool operator==(const Developer &dev) const;
	std::ostream & operator<<(std::ostream &out);

	std::ostream & writeToFile(std::ostream &out);

	string displayNameDev();
};


class Individual: public Developer
{
public:
	Individual(string name, string address, int nif);
};

class Company: public Developer
{
	string businessName;
	int code;

public:
	Company();
	Company(string businessname, int code, string name, string address, int nif);
};

#endif /* DEVELOPER_H_ */
