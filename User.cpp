/*
 * User.cpp
 *
 *  Created on: 30/12/2014
 *      Author: Sofia Reis
 */

#include "User.h"
#include <sstream>

int User::allIDs=0;

User::User(int type, string username, string password) {
	this->type = type;
	this->username = username;
	this->password = password;
	this->id=allIDs;
	allIDs++;
}

User::~User() {
	// TODO Auto-generated destructor stub
}

int User::getType(){
	return type;
}

void User::setType(int type){
	this->type = type;
}

string User::getUsername(){
	return username;
}
void User::setUsername(string username)
{
	this->username = username;
}
string User::getPassword()
{
	return password;
}
void User::setPassword(string password)
{
	this->password = password;
}

int User::getId(){
	return id;
}

void User::setId(int id){
	this->id=id;
}

std::ostream & User::writeToFile(std::ostream &out){
	out << id << "," << username << ",";
	out << password << ",";
	out << type;

	return out;
}

std::ostream & User::operator<<(std::ostream &out){
	out << "User ID: " << id << endl;
	out << "Username: " << username << endl;
	out << "Password: " << password << endl;
	out << "Type: " << type << endl;
	out << endl;
		return out;
}
string User::displayInfo()
{
	stringstream out;
	out << "User ID: " << id << endl;
	out << "Username: " << username << endl;
	out << "Password: " << password << endl;
	out << "Type: " << type << endl;

	return out.str();
}
