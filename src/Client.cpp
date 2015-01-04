/*!
 * \file Client.cpp
 *
 * \author FEUP AEDA1415
 * \author Sofia Reis
 * \author Anais Dias
 * \author Joao Viana
 *
 * \date Janeiro 2015
 *
 */
#include "Client.h"
#include "Exceptions.h"
#include <iostream>
#include <sstream>

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

string Client::displayInfo(){
	stringstream out;
	out << " Client ID: " << id << endl;
	out << " Username: " << username << endl;
	out << " Age: " << age << endl;

	return out.str();
}

string Client::displayName() {
	stringstream out;
	out << "Client Name: " << username << endl;

	return out.str();
}

bool Client::operator==(const Client &client) const{
	if(this->id==client.id && this->username==client.username) return true;
	return false;
}

std::ostream & Client::operator<<(std::ostream &out){
	out << "Client ID: " << id << endl;
	out << "Client name: " << username << endl;
	out << "Age: " << age << endl;
	out << endl;
	return out;
}

std::ostream & Client::writeToFile(std::ostream &out){
	out << id << "," << username << ",";
	out << age << ",";
	out << transactions.size() << ",";
	for(unsigned int i=0; i<transactions.size(); i++){
		out << transactions[i]->getID();
		if(i!=transactions.size()) out << ",";
	}
	return out;

}
