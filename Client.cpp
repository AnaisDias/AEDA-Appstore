/*
 * Client.cpp
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#include "Client.h"

int Client::allIDs=0;

Client::Client() {
	this->id=allIDs;
	allIDs++;
	this->age=0;
}

Client::Client(string username, int age) {
	this->username = username;
	this->age = age;
	this->id=allIDs;
	allIDs++;
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

void Client::resetID(){
	allIDs=0;
}

string Client::getUsername() const{
	return username;
}

int Client::getAge() const {
	return age;
}

int Client::getID() const{
	return id;
}

vector<Transaction*> Client::getTransactions() const{
	return transactions;
}

void Client::setUsername(string username){
	this->username=username;
}

void Client::setAge(int age){
	this->age=age;
}

void Client::setID(int id){
	this->id=id;
}

/////////////////////

void Client::addTransaction(Transaction* trans){
	transactions.push_back(trans);
}

bool Client::removeTransaction(Transaction* trans){
	for(int i=0; i<transactions.size(); i++){
		if(trans==transactions[i]){
			transactions.erase(transactions.begin() + i);
			return true;
		}
	}
	return false;
}

void Client::classifyApp(App* app, int classification){
	app->addRating(classification);
}

void Client::commentApp(App* app, string comment){
	comment+= "by ";
	comment+= this->username;
	app->addComment(comment);
}

bool Client::operator==(const Client &client) const{
	if(this->id==client.id && this->username==client.username) return true;
	return false;
}
