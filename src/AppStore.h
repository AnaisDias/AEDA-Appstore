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
	/*
	 * Constructs and initializes an AppStore by default.
	 */
	AppStore();
	/*
	 * Destructs and erases the members of an AppStore.
	 */
	~AppStore();

	/*
	 * Gets the name of the AppStore
	 * @return name
	 * 				name of the AppStore
	 */
	string getName();

	/*
	 * Sets the name of the AppStore
	 * @param name
	 * 				name of the AppStore
	 */
	void setName(string name);

	/*
	 * Adds a pointer to an app to the AppStore
	 *
	 * @param app
	 * 				pointer to App
	 */
	void addApp(App* app);

	/*
	 * Adds a pointer to a client to the AppStore
	 *
	 * @param cli
	 * 				pointer to client
	 */
	void addClient(Client* cli);

	/*
	 * Adds a pointer to a developer to the AppStore
	 *
	 * @param dev
	 * 				pointer to developer
	 */
	void addDeveloper(Developer* dev);

	/*
	 * Adds a pointer to a user to the AppStore
	 *
	 * @param user
	 * 				pointer to user
	 */
	void addUser(User* user);

	/*
	 * Removes a pointer to an app from the apps vector in the AppStore, that stores all apps.
	 *
	 * @param app
	 * 				pointer to app to be removed
	 * @return true if app exists and was removed, false if it does not exist in the AppStore
	 */
	bool removeApp(App* app);

	/*
	 * Removes a pointer to a client from the clients vector in the AppStore, that stores all clients.
	 *
	 * @param cli
	 * 				pointer to client to be removed
	 * @return true if client exists and was removed, false if it does not exist in the AppStore
	 */
	bool removeClient(Client* cli);

	/*
	 * Removes a pointer to a developer from the developers vector in the AppStore, that stores all developers.
	 *
	 * @param dev
	 * 				pointer to developer to be removed
	 * @return true if developer exists and was removed, false if it does not exist in the AppStore
	 */
	bool removeDeveloper(Developer* dev);


	/*
	 * Adds a pointer to an app to the priority queue that stores apps that were not yet accepted
	 *
	 * @param app
	 * 				pointer to app
	 */
	void addToPQ(App *app);

	/*
	 * Pops the top app from the priority queue that stores apps that were not yet accepted
	 *
	 */
	void removeFromPQ();

	/*
	 * Searches app which has the id passed as argument
	 *
	 * @param id
	 * 				id of app to be returned
	 * @return pointer to app with the requested id
	 */
	App* findAppByID(int id);

	/*
	 * Searches all apps which have the name passed as argument
	 *
	 * @param name
	 * 				name of apps to be returned
	 * @return vector of pointers to apps with the requested name
	 */
	vector<App*> findAppsByName(string name);

	/*
	 * Searches all apps which have the type passed as argument
	 *
	 * @param type
	 * 				type of apps to be returned
	 * @return vector of pointers to apps with the requested type
	 */
	vector<App*> findAppsByType(int type);

	/*
	 * Assembles a vector of the top ten apps, by going through the first ten apps in the binary search tree of the Appstore
	 *
	 * @return vector of pointers to the top ten apps
	 */
	vector<App*> topTenApps();

	/*
	 * Searches client which has the id passed as argument
	 *
	 * @param id
	 * 				id of client to be returned
	 * @return pointer to client with the requested id
	 */
	Client* findClientByID(int id);

	/*
	 * Searches developer which has the id passed as argument
	 *
	 * @param id
	 * 				id of developer to be returned
	 * @return pointer to developer with the requested id
	 */
	Developer* findDeveloperByID(int id);

	/*
	 * Searches transaction which has the id passed as argument
	 *
	 * @param id
	 * 				id of transaction to be returned
	 * @return pointer to transaction with the requested id
	 */
	Transaction* findTransactionByID(int id);

	/*
	 * Searches unaccepted app which has the id passed as argument in the priority queue
	 *
	 * @param id
	 * 				id of app to be returned
	 * @return pointer to app with the requested id
	 */
	App* findUnacceptedAppsByID(int id);

	/*
	 * Searches user which has the username passed as argument
	 *
	 * @param username
	 * 				username of user to be returned
	 * @return pointer to user with the requested username
	 */
	User* findUserByUsername(string username);

	/*
	 * Returns pointer to the currently logged in user
	 *
	 * @return pointer to user that is currently logged in
	 */
	User* getLoggedInUser() const;

	/*
	 * Sets the currently logged in user to the pointer passed as parameter
	 *
	 * @param pointer to user
	 */
	void setLoggedInUser(User* user);

	/*
	 * Returns all the apps in the appstore
	 *
	 * @return vector of pointers to all the apps
	 */
	vector<App*> getApps();

	/*
	 * Returns the appstore's binary search tree
	 *
	 * @return Appstore's binary search tree
	 */
	BST<App*> getAppTree();

	/*
	 * Sets all the apps in the appstore
	 *
	 * @param vector of pointers to all the apps
	 */
	void setApps(vector<App*> apps);


	/*
	 * Sets the appstore's binary search tree
	 *
	 * @param binary search tree
	 */
	void setAppTree(BST<App*> apps);

	/*
	 * Saves all the apps in the appstore to a txt file
	 */
	void saveApps();

	/*
	 * Loads all the apps to the appstore from a txt file
	 */
	void loadApps();

	/*
	 * Auxiliary function to loading functions, performs the linking between transactions and apps
	 */
	void assignTransactionsToApps();

	/*
	 * Removes pointer to app from hash table of apps that are not for sale and changes app's forSale value to true
	 *
	 * @param app
	 * 				pointer to app to be sold
	 * @return true if app exists and is now for sale, false if it does not exist in the hash table
	 */
	bool sellApp(App* app);

	/*
	 * Inserts pointer to app in hash table of apps that are not for sale and changes app's forSale value to false
	 *
	 * @param app
	 * 				pointer to app that will no longer be sold
	 * @return true if app did not exist previously in hash table and is now not for sale, false if it already was in the hash table
	 */
	bool removeSaleApp(App* app);

	/*
	 * Returns vector of pointers to apps that are not for sale and that are published by the parameter developer
	 *
	 * @param dev
	 * 				pointer to developer
	 * @return
	 * 				vector of pointers to apps
	 */
	vector<App*> getUnsoldAppsByDeveloper(Developer *dev);

	/*
	 * Returns vector of pointers to all apps that are for sale
	 *
	 * @return
	 * 			vector of pointers to apps
	 */
	vector<App*> getAppsForSale();

	/*
	 * Returns vector of pointers to all apps that are for sale from the apps present in the parameter vector
	 *
	 * @param
	 * 			vector of pointer to apps
	 *
	 * @return
	 * 			vector of pointers to apps
	 */
	vector<App*> getAppsForSaleFromVector(vector<App*> apps);

	/*
	 * Returns vector of pointers to apps that are not for sale and that are published by the developer with the parameter id
	 *
	 * @param id
	 * 				id of developer
	 * @return
	 * 				vector of pointers to apps
	 */
	vector<App*> getDeveloperAppsForSale(int id);

	/*
	 * If vector has a pointer to an app with the specified ID, this function returns true, otherwise it returns false
	 *
	 * @param apps
	 * 				vector of pointers to apps
	 * @param id
	 * 				id of app
	 *
	 * @return
	 * 				boolean value
	 */
	bool isIDinAppVector(vector<App*> apps, int id);
	/*
	 * Returns vector of pointers to all the clients in the appstore
	 *
	 * @return
	 * 				vector of pointers to clients
	 */
	vector<Client*> getClients();

	/*
	 * Sets vector of pointers to all the clients in the appstore as the parameter passed
	 *
	 * @param
	 * 				vector of pointers to clients
	 */
	void setClients(vector<Client*> clients);

	/*
	 * Saves all the clients in the appstore to a txt file
	 */
	void saveClients();

	/*
	 * Loads all the clients to the appstore from a txt file
	 */
	void loadClients();

	/*
	 * Returns vector of pointers to all the developers in the appstore
	 *
	 * @return
	 * 				vector of pointers to developers
	 */
	vector<Developer*> getDevelopers();

	/*
	 * Sets vector of pointers to all the developers in the appstore as the parameter passed
	 *
	 * @param
	 * 				vector of pointers to developers
	 */
	void setDevelopers(vector<Developer*> developers);

	/*
	 * Saves all the developers in the appstore to a txt file
	 */
	void saveDevelopers();
	/*
	 * Loads all the developers to the appstore from a txt file
	 */
	void loadDevelopers();

	/*
	 * Saves all the users in the appstore to a txt file
	 */
	void saveUsers();
	/*
	 * Loads all the users to the appstore from a txt file
	 */
	void loadUsers();

	/*
	 * Auxiliary function to loading functions, performs the linking between apps and developers
	 */
	void assignPublishedAppsToDevs();
	/*
	 * Auxiliary function to loading functions, performs the linking between transactions and clients
	 */
	void assignTransactionsToClients();
	/*
	 * Returns vector of pointers to all the transactions in the appstore
	 *
	 * @return
	 * 				vector of pointers to transactions
	 */
	vector<Transaction*> getTransactions();

	/*
	 * Sets vector of pointers to all the transactions in the appstore as the parameter passed
	 *
	 * @param
	 * 				vector of pointers to transactions
	 */
	void setTransactions(vector<Transaction *> transactions);

	/*
	 * Saves all the transactions in the appstore to a txt file
	 */
	void saveTransactions();

	/*
	 * Loads all the transactions to the appstore from a txt file
	 */
	void loadTransactions();



	///MENUS///

	/*
	 * Menu that displays individual developers
	 */
	void ShowIndivDev();
	/*
	 * Menu that displays company developers
	 */
	void ShowCompDev();
	void ShowAppsByName(int id);

	//APPS//
	/*
	 * Menu that displays the top ten apps in the appstore
	 */
	void top10Apps();
	/*
	 * Menu that displays apps listed by name
	 */
	void AppsListName();

	/*
	 * Menu that displays apps listed by type
	 */
	void AppsListType();

	/*
	 * Menu that displays all apps
	 */
	void AllAppsList();

	/*
	 * Menu that displays all apps not for sale
	 */
	void AppsNotForSaleList();

	/*
	 * Menu that allows the rating of apps
	 */
	void RateApps();

	/*
	 * Menu that allows the addition of a new app
	 */
	App* AddApplicationMenu();

	/*
	 * Menu that allows the removal of an app
	 */
	void RemoveApplicationMenu();

	/*
	 * Menu that allows the removal of the sale of an app
	 */
	void RemoveSaleMenu();

	/*
	 * Menu that allows the activation of the sale of an app
	 */
	void StartSaleMenu();
	/*
	 * Menu that allows the management of an app
	 *
	 * @param app
	 * 				pointer to app to be managed
	 */
	void AppManagementMenu(App* app);

	/*
	 * Menu that allows the addition of a new developer
	 */
	void addDeveloperMenu();

	/*
	 * Menu that allows the approval of an app
	 */
	void ApproveNewApps();

	//CLIENT//

	/*
	 * Menu that displays all clients
	 */
	void ClientsList();

	/*
	 * Menu that displays the apps purchased by a given client
	 */
	void PurchasedApps();

	/*
	 * Menu that allows the addition of a new client
	 */
	void AddClients();

	/*
	 * Menu that allows the removal of a client
	 */
	void RemoveClients();

	/*
	 * Menu that allows the management of a client
	 *
	 * @param client
	 * 				pointer to client to be managed
	 */
	void ClientManagementMenu(Client* client);

	/*
	 * Menu that allows the purchase of apps by a given client
	 */
	void BuyApp(Client* cli);


	//DEV//

	/*
	 * Menu that displays all individual developers
	 */
	void IndividualDevList();

	/*
	 * Menu that displays all company developers
	 */
	void EnterpriseList();

	/*
	 * Menu that displays the apps created by a given developer
	 */
	void AppsCreated();

	/*
	 * Menu that displays the sales of the apps created by a given developer
	 */
	void SalesData();

	/*
	 * Menu that allows the addition of a new developer
	 */
	void AddDev();

	/*
	 * Menu that allows the removal of a developer
	 */
	void RemoveDev();

	/*
	 * Menu that displays all developers
	 */
	void ShowAllDev();


	//TRANSACTIONS//
	/*
	 * Menu that displays all transactions of a given app
	 */
	void TransApps();
	/*
	 * Menu that displays all transactions of a given client
	 */
	void TransClients();
	/*
	 * Menu that displays all transactions of a given developer
	 */
	void TransDev();
	/*
	 * Menu that displays all transactions
	 */
	void ShowAllTransactions();

};



#endif /* APPSTORE_H_ */
