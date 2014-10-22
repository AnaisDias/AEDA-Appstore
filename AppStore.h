/*
 * AppStore.h
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */

#ifndef APPSTORE_H_
#define APPSTORE_H_
#pragma once

#include<vector>
#include<string>
#include "App.h"
#include "Client.h"
#include "Developer.h"

using namespace std;

class AppStore {
	string name;
	// Todas as apps
	vector<App> apps;
	// Todos os clientes
	vector<Client> clients;
	// Todos os developers
	vector<Developer> developers;
public:
	AppStore();
	AppStore(string name);
	~AppStore();
	void addApp(App app);
	void addClient(Client cli);
	void addDeveloper(Developer dev);

	// Saves AND Loads

	//Menus

	//Gets e Sets

	string getName();
	void setName(string name);

	vector<App> getApps();
	void setApps(vector<App> apps);

	vector<Client> getClients();
	void setClients(vector<Client> clients);

	vector<Developer> getDevelopers();
	void setDevelopers(vector<Developer> developers);
};



#endif /* APPSTORE_H_ */