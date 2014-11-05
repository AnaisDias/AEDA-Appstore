/*
 * AppStore.cpp
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */

#include <string>
#include "AppStore.h"
#include "Exceptions.h"

using namespace std;

AppStore::AppStore() {
	this->name = "APP STORE";
}

AppStore::AppStore(string name) {
	this->name = name;
}

AppStore::~AppStore() {
	for(int i=0; i<apps.size(); i++){
			delete apps[i];
			apps.erase(apps.begin()+i);
			i--;
		}
	for(int i=0; i<clients.size(); i++){
			delete clients[i];
			clients.erase(clients.begin()+i);
			i--;
		}
	for(int i=0; i<developers.size(); i++){
			delete developers[i];
			developers.erase(developers.begin()+i);
			i--;
		}
	for(int i=0; i<transactions.size(); i++){
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

bool AppStore::removeApp(App* app) {
	for (int i = 0; i < apps.size(); i++) {
		if (apps[i] == app)
			apps.erase(apps.begin()+i);
			i--;
			return true;
	}
	return false;
}

App* AppStore::findAppByID(int id){
	for(int i=0; i<apps.size();i++){
		if(apps[i]->getID()==id) return apps[i];
	}
	throw AppDoesNotExist(id);
	return NULL;
}

Client* AppStore::findClientByID(int id){
	for(int i=0; i<clients.size();i++){
		if(clients[i]->getID()==id) return clients[i];
	}
	throw ClientDoesNotExist(id);
	return NULL;
}

Developer* AppStore::findDeveloperByID(int id){
	for(int i=0; i<developers.size();i++){
		if(developers[i]->getID()==id) return developers[i];
	}
	throw DeveloperDoesNotExist(id);
	return NULL;
}

Transaction* AppStore::findTransactionByID(int id){
	for(int i=0; i<transactions.size();i++){
		if(transactions[i]->getID()==id) return transactions[i];
	}
	throw TransactionDoesNotExist(id);
	return NULL;
}
