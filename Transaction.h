/*
 * Transaction.h
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */
#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include "App.h"
#include "Client.h"

using namespace std;

class Client;
class App;

class Transaction {
	Client *client;
	// data formato???
	vector<App*> apps;
	string usedVoucher;
	static vector<string> workingVouchers;

public:
	Transaction();
	~Transaction();
	bool operator==(const App &ic1) const;
};

#endif /* TRANSACTION_H_ */
