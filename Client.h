/*
 * Client.h
 *
 *  Created on: 7 de Out de 2014
 *      Author: Sofia
 */
#ifndef CLIENT_H_
#define CLIENT_H_

#include <vector>
#include "Transaction.h"
#include "App.h"

using namespace std;


class Transaction;
class App;


class Client {
	string username;
	int id;
	static int allIDs;
	int age;
	vector<Transaction*> transactions;
public:
	Client();
	Client(string username, int id, int age);
	~Client();


	/////////////////////
	string getUsername() const;
	int getAge() const;
	int getID() const;
	vector<Transaction*> getTransactions() const;

	void setUsername(string username);
	void setAge(int age);
	void setID(int id);
	/////////////////////

	static void resetID();
	void addTransaction(Transaction* trans);
	void removeTransaction(Transaction* trans);
	bool classifyApp(App* app, int classification);
	bool commentApp(App* app, string comment);

};

#endif /* CLIENT_H_ */
