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

App::App(int price, string type, string description)
{
	this->price = price;
	this->type = type;
	this->description = description;
}
