/*
 * Client.cpp
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#include "Client.h"

Client::Client() {
	// TODO Auto-generated constructor stub

}

Client::Client(string username, int id, int age) {
	this->username = username;
	this->id = id;
	this->age = age;
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

string Client::getUsername() {
	return username;
}

int Client::getAge() {
	return age;
}
