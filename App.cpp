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
string App::getName() {
	return name;
}

float App::getPrice() {
	return price;
}

string App::getType() {
	return type;
}

string App::getDescription() {
	return description;
}

float App::getRatings() {
	return ratings;
}
