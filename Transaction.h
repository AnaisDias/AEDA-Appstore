/*
 * Transaction.h
 *
 *  Created on: 18 de Out de 2014
 *      Author: Sofia
 */

#include "App.h"

using namespace std;

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

class Transaction {
	Client *client;
	// data formato???
	vector<App> apps;
	string usedVoucher;
	static vector<string> workingVouchers;

public:
	Transaction();
	virtual ~Transaction();
};

#endif /* TRANSACTION_H_ */
