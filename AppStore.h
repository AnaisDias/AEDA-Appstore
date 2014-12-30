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
#include<queue>
#include<string>
#include "App.h"
#include "Client.h"
#include "Developer.h"
#include "Menu.h"
#include "BST.h"
#include <tr1/unordered_set>

using namespace std;

struct hApp {

	int operator()(const App& app) const{
		int hashVal = 0;
		for ( int i = 0; i <app.getName().size() ; i++ )
			hashVal = 37*hashVal + app.getName()[i];
		return hashVal;
	}

	bool operator()(const App& app1, const App& app2) const {
		return (app1.getName()==app2.getName() && app1.getID()==app2.getID());
	}

};
typedef tr1::unordered_set<App, hApp, hApp> hashApp;

class AppStore {
	string name;
	// Todas as apps
	vector<App*> apps;
	// Todos os clientes
	vector<Client*> clients;
	// Todos os developers
	vector<Developer*> developers;
	vector<Transaction*> transactions;
	BST<App*> appTree;
	hashApp appsNotForSale;
	//priority_queue<App*, vector<App*>, AppCompare> unacceptedApps;

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

	void addToPQ(App *app);

	App* findAppByID(int id);
	vector<App*> findAppsByName(string name);
	vector<App*> findAppsByType(int type);
	vector<App*> topTenApps();


	Client* findClientByID(int id);
	Developer* findDeveloperByID(int id);
	Transaction* findTransactionByID(int id);

	//Gets e Sets


	string getName();
	void setName(string name);

	vector<App*> getApps();
	BST<App*> getAppTree();
	void setApps(vector<App*> apps);
	void setAppTree(BST<App*> apps);
	void saveApps();
	void loadApps();
	void loadApps2();
	void assignTransactionsToApps();
	//hashApp
	bool sellApp(App* app);
	bool removeSaleApp(App* app);
	vector<App> getUnsoldAppsByDeveloper(Developer *dev);
	vector<App*> getAppsForSale();

	vector<Client*> getClients();
	void setClients(vector<Client*> clients);
	void saveClients();
	void loadClients();

	vector<Developer*> getDevelopers();
	void setDevelopers(vector<Developer*> developers);
	void saveDevelopers();
	void loadDevelopers();
	void assignPublishedAppsToDevs();

	vector<Transaction*> getTransactions();
	void setTransactions(vector<Transaction *> transactions);
	void saveTransactions();
	void loadTransactions();



	///MENUS///
	void ShowIndivDev();
	void ShowCompDev();
	void ShowAppsByName(int id);

	//APPS//
	void top10Apps();
	void AppsListName();
	void AppsListType();
	void AllAppsList();
	void RateApps();
	App* AddApplicationMenu(); //uses addApp
	void RemoveApplicationMenu(); //uses removeApp
	void AppManagementMenu(App* app);
	void addDeveloperMenu();

	//CLIENT//
	void ClientsList();
	void PurchasedApps();
	void AddClients();
	void RemoveClients();
	void ClientManagementMenu(Client* client);
	void BuyApp(Client* cli);


	//DEV//
	void IndividualDevList();
	void EnterpriseList();
	void AppsCreated();
	void SalesData();
	void AddDev();
	void RemoveDev();
	void ShowAllDev();
	void DevManagementMenu(Developer* dev){}
	void DevManagementMenu(Individual* ind);
	void DevManagementMenu(Company* comp);

	//TRANSACTIONS//
	void TransApps();
	void TransClients();
	void TransDev();
	void ShowAllTransactions();

};



#endif /* APPSTORE_H_ */
