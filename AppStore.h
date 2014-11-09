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
	vector<App*> findAppsByName(string name);
	vector<App*> findAppsByType(int type);
	vector<App*> orderAppsByTop5Rating();


	Client* findClientByID(int id);
	Developer* findDeveloperByID(int id);
	Transaction* findTransactionByID(int id);

	//Gets e Sets


	string getName();
	void setName(string name);

	vector<App*> getApps();
	void setApps(vector<App*> apps);
	void saveApps();
	void loadApps(string filename);

	vector<Client*> getClients();
	void setClients(vector<Client*> clients);
	void saveClients();
	void loadClients(string filename);

	vector<Developer*> getDevelopers();
	void setDevelopers(vector<Developer*> developers);
	void saveDevelopers();
	void loadDevelopers(string filename);

	vector<Transaction*> getTransactions();
	void setTransactions(vector<Transaction *> transactions);
	void saveTransactions();
	void loadTransaction();



	//APPS//
	void Top5Apps();
	void AppsListName();
	void AppsListType();
	void AllAppsList();
	void RateApps();
	void AddApplicationMenu(); //uses addApp
	void RemoveApplicationMenu(); //uses removeApp
	void AppManagementMenu(App* app);

	//CLIENT//
	void ClientsList();
	void PurchasedApps();
	void AddClients();
	void RemoveClients();

	//DEV//
	void IndividualDevList(AppStore as);
	void EnterpriseList(AppStore as);
	void AppsCreated(AppStore as);
	void SalesData(AppStore as);
	void AddDev(AppStore as);
	void RemoveDev(AppStore as);

	//TRANSACTIONS//
	void TransApps(AppStore as);
	void TransClients(AppStore as);
	void TransDev(AppStore as);

};



#endif /* APPSTORE_H_ */
