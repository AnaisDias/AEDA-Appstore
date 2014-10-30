/*
 * App.cpp
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#include "App.h"

App::App() {
	// TODO Auto-generated constructor stub

}

App::~App() {
	// TODO Auto-generated destructor stub
}

App::App(string name, int price, string type, string description) {
	this->name = name;
	this->price = price;
	this->type = type;
	this->description = description;
}


//////////////////////////////////////
string App::getName() const {
	return name;
}

float App::getPrice() const {
	return price;
}

string App::getType() const {
	return type;
}

string App::getDescription() const {
	return description;
}

float App::getRatings() const {
	return ratings;
}
