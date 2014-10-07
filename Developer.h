/*
 * Developer.h
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#ifndef DEVELOPER_H_
#define DEVELOPER_H_

class Developer {
	string name;
	string adress;
public:
	Developer();
	virtual ~Developer();
};


class Individual: public Developer
{
public:
	Individual();
	~Individual();
};

class Business: public Developer
{
	string business_name;
	int code;

public:
	Business();
	Business(string business_name, int code);
	~Business();
};

#endif /* DEVELOPER_H_ */
