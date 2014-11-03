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
	vector<App*> apps;
	// Todos os clientes
	vector<Client*> clients;
	// Todos os developers
	vector<Developer*> developers;
public:
	AppStore();
	AppStore(string name);
	~AppStore();
	void addApp(App* app);
	void addClient(Client* cli);
	void addDeveloper(Developer* dev);
	bool removeApp(App* app);
	bool removeClient(Client* cli);
	bool removeDeveloper(Developer* dev);

	App* findAppByID(int id);
	Client* findClientByID(int id);
	Developer* findDeveloperByID(int id);
	Transaction* findTransactionByID(int id);


	// Saves AND Loads
	void saveAppstore(string filename);
	void loadAppstore(string filename);
	//Menus

	//Gets e Sets


	string getName();
	void setName(string name);


	vector<App*> getApps();
	void setApps(vector<App*> apps);
	void saveApps(string filename);
	void loadApps(string filename);

	vector<Client*> getClients();
	void setClients(vector<Client*> clients);
	void saveClients(string filename);
	void loadClients(string filename);

	vector<Developer*> getDevelopers();
	void setDevelopers(vector<Developer*> developers);
	void saveDevelopers(string filename);
	void loadDevelopers(string filename);

};



#endif /* APPSTORE_H_ */
