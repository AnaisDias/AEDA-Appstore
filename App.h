/*
 * App.h
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */


#include <string>

using namespace std;

#ifndef APP_H_
#define APP_H_


class App {
	int price;
	string type;
	string description;
public:
	App();
	virtual ~App();
};

#endif /* APP_H_ */
