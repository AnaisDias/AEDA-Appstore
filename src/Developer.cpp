/*
 * Developer.cpp
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#include "Developer.h"
#include "AppStore.h"
#include <iostream>
#include <sstream>

int Developer::allIDs=0;

Developer::Developer() {
	id=allIDs;
	allIDs++;
	nif=0;
	name="";
	earnings=0;
	appsPublished.clear();

}

Developer::Developer(string name, string address, int nif) {
	this->name = name;
	this->address = address;
	this->nif = nif;
	this->id=allIDs;
	earnings= 0;
	allIDs++;
}

Developer::~Developer() {
	for(unsigned int i=0; i<appsPublished.size(); i++){
			delete appsPublished[i];
			appsPublished.erase(appsPublished.begin()+i);
			i--;
		}
}

int Developer::getID() const{
	return id;
}

string Developer::getName() const{
	return name;
}

string Developer::getAddress() const {
	return address;
}

int Developer::getNif() const{
	return nif;
}

vector<App*> Developer::getApps() const{
	return appsPublished;
}

void Developer::setID(int id){
	this->id=id;
}

void Developer::setName(string name){
	this->name=name;
}

void Developer::setAddress(string address){
	this->address=address;
}

void Developer::setNif(int nif){
	this->nif=nif;
}

void Developer::setApps(vector<App*> apps){
	this->appsPublished=apps;
}

/////////////////////

void Developer::addApp(App* app){
	appsPublished.push_back(app);
}

bool Developer::removeApp(App* app){
	for(unsigned int i=0; i<appsPublished.size(); i++){
		if(app==appsPublished[i]){
			appsPublished.erase(appsPublished.begin() + i);
			return true;
		}
	}
	return false;
}

string Developer::displayInfo(){

	stringstream out;
	out << " Developer ID: " << id << endl;
	out << " Name: " << name << endl;
	out << " Address: " << address << endl;
	out << " NIF: " << nif << endl;

	return out.str();
}

string Company::displayInfo()
{
	cout << Developer::displayInfo();

	stringstream out;
	out << " Company: " << businessName << endl;
	out << " Code: " << code << endl;

	return out.str();

}

string Individual::displayInfo()
{
	return Developer::displayInfo();
}

void Developer::displayAllSales(){

	for(unsigned int i = 0; i < appsPublished.size(); i++)
	{
		cout << appsPublished[i]->displayInfo() << endl;
	}
}

bool Developer::operator==(const Developer &dev) const{
	if(this->name==dev.name && this->nif==dev.nif)
		{
		return true;
		}

	return false;
}

std::ostream & Developer::operator<<(std::ostream &out){
	out << "Developer ID: " << id << endl;
	out << "Developer name: " << name << endl;
	out << "Address: " << address << endl;
	out << "NIF: " << nif << endl;
	out << endl;
	return out;
}

std::ostream & Developer::writeToFile(std::ostream &out){
	out << id << "," << devtype() << "," << name << "," << address << ",";
	out << nif << ",";
	return out;
}

std::ostream & Individual::writeToFile(std::ostream &out)
{
	Developer::writeToFile(out);

	return out;
}

std::ostream & Company::writeToFile(std::ostream &out)
{
	Developer::writeToFile(out);

	out << businessName << "," << code;
	return out;
}

/////////////////////

Individual::Individual(string name, string address, int nif):Developer(name, address, nif){
}

Company::Company(string businessname, int code, string name, string address, int nif):Developer(name, address, nif){
	this->code=code;
	this->businessName=businessname;
}

string Developer::displayNameDev() {
	stringstream out;
	out << "Dev Name: " << name << endl;

	return out.str();
}

void Individual::DevManagementMenu(AppStore* as){
	string name, address, busName;
	int nif;
	App *app;
	char choice;
	char y;

	if(as->getLoggedInUser()->getType()==1 || (as->getLoggedInUser()->getType()==3 && as->getLoggedInUser()->getID()==this->getID())){


		system("cls");
		cout << "\n INDIVIDUAL DEVELOPER MANAGEMENT: ID=" << getID() << endl;
		cout << " ---------------------------------------------------------" << endl;

		cout << "   1 - Change Name" << endl;
		cout << "   2 - Change Address" << endl;
		cout << "   3 - Change Nif" << endl;
		cout << "   4 - Publish App" << endl;
		cout << endl;
		cout << "   0 - Go Back" << endl;
		cout << endl;
		cout << " Option: ";
		cin >> choice;

		switch(choice)
		{

		case '1':
			system("cls");
			cout << "\n Insert a new name: " ;
			cin.get();
			getline(cin,name);
			setName(name);
			break;
		case '2':
			system("cls");
			cout << "\n Insert a new address:";
			cin.get();
			getline(cin,address);
			setAddress(address);
			break;
		case'3':
			system("cls");
			cout<< "\n Insert a new Nif: ";
			cin >> nif;
			setNif(nif);
			break;
		case '4':
			system("cls");
			cout << "\n PUBLISHING NEW APP: " << endl;
			app = as->AddApplicationMenu();
			addApp(app);
			break;
		case '0':
			system("cls");
			return;
			break;
		default:
			system("cls");
			DevManagementMenu(as);
			break;
		}
		cout << "\n Developer Sucessfully Edited. Press y to go back.";
		cin >> y;
	}
	else{
		cout << " Message: You don't have the permission to access this menu." << endl;
		return;
	}
}

void Company::DevManagementMenu(AppStore* as){
	string name, address, busName;
		int nif, code;
		App *app;
		char choice;
		char y;

		if(as->getLoggedInUser()->getType()==1 || (as->getLoggedInUser()->getType()==3 && as->getLoggedInUser()->getID()==this->getID()) ){

			cout << "\n ENTERPRISE DEVELOPER MANAGEMENT: ID=" << getID() << endl;
			cout << " ---------------------------------------------------------" << endl;

			cout << "   1 - Change Name" << endl;
			cout << "   2 - Change Address" << endl;
			cout << "   3 - Change Nif" << endl;
			cout << "   4 - Publish App" << endl;
			cout << "   5 - Company Name" << endl;
			cout << "   6 - Change Code" << endl;
			cout << endl;
			cout << "   0 - Go back" << endl;
			cout << endl;
			cout << " Option: ";
			cin >> choice;

			switch(choice)
			{

			case '1':
				system("cls");
				cout << "\n Insert a new name: " ;
				cin.get();
				getline(cin,name);
				setName(name);
				break;
			case '2':
				system("cls");
				cout << "\n Insert a new address:";
				cin.get();
				getline(cin,address);
				setAddress(address);
				break;
			case'3':
				system("cls");
				cout<< "\n Insert a new Nif: ";
				cin >> nif;
				setNif(nif);
				break;
			case '4':
				system("cls");
				cout << "\n PUBLISHING NEW APP: " << endl;
				app = as->AddApplicationMenu();
				addApp(app);
				break;
			case '5':
				system("cls");
				cout << "\n Insert new Company Name: ";
				cin.get();
				getline(cin,busName);
				setCompanyName(busName);
				break;
			case'6':
				system("cls");
				cout << "\n Insert new code: ";
				cin >> code;
				setCode(code);
				break;
			case'0':
				system("cls");
				return;
				break;
			default:
				system("cls");
				DevManagementMenu(as);
				break;

			}
			cout << "\n Developer Sucessfully Edited. Press y to go back.";
			cin >> y;
		}

		else{
			cout << "oops" << endl;
			cout << "You don't have the permission to access this menu" << endl;
			return;
		}

}
