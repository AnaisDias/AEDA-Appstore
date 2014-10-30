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

string Developer::getName() {
	return name;
}

string Developer::getAddress() {
	return address;
}

int Developer::getNif() {
	return nif;
}
