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
	int price;
	string type;
	string description;
	// acrescentar mais membros
	int classification; //1 NAO GOSTO - 5 ESPETACULAR

public:
	App();
	App(int price, string type, string description);
	~App();
};

#endif /* APP_H_ */
