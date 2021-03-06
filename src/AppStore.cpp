/*
 /*!
 * \file AppStore.cpp
 *
 * \author FEUP AEDA1415
 * \author Sofia Reis
 * \author Anais Dias
 * \author Joao Viana
 *
 * \date Janeiro 2015
 *
 */
#include <string>
#include "AppStore.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <time.h>

using namespace std;

AppStore::AppStore():appTree(new App()) {
	this->name = "APP STORE";
}

AppStore::~AppStore() {
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
	appTree.insert(app);
	if(!app->getSaleStatus()) appsNotForSale.insert(app);
}
void AppStore::addClient(Client* cli) {
	clients.push_back(cli);
}
void AppStore::addDeveloper(Developer* dev) {
	developers.push_back(dev);
}

void AppStore::addUser(User* user){
	users.push_back(user);
}

string AppStore::getName() {
	return name;
}
void AppStore::setName(string name) {
	this->name = name;
}

User* AppStore::getLoggedInUser() const{
	return loggedInUser;
}

void AppStore::setLoggedInUser(User* user){
	loggedInUser=user;
}

vector<App*> AppStore::getApps() {
	return apps;
}

BST<App*> AppStore::getAppTree(){
	return appTree;
}

void AppStore::setApps(vector<App*> apps) {
	this->apps = apps;
}

void AppStore::setAppTree(BST<App*> apps){
	this->appTree=apps;
}

bool AppStore::sellApp(App* app){
	hashApp::iterator it = appsNotForSale.find(app);
	if(it == appsNotForSale.end()) return false;
	else{
		app->setSaleStatus(true);
		appsNotForSale.erase(it);
		return true;
	}
}

bool AppStore::removeSaleApp(App* app){

	if(app->getSaleStatus()==false) return false;
	else{
		app->setSaleStatus(false);
		pair<hashApp::iterator, bool> it = appsNotForSale.insert(app);
		return it.second;
	}
}

vector<App*> AppStore::getUnsoldAppsByDeveloper(Developer *dev){
	vector<App*> apps;
	hashApp::iterator it = appsNotForSale.begin();
	while(it!=appsNotForSale.end()){
		if((*it)->getDeveloper()->getID()==dev->getID()) apps.push_back(*it);
		it++;
	}
	return apps;

}

vector<App*> AppStore::getAppsForSale(){
	vector<App*> sale;
	for(unsigned int i=0;i<apps.size();i++){
		if(apps[i]->getSaleStatus()){
			sale.push_back(apps[i]);
		}
	}
	return sale;
}

vector<App*> AppStore::getAppsForSaleFromVector(vector<App*> apps){
	vector<App*> sale;
	for(unsigned int i=0;i<apps.size();i++){
		if(apps[i]->getSaleStatus()){
			sale.push_back(apps[i]);
		}
	}
	return sale;
}

bool AppStore::isIDinAppVector(vector<App*> apps, int id){
	for(int i=0; i<apps.size();i++){
		if(apps[i]->getID()==id) return true;
	}

	return false;
}

vector<App*> AppStore::getDeveloperAppsForSale(int id){
	vector<App*> sale;
		for(unsigned int i=0;i<apps.size();i++){
			if(apps[i]->getSaleStatus() && apps[i]->getDeveloper()->getID()==id){
				sale.push_back(apps[i]);
			}
		}
		return sale;
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
		if ((*apps[i]) == (*app)){
			apps.erase(apps.begin()+i);
			i--;
			appTree.remove(app);
			return true;
		}
	}
	return false;
}

bool AppStore::removeClient(Client* client){
	for (unsigned int i = 0; i < clients.size(); i++) {
		if ((*clients[i]) == (*client)){
			clients.erase(clients.begin()+i);
			i--;
			return true;
		}
	}
	return false;
}

bool AppStore::removeDeveloper(Developer *dev){
	for (unsigned int i = 0; i < developers.size(); i++) {
		if ((*developers[i]) == (*dev)){
				developers.erase(developers.begin()+i);
				i--;
				return true;
		}
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

vector<App*> AppStore::findAppsByName(string name){
	vector<App*> appsbyname;
	for(unsigned int i=0; i<apps.size();i++){
		if(apps[i]->getName()==name) appsbyname.push_back(apps[i]);
	}
	return appsbyname;
}

vector<App*> AppStore::findAppsByType(int type){
	vector<App*> appsbytype;
	for(unsigned int i=0; i<apps.size();i++){
		if(apps[i]->getType()==type) appsbytype.push_back(apps[i]);
	}
	return appsbytype;
}

bool ordenaRating(App* app1, App* app2){
	return (app1->getRatings() > app2->getRatings());
}

vector<App*> AppStore::topTenApps(){
	BSTItrIn<App*> it(appTree);
	int n=0;
	vector<App*> top10;
	while(n<10 && !it.isAtEnd()){
		top10.push_back(it.retrieve());
		it.advance();
		n++;
	}
	return top10;
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

User* AppStore::findUserByUsername(string username){
	for(unsigned int i=0; i<users.size();i++){
		if(users[i]->getUsername()==username) return users[i];
	}
	return NULL;
}

//////////MENUS//////////

/////////////////////////
////////SUB APP /////////
/////////////////////////

void AppStore::top10Apps(){

	vector<App*> top10 = topTenApps();
	string input;

	unsigned int var;
	if(top10.size() < 10) var = top10.size();
	else var = 10;

	cout << "\n TOP 10 APPS" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	for(unsigned int i=0; i<var; i++){
		cout << top10[i]->displayInfo() << endl;
	}

	cout << endl << " Select app by ID or enter 'r' to return: ";
	cin >> input;
	int in = atoi(input.c_str());
	if(input == "r") return;

	else try{
		AppManagementMenu(findAppByID(in));
	}
	catch (AppDoesNotExist &e1){
		system("cls");
		cout << "\n MESSAGE: Specified app does not exist. ID: " << e1.getID();
		cin.get();
	}
}

void AppStore::AppsListName() {

	string input, name;
	string input2;
	vector<App*> appsN;

	cout << "\n Enter app name: ";
	cin.get();
	getline(cin,name);

	appsN=findAppsByName(name);

	system("cls");
	cout << "\n Apps List By NAME: " << endl;
	cout << " ---------------------------------------------------------" << endl;

	if(appsN.empty()) {
		cout << "\n No apps with the requested name. Press y to go back." <<endl;
		char y;
		cin >> y;
		system("cls");
		return;
	}
	else{
		for(unsigned int i=0; i<appsN.size();i++){
			cout << appsN[i]->displayInfo() << endl;
		}

		cout << endl << " Select app by ID or enter 'r' to return: ";
		cin >> input2;
		int in = atoi(input2.c_str());
		if(input2 == "r") {
			system("cls");
			return;
		}
		else if(!isIDinAppVector(appsN,in)){
			cout << endl << " Message: Invalid ID selected";
			char y;
			cout << "Press y to go back.";
			cin >> y;
			system("cls");
			return;
		}
		else try{
			AppManagementMenu(findAppByID(in));
		}
		catch (AppDoesNotExist &e1){
			cout << "\n Message: Specified app does not exist. ID: " << e1.getID() << endl;
			char y;
			cout << "Press y to go back.";
			cin >> y;
			system("cls");
		}
	}
}

void AppStore::AppsListType() {

	int type;
	string input;
	vector<App*> appstype;

	cout << "\n APPS BY TYPE: "<<endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << "\n  1. Entertainment" << endl;
	cout << "  2. Finances" << endl;
	cout << "  3. Games" << endl;
	cout << "  4. Fitness" << endl;
	cout << "  5. Lifestyle" << endl;
	cout << "  6. Music" << endl;
	cout << "  7. Photography" << endl;
	cout << "  8. Productivity" << endl;
	cout << "  9. Social Networks" << endl;
	cout << "  10. Sports" << endl;
	cout << "  11. Traveling" << endl;
	cout << "  12. Utilities" << endl << endl;
	cout << "  Option: ";
	cin >> type;
	appstype = findAppsByType(type);
	appstype = this->getAppsForSaleFromVector(appstype);
	system("cls");
	cout << endl;
	if(appstype.empty()){
		cout << " Message: No apps with the requested type. Press y to go back.";
		char y;
		cin >> y;
		system("cls");
	}

	else{
		cout << "\n APPS BY TYPE=" << type << ": "<<endl;
			cout << " ---------------------------------------------------------" << endl;
		for(unsigned int i=0; i<appstype.size(); i++){
			cout << appstype[i]->displayInfo() << endl;
			cout << endl << " Select app by ID or enter 'r' to return: ";
			cin >> input;
			int in = atoi(input.c_str());
			if(input == "r") {
				system("cls");
				return;
			}
			else if(!isIDinAppVector(appstype,in)){
						cout << endl << " Message: Invalid ID selected";
						char y;
						cout << "Press y to go back.";
						cin >> y;
						system("cls");
						return;
					}
			else try{
				AppManagementMenu(findAppByID(in));
			}
			catch (AppDoesNotExist &e1){
				cout << " Message: Specified app does not exist. ID: " << e1.getID() << endl;
				cin.get();
			}
		}


	}


}

void AppStore::AllAppsList(){
	cout << "\n APPS LIST" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	string input;
	if(apps.empty()){
		cout << " Message: No apps. Press y to go back" <<endl;
		cin.get();
		return;
	}
	vector<App*>allapps = this->getAppsForSaleFromVector(apps);
	vector<App *>::iterator it = allapps.begin();
	for( ;it<allapps.end(); it++){
		cout << (*(*it)).displayInfo();
				cout << endl;
	}
	cout << endl << " Select app by ID or enter 'r' to return: ";
	cin >> input;
	int in = atoi(input.c_str());
	if(input == "r") {
		system("cls");
		return;
	}

	else try{
		AppManagementMenu(findAppByID(in));
	}
	catch (AppDoesNotExist &e1){
		cout << " Message: Specified app does not exist. ID: " << e1.getID() << endl;
		cin.get();
	}
}

void AppStore::AppsNotForSaleList(){
	cout << "\n APPS NOT FOR SALE" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	string input, input2;
	if(appsNotForSale.empty()){
		cout << " Message: No apps. Press any key to go back" <<endl;
		cin.get();
		cin.get();
		return;
	}
	hashApp::iterator it = appsNotForSale.begin();
	while(it!=appsNotForSale.end()){
		cout << (*(*it)).displayInfo();
		cout << endl;
		it++;
	}

	cout << endl << " Select app by ID or enter 'r' to return: ";
			cin >> input2;
			int in = atoi(input2.c_str());
			if(input2 == "r") {
				system("cls");
				return;
			}

			else try{
				AppManagementMenu(findAppByID(in));
			}
			catch (AppDoesNotExist &e1){
				cout << "\n Message: Specified app does not exist. ID: " << e1.getID() << endl;
				char y;
				cout << "Press y to go back.";
				cin >> y;
				system("cls");
			}
	cin.get();
	cin.get();
	return;
}

void AppStore::RateApps() {
	string name;
	int rate;
	string input;
	App *app;

	cout << "\n Which app do you want to rate?" << endl;
	cout << "\n APPS LIST:" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	vector<App*> allapps = this->getAppsForSaleFromVector(apps);
	if(allapps.empty()){
		cout << "\n Message: No apps. Press any key to go back" <<endl;
		cin.get();
		cin.get();
	}
	for(unsigned int i=0; i<allapps.size(); i++){
		cout << allapps[i]->displayInfo();
		cout << endl;
	}
	cout << endl << "\n Select app by ID or enter 'r' to return: ";
	cin >> input;
	int in= atoi(input.c_str());
	if(input == "r") {
		system("cls");
		return;
	}
	else{
		try{
			app = findAppByID(in);
			}
		catch (AppDoesNotExist &e1){
			cout << "\n Message: Specified app does not exist. ID: " << e1.getID() <<". Press y to go back.";
			char y;
			cin >> y;
			system("cls");
			return;
		}
		system("cls");
		cout << "\n RATE:" << endl;
		cout << " ---------------------------------------------------------" << endl;
			cout << endl;
		cout << "   1 - Hate" << endl;
		cout << "   2 - Dislike" << endl;
		cout << "   3 - Like" << endl;
		cout << "   4 - Love" << endl;
		cout << "   5 - Amazing" << endl;
		cout << "\n   0 - Go Back" << endl;
		cout << "\n Option: ";
		cin >> rate;
		if(rate==0) return;
		if(rate>=1 && rate<=5){
		app->addRating(rate);
		cout << "\n Rating added successfully! Press y to go back.";
		char y;
		cin >> y;
		}
		else{
			cout << "\n Message: Invalid Rate. Press y to go back." << endl;
			char y;
			cin >> y;
		}
	}
}

void AppStore::addToPQ(App *app){
	unacceptedApps.push(app);
}


App* AppStore::AddApplicationMenu() {

	time_t submission;
	string name, desc;
	int type, dev;
	float price;

	cout << "\n ADD APP" <<endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	cout << " Insert the following information: " << endl << endl;
	cout << " Name: ";
	cin.get();
	getline(cin,name);
	cout << endl << " Price: ";
	cin >> price;
	cout << endl << " Type: " << endl;
	cout << "\n  1. Entertainment" << endl;
	cout << "  2. Finances" << endl;
	cout << "  3. Games" << endl;
	cout << "  4. Fitness" << endl;
	cout << "  5. Lifestyle" << endl;
	cout << "  6. Music" << endl;
	cout << "  7. Photography" << endl;
	cout << "  8. Productivity" << endl;
	cout << "  9. Social Networks" << endl;
	cout << "  10. Sports" << endl;
	cout << "  11. Traveling" << endl;
	cout << "  12. Utilities" << endl << endl;
	cout << " Option: ";
	cin >> type;
	cout << endl << " Add a short description (no commas): ";
	cin.get();
	getline(cin,desc);
	if(this->getLoggedInUser()->getType()==3){
		dev=getLoggedInUser()->getID();
	}
	else{
		cout << endl << " Developer's ID: ";
		cin >> dev;
	}

	App *app;
	try{
		app = new App(name, price, type, desc);
		app->setDeveloper(findDeveloperByID(dev));
		time(&submission);
		app->setTime(submission);
		addToPQ(app);
		saveApps();
		cout << "\n Message: App " << name << " Added Successfully To The Appstore. Press y to go back." << endl;
		char y;
		cin >> y;
		return app;
	}
	catch(DeveloperDoesNotExist &e)
	{
		cout << "\n Specified developer not exists. ID: " << e.getID() << endl;
		AddApplicationMenu();
	}
}


void AppStore::RemoveApplicationMenu() {
	string input;
	if(apps.empty()){
		cout << "\n No apps available. Press y to go back";
		char y = 'y';
		cin >> y;
		system("cls");
		return;
	}

	for(unsigned int i=0; i<apps.size(); i++){
		cout << apps[i]->displayInfo() << endl;
	}

	cout << " Select app by ID or enter 'r' to return: ";
	cin >> input;
	if(input == "r") {
		system("cls");
		return;
	}

	try{
		App *app = findAppByID(atoi(input.c_str()));
		removeApp(app);
		cout << " " << app->getName() << " was deleted. Press y to go back." << endl;
	}catch(AppDoesNotExist &e){
		cout << "\n Message: Specified app not exists. ID: " << e.getID() <<". Press y to go back.";
	}

	char y;
	cin >> y;
}

void AppStore::RemoveSaleMenu(){
	string input;
	vector<App*> devAppsForSale = getDeveloperAppsForSale(this->getLoggedInUser()->getID());
		if(devAppsForSale.empty()){
			cout << "No apps. Press any key to go back" <<endl;
			cout << endl;
					char y = 'y';
					cout << "\n Go Back? (y)";
					cin >> y;
					if (y == 'y') {
						system("cls");
						return;
					}
		}
		for(unsigned int i=0; i<devAppsForSale.size(); i++){
			cout << devAppsForSale[i]->displayInfo() << endl;
		}
		cout << " Select app by ID or enter 'r' to return: ";
		cin >> input;
		if(input == "r") {
			system("cls");
			return;
		}

		App *app = findAppByID(atoi(input.c_str()));
		if(app->getDeveloper()->getID()!=this->getLoggedInUser()->getID()){
			cout << "You don't have the permission to remove this app's sale" << endl;

		}
		else{
		removeSaleApp(app);

		cout << " " << app->getName() << " is not for sale anymore." << endl;
		cout << endl;
		}
				char y = 'y';
				cout << "\n Go Back? (y)";
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
}

void AppStore::StartSaleMenu(){
	string input;
	Developer* dev=findDeveloperByID(this->getLoggedInUser()->getID());
		vector<App*> devAppsUnsold = getUnsoldAppsByDeveloper(dev);
			if(devAppsUnsold.empty()){
				cout << "No apps. Press any key to go back" <<endl;
				cout << endl;
						char y = 'y';
						cout << "\n Go Back? (y)";
						cin >> y;
						if (y == 'y') {
							system("cls");
							return;
						}
			}
			for(unsigned int i=0; i<devAppsUnsold.size(); i++){
				cout << devAppsUnsold[i]->displayInfo() << endl;
			}
			cout << " Select app by ID or enter 'r' to return: ";
			cin >> input;
			if(input == "r") {
				system("cls");
				return;
			}

			App *app = findAppByID(atoi(input.c_str()));
			if(app->getDeveloper()->getID()!=this->getLoggedInUser()->getID()){
				cout << "You don't have the permission to start selling this app" << endl;

			}
			else{
			sellApp(app);

			cout << " " << app->getName() << " is for sale again." << endl;
			cout << endl;
			}
					char y = 'y';
					cout << "\n Go Back? (y)";
					cin >> y;
					if (y == 'y') {
						system("cls");
						return;
					}
}

void AppStore::AppManagementMenu(App* app){

	string name;
	int type, dev, rating;
	char choice;
	Transaction *trans;
	vector<App*> appsTrans;
	Client *cli;

	if(this->getLoggedInUser()->getType()==1 ||(this->getLoggedInUser()->getType()==3 && app->getDeveloper()->getID()==this->getLoggedInUser()->getID()))
	{
		system("cls");
		cout << "\n APP MANAGEMENT: ID=" << app->getID() << endl;
		cout << " ---------------------------------------------------------";
		cout << "\n What do you wish to do? " << endl;
		cout << endl;
		cout << "   1 - Change name" << endl;
		cout << "   2 - Change type" << endl;
		cout << "   3 - Change developer" << endl;
		cout << "   4 - Add rating" << endl;
		cout << "   5 - Remove app" << endl;

		cout << "\n   0 - Go Back" << endl<< endl << endl;
		cout << " Option: ";
		cin >> choice;

		switch(choice) {
		case '1':
			system("cls");
			cout << "\n Insert new name: ";
			cin.get();
			getline(cin, name);
			app->setName(name);
			cout << endl << " Name changed to " << name << endl;
			break;
		case '2':
			system("cls");
			cout << "\n Type: "<<endl;
			cout << " ---------------------------------------------------------" << endl;
			cout << "\n  1. Entertainment" << endl;
			cout << "  2. Finances" << endl;
			cout << "  3. Games" << endl;
			cout << "  4. Fitness" << endl;
			cout << "  5. Lifestyle" << endl;
			cout << "  6. Music" << endl;
			cout << "  7. Photography" << endl;
			cout << "  8. Productivity" << endl;
			cout << "  9. Social Networks" << endl;
			cout << "  10. Sports" << endl;
			cout << "  11. Traveling" << endl;
			cout << "  12. Utilities" << endl << endl;
			cout << "  Option: ";
			cin >> type;
			if(type>=1 && type<=12){
				app->setType(type);
				appTree.remove(app);
				appTree.insert(app);
				cout << endl << " Type changed to " << type << endl;
			}else
			{
				cout << "\n Message: Type not available.";
			}
			break;
		case '3':
			try{
				system("cls");
				cout << "\n Insert new developer ID: ";
				cin >> dev;
				app->setDeveloper(findDeveloperByID(dev));
				cout << endl << " Developer's new ID is " << dev << endl;
			}
			catch(DeveloperDoesNotExist &e)
			{
				cout << "\n Message: Specified developer not exists. ID: " << e.getID() << endl;
			}
			break;
		case '4':
			system("cls");
			cout << "\n Insert new rating(1-5): ";
			cin >> rating;
			if(rating >=1 && rating<=5){
				app->addRating(rating);
				appTree.remove(app);
				appTree.insert(app);
				cout << endl << " Rating added: " << rating << endl;
			}
			else{
				cout << "\n Message: Invalid Rating Value." << endl;
			}
			break;
		case '5':
			removeApp(app);
			appTree.remove(app);
			cout << "\n Message: App successfully removed. ";
			break;
		case'0':
			system("cls");
			break;
		default:
			system("cls");
			AppManagementMenu(app);
			break;
		}
		char y;
		cout << "\n Go Back? Press y.";
		cin >> y;
		system("cls");
		return;

	}
	else if(this->getLoggedInUser()->getType()==2){
		system("cls");
		cout << "\n APP MENU: ID=" << app->getID() << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "\n What do you wish to do? " << endl;
		cout << endl;
		cout << "   1 - Buy app" << endl;
		cout << "   2 - Add rating" << endl;

		cout << "\n   0 - Go Back" << endl<< endl << endl;
		cout << " Option: ";
		cin >> choice;

		switch(choice) {


		case '1':
			system("cls");
			cli=findClientByID(this->getLoggedInUser()->getID());
			appsTrans.push_back(app);
			trans = new Transaction();
			trans->setClient(cli);
			cli->addTransaction(trans);
			trans->setApps(appsTrans);
			cout << "Successful purchase! " << endl;
			break;
		case '2':
			system("cls");
			cout << "\n Insert new rating(1-5): ";
			cin >> rating;
			app->addRating(rating);
			appTree.remove(app);
			appTree.insert(app);
			cout << endl << " Rating added: " << rating << endl;
			break;
		case '0':
			system("cls");
			return;
		default:
			system("cls");
			AppManagementMenu(app);
			break;
		}
	}
	else{
		cout << " Message: You don't have the permission to access this app." << endl;
		return;
	}
}

void AppStore::removeFromPQ()
{
	unacceptedApps.pop();
}

App* AppStore::findUnacceptedAppsByID(int id)
{
	appsPQ buf = unacceptedApps;
	while(!buf.empty())
	{
		if(buf.top()->getID()==id) return buf.top();
		buf.pop();
	}
	throw AppDoesNotExist(id);
	return NULL;
}

void AppStore::ApproveNewApps()
{
	App *app;

	cout << "\n APPS TO APPROVE " << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	string input;
	if(unacceptedApps.empty()){
		cout << " Message: No apps to approve. Press y to leave.";
		char y; cin >> y;
		return;
	}
	else{
		appsPQ buf = unacceptedApps;
		while(!buf.empty())
		{
			cout << buf.top()->displayInfo() << endl;
			buf.pop();
		}
	}

	cout << endl << " Select an app by ID to manage it, enter 'a' to approve the top app or enter 'r' to return: ";
	cin >> input;
	int in = atoi(input.c_str());
	if(input == "r") {
		system("cls");
		return;
	}
	else if(input == "a") {
		app = unacceptedApps.top();
		app->setValidation(true);
		apps.push_back(app);
		removeFromPQ();
		saveApps();
		cout << "\n Message: App sucessfully aproved. Press y to go back."; char y; cin >> y;
		return;
	}
	else{
		try{
			app = findUnacceptedAppsByID(in);
		}
		catch (AppDoesNotExist &e1){
			cout << "\n Message: Specified app does not exist. ID: " << e1.getID() <<". ";
			cout << "Press y to go back.";
			char y; cin >> y;
			return;

		}
		AppManagementMenu(app);
	}
}

/////////////////////////
//////SUB CLIENT ////////
/////////////////////////

void AppStore::ClientsList() {
	cout << "\n CLIENTS LIST" << endl;
	cout << " ---------------------------------------------------------" << endl;

	string input;
	if(clients.empty()){
		cout << "\n No clients Available. Press y to go back.";
		char y; cin >> y;
		return;
	}
	for(unsigned int i = 0; i < clients.size(); i++)
	{
		cout << clients[i]->displayInfo() << endl;
	}

	cout << endl << " Select client by ID or enter 'r' to return: ";
	cin >> input;
	int in = atoi(input.c_str());
	if(input == "r") {
		system("cls");
		return;
	}
	else try{
		ClientManagementMenu(findClientByID(in));
	}
	catch (ClientDoesNotExist &e1){
		cout << "\n Message: Specified client does not exist. ID: " << e1.getID() <<". Press y to go back.";
		char y; cin >> y;
	}
}

void AppStore::PurchasedApps() {
	cout << "\n PURCHASED APPS" << endl;
	cout << " ---------------------------------------------------------" << endl;
	string input;
	if(clients.empty()){
		cout << "\n No clients. Press y to go back" <<endl;
		char y; cin >> y;
		system("cls");
		return;
	}
	for(unsigned int i = 0; i < clients.size(); i++)
	{
		cout << clients[i]->displayInfo() << endl;
	}

	cout << endl << " Select client by ID or enter 'r' to return: ";
	cin >> input;
	int in = atoi(input.c_str());
	if(input == "r") {
		system("cls");
		return;
	}
	else try{
		system("cls");
		cout << "\n PURCHASED APPS BY "<<  findClientByID(in)->getUsername() << endl;
		cout << " ---------------------------------------------------------" << endl;
		vector<Transaction*> trans = findClientByID(in)->getTransactions();
		if(trans.empty()) cout << "\n No purchases Available." << endl;

		for(unsigned int i=0; i<trans.size();i++){
			vector<App*> tApps=trans[i]->getApps();
			for(unsigned int j=0; j<tApps.size();j++){
				cout << tApps[j]->displayInfo() << endl;
			}
		}
		cout << " Press y to go back."; char y; cin >> y;
		return;
	}
	catch (ClientDoesNotExist &e1){
		cout << " Message: Specified client does not exist. ID: " << e1.getID() <<". Press y to go back.";
	}

	char y; cin >> y;
}

void AppStore::AddClients() {
	string name;
	int age;

	cout << "\n ADD CLIENT" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	cout << " Name: ";
	cin.get();
	getline(cin,name);
	cout << endl;
	cout << " Age: ";
	cin >> age;

	Client *cli = new Client(name, age);
	clients.push_back(cli);

	cout << endl << endl;
	cout << " Client added successfully to the Appstore database. Press y to go back.";
	char y; cin >> y;

}

void AppStore::RemoveClients() {


	string input;
	cout << "\n CLIENTS LIST" << endl;
	cout << " ---------------------------------------------------------" << endl;

	for(unsigned int i = 0; i < clients.size(); i++)
	{
		cout << clients[i]->displayInfo() << endl;
	}

	cout << endl << " Select client by ID or enter 'r' to return: ";
	cin >> input;
	int in = atoi(input.c_str());
	if(input == "r") {
		system("cls");
		return;
	}
	else try{
		removeClient(findClientByID(in));
		cout << endl << "\n Client removed successfully from the Appstore database. Press y to go back.";
		char y; cin >> y;
	}
	catch (ClientDoesNotExist &e1){
		cout << "\n Specified client does not exist. ID: " << e1.getID() << endl;
	}

}

void AppStore::BuyApp(Client *cli)
{

	string voucher;
	cout << "\n APPS LIST" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << endl;

		string input;
		vector<App*> allapps = this->getAppsForSaleFromVector(apps);
		if(allapps.empty()){
			cout << "\n No apps Available. Press y to go back" <<endl;
			char y; cin >> y;
			return;
		}
		vector<App *>::iterator it = allapps.begin();
		for( ;it<allapps.end(); it++){
			cout << (*(*it)).displayInfo();
					cout << endl;
		}

		vector<App *> appsTrans;

		while(input!="r")
		{
			cout << endl << " Select the app you want to buy by ID or enter 'r' to return: ";
			cin >> input;
			int in = atoi(input.c_str());
			if(input == "r") break;

			try{
				App *app = findAppByID(in);
				appsTrans.push_back(app);
			}catch(AppDoesNotExist &e)
			{
				cout << "\n Message: Specified App does not exist " << e.getID() <<". Press y to go back.";
				char y; cin >> y;
			}

		}

		Transaction *trans;
		trans = new Transaction();
		trans->setClient(cli);
		cli->addTransaction(trans);
		trans->setApps(appsTrans);

		cout << "\n APPS BOUGHT:" << endl << endl;
		for(unsigned int i = 0; i < appsTrans.size(); i++)
		{
			cout << " - " << appsTrans[i]->getName() << endl;
		}

		cout << "\n Do you have a voucher? (yes or not) ";
		cin >> voucher;

		if(voucher == "yes")
		{
			for(unsigned int i = 0; i < appsTrans.size(); i++)
			{
				float price = appsTrans[i]->getPrice()*0.95;
				appsTrans[i]->setPrice(price);
			}
		}

		transactions.push_back(trans);

		char y;
		cout << "\n Press y to go back.";
		cin >> y;
		system("cls");
}

void AppStore::ClientManagementMenu(Client* cli){
	string name, ageinput;
	int  age;
	char choice;

	if(this->getLoggedInUser()->getType()==1){
		system("cls");
		cout << "\n CLIENT MANAGEMENT: ID=" << cli->getID() << endl << endl;
		cout << " ---------------------------------------------------------" << endl;


		cout << " What do you wish to do? " << endl;
		cout << endl;
		cout << "   1. Change username" << endl;
		cout << "   2. Change age" << endl;
		cout << "   3. Buy App" << endl;
		cout << endl;
		cout << "   0. Go back" << endl;
		cout << "\n Option: ";
		cin >> choice;


		switch(choice) {

		case '1':
			system("cls");
			cout << "\n Insert new name: ";
			cin.get();
			getline(cin,name);
			cli->setUsername(name);
			cout << endl << " Name changed to " << name <<". Press y to go back.";
			break;
		case '2':
			system("cls");
			cout << "\n Insert new age: ";
			cin >> ageinput;
			age=atoi(ageinput.c_str());
			if(age>0 && age<=150){
				cli->setAge(age);
				cout << endl << "\n Age changed to " << age <<". Press y to go back.";;
			}
			else{
				cout << "\n Message: Invalid Age. Press y to go back.";
			}
			break;
		case '3':
			system("cls");
			BuyApp(cli);
			return;
			break;
		case '0':
			system("cls");
			return;
			break;
		default:
			system("cls");
			ClientManagementMenu(cli);
			break;
		}
		char y;
		cin >> y;
	}
	else{
		cout << "You don't have the permission to access this menu" << endl;
		return;
	}

}

/////////////////////////
//////SUB DEV ///////////
/////////////////////////

void AppStore::ShowIndivDev()
{
	cout << " INDIVIDUAL DEVELOPERS" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	for(unsigned int i = 0; i<developers.size(); i++)
	{

		if(developers[i]->devtype() == 1)
		{
			cout << developers[i]->displayInfo() << endl;
		}
	}
}

void AppStore::ShowCompDev()
{
	cout << " ENTERPRISE DEVELOPERS" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << endl;
	for(unsigned int i = 0; i<developers.size(); i++)
	{
		if(developers[i]->devtype() == 2)
		{
			cout << developers[i]->displayInfo() << endl;
		}
	}
}

void AppStore::IndividualDevList() {
	cout << "\n INDIVIDUAL DEVELOPERS" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << endl;

	ShowIndivDev();

	char y;
	cout << "\n Press y to go back.";
	cin >> y;
	system("cls");
}

void AppStore::ShowAllDev()
{
	char y;
	cout << "\n DEVELOPERS LIST" << endl;
	cout << " ---------------------------------------------------------" << endl;

	string input;
	if(developers.empty()){
		cout << "\n Message: No Developers. Press y to go back" <<endl;
		cin >> y;
		return;
	}
	vector<Developer *>::iterator it = developers.begin();
	for( ;it<developers.end(); it++){
		cout << (*(*it)).displayInfo();
		cout << endl << endl;;
	}
	cout << "\n Select developer by ID or enter 'r' to return: ";
	cin >> input;
	int in = atoi(input.c_str());
	if(input == "r") {
		system("cls");
		return;
	}
	else try{
		findDeveloperByID(in)->DevManagementMenu(this);
	}
	catch (DeveloperDoesNotExist &e1){
		cout << "\n Message: Specified developer does not exist. ID: " << e1.getID() <<". Press y to go back.";
		cin >> y;
	}

}

void AppStore::EnterpriseList() {
	cout << "\n ENTERPRISE DEVELOPERS" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	ShowCompDev();

	char y;
	cout << "\n Press y to go back.";
	cin >> y;
	system("cls");
}

void AppStore::ShowAppsByName(int id)
{
	cout << " APPS" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	Developer *dev = findDeveloperByID(id);
	vector<App*> appsN = dev->getApps();
	for(unsigned int i = 0; i < appsN.size(); i++)
	{
		cout << appsN[i]->displayInfo() << endl;
	}

	cout << "\n Press y to go back." << endl;
	char y; cin >> y;
}

void AppStore::AppsCreated() {
	char choice;
	int id;
	cout << "\n APPS CREATED BY A DEV/ENTERPRISE:" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	cout << "   1 - Individual Developer" << endl;
	cout << "   2 - Enterprise" << endl << endl;
	cout << "   0 - Go back" << endl << endl;
	cout << " Option: ";
	cin >> choice;

	switch(choice) {

	case '1':
		system("cls");
		ShowIndivDev();
		cout << endl;
		cout << " ID developer: ";
		cin >> id;
		cout << endl;
		system("cls");
		ShowAppsByName(id);
		break;
	case '2':
		system("cls");
		ShowCompDev();
		cout << endl;
		cout << " Apps Created By: ";
		cin >> id;
		cout << endl;
		system("cls");
		ShowAppsByName(id);
		break;
	case '0':
		system("cls");
		break;
	default:
		break;
	}
}

void AppStore::SalesData() {

	cout << "\n CHOOSE DEVELOPER ID OR 0 TO GO BACK: ";
	int input;
	char y;
	cin >> input;
	if(input == 0) return;
cout << endl;

	try{
		Developer *dev = findDeveloperByID(input);

		for(unsigned int i = 0; i < transactions.size(); i++)
			{
				vector<App *> transApp = transactions[i]->getApps();

				for(unsigned int i = 0; i < transApp.size(); i++)
				{
					if(dev == transApp[i]->getDeveloper())
					{
						cout << transApp[i]->displayInfo() << endl;
					}
				}
			}
	}
	catch(DeveloperDoesNotExist &e)
	{
		cout << "\n Message: Specified Developer does not exist: " << e.getID() << ". Press y to go back.";
		cin >> y;
		return;
	}



	cout << " Press y to go back.";

	cin >> y;
}



void AppStore::AddDev() {

	cout << "\n ADD DEVELOPER" << endl;
	cout << " ---------------------------------------------------------" << endl;
	string name,adress, company;
			int nif, code;

			cout << " Insert the following information: " << endl << endl;
			cout << "   1 - Individual Developer" << endl;
			cout << "   2 - Enterprise" << endl;
			char type;
			cout << "\n Option: ";
			cin >> type;
			system("cls");
			switch(type)
			{
			case '1':
				cout << "\n CREATING INDIVIDUAL DEVELOPER" << endl;
				cout << " ---------------------------------------------------------" << endl;
				cout << "\n Name: ";
				cin.get();
				getline(cin,name);
				cout << "\n Adress: ";
				cin.get();
				getline(cin,adress);
				cout << "\n NIF: ";
				cin >> nif;
				Individual *ind;
				ind = new Individual(name, adress, nif);
				addDeveloper(ind);
				break;
			case '2':
				cout << "\n CREATING ENTERPRISE DEVELOPER" << endl;
				cout << " ---------------------------------------------------------" << endl;

				cout << "\n Name: ";
				cin.get();
				getline(cin,name);
				cout << endl << "\n Adress: ";
				cin.get();
				getline(cin,adress);
				cout << endl << "\n NIF: ";
				cin >> nif;
				cout << endl << "\n Company Name: ";
				cin.get();
				getline(cin,company);
				cout << endl << "\n Code: ";
				cin >> code;
				Company *comp;
				comp = new Company(company, code, name, adress, nif);
				addDeveloper(comp);
				break;
			default:
				system("cls");
				AddDev();
				break;
			}

			cout << "\n Developer " << name << " added successfully to the Appstore. Press y to go back.";
			char y; cin >> y;
}


void AppStore::RemoveDev() {

	string input;
	char y;
		if(apps.empty()){
			cout << "\n No Developers. Press y to go back" <<endl;
			cin >> y;
			return;
		}
		for(unsigned int i=0; i<developers.size(); i++){
			cout << developers[i]->displayInfo() << endl;
		}
		cout << endl << "\n Select developer by ID or enter 'r' to return: ";
		cin >> input;
		if(input == "r") {
			system("cls");
			return;
		}

		try{
		Developer *dev = findDeveloperByID(atoi(input.c_str()));
		removeDeveloper(dev);
		}catch(DeveloperDoesNotExist &e)
		{
			cout << "\n Specifier Developer does not exist: " << e.getID() << ". Press y to go back.";
			cin >> y;
			return;
		}

		cout << "\n Developer removed successfully from the Appstore. Press y to go back." << endl;
		cin >> y;
}
/////////////////////////
//////SUB TRANS /////////
/////////////////////////

void AppStore::TransApps() {
	cout << "\n APPS TRANSACTIONS: " << endl;
	cout << " ---------------------------------------------------------" << endl;
	for(unsigned int i=0; i<apps.size();i++){
		cout << apps[i]->displayInfo() << endl;
	}

	int in;
	cout << endl << " Choose an app ID: ";
	cin >> in;

	App *app = findAppByID(in);

	cout << " \n\n TRANSACTIONS OF APP " << app->getName() <<": " << endl;
	vector<Transaction *>appsTrans = app->getTransactions();

	for(unsigned int i = 0; i < appsTrans.size(); i++)
	{
		cout << "\n" << appsTrans[i]->displayInfo() << endl;
	}

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
	}
}

void AppStore::TransClients() {

	cout << "\n CLIENTS TRANSACTIONS: " << endl;
	cout << " ---------------------------------------------------------" << endl;

	for(unsigned int i = 0; i < clients.size(); i++)
		{
			cout << clients[i]->displayInfo() << endl;
		}

	int in;
		cout << endl << " Choose a Client ID: ";
		cin >> in;

		Client *cli = findClientByID(in);

		cout << " \n\n TRANSACTIONS OF CLIENT " << cli->getUsername() << ": " << endl;
		vector<Transaction *> transApp = cli->getTransactions();

		for(unsigned int i = 0; i < transApp.size(); i++)
		{
			cout << "\n Transaction " << transApp[i]->getID() <<": " << endl;
			vector<App *> appsT =  transApp[i]->getApps();
			for(unsigned int j = 0; j < appsT.size(); j++)
			{
				cout << " " << appsT[j]->getID()<<" - " << appsT[j]->getName() << endl;
			}
		}



	cout << endl;
	char y = 'y';
	cout << "\n Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");

	}
}

void AppStore::TransDev() {
	cout << "\n Developers TRANSACTIONS: " << endl;
	cout << " ---------------------------------------------------------" << endl;
	for(unsigned int i=0; i<developers.size();i++){
		cout << developers[i]->displayInfo() << endl;
	}

	int in;
	cout << endl << " Choose a Developer ID: ";
	cin >> in;

	Developer *dev = findDeveloperByID(in);

	cout << " \n\n TRANSACTIONS OF DEVELOPER " << dev->getName() <<": " << endl;
	vector<App *> devApps = dev->getApps();

	for(unsigned int i = 0; i < devApps.size(); i++)
	{
		vector<Transaction *> trans = devApps[i]->getTransactions();
		for(unsigned int j = 0; j < trans.size(); j++)
		{
			cout << " " << trans[j]->getClient()->getID() << " " << trans[j]->getClient()->getUsername() << endl;

		}
	}

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
	}
}

void AppStore::ShowAllTransactions()
{
	cout << "\n TRANSACTIONS: " << endl;
	cout << " ---------------------------------------------------------" << endl;
	for(unsigned int i = 0; i < transactions.size(); i++)
	{
		cout << transactions[i]->displayInfo();
		vector<App *> tapp = transactions[i]->getApps();
		for(unsigned int i = 0; i < tapp.size(); i++)
		{
			cout << " " << tapp[i]->getID() << " - " << tapp[i]->getName() << endl;
		}
		cout << endl ;
	}

	cout << endl;
		char y = 'y';
		cout << "Go Back? (y)";
		cin >> y;
		if (y == 'y') {
			system("cls");
			return;

		}
}

void AppStore::assignPublishedAppsToDevs(){
	for(unsigned int i=0; i<developers.size();i++){
		for(unsigned int j=0; j<apps.size();j++){
			if(developers[i]->getID() == apps[j]->getDeveloper()->getID()){
				developers[i]->addApp(apps[j]);
			}
		}
	}
}

void AppStore::assignTransactionsToApps(){
	vector<App*> appsT;
	for(unsigned int i=0; i<apps.size();i++){
		for(unsigned int j=0; j<transactions.size();j++){
			for(unsigned int k=0; k< transactions[j]->getApps().size();k++){
				appsT = transactions[j]->getApps();
				if(apps[i]->getID() == appsT[k]->getID()){
					apps[i]->addTransaction(transactions[j]);
				}
			}
		}
	}
}

void AppStore::assignTransactionsToClients(){
	for(unsigned int i=0; i<clients.size();i++){
		for(unsigned int j=0; j<transactions.size();j++){
			if(transactions[j]->getClient()->getID()==clients[i]->getID()){
				clients[i]->addTransaction(transactions[j]);
			}
		}
	}
}


/**********************************************************
 **********************************************************
 *                    SAVES AND LOADS                     *
 **********************************************************
 * SAVES                                                  *
 **********************************************************/

void AppStore::saveApps()
{
	vector<App *>::iterator it = apps.begin();

	ofstream file;
	file.open("apps.txt", ios::trunc);

	for(; it != apps.end(); it++)
	{
		(*it)->writeToFile(file);
		file << endl;
	}

	appsPQ buf = unacceptedApps;
	while(!buf.empty())
	{
		buf.top()->writeToFile(file);
		file << endl;
		buf.pop();
	}

	system("cls");
	file.close();
}

void AppStore::saveDevelopers()
{
	vector<Developer *>::iterator it = developers.begin();

	ofstream file;
	file.open("developers.txt",ios::trunc);

	for(; it != developers.end(); it++)
	{
		(*it)->writeToFile(file);
		file << endl;
	}

	system("cls");
	file.close();
}

void AppStore::saveClients()
{
	vector<Client *>::iterator it = clients.begin();

	ofstream file;
	file.open("clients.txt",ios::trunc);

	for(; it != clients.end(); it++)
	{
		(*it)->writeToFile(file);
		file << endl;
	}
	system("cls");
	file.close();
}

void AppStore::saveUsers()
{
	vector<User *>::iterator it = users.begin();

	ofstream file;
	file.open("users.txt",ios::trunc);

	for(; it != users.end(); it++)
	{
		(*it)->writeToFile(file);
		file << endl;
	}
	system("cls");
	file.close();
}

void AppStore::saveTransactions()
{
	vector<Transaction *>::iterator it = transactions.begin();

	ofstream file;
	file.open("transactions.txt",ios::trunc);

	for(; it != transactions.end(); it++)
	{
		(*it)->writeToFile(file);
		file << endl;
	}
	system("cls");
	file.close();
}

/**********************************************************
* LOADS                                                   *
**********************************************************/

void AppStore::loadApps()
{
	ifstream file;
	file.open("apps.txt");

	App *app;
	int id, devId, numR, numC, type, sale, validation;
	float price, rating;
	string name, description, comment;
	time_t submisson;
	string line, line1, readline;
	vector<string> fields;
	int firstread = 0;

	if(file.is_open()){
		while(getline(file, line))
		{
			int i=0;

			cout << line << endl;
			fields.clear();

			stringstream ss(line);
			string field;
			while (getline(ss, field, ',')){
				fields.push_back(field);
			}

			id = atoi(fields[i].c_str());
			cout << id << endl;
			i++;
			name = fields[i];
			i++;
			price = atof(fields[i].c_str());
			i++;
			type = atoi(fields[i].c_str());
			i++;
			description = fields[i];
			i++;
			devId = atoi(fields[i].c_str());
			i++;
			sale = atoi(fields[i].c_str());
			i++;
			validation = atoi(fields[i].c_str());
			i++;
			submisson = atoi(fields[i].c_str());
			i++;
			numR = atoi(fields[i].c_str());

			app= new App(name,price,type,description);
			app->setDeveloper(findDeveloperByID(devId));
			app->setTime(submisson);

			if(sale==1) app->setSaleStatus(true);
			else { app->setSaleStatus(false);}
			if(validation == 1) app->setValidation(true);
			else app->setValidation(false);
			for(int j=0; j<numR; j++){
				rating = atoi(fields[i].c_str());
				i++;
				app->addRating(rating);
			}
			i++;
			i++;

			numC = atoi(fields[i].c_str());

			i++;
			for(int j=0; j<numC; j++){
				comment = fields[i];
				i++;
				app->addComment(comment);

			}
			if(validation == 1) addApp(app);
			else if(validation == 0) addToPQ(app);
			firstread++;
			}
	}
	file.close();
}



void AppStore::loadDevelopers()
{
	ifstream file;
	file.open("developers.txt", ios::in);

	int id, nif, type, code;
	string name, address, bName;
	string line;

	if(file.is_open()){
		while(getline(file,line))
		{
			vector<string> fields;
			stringstream ss( line );
			string field;
			while (getline( ss, field, ',' )){
				fields.push_back(field);
			}
			int i=0;
			vector<App*>appsP;

			id = atoi(fields[i].c_str());
			i++;

			type = atoi(fields[i].c_str());
			i++;

			name = fields[i];
			i++;
			address = fields[i];
			i++;
			nif = atoi(fields[i].c_str());


			if(type == 1)
			{
				Individual *ind;
				ind = new Individual(name,address, nif);
				ind->setID(id);
				developers.push_back(ind);
			}
			else if(type == 2)
			{
				i++;
				bName = fields[i];
				i++;
				code = atoi(fields[i].c_str());
				Company *comp;
				comp = new Company(bName, code, name,address, nif);
				comp->setID(id);
				developers.push_back(comp);
			}
		}
	}
	file.close();
}

void AppStore::loadClients()
{
	ifstream file;
	file.open("clients.txt", ios::in);

	int id, age, numT;
	string username, line;

	if(file.is_open()){
		while(getline(file,line))
		{
			vector<string> fields;
			stringstream ss( line );
			string field;
			while (getline( ss, field, ',' )){
				fields.push_back(field);
			}
			int i=0;
			Client *client;
			vector<App*>appsP;

			id = atoi(fields[i].c_str());
			i++;
			username = fields[i];
			i++;
			age = atoi(fields[i].c_str());
			i++;

			numT = atoi(fields[i].c_str());
			i++;

			client = new Client(username,age);
			client->setID(id);
			clients.push_back(client);
		}
	}
	file.close();
}

void AppStore::loadTransactions()
{
	ifstream file;
	file.open("transactions.txt", ios::in);

	int id, numA, appID, cliID;
	string usedVoucher,line;

	if(file.is_open()){
		while(getline(file,line))
				{
					vector<string> fields;
					stringstream ss( line );
					string field;
					while (getline( ss, field, ',' )){
						fields.push_back(field);
					}
					int i=0;
					Transaction *transaction;
					vector<App*>appsP;

					id = atoi(fields[i].c_str());
					i++;
					cliID = atoi(fields[i].c_str());
					i++;
					usedVoucher = fields[i];
					i++;

					numA = atoi(fields[i].c_str());
					i++;
					transaction = new Transaction();
					transaction->setID(id);
					transaction->setClient(findClientByID(cliID));
					transaction->setUsedVoucher(usedVoucher);
					for(int j=0; j<numA; j++){
						appID = atoi(fields[i].c_str());
						i++;
						transaction->addApp(findAppByID(appID));
					}
					transactions.push_back(transaction);
				}
			}
			file.close();
}

void AppStore::loadUsers()
{
	ifstream file;
	file.open("users.txt", ios::in);

	int id, type;
	string username, line, password;

	if(file.is_open()){
		while(getline(file,line))
		{
			vector<string> fields;
			stringstream ss( line );
			string field;
			while (getline(ss, field, ',' )){
				fields.push_back(field);
			}
			int i=0;

			User *user;
			id = atoi(fields[i].c_str());
			i++;
			username = fields[i];
			i++;
			password = fields[i];
			i++;
			type = atoi(fields[i].c_str());
			i++;

			user = new User(type, username, password, id);
			user->setID(id);
			users.push_back(user);
		}
	}
	file.close();

}





