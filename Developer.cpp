/*
 * Developer.cpp
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#include "Developer.h"

Developer::Developer() {
	// TODO Auto-generated constructor stub

}

Developer::Developer(string name, string address, int nif) {
	this->name = name;
	this->address = address;
	this->nif = nif;
}

Developer::~Developer() {
	// TODO Auto-generated destructor stub
}

string Developer::getName() const{
	return name;
}

string Developer::getAddress() const {
	return address;
}

int Developer::getNif() const{
	return nif;
}

vector<App*> Developer::getApps() const{
	return appsPublished;
}

void Developer::setName(string name){
	this->name=name;
}
void Developer::setAddress(string address){
	this->address=address;
}
void Developer::setNif(int nif){
	this->nif=nif;
}
void Developer::setApps(vector<App*> apps){
	this->appsPublished=apps;
}
/////////////////////

void Developer::addApp(App* app){
	appsPublished.push_back(app);
}

bool Developer::removeApp(App* app){
	for(int i=0; i<appsPublished.size(); i++){
		if(app==appsPublished[i]){
			appsPublished.erase(appsPublished.begin() + i);
			return true;
		}
	}
	return false;
}

void Developer::displayInfo(){

}

void Developer::displayAllSales(){

}

bool Developer::operator==(const Developer &dev) const{
	if(this->name==dev.name && this->nif==dev.nif) return true;
	return false;
}
