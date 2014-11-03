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
	static int allIDs;
	int id;
	Client *client;
	// data formato???
	vector<App*> apps;
	string usedVoucher;
	static vector<string> workingVouchers;

public:
	Transaction();
	~Transaction();
	static void resetIDs();
	int getID() const;
	Client* getClient() const;
	vector<App*> getApps() const;
	string getUsedVoucher() const;

	void setID(int id);
	void setClient(Client* cli);
	void setApps(vector<App*> apps);
	void setUsedVoucher(string voucher);

	static void setWorkingVouchers(vector<string> vouchers);
	static void addWorkingVoucher(string voucher);

	bool operator==(const Transaction &trans) const;
	std::ostream & operator<<(std::ostream &out);

	std::ostream & writeToFile(std::ostream &out);
};

#endif /* TRANSACTION_H_ */
