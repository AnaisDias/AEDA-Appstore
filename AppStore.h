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
#include "Menu.h"

using namespace std;

class AppStore {
	string name;
	// Todas as apps
	vector<App*> apps;
	// Todos os clientes
	vector<Client*> clients;
	// Todos os developers
	vector<Developer*> developers;
	vector<Transaction*> transactions;
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

	///MENUS///

	//APPS//
	void AppsListName();
	void AppsListSale();
	void AppsListType();
	void RateApps();
	void AddApplication(); //uses addApp
	void RemoveApplication(); //uses removeApp

	//CLIENT//
	void ClientsList();
	void PurchasedApps();
	void AddClients();
	void RemoveClients();

	//DEV//
	void IndividualDevList();
	void EnterpriseList();
	void AppsCreated();
	void SalesData();
	void AddDev();
	void RemoveDev();

	//TRANSACTIONS//
	void TransApps();
	void TransClients();
	void TransDev();

};



#endif /* APPSTORE_H_ */
