/*
 * Developer.cpp
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#include "Developer.h"
#include <iostream>

int Developer::allIDs=0;

Developer::Developer() {
	id=allIDs;
	allIDs++;
	nif=0;
	name="";

}

Developer::Developer(string name, string address, int nif) {
	this->name = name;
	this->address = address;
	this->nif = nif;
	this->id=allIDs;
	allIDs++;
}

Developer::~Developer() {
	for(unsigned int i=0; i<appsPublished.size(); i++){
			delete appsPublished[i];
			appsPublished.erase(appsPublished.begin()+i);
			i--;
		}
}

int Developer::getID() const{
	return id;
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

void Developer::setID(int id){
	this->id=id;
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

std::ostream & Developer::operator<<(std::ostream &out){
	out << "Developer ID: " << id << endl;
	out << "Developer name: " << name << endl;
	out << "Address: " << address << endl;
	out << "NIF: " << nif << endl;
	out << endl;
	return out;
}

std::ostream & Developer::writeToFile(std::ostream &out){
	out << id << "," << name << "," << address << ",";
	out << nif << ",";
	for(int i=0; i<appsPublished.size();i++){
		out << appsPublished[i]->getID();
		if(i!=appsPublished.size()) out << ",";
	}
	return out;
}

/////////////////////

Individual::Individual(string name, string address, int nif):Developer(name, address, nif){
}

Company::Company(string businessname, int code, string name, string address, int nif):Developer(name, address, nif){
	this->code=code;
	this->businessName=businessname;
}
