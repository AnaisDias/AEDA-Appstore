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
		if (apps[i] == app)
			apps.erase(apps.begin()+i);
			i--;
			return true;
	}
	return false;
}

bool AppStore::removeClient(Client* client){
	for (unsigned int i = 0; i < clients.size(); i++) {
			if (clients[i] == client)
				clients.erase(clients.begin()+i);
				i--;
				return true;
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
	cout << "TOP 5 APPS" << endl << endl;
	unsigned int var;
	if(apps.size() < 5) var = apps.size();
		else var = 5;
	for(int i=0; i<var; i++){
		cout << top5[i]->displayInfo() << endl;
	}
	cout << endl << "Select app by ID or enter 'r' to return: ";
	cin >> input;
	cout << input << endl;
	int in = atoi(input.c_str());
	if(input == "r") return;
	else try{
		AppManagementMenu(findAppByID(in));
	}
	catch (AppDoesNotExist &e1){
		cout << "Specified app does not exist. ID: " << e1.getID() << endl;
	}
}

void AppStore::AppsListName() {
	string input;
	string input2;
	vector<App*> appsN;
	cout << "Enter app name: ";
	cin >> input;
	appsN=findAppsByName(input);

	system("cls");
	cout << "Apps List By NAME: " << endl;
	if(appsN.empty()) {
		cout << "No apps with the requested name. Press any key to go back" <<endl;
		cin.get();
		return;
	}
	else{
		for(int i=0; i<appsN.size();i++){
			cout << appsN[i]->displayInfo() << endl;
		}
	}

	cout << endl << "Select app by ID or enter 'r' to return: ";
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
		cout << "Specified app does not exist. ID: " << e1.getID() << endl;
	}
}


void AppStore::AppsListType() {
	int type;
	string input;
	vector<App*> appstype;
	cout << "Apps List By TYPE: " << endl;
	cout << endl << "Types: ";
	cout << "1. Entertainment" << endl;
	cout << "2. Finances" << endl;
	cout << "3. Games" << endl;
	cout << "4. Fitness" << endl;
	cout << "5. Lifestyle" << endl;
	cout << "6. Music" << endl;
	cout << "7. Photography" << endl;
	cout << "8. Productivity" << endl;
	cout << "9. Social Networks" << endl;
	cout << "10. Sports" << endl;
	cout << "11. Traveling" << endl;
	cout << "12. Utilities" << endl;

	cout << "Select a type: ";
	cin >> type;
	appstype = findAppsByType(type);
	if(appstype.empty()){
		cout << "No apps with the requested type. Press any key to go back" <<endl;
		cin.get();
		return;
	}
	else{
	for(int i=0; i<appstype.size(); i++){
		cout << appstype[i]->displayInfo() << endl;
	}
	}

	cout << endl << "Select app by ID or enter 'r' to return: ";
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
		cout << "Specified app does not exist. ID: " << e1.getID() << endl;
	}
	//insert try and catch here

}

void AppStore::AllAppsList(){
	string input;
	if(apps.empty()){
		cout << "No apps. Press any key to go back" <<endl;
		cin.get();
		return;
	}
	vector<App *>::iterator it = apps.begin();
	for( ;it<apps.end(); it++){
		cout << (*(*it)).displayInfo();
				cout << endl;
	}
	cout << endl << "Select app by ID or enter 'r' to return: ";
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
		cout << "Specified app does not exist. ID: " << e1.getID() << endl;
	}
}
void AppStore::RateApps() {
	string name;
	string rate;
	string input;
	App *app;

	cout << "Which app do you want to rate?" << endl;
	cout << "Apps List:" << endl;

	if(apps.empty()){
		cout << "No apps. Press any key to go back" <<endl;
		cin.get();
		return;
	}
	for(int i=0; i<apps.size(); i++){
		cout << apps[i]->displayInfo();
		cout << endl;
	}
	cout << endl << "Select app by ID or enter 'r' to return: ";
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
			cout << "Specified app does not exist. ID: " << e1.getID() << endl;
		}
		system("cls");
		cout << "RATE:" << endl;
		cout << "1 - Hate" << endl;
		cout << "2 - Dislike" << endl;
		cout << "3 - Like" << endl;
		cout << "4 - Love" << endl;
		cout << "5 - Amazing" << endl;
		cout << "0 - Go Back" << endl;
		cout << "OPTION: ";
		cin >> rate;
		cin.get();

		if(rate=="0") return;

		app->addRating(atoi(rate.c_str()));
		//add try and catch here
		cout << "Rating added successfully!" << endl;
		cin.get();


	}
}

void AppStore::AddApplicationMenu() {
	string name, desc;
	int type, dev;
	float price;
	cout << "ADD APP" <<endl;
	cout << "Insert the following information: " << endl << endl;
	cout << "Name: ";
	cin.get();
	cin >> name;
	cout << endl << "Price: ";
	cin >> price;
	cout << endl << "Type (select from 1 to 12): ";
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
	cin >> type;
	cout << endl << "Add a short description (no commas): ";
	cin.get();
	getline(cin,desc);
	cout << endl << "Developer's ID: ";
	cin >> dev;

	App *app;
	app = new App(name, price, type, desc);
	app->setDeveloper(findDeveloperByID(dev));
	//add try and catch exception here

	addApp(app);

	cout << "App" << name << "Added Successfully To The Appstore" << endl;
	cout << endl;
	cout << "Press any key to return ";
	cin.get();

}


void AppStore::RemoveApplicationMenu() {
	string input;
	if(apps.empty()){
		cout << "No apps. Press any key to go back" <<endl;
		cin.get();
		return;
	}
	for(int i=0; i<apps.size(); i++){
		cout << apps[i] << endl;
	}
	cout << endl << "Select app by ID or enter 'r' to return: ";
	cin >> input;
	if(input == "r") {
		system("cls");
		return;
	}

	App *app = findAppByID(atoi(input.c_str()));
	// add try and catch here;
	removeApp(app);

	cout << "App removed successfully from the Appstore" << endl;
	cout << endl;
	cout << "Press any key to return ";
	cin.get();
}

void AppStore::AppManagementMenu(App* app){

	string name;
	int choice, type, dev, rating;
	system("cls");
	cout << "APP MANAGEMENT: ID=" << app->getID() << endl << endl;
	cout << "What do you wish to do? " << endl;
	cin.get();
	cout << "1. Change name" << endl;
	cout << "2. Change type" << endl;
	cout << "3. Change developer" << endl;
	cout << "4. Add rating" << endl;
	cout << "5. Remove app" << endl;
	cin >> choice;


	switch(choice) {

			case 1: system("cls");
			cout << "Insert new name ";
					cin >> name;
					app->setName(name);
					cout << endl << "Name changed to " << name << endl;
					break;
			case 2: cout << "Insert new type ";
			cin >> type;
			app->setType(type);
			cout << endl << "Type changed to " << type << endl;
					break;
			case 3: cout << "Insert new developer ID ";
			cin >> dev;
			app->setDeveloper(findDeveloperByID(dev));
			//add try and catch here
			cout << endl << "Developer's new ID is " << dev << endl;

					break;
			case 4: cout << "Insert new rating ";
			cin >> rating;
			app->addRating(rating);
			cout << endl << "Rating added: " << rating << endl;

					break;
			case 5: removeApp(app);
					cout << "App successfully removed. ";
					break;
			default: break;
	}
	cout << endl;
	cin.get();
	cout << "Press any key to return ";
	cin.get();
}

/////////////////////////
//////SUB CLIENT ////////
/////////////////////////

void AppStore::ClientsList() {
	cout << "\n CLIENTS LIST" << endl;
	cout << " ---------------------------------------------------------" << endl;

	string input;
		if(clients.empty()){
			cout << "No clients. Press any key to go back" <<endl;
			cin.get();
			return;
		}
	for(unsigned int i = 0; i < clients.size(); i++)
	{
		cout << clients[i]->displayInfo() << endl;
	}

	cout << endl << "Select client by ID or enter 'r' to return: ";
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
		cout << "Specified client does not exist. ID: " << e1.getID() << endl;
	}
}

void AppStore::PurchasedApps() {
	cout << "PURCHASED APPS" << endl;
		cout << " ---------------------------------------------------------" << endl;

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

}

void AppStore::RemoveClients() {
	int id;
	cout << "ID of client to be removed: ";
	cin >> id;


	try{
		removeClient(findClientByID(id));
	}
	catch (ClientDoesNotExist &e1){
		cout << "Specified client does not exist. ID: " << e1.getID() << endl;
	}

	cout << endl << "Client removed successfully from the Appstore database" << endl;

	cout << endl;
	cout << "Press any key to return ";
	cin.get();

}

void AppStore::ClientManagementMenu(Client* cli){
	string name;
	int choice, age;
	system("cls");
	cout << "CLIENT MANAGEMENT: ID=" << cli->getID() << endl << endl;
	cout << "What do you wish to do? " << endl;
	cin.get();
	cout << "1. Change username" << endl;
	cout << "2. Change age" << endl;
	cout << "Any other key. Go Back" << endl;
	cin >> choice;


	switch(choice) {

	case 1: system("cls");
	cout << "Insert new name ";
	cin >> name;
	cli->setUsername(name);
	cout << endl << "Name changed to " << name << endl;
	break;

	case 2: "Insert new age ";
	cin >> age;
	cli->setAge(age);
	cout << endl << "Age changed to " << age << endl;
	break;

	default:
		cin.get();
		break;
	}
	cout << endl;
	cin.get();
	cout << "Press any key to return ";
	cin.get();
}

/////////////////////////
//////SUB DEV ///////////
/////////////////////////

void AppStore::IndividualDevList() {
	cout << "INDIVIDUAL DEVELOPERS: " << endl;

	//display list

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		DeveloperMenu();
	}


}

void AppStore::EnterpriseList() {
	cout << "ENTERPRISES: " << endl;

	//display list

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		DeveloperMenu();
	}


}

void AppStore::AppsCreated() {
	int choice;
	char y = 'y';
	string name;
	cout << "APPS CREATED BY A DEV/ENTERPRISE: " << endl;
	cout << "1 - Individual Developer" << endl;
	cout << "2 - Enterprise" << endl;
	cout << "0 - Go back" << endl;
	cout << "OPTION: ";
	cin >> choice;

	switch(choice) {

	case 1: system("cls");
			//display list of devs
			cout << endl;
			cout << "Apps Created By: ";
			cin >> name;
			//display apps;
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				DeveloperMenu();
			}
			break;
	case 2: system("cls");
			//display list of enterprises
			cout << endl;
			cout << "Apps Created By: ";
			cin >> name;
			//display apps;
			cout << endl;
			cout << "Go Back? (y)";
			cin >> y;
			if (y == 'y') {
				system("cls");
				DeveloperMenu();
			}
			break;
	case 0: system("cls");
			DeveloperMenu();
			break;
	default: break;
	}
}

void AppStore::SalesData() {

}

void AppStore::AddDev() {
	string name;
	cout << "Developer To Be Added: ";
	cin >> name;

	//add dev to the appstore

	cout << "Developer Added Successfully To The Appstore" << endl;

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		DeveloperMenu();
	}
}

void AppStore::RemoveDev() {
	string name;
	cout << "Developer To Be Removed: ";
	// display list of Devs
	cout << "Remove: ";
	cin >> name;

	//remove dev from the appstore

	cout << "Developer Removed Successfully From The Appstore" << endl;

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		DeveloperMenu();
	}
}

/////////////////////////
//////SUB TRANS /////////
/////////////////////////

void AppStore::TransApps() {
	cout << "APPS TRANSACTIONS: " << endl;
	//display apps transactions

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		TransactionMenu();
	}
}

void AppStore::TransClients() {
	cout << "CLIENTS TRANSACTIONS: " << endl;
	//display the client transactions????

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		TransactionMenu();
	}
}

void AppStore::TransDev() {
	cout << "DEVELOPERS/ENTERPRISES TRANSACTIONS: " << endl;
	//display the devs list and which transaction the client wants to see????? lol

	cout << endl;
	char y = 'y';
	cout << "Go Back? (y)";
	cin >> y;
	if (y == 'y') {
		system("cls");
		TransactionMenu();
	}
}

/**********************************************************
 *                    SAVES AND LOADS                     *
 *********************************************************/

void AppStore::saveApps()
{
	vector<App *>::iterator it = apps.begin();

	ofstream file;
	file.open("apps1.txt", ios::trunc);


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
	file.open("developers1.txt",ios::trunc);

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
	file.open("clients1.txt",ios::trunc);

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
	file.open("transactions1.txt",ios::trunc);

	for(; it != transactions.end(); it++)
	{
		(*it)->writeToFile(file);
		file << endl;
	}
	system("cls");
	file.close();
	cout << "\n Transactions saved." << endl;
}

///LOADS

void AppStore::loadApps()
{
	cout << "Loading Apps..." << endl;

	ifstream file;
	file.open("apps.txt");

	App *app;
	int id, devId, numR, numC, numT, transid, type;
	float price, rating;
	string name, description, comment;
	string line, line1, readline;
	vector<string> fields;
	int firstread = 0;
	int j=0;


	if(file.is_open()){
		while(getline(file, line))
		{
			int i=0;
		//	App *app;


			cout << line << endl;
			//getline(file, line);
			//cout << "segundo getline: " << line << endl;


			fields.clear();

			stringstream ss(line);
			//ss(line);
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
			//cout << i << endl;
			numC = atoi(fields[i].c_str());
			//cout << numC << endl;
			i++;
			for(int j=0; j<numC; j++){
				comment = fields[i];
				i++;
				app->addComment(comment);
				//cout << "comment added" << endl;
			}

			/*
			numT = atoi(loadTokens(i,line).c_str());

			for(int j=0; j<numT; j++){
				transid = atoi(loadTokens(i,line).c_str());
				i++;
				app->addTransaction(findTransactionByID(transid));
			}*/

			apps.push_back(app);
			firstread++;
			cout << "app loaded" << endl;
		//	ss.str("");
		//	ss.clear();
			}

	}

	file.close();
	cout <<"\n Apps Loaded." << endl;

}

void AppStore::loadApps2()
{
cout << "Loading Apps..." << endl;

	ifstream file;
	file.open("apps.txt");

	App *app;
	int id, devId, numR, numC, numT, transid, type;
	float price, rating;
	string name, description, comment;
	string line, line1, readline;
	vector< vector<string> > fields;
	vector<string> info;
	fields.resize(100);
	int firstread = 0;
	int j=0;
	int i=0;


	if(file.is_open()){

		while(!file.eof())
		{
		//	App *app;

			getline(file, line);
			getline(file, line);
			cout << line << endl;
			//getline(file, line);
			//cout << "segundo getline: " << line << endl;

			stringstream ss(line);
			//ss(line);
			string field;

			while (ss.good()){
				getline(ss, field, ',');
				cout << field << endl;
				(fields[j]).push_back(field);

			}
			j++;

		}

		cout << j << endl;
		int k=0;

		while(k<j){
			int i=0;
			info = fields[k];
			id = atoi(info[i].c_str());
			cout << id << endl;
			i++;
			name = info[i];
			cout << name << endl;
			i++;
			price = atof(info[i].c_str());
			i++;
			type = atoi(info[i].c_str());
			i++;
			description = info[i];
			i++;
			devId = atoi(info[i].c_str());
			cout << devId << endl;
			i++;
			numR = atoi(info[i].c_str());

			cout << numR << endl;
			app= new App(name,price,type,description);
			app->setDeveloper(findDeveloperByID(devId));
			for(int j=0; j<numR; j++){
				rating = atoi(info[i].c_str());
				i++;
				app->addRating(rating);
			}
			i++;
			i++;
			//cout << i << endl;
			numC = atoi(info[i].c_str());
			//cout << numC << endl;
			i++;
			for(int j=0; j<numC; j++){
				comment = info[i];
				i++;
				app->addComment(comment);
				//cout << "comment added" << endl;
			}
			apps.push_back(app);
			k++;
			cout << "app loaded" << endl;
			continue;
		//	ss.str("");
		//	ss.clear();
			}

		cout << k << endl;




	file.close();
	cout <<"\n Apps Loaded." << endl;
	}
}

void AppStore::loadDevelopers()
{
	cout << "Loading Developers..." << endl;

	ifstream file;
	file.open("developers.txt", ios::in);

	int id, nif;
	string name, address;
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
			Developer *developer;
			vector<App*>appsP;

			id = atoi(fields[i].c_str());
			i++;
			name = fields[i];
			i++;
			address = fields[i];
			i++;
			nif = atoi(fields[i].c_str());

			developer = new Developer(name, address, nif);
			developer->setID(id);
			//AppsPublished (vai ser numa funçao diferente)
			developers.push_back(developer);
			cout << "Developer added" << endl;
		}

	}

	file.close();
	cout <<"\n Developers Loaded." << endl;
}

void AppStore::assignPublishedAppsToDevs(){

	for(int i=0; i<developers.size();i++){
		for(int j=0; j<apps.size();j++){
			if(developers[i]->getID() == apps[j]->getDeveloper()->getID()){
				developers[i]->addApp(apps[j]);
			}
		}
	}
}


void AppStore::loadClients()
{
	cout << "Loading Clients...";

	ifstream file;
	file.open("clients.txt", ios::in);

	int id, age, numT, transid;
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
			//set transactions
			client = new Client(username,age);
			client->setID(id);
			//AppsPublished (vai ser numa funçao diferente)
			clients.push_back(client);
			cout << "Client added" << endl;
		}

	}


	file.close();
	cout << "\n Clients Loaded.";
}

void AppStore::loadTransactions()
{
	cout << "Loading Transactions...";

	ifstream file;
	file.open("transactions.txt", ios::in);


	int id, clientId, numA, appID, cliID;
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
					//set transactions
					transaction = new Transaction();
					transaction->setID(id);
					transaction->setClient(findClientByID(cliID));
					transaction->setUsedVoucher(usedVoucher);
					for(int j=0; j<numA; j++){
						appID = atoi(fields[i].c_str());
						i++;
						transaction->addApp(findAppByID(appID));
					}
					//AppsPublished (vai ser numa funçao diferente)
					transactions.push_back(transaction);
					cout << "Transaction added" << endl;
				}

			}


			file.close();
			cout << "\n Clients Loaded.";
}

void AppStore::assignTransactionsToApps(){
	vector<App*> appsT;
	for(int i=0; i<apps.size();i++){
		for(int j=0; j<transactions.size();j++){
			for(int k=0; k< transactions[j]->getApps().size();k++){
				appsT = transactions[j]->getApps();
				if(apps[i]->getID() == appsT[k]->getID()){
					apps[i]->addTransaction(transactions[j]);
				}
			}
		}
	}
}



