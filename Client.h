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
	vector<Transaction> transactions;
public:
	Client();
	~Client();
};

#endif /* CLIENT_H_ */
