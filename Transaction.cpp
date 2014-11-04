/*
 * Transaction.cpp
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */

#include "Transaction.h"
#include <iostream>

int Transaction::allIDs=0;
vector<string> vouchers; //clear vector?
vector<string> Transaction::workingVouchers = vouchers;

Transaction::Transaction() {
	// TODO Auto-generated constructor stub
	this->id=allIDs;
	allIDs++;
}

Transaction::~Transaction() {
	delete client;
	for(int i=0; i<apps.size(); i++){
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

std::ostream & Transaction::operator<<(std::ostream &out){
	out << "Transaction ID: " << id << endl;
	out << "Client ID: " << client->getID() << "  Client Username: " << client->getUsername() << endl;
	out << "Apps purchased: " << endl;
	for(int i=0; i<apps.size(); i++){
		out << apps[i];
	}
	out << endl;
	return out;
}

std::ostream & Transaction::writeToFile(std::ostream &out){
	out << id << "," << client->getID() << ",";
	out << usedVoucher;
	for(int i=0; i<apps.size(); i++){
		out << apps[i]->getID() << ",";
	}
	return out;
}
