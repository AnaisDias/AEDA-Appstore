/*
 * Client.h
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */

#include <vector>
#include "Transaction.h"

using namespace std;

#ifndef CLIENT_H_
#define CLIENT_H_



class Client {
	string username;
	int id;
	static int allIDs;
	int age;
	vector<Transaction> transactions;
public:
	Client();
	Client(string username, int id, int age);
	~Client();


	/////////////////////
	string getUsername();
	//static int getIds(); idk what to do im dumb
	int getAge();
	/////////////////////

};

#endif /* CLIENT_H_ */
