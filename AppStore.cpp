/*
 * AppStore.cpp
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */

#include <string>
#include "AppStore.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>

using namespace std;

AppStore::AppStore() {
	this->name = "APP STORE";
}

AppStore::AppStore(string name) {
	this->name = name;
}

AppStore::~AppStore() {
	for(unsigned int i=0; i<apps.size(); i++){
		delete apps[i];
		apps.erase(apps.begin()+i);
		i--;
	}
	for(unsigned int i=0; i<clients.size(); i++){
		delete clients[i];
		clients.erase(clients.begin()+i);
		i--;
	}
	for(unsigned int i=0; i<developers.size(); i++){
		delete developers[i];
		developers.erase(developers.begin()+i);
		i--;
	}
	for(unsigned int i=0; i<transactions.size(); i++){
		delete transactions[i];
		transactions.erase(transactions.begin()+i);
		i--;
	}
}

void AppStore::addApp(App* app) {
	apps.push_back(app);
}
void AppStore::addClient(Client* cli) {
	clients.push_back(cli);
}
void AppStore::addDeveloper(Developer* dev) {
	developers.push_back(dev);
}

// Saves AND Loads

//Menus

//Gets e Sets

string AppStore::getName() {
	return name;
}
void AppStore::setName(string name) {
	this->name = name;
}

vector<App*> AppStore::getApps() {
	return apps;
}
void AppStore::setApps(vector<App*> apps) {
	this->apps = apps;
}

vector<Client*> AppStore::getClients() {
	return clients;
}
void AppStore::setClients(vector<Client*> clients) {
	this->clients = clients;
}

vector<Developer*> AppStore::getDevelopers() {
	return developers;
}

void AppStore::setDevelopers(vector<Developer*> developers) {
	this->developers = developers;
}

vector<Transaction*> AppStore::getTransactions()
{
	return transactions;
}

void AppStore::setTransactions(vector<Transaction *> transactions)
{
	this->transactions = transactions;
}

bool AppStore::removeApp(App* app) {
	for (unsigned int i = 0; i < apps.size(); i++) {
		if (apps[i] == app)
			apps.erase(apps.begin()+i);
			i--;
			return true;
	}
	return false;
}

App* AppStore::findAppByID(int id){
	for(unsigned int i=0; i<apps.size();i++){
		if(apps[i]->getID()==id) return apps[i];
	}
	throw AppDoesNotExist(id);
	return NULL;
}

Client* AppStore::findClientByID(int id){
	for(unsigned int i=0; i<clients.size();i++){
		if(clients[i]->getID()==id) return clients[i];
	}
	throw ClientDoesNotExist(id);
	return NULL;
}

Developer* AppStore::findDeveloperByID(int id){
	for(unsigned int i=0; i<developers.size();i++){
		if(developers[i]->getID()==id) return developers[i];
	}
	throw DeveloperDoesNotExist(id);
	return NULL;
}

Transaction* AppStore::findTransactionByID(int id){
	for(unsigned int i=0; i<transactions.size();i++){
		if(transactions[i]->getID()==id) return transactions[i];
	}
	throw TransactionDoesNotExist(id);
	return NULL;
}

//////////MENUS//////////

/////////////////////////
////////SUB APP /////////
/////////////////////////

void AppStore::AppsListName() {
	cout << "Apps List By NAME: " << endl;

	//display da função da lista

	cout << endl;
	string y;
	cout << "Go Back? (y)";
	cin >> y;
	system("cls");
	AppsMenu();

}

void AppStore::AppsListSale() {
	cout << "Apps List By SALE NUMBERS: " << endl;

	//display da função da lista

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		AppsMenu();}
}

void AppStore::AppsListType() {
	cout << "Apps List By TYPE: " << endl;

	//display da função da lista

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		AppsMenu();}
}

void AppStore::RateApps() {
	string name;
	char y = 'y';
	int rate;

	cout << "Which App Do You Want To Rate?" << endl;
	cout << "Apps List" << endl;
	//call Apps List by name
	cin >> name;
	system("cls");
	cout << "RATE:" << endl;
	cout << "1 - Hate" << endl;
	cout << "2 - Dislike" << endl;
	cout << "3 - Like" << endl;
	cout << "4 - Adore" << endl;
	cout << "5 - Amazing" << endl;
	cout << "0 - Go Back" << endl;
	cout << "OPTION: ";
	cin >> rate;

	switch(rate) {

	case 1: system("cls");
			//call function to rate wt 1;
			cout << "App rated successfully!";
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if(y == 'y') {
			system("cls");
			AppsMenu();}
			break;
	case 2: system("cls");
			//call function to rate wt 2;
			cout << "App rated successfully!";
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if(y == 'y') {
			system("cls");
			AppsMenu();}
			break;
	case 3: system("cls");
			//call function to rate wt 3;
			cout << "App rated successfully!";
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if(y == 'y') {
			system("cls");
			AppsMenu();}
			break;
	case 4: system("cls");
			//call function to rate wt 4;
			cout << "App rated successfully!";
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if(y == 'y') {
			system("cls");
			AppsMenu();}
			break;
	case 5: system("cls");
			//call function to rate wt 5;
			cout << "App rated successfully!";
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if(y == 'y') {
			system("cls");
			AppsMenu();}
			break;
	case 0: system("cls");
			AppsMenu();
			break;
	default: break;
	}
}

void AppStore::AddApplication() {
	string name;
	cout << "Name Of The App To Be Added: ";
	cin >> name;

	//call function that adds apps

	cout << "App" << name << "Added Successfully To The Appstore" << endl;
	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
	system("cls");
	AppsMenu();}
}

void AppStore::RemoveApplication() {
	string name;
	cout << "Name Of The App To Be Removed: ";
	cin >> name;

	//call function that removes apps

	cout << "App" << name << "Removed Successfully From The Appstore" << endl;
	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		AppsMenu();}
}

/////////////////////////
//////SUB CLIENT ////////
/////////////////////////

void AppStore::ClientsList() {
	cout << "CLIENTS LIST" << endl;
	//display list

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if(y == 'y') {
	system("cls");
	ClientMenu();
	}
}

void AppStore::PurchasedApps() {
	cout << "PURCHASED APPS" << endl;
	//display list

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		ClientMenu();}
}

void AppStore::AddClients() {
	string name;
	cout << "Name Of The Client To Be Added: ";
	cin >> name;

	//add client

	cout << "Client Added Successfully To The Appstore Database" << endl;

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		ClientMenu();
	}
}

void AppStore::RemoveClients() {
	string name;
	cout << "Name Of The Client To Be Removed: ";
	cin >> name;

	//remove client

	cout << "Client Removed Successfully From The Appstore Database" << endl;

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		ClientMenu();
	}

}

/////////////////////////
//////SUB DEV ///////////
/////////////////////////

void AppStore::IndividualDevList() {
	cout << "INDIVIDUAL DEVELOPERS: " << endl;

	//display list

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		DeveloperMenu();
	}


}

void AppStore::EnterpriseList() {
	cout << "ENTERPRISES: " << endl;

	//display list

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		DeveloperMenu();
	}


}

void AppStore::AppsCreated() {
	int choice;
	char y = 'y';
	string name;
	cout << "APPS CREATED BY A DEV/ENTERPRISE: " << endl;
	cout << "1 - Individual Developer" << endl;
	cout << "2 - Enterprise" << endl;
	cout << "0 - Go back" << endl;
	cout << "OPTION: ";
	cin >> choice;

	switch(choice) {

	case 1: system("cls");
			//display list of devs
			cout << endl;
			cout << "Apps Created By: ";
			cin >> name;
			//display apps;
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				DeveloperMenu();
			}
			break;
	case 2: system("cls");
			//display list of enterprises
			cout << endl;
			cout << "Apps Created By: ";
			cin >> name;
			//display apps;
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				DeveloperMenu();
			}
			break;
	case 0: system("cls");
			DeveloperMenu();
			break;
	default: break;
	}
}

void AppStore::SalesData() {

}

void AppStore::AddDev() {
	string name;
	cout << "Developer To Be Added: ";
	cin >> name;

	//add dev to the appstore

	cout << "Developer Added Successfully To The Appstore" << endl;

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		DeveloperMenu();
	}
}

void AppStore::RemoveDev() {
	string name;
	cout << "Developer To Be Removed: ";
	// display list of Devs
	cout << "Remove: ";
	cin >> name;

	//add dev to the appstore

	cout << "Developer Removed Successfully From The Appstore" << endl;

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		DeveloperMenu();
	}
}

/////////////////////////
//////SUB TRANS /////////
/////////////////////////

void AppStore::TransApps() {
	cout << "APPS TRANSACTIONS: " << endl;
	//display apps transactions

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		TransactionMenu();
	}
}

void AppStore::TransClients() {
	cout << "CLIENTS TRANSACTIONS: " << endl;
	//display the client transactions????

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		TransactionMenu();
	}
}

void AppStore::TransDev() {
	cout << "DEVELOPERS/ENTERPRISES TRANSACTIONS: " << endl;
	//display the devs list and which transaction the client wants to see????? lol

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		TransactionMenu();
	}
}

/**********************************************************
 *                    SAVES AND LOADS                     *
 *********************************************************/

void AppStore::saveApps()
{
	vector<App *>::iterator it = apps.begin();

	ofstream file;
	file.open("apps.txt",ios::trunc);

	for(; it != apps.end(); it++)
	{
		(*it)->writeToFile(file);
	}
	system("cls");
	file.close();
	cout << "\n Apps saved." << endl;
}

void AppStore::saveDevelopers()
{
	vector<Developer *>::iterator it = developers.begin();

	ofstream file;
	file.open("developers.txt",ios::trunc);

	for(; it != developers.end(); it++)
	{
		(*it)->writeToFile(file);
	}
	system("cls");
	file.close();
	cout << "\n Developers saved." << endl;
}

void AppStore::saveClients()
{
	vector<Client *>::iterator it = clients.begin();

	ofstream file;
	file.open("clients.txt",ios::trunc);

	for(; it != clients.end(); it++)
	{
		(*it)->writeToFile(file);
	}
	system("cls");
	file.close();
	cout << "\n Clients saved." << endl;
}

void AppStore::saveTransactions()
{
	vector<Transaction *>::iterator it = transactions.begin();

	ofstream file;
	file.open("transactions.txt",ios::trunc);

	for(; it != transactions.end(); it++)
	{
		(*it)->writeToFile(file);
	}
	system("cls");
	file.close();
	cout << "\n Transactions saved." << endl;
}


