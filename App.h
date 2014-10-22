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
	float price;
	string type;
	string description;
	Developer *developer;
	// acrescentar mais membros
	float classification; //1 NAO GOSTO - 5 ESPETACULAR float porque vai ser a media das classificaçoes atribuidas
	vector<string> comments;

public:
	App();
	App(int price, string type, string description);
	~App();
};

#endif /* APP_H_ */
