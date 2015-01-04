/*!
 * \file Client.h
 *
 * \author FEUP AEDA1415
 * \author Sofia Reis
 * \author Anais Dias
 * \author Joao Viana
 *
 * \date Janeiro 2015
 *
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
	/*!
	 * Constructs and initializes a Client by default.
	 */
	Client();
	/*!
	 * Constructs and initializes an App with a specific name,
	 * price, type and description.
	 *
	 * @param username
	 * 				Client's username
	 * @param price
	 * 				Client's age
	 */
	Client(string username, int age);
	/*!
	 * Destructs and erases the members of the Client.
	 */
	~Client();

	/*!
	 * Resets all Clients' IDs
	 */
	static void resetID();
	/*!
	 * Gets the Client username
	 *
	 * @return username
	 */
	string getUsername() const;
	/*!
	 * Gets the Client age
	 *
	 * @return age
	 */
	int getAge() const;
	/*!
	 * Gets the Client ID
	 *
	 * @return id
	 */
	int getID() const;
	/*!
	 * Gets all Clients' Transactions.
	 *
	 * @return transactions
	 */
	vector<Transaction*> getTransactions() const;
	/*!
	 * Set the Client's username.
	 *
	 * @param username
	 * 				the client's username
	 */
	void setUsername(string username);
	/*!
	 * Set the Client's Age.
	 *
	 * @param age
	 * 				the client's age
	 */
	void setAge(int age);
	/*!
	 * Set the Client's ID.
	 *
	 * @param id
	 * 				the client's ID
	 */
	void setID(int id);


	/*!
	 * Adds Client's transaction.
	 *
	 * @param trans
	 * 				the client's transaction
	 */
	void addTransaction(Transaction* trans);
	/*!
	 * Removes Client's transaction.
	 *
	 * @param trans
	 * 				the client's transaction
	 */
	bool removeTransaction(Transaction* trans);
	/*!
	 * Classifies App.
	 *
	 * @param app
	 * 				the chosen app
	 * @param classification
	 * 				the rating
	 */
	void classifyApp(App* app, int classification);
	/*!
	 * Comments App.
	 *
	 * @param app
	 * 				the chosen app
	 * @param comment
	 * 				app's comment
	 */
	void commentApp(App* app, string comment);

	/*!
	 * Displays Client's info.
	 *
	 * @return out.str()
	 */
	string displayInfo();
	/*!
	 * Displays Client's name.
	 *
	 * @return out.srt()
	 */
	string displayName();

	/*!
	 * == operator
	 * @param client
	 * 			client
	 */
	bool operator==(const Client &client) const;
	/*!
	 * Output operator
	 * @param out
	 * 			output
	 */
	std::ostream & operator<<(std::ostream &out);
	/*!
	 * Writes to .txt file
	 * @param out
	 * 			output
	 */
	std::ostream & writeToFile(std::ostream &out);
};

#endif /* CLIENT_H_ */
