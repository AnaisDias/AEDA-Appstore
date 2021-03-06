 /*!
 * \file Transaction.cpp
 *
 * \author FEUP AEDA1415
 * \author Sofia Reis
 * \author Anais Dias
 * \author Joao Viana
 *
 * \date Janeiro 2015
 *
 */
#include "Transaction.h"
#include <iostream>
#include <sstream>

int Transaction::allIDs=0;
vector<string> vouchers;
vector<string> Transaction::workingVouchers = vouchers;

Transaction::Transaction() {
	this->id=allIDs;
	allIDs++;
}

Transaction::~Transaction() {
	delete client;
	for(unsigned int i=0; i<apps.size(); i++){
		delete apps[i];
		apps.erase(apps.begin()+i);
		i--;
	}
	// TODO Auto-generated destructor stub
}

void Transaction::resetIDs(){
	allIDs=0;
}

int Transaction::getID() const{
	return id;
}

Client* Transaction::getClient() const{
	return client;
}

vector<App*> Transaction::getApps() const{
	return apps;
}

string Transaction::getUsedVoucher() const{
	return usedVoucher;
}

void Transaction::addApp(App *app){
	apps.push_back(app);
	float earn = app->getPrice() * 0.8;
	app->getDeveloper()->addEarnings(earn);
}

void Transaction::setID(int id){
	this->id=id;
}

void Transaction::setClient(Client* cli){
	this->client=cli;
}

void Transaction::setApps(vector<App*> apps){
	this->apps=apps;
}

void Transaction::setUsedVoucher(string voucher){
	usedVoucher=voucher;
}

void Transaction::setWorkingVouchers(vector<string> vouchers){
	workingVouchers=vouchers;
}

void Transaction::addWorkingVoucher(string voucher){
	workingVouchers.push_back(voucher);
}



bool Transaction::operator==(const Transaction &trans) const{
	Client* cli =this->client;
	Client* cli2 =trans.client;

	if(*cli==*cli2 && this->apps==trans.apps){
		return true;
	}
	return false;
}

string Transaction::displayInfo()
{
	stringstream out;
	out << " Transaction ID: " << id << endl;
	out << " Client Name: " << client->getUsername() << endl;

	return out.str();
}


std::ostream & Transaction::operator<<(std::ostream &out){
	out << "Transaction ID: " << id << endl;
	out << "Client ID: " << client->getID() << "  Client Username: " << client->getUsername() << endl;
	out << "Apps purchased: " << endl;
	for(unsigned int i=0; i<apps.size(); i++){
		out << apps[i];
	}
	out << endl;
	return out;
}

std::ostream & Transaction::writeToFile(std::ostream &out){
	out << id << "," << client->getID() << ",";
	out << usedVoucher << "," << apps.size() << ",";
	for(unsigned int i=0; i<apps.size(); i++){
		out << apps[i]->getID() << ",";
	}
	return out;
}
