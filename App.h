/*
 * App.h
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */


#include <string>
#include <vector>

using namespace std;

#ifndef APP_H_
#define APP_H_


class App {
	string name;
	float price;
	string type;
	string description;
	Developer *developer;
	// acrescentar mais membros
	float ratings; //1 NAO GOSTO - 5 ESPETACULAR float porque vai ser a media das classifica�oes atribuidas
	vector<string> comments;

public:
	App();
	App(string name, int price, string type, string description);
	~App();



	/////////////////////
	string getName();
	float getPrice();
	string getType();
	string getDescription();
	float getRatings();
	/////////////////////

};

#endif /* APP_H_ */
