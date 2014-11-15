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
	Client(string username, int age);
	~Client();


	/////////////////////
	static void resetID();
	string getUsername() const;
	int getAge() const;
	int getID() const;
	vector<Transaction*> getTransactions() const;

	void setUsername(string username);
	void setAge(int age);
	void setID(int id);

	/////////////////////


	void addTransaction(Transaction* trans);
	bool removeTransaction(Transaction* trans);
	void classifyApp(App* app, int classification);
	void commentApp(App* app, string comment);

	string displayInfo();
	string displayName();

	bool operator==(const Client &client) const;
	std::ostream & operator<<(std::ostream &out);

	std::ostream & writeToFile(std::ostream &out);
};

#endif /* CLIENT_H_ */
