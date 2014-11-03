/*
 * AppStore.cpp
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */

#include <string>
#include "AppStore.h"

using namespace std;

AppStore::AppStore() {
	this->name = "APP STORE";
}

AppStore::AppStore(string name) {
	this->name = name;
}

AppStore::~AppStore() {

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
	return false;;
}

