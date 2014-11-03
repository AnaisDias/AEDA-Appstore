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
#include <vector>

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
	Client* getClient() const;
	vector<App*> getApps() const;
	string getUsedVoucher() const;

	void setClient(Client* cli);
	void setApps(vector<App*> apps);
	void setUsedVoucher(string voucher);

	static void setWorkingVouchers(vector<string> vouchers);
	static void addWorkingVoucher(string voucher);

	bool operator==(const Transaction &trans) const;
};

#endif /* TRANSACTION_H_ */
