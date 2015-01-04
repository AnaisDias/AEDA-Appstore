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
	vector<App*> apps;
	string usedVoucher;
	static vector<string> workingVouchers;

public:
	/*
	 * Constructs and initializes a Transaction by default.
	 */
	Transaction();
	/*
	 * Destructs and erases the members of the Transaction.
	 */
	~Transaction();
	/*
	 * Resets all IDs.
	 */
	static void resetIDs();
	/*
	 * Gets IDs
	 *
	 * @return id
	 */
	int getID() const;
	/*
	 * Gets Client
	 *
	 * @return Client
	 */
	Client* getClient() const;
	/*
	 * Gets Apps
	 *
	 * @return Apps
	 */
	vector<App*> getApps() const;
	/*
	 * Gets Used Voucher
	 *
	 * @return Used Voucher
	 */
	string getUsedVoucher() const;

	/*
	 * Adds App
	 */
	void addApp(App *app);

	/*
	 * Sets ID
	 * @param id
	 * 			id
	 */
	void setID(int id);
	/*
	 * Sets Client
	 * @param Client
	 * 			Client
	 */
	void setClient(Client* cli);
	/*
	 * Sets apps
	 * @param apps
	 * 			apps
	 */
	void setApps(vector<App*> apps);
	/*
	 * Sets voucher
	 * @param voucher
	 * 			voucher
	 */
	void setUsedVoucher(string voucher);

	/*
	 * Sets Working vouchers
	 * @param vouchers
	 * 			vouchers
	 */
	static void setWorkingVouchers(vector<string> vouchers);
	/*
	 * Adds Working vouchers
	 * @param vouchers
	 * 			vouchers
	 */
	static void addWorkingVoucher(string voucher);

	/*
	 * Displays Transaction Info
	 * @return Transactions' info
	 */
	string displayInfo();

	/*
	 * == operator
	 * @param trans
	 * 			transaction
	 */
	bool operator==(const Transaction &trans) const;
	/*
	 * Output operator
	 * @param out
	 * 			output
	 */
	std::ostream & operator<<(std::ostream &out);
	/*
	 * Writes to .txt file
	 * @param out
	 * 			output
	 */
	std::ostream & writeToFile(std::ostream &out);
};

#endif /* TRANSACTION_H_ */
