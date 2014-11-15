/*
 * AppStore.cpp
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */

#include <string>
#include "AppStore.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

AppStore::AppStore() {
	this->name = "APP STORE";
}

AppStore::AppStore(string name) {
	this->name = name;
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
}
void AppStore::addClient(Client* cli) {
	clients.push_back(cli);
}
void AppStore::addDeveloper(Developer* dev) {
	developers.push_back(dev);
}

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

vector<Transaction*> AppStore::getTransactions()
{
	return transactions;
}

void AppStore::setTransactions(vector<Transaction *> transactions)
{
	this->transactions = transactions;
}

bool AppStore::removeApp(App* app) {
	cout << apps.size() << endl;
	for (unsigned int i = 0; i < apps.size(); i++) {
		if (apps[i] == app){
			apps.erase(apps.begin()+i);
			i--;

			return true;
		}

	}
	return false;
}

bool AppStore::removeClient(Client* client){
	for (unsigned int i = 0; i < clients.size(); i++) {
		if (clients[i] == client){
			clients.erase(clients.begin()+i);
			i--;
			return true;
		}


	}
	return false;
}

bool AppStore::removeDeveloper(Developer *dev){
	for (unsigned int i = 0; i < developers.size(); i++) {
		if (developers[i] == dev){

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

vector<App*> AppStore::orderAppsByTop5Rating(){
	vector<App*> apps2 = apps;
	vector<App*> top5;
	sort(apps2.begin(), apps2.end(), ordenaRating);
	for(int i=0; i<5; i++){
		top5.push_back(apps2[i]);
	}
	return top5;
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

//////////MENUS//////////

/////////////////////////
////////SUB APP /////////
/////////////////////////

void AppStore::Top5Apps(){
	vector<App*> top5 = orderAppsByTop5Rating();

		string input;

		unsigned int var;
		if(apps.size() < 5) var = apps.size();
		else var = 5;

		cout << "\n TOP 5 APPS" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << endl;
		for(unsigned int i=0; i<var; i++){
			cout << top5[i]->displayInfo() << endl;
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

		}

}

void AppStore::AppsListName() {
	string input;
	string input2;
	vector<App*> appsN;
	cout << "\n Enter app name: ";
	cin >> input;
	appsN=findAppsByName(input);

	system("cls");
	cout << "\n Apps List By NAME: " << endl;
	if(appsN.empty()) {
		cout << "\n No apps with the requested name. Press any key to go back" <<endl;
		cout << endl;
				char y = 'y';
				cout << "\n Go Back? (y)";
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
	}
	else{
		for(unsigned int i=0; i<appsN.size();i++){
			cout << appsN[i]->displayInfo() << endl;
		}
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
		cout << "\n Specified app does not exist. ID: " << e1.getID() << endl;
	}
	cout << endl;
			char y = 'y';
			cout << "\n Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				return;
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
	system("cls");
	cout << endl;
	if(appstype.empty()){
		cout << " No apps with the requested type. Press any key to go back" <<endl;
		cout << endl;
				char y = 'y';
				cout << "\n Go Back? (y)";
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
	}
	else{
	for(unsigned int i=0; i<appstype.size(); i++){
		cout << appstype[i]->displayInfo() << endl;
	}
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
		cout << " Specified app does not exist. ID: " << e1.getID() << endl;
	}
	cout << endl;
			char y = 'y';
			cout << "\n Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				return;
			}

}

void AppStore::AllAppsList(){
	cout << "\n APPS LIST" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	string input;
	if(apps.empty()){
		cout << " No apps. Press any key to go back" <<endl;
		cin.get();
		return;
	}
	vector<App *>::iterator it = apps.begin();
	for( ;it<apps.end(); it++){
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
		cout << " Specified app does not exist. ID: " << e1.getID() << endl;
	}
	cout << endl;
			char y = 'y';
			cout << "\n Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				return;
			}
}
void AppStore::RateApps() {
	string name;
	string rate;
	string input;
	App *app;

	cout << "\n Which app do you want to rate?" << endl;
	cout << "\n APPS LIST:" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	if(apps.empty()){
		cout << "\n No apps. Press any key to go back" <<endl;
		cout << endl;
				char y = 'y';
				cout << "\n Go Back? (y)";
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
	}
	for(unsigned int i=0; i<apps.size(); i++){
		cout << apps[i]->displayInfo();
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
			cout << "\n Specified app does not exist. ID: " << e1.getID() << endl;
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

		if(rate=="0") return;

		app->addRating(atoi(rate.c_str()));

		cout << "\n Rating added successfully!" << endl;
		cout << endl;
				char y = 'y';
				cout << "\n Go Back? (y)";
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}


	}
}

App* AppStore::AddApplicationMenu() {
	string name, desc;
	int type, dev;
	float price;
	cout << "\n ADD APP" <<endl;
	cout << " ---------------------------------------------------------" << endl;
		cout << endl;
	cout << " Insert the following information: " << endl << endl;
	cout << " Name: ";
	cin >> name;
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
	cout << endl << " Developer's ID: ";
	cin >> dev;

	App *app;
	try{


	app = new App(name, price, type, desc);
	app->setDeveloper(findDeveloperByID(dev));

	addApp(app);

	cout << "\n App " << name << " Added Successfully To The Appstore" << endl;


	cout << endl;
			char y = 'y';
			cout << "\n Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				return app;

			}}
	catch(DeveloperDoesNotExist &e)
	{
		cout << "\n Specified developer not exists. ID: " << e.getID() << endl;
		AddApplicationMenu();
	}

}


void AppStore::RemoveApplicationMenu() {
	string input;
	if(apps.empty()){
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
	for(unsigned int i=0; i<apps.size(); i++){
		cout << apps[i]->displayInfo() << endl;
	}
	cout << " Select app by ID or enter 'r' to return: ";
	cin >> input;
	if(input == "r") {
		system("cls");
		return;
	}

	App *app = findAppByID(atoi(input.c_str()));
	removeApp(app);

	cout << " " << app->getName() << " was deleted." << endl;
	cout << endl;
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
	system("cls");
	cout << "\n APP MANAGEMENT: ID=" << app->getID() << endl;
	cout << " ---------------------------------------------------------" << endl;
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


			case '1': system("cls");
			cout << "\n Insert new name: ";
					cin >> name;
					app->setName(name);
					cout << endl << " Name changed to " << name << endl;
					break;
			case '2':
				system("cls");
				cout << endl << "\n Type: "<<endl;
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
				app->setType(type);
				cout << endl << " Type changed to " << type << endl;
				break;
			case '3':
				system("cls");

				cout << "\n Insert new developer ID: ";
				cin >> dev;
				app->setDeveloper(findDeveloperByID(dev));
				cout << endl << "Developer's new ID is " << dev << endl;
				break;
			case '4':
				system("cls");
				cout << "\n Insert new rating: ";
				cin >> rating;
				app->addRating(rating);
				cout << endl << "Rating added: " << rating << endl;

				break;
			case '5':
				removeApp(app);
				cout << "\n App successfully removed. ";
				break;
			case '0':
				system("cls");
				return;
			default:
				system("cls");
				AppManagementMenu(app);
				break;
	}
	cout << endl;
			char y = 'y';
			cout << "\n Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				return;
			}}
/////////////////////////
//////SUB CLIENT ////////
/////////////////////////

void AppStore::ClientsList() {
	cout << "\n CLIENTS LIST" << endl;
	cout << " ---------------------------------------------------------" << endl;

	string input;
		if(clients.empty()){
			cout << "\n No clients." <<endl;
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
		cout << "\n Specified client does not exist. ID: " << e1.getID() << endl;
		char y;
							cout << "\n Go Back? (y)";
							cin >> y;
							if (y == 'y') {
								system("cls");
								return;
							}
	}

	cin >> input;

		if(input == "r") {
			system("cls");
			return;
		}

}

void AppStore::PurchasedApps() {
	cout << "\n PURCHASED APPS" << endl;
	cout << " ---------------------------------------------------------" << endl;
	string input;
	if(clients.empty()){
		cout << "No clients. Press any key to go back" <<endl;
		char input;
			cout << "\n\n Enter 'r' to return: ";
			cin >> input;

			if(input == 'r') return;
			system("cls");
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
				vector<Transaction*> trans = findClientByID(in)->getTransactions();
				if(trans.empty()) cout << " No purchases. " << endl << endl;
				for(unsigned int i=0; i<trans.size();i++){
					vector<App*> tApps=trans[i]->getApps();
					for(unsigned int j=0; j<tApps.size();j++){
						cout << tApps[j]->displayInfo() << endl;
					}
				}
			}
			catch (ClientDoesNotExist &e1){
				cout << " Specified client does not exist. ID: " << e1.getID() << endl;
			}

			cout << endl;
					char y = 'y';
					cout << "\n Go Back? (y)";
					cin >> y;
					if (y == 'y') {
						system("cls");
						return;
					}

}

void AppStore::AddClients() {
	string name;
	int age;

	cout << "\n ADD CLIENT" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;

	cout << " Name: ";
	cin >> name;
	cout << endl;
	cout << " Age: ";
	cin >> age;

	Client *cli = new Client(name, age);
	clients.push_back(cli);

	cout << endl << endl;
	cout << " Client added successfully to the Appstore database." << endl;

	cout << endl;
			char y = 'y';
			cout << "\n Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				return;
			}
}

void AppStore::RemoveClients() {


	cout << "\n CLIENTS LIST" << endl;
		cout << " ---------------------------------------------------------" << endl;

	for(unsigned int i = 0; i < clients.size(); i++)
		{
			cout << clients[i]->displayInfo() << endl;
		}

	int id;
	cout << "\n ID of client to be removed: ";
	cin >> id;


	try{
		removeClient(findClientByID(id));
		cout << endl << "\n Client removed successfully from the Appstore database" << endl;

		char y;
					cout << "\n Go Back? (y)";
					cin >> y;
					if (y == 'y') {
						system("cls");
						return;
					}
	}
	catch (ClientDoesNotExist &e1){
		cout << "\n Specified client does not exist. ID: " << e1.getID() << endl;
	}


	cout << endl;
			char y;
			cout << "\n Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				return;
			}

}

void AppStore::BuyApp(Client *cli)
{

	string voucher;
	cout << "\n APPS LIST" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << endl;

		string input;
		if(apps.empty()){
			cout << " No apps. Press any key to go back" <<endl;

			return;
		}
		vector<App *>::iterator it = apps.begin();
		for( ;it<apps.end(); it++){
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


			App *app = findAppByID(in);
			appsTrans.push_back(app);
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


		cout << endl;
		char y = 'y';
		cout << "\n Go Back? (y)";
		cin >> y;
		if (y == 'y') {
			system("cls");
			return;
		}
}

void AppStore::ClientManagementMenu(Client* cli){
	string name;
	int  age;
	char choice;
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
	cin >> name;
	cli->setUsername(name);
	cout << endl << "Name changed to " << name << endl;
	break;

	case '2':
		system("cls");
		cout << "\n Insert new age: ";
		cin >> age;
		cli->setAge(age);
		cout << endl << "\n Age changed to " << age << endl;

	break;
	case '3':
		system("cls");
		BuyApp(cli);
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

}

/////////////////////////
//////SUB DEV ///////////
/////////////////////////

void AppStore::ShowIndivDev()
{
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

	cout << endl;
	char y = 'y';
	cout << "\n Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");

	}
}

void AppStore::ShowAllDev()
{
	cout << "\n DEVELOPERS LIST" << endl;
	cout << " ---------------------------------------------------------" << endl;


	string input;
	if(developers.empty()){
		cout << "No Developers. Press any key to go back" <<endl;
		cin.get();
		return;
	}
	vector<Developer *>::iterator it = developers.begin();
	for( ;it<developers.end(); it++){
		cout << (*(*it)).displayInfo();
		cout << endl << endl;;
	}
	cout << "\n Select app by ID or enter 'r' to return: ";
	cin >> input;
	int in = atoi(input.c_str());
	if(input == "r") {
		system("cls");
		return;
	}

	else try{
		DevManagementMenu(findDeveloperByID(in));
	}
	catch (DeveloperDoesNotExist &e1){
		cout << "\n Specified Developer does not exist. ID: " << e1.getID() << endl;
	}

}

void AppStore::EnterpriseList() {
	cout << "\n ENTERPRISE DEVELOPERS" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << endl;

	ShowCompDev();

	cout << endl;
	char y = 'y';
	cout << "\n Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		return;
	}


}

void AppStore::ShowAppsByName(int id)
{
	Developer *dev = findDeveloperByID(id);
	vector<App*> appsN = dev->getApps();
	for(unsigned int i = 0; i < appsN.size(); i++)
	{
		cout << appsN[i]->displayInfo() << endl;
	}
}

void AppStore::AppsCreated() {
	char choice;
	char y = 'y';
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
		cout << "ID developer: ";
		cin >> id;
		cout << endl;
		ShowAppsByName(id);
		break;
	case '2':
		system("cls");
		ShowCompDev();
		cout << endl;
		cout << "Apps Created By: ";
		cin >> id;
		cout << endl;
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

	cout << "\n Choose Developer id: ";
	int input;
	cin >> input;

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
	char y = 'y';
		cout << "\n Go Back? (y)";
		cin >> y;
		if (y == 'y') {
			system("cls");
		}

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
				cin >> name;
				cout << "\n Adress: ";
				cin.get();
				getline(cin,adress);
				cout << endl << "\n NIF: ";
				cin >> nif;
				Individual *ind;
				ind = new Individual(name, adress, nif);
				addDeveloper(ind);
				break;
			case '2':
				cout << "\n CREATING ENTERPRISE DEVELOPER" << endl;
				cout << " ---------------------------------------------------------" << endl;

				cout << "\n Name: ";
				cin >> name;
				cout << endl << "\n Adress: ";
				cin.get();
				cin.get();
				getline(cin,adress);
				cout << endl << "\n NIF: ";
				cin >> nif;
				cout << endl << "\n Company Name: ";
				cin >> company;
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

			cout << "\n Developer " << name << " Added Successfully To The Appstore" << endl;
			cout << endl;


	char y = 'y';
	cout << "\n Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		return;
	}
}


void AppStore::RemoveDev() {

	string input;
		if(apps.empty()){
			cout << "\n No Developers. Press any key to go back" <<endl;
			cin.get();
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

		Developer *dev = findDeveloperByID(atoi(input.c_str()));
		removeDeveloper(dev);

		cout << "\n Developer removed successfully from the Appstore" << endl;
		cout << endl;
		char y = 'y';
			cout << "\n Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				return;
			}


}

void AppStore::DevManagementMenu(Individual* ind){

	string name, address, busName;
		int nif;
		App *app;
		char choice;
		system("cls");
		cout << "\n DEVELOPER MANAGEMENT: ID=" << ind->getID() << endl;
		cout << " ---------------------------------------------------------" << endl;


			cout << "\n EDITING INDIVIDUAL DEVELOPER" << endl;
			cout << " ---------------------------------------------------------" << endl;

			cout << "   1 - Change Name" << endl;
			cout << "   2 - Change Address" << endl;
			cout << "   3 - Change Nif" << endl;
			cout << "   4 - Publish App" << endl;
			cout << " Option: ";
			cin >> choice;

			switch(choice)
			{

			case '1':
				system("cls");
				cout << "\n Insert a new name: " ;
				cin >> name;
				ind->setName(name);
				break;
			case '2':
				system("cls");
				cout << "\n Insert a new address:";
				cin.get();
				getline(cin,address);
				ind->setAddress(address);
				break;
			case'3':
				system("cls");
				cout<< "\n Insert a new Nif: ";
				cin >> nif;
				ind->setNif(nif);
				break;
			case '4':
				system("cls");
				cout << "\n PUBLISHING NEW APP: " << endl;
				app = AddApplicationMenu();
				ind->addApp(app);
				break;
			default:
				system("cls");
				DevManagementMenu(ind);
				break;
			}


}



void AppStore::DevManagementMenu(Company* comp){


	string name, address, busName;
			int nif, code;
			App *app;
	char choice;
	cout << "\n EDITING ENTERPRISE DEVELOPER" << endl;
		cout << " ---------------------------------------------------------" << endl;

		cout << "   1 - Change Name" << endl;
		cout << "   2 - Change Address" << endl;
		cout << "   3 - Change Nif" << endl;
		cout << "   4 - Publish App" << endl;
		cout << "   5 - Company Name" << endl;
		cout << "   6 - Change Code" << endl;
		cout << " Option: ";
		cin >> choice;

		switch(choice)
		{

		case '1':
			system("cls");
			cout << "\n Insert a new name: " ;
			cin >> name;
			comp->setName(name);
			break;
		case '2':
			system("cls");
			cout << "\n Insert a new address:";
			cin.get();
			getline(cin,address);
			comp->setAddress(address);
			break;
		case'3':
			system("cls");
			cout<< "\n Insert a new Nif: ";
			cin >> nif;
			comp->setNif(nif);
			break;
		case '4':
			system("cls");
			cout << "\n PUBLISHING NEW APP: " << endl;
			app = AddApplicationMenu();
			comp->addApp(app);
			break;
		case '5':
			system("cls");
			cout << "\n Insert new Company Name: ";
			cin >> busName;
			comp->setCompanyName(busName);
			break;
		case'6':
			system("cls");
			cout << "\n Insert new code: ";
			cin >> code;
			comp->setCode(code);
			break;

		default:
			system("cls");
			DevManagementMenu(comp);
			break;

		}


	cout << endl;
	char y = 'y';
	cout << "\n Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		return;
	}}

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
	cout << endl << " Choose an ID App: ";
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
		cout << endl << " Choose a Client: ";
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
		cout << endl << " Choose an ID Developer: ";
		cin >> in;

		Developer *dev = findDeveloperByID(in);

		cout << " \n\n TRANSACTIONS OF APP " << dev->getName() <<": " << endl;
		vector<App *> devApps = dev->getApps();

		for(unsigned int i = 0; i < devApps.size(); i++)
		{
			vector<Transaction *> trans = devApps[i]->getTransactions();
			for(unsigned int j = 0; j < trans.size(); j++)
			{
				cout << " " << trans[i]->getID();
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

	system("cls");
	file.close();
	cout << "\n Apps saved." << endl;
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
	cout << "\n Developers saved." << endl;
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
	cout << "\n Clients saved." << endl;
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
	cout << "\n Transactions saved." << endl;
}

/**********************************************************
* LOADS                                                   *
**********************************************************/

void AppStore::loadApps()
{
	cout << "\n Loading Apps..." << endl;

	ifstream file;
	file.open("apps.txt");

	App *app;
	int id, devId, numR, numC, type;
	float price, rating;
	string name, description, comment;
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
				cout << field << endl;
			}

			id = atoi(fields[i].c_str());
			cout << id << endl;
			i++;
			name = fields[i];
			cout << name << endl;
			i++;
			price = atof(fields[i].c_str());
			i++;
			type = atoi(fields[i].c_str());
			i++;
			description = fields[i];
			i++;
			devId = atoi(fields[i].c_str());
			cout << devId << endl;
			i++;
			numR = atoi(fields[i].c_str());

			cout << numR << endl;
			app= new App(name,price,type,description);
			app->setDeveloper(findDeveloperByID(devId));
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
			apps.push_back(app);
			firstread++;
			}
	}
	file.close();
	cout <<"\n Apps Loaded." << endl;
}



void AppStore::loadDevelopers()
{
	cout << "\n Loading Developers..." << endl;

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
				cout << "Individual added" << endl;
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
				cout << "Company added" << endl;
			}
		}
	}
	file.close();
	cout <<"\n Developers Loaded." << endl;
}

void AppStore::loadClients()
{
	cout << "\n Loading Clients...";

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
			cout << "Client added" << endl;
		}
	}
	file.close();
	cout << "\n Clients Loaded.";
}

void AppStore::loadTransactions()
{
	cout << "\n Loading Transactions...";

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
					cout << numA << endl;
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
			cout << "\n Clients Loaded.\n ";
}




