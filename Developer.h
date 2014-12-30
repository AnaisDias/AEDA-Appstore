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
	vector<App*> appsPublished;

public:
	Developer();
	Developer(string name, string address, int nif);
	~Developer();

	virtual int devtype(){}
	virtual std::ostream & writeToFile(std::ostream &out);

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
	virtual string displayInfo();
	void displayAllSales();
	bool operator==(const Developer &dev) const;
	std::ostream & operator<<(std::ostream &out);



	string displayNameDev();
};


class Individual: public Developer
{
public:
	Individual(string name, string address, int nif);
	std::ostream & writeToFile(std::ostream &out);
	string displayInfo();
	int devtype(){
		return 1;
	}
};

class Company: public Developer
{
	string businessName;
	int code;

public:
	Company();
	Company(string businessname, int code, string name, string address, int nif);
	std::ostream & writeToFile(std::ostream &out);
	int devtype(){
			return 2;
		}
	string displayInfo();
	string getCompanyName(){
		return businessName;
	}
	int getCode(){
		return code;
	}

	void setCompanyName(string businessname)
	{
		this->businessName = businessname;
	}

	void setCode(int code)
	{
		this->code = code;
	}

};

#endif /* DEVELOPER_H_ */
