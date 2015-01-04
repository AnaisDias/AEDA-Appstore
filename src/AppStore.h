/*
c * AppStore.h
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */

#ifndef APPSTORE_H_
#define APPSTORE_H_


#include<vector>
#include<queue>
#include<string>
#include "App.h"
#include "Client.h"
#include "Developer.h"
#include "Menu.h"
#include "BST.h"
#include "User.h"
#include <tr1/unordered_set>
#pragma once

using namespace std;

struct hApp {

	int operator()(const App *app) const{
		int hashVal = 0;
		for (unsigned int i = 0; i<app->getName().size() ; i++ )
			hashVal = 37*hashVal + app->getName()[i];
		return hashVal;
	}

	bool operator()(const App *app1, const App *app2) const {
		return (app1->getName()==app2->getName() && app1->getID()==app2->getID());
	}

};
typedef tr1::unordered_set<App*, hApp, hApp> hashApp;

struct AppCompare
{
	bool operator()(const App* app1, const App* app2) const
	{
		if(app1->getTime()>app2->getTime()) return true;
		else if(app1->getTime()==app2->getTime()){
			if(app1->getPrice()<app2->getPrice()) return true;
			else if(app1->getPrice()==app2->getPrice()){
				return app1->getName()<app2->getName();
			}
		}
		return false;
	}
};

typedef std::priority_queue<App*, vector<App*>, AppCompare> appsPQ;

class AppStore {
	string name;
	vector<App*> apps;
	vector<Client*> clients;
	vector<Developer*> developers;
	vector<User *> users;
	vector<Transaction*> transactions;
	BST<App*> appTree;
	hashApp appsNotForSale;
	User* loggedInUser;
	appsPQ unacceptedApps;
public:
	AppStore();
	~AppStore();
	void addApp(App* app);
	void addClient(Client* cli);
	void addDeveloper(Developer* dev);
	void addUser(User* user);
	bool removeApp(App* app);
	bool removeClient(Client* cli);
	bool removeDeveloper(Developer* dev);

	void addToPQ(App *app);
	void removeFromPQ(App *app);

	App* findAppByID(int id);
	vector<App*> findAppsByName(string name);
	vector<App*> findAppsByType(int type);
	vector<App*> topTenApps();

	Client* findClientByID(int id);
	Developer* findDeveloperByID(int id);
	Transaction* findTransactionByID(int id);
	App* findUnacceptedAppsByID(int id);

	User* findUserByUsername(string username);

	string getName();
	void setName(string name);

	User* getLoggedInUser() const;
	void setLoggedInUser(User* user);

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
	vector<App*> getUnsoldAppsByDeveloper(Developer *dev);
	vector<App*> getAppsForSale();

	vector<App*> getAppsForSaleFromVector(vector<App*> apps);

	vector<App*> getDeveloperAppsForSale(int id);

	vector<Client*> getClients();
	void setClients(vector<Client*> clients);
	void saveClients();
	void loadClients();

	vector<Developer*> getDevelopers();
	void setDevelopers(vector<Developer*> developers);
	void saveDevelopers();
	void loadDevelopers();
	void saveUsers();
	void loadUsers();
	void assignPublishedAppsToDevs();

	void saveUnacceptedApps();
	void loadUnacceptedApps();
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
	void AppsNotForSaleList();
	void RateApps();
	App* AddApplicationMenu(); //uses addApp
	void RemoveApplicationMenu(); //uses removeApp
	void RemoveSaleMenu();
	void StartSaleMenu();
	void AppManagementMenu(App* app);
	void addDeveloperMenu();
	void ApproveNewApps();

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


	//TRANSACTIONS//
	void TransApps();
	void TransClients();
	void TransDev();
	void ShowAllTransactions();

};



#endif /* APPSTORE_H_ */
