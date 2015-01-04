#ifndef APP_H_
#define APP_H_

#include <string>
#include <vector>
#include "Developer.h"
#include "Transaction.h"
#include <ctime>

using namespace std;

class Developer;
class Transaction;

class App {
	static int allIDs;
	int id;
	string name;
	float price;
	int type;
	string description;
	Developer* developer;
	float ratings;
	bool validated;
	vector<int> allRatings;
	vector<string> comments;
	vector<Transaction*> transactions;
	time_t submission_time;
	bool forSale;

public:
	/*
	 * Constructs and initializes an App by deafult.
	 */
	App();
	/*
	 * Constructs and initializes an App with a specific name,
	 * price, type and description.
	 *
	 * @param name
	 * 				name of the App
	 * @param price
	 * 				price of the App
	 * @param type
	 * 				type of the App
	 * @param description
	 * 				description of the App
	 */
	App(string name, float price, int type, string description);
	/*
	 * Destructs and erases the members of the App.
	 */
	~App();
	/*
	 * Resets all IDs.
	 */
	static void resetIDs();

	/*
	 * Gets the App ID.
	 *
	 * @return the ID App.
	 */
	int getID() const;
	/*
	 * Gets the App Name.
	 *
	 * @return the Name App.
	 */
	string getName() const;
	/*
	 * Gets the App Price.
	 *
	 * @return the Price App.
	 */
	float getPrice() const;
	/*
	 * Gets the App Type.
	 *
	 * @return the Type App.
	 */
	int getType() const;
	/*
	 * Gets the App Description.
	 *
	 * @return the Description App.
	 */
	string getDescription() const;
	/*
	 * Gets the App Rating.
	 *
	 * @return the Rating App.
	 */
	float getRatings() const;
	/*
	 * Gets all App ratings.
	 *
	 * @return vector with all App ratings.
	 */
	vector<int> getAllRatings() const;
	/*
	 * Gets the App Developer.
	 *
	 * @return the Developer App.
	 */
	Developer* getDeveloper() const;
	/*
	 * Gets all App comments.
	 *
	 * @return vector with all App comments.
	 */
	vector<string> getComments() const;
	/*
	 * Gets all App Transactions.
	 *
	 * @return vector with all App transactions.
	 */
	vector<Transaction*> getTransactions() const;
	/*
	 * Gets the App submission time.
	 *
	 * @return the submission_time App.
	 */
	time_t getTime() const;
	/*
	 * Gets the App validation.
	 *
	 * @return the validation App.
	 */
	bool getValidation() const;
	/*
	 * Gets the App Sale Status.
	 *
	 * @return the Sale Status App.
	 */
	bool getSaleStatus() const;
	/*
	 * Sets the App id.
	 *
	 * @param id
	 * 				the id App
	 */
	void setID(int id);
	/*
	 * Sets the App name.
	 *
	 * @param name
	 * 				the App's name
	 */
	void setName(string name);
	/*
	 * Set the App price.
	 *
	 * @param price
	 * 				the App's type
	 */
	void setPrice(int price);
	/*
	 * Set the App type.
	 *
	 * @param type
	 * 				the App's type
	 */
	void setType(int type);
	/*
	 * Set the App description.
	 *
	 * @param description
	 * 				the App's description
	 */
	void setDescription(string description);
	/*
	 * Set the App developer.
	 *
	 * @param developer
	 * 				the App's developer
	 */
	void setDeveloper(Developer* developer);
	/*
	 * Set the App's ratings.
	 *
	 * @param ratings
	 * 				the App's ratings
	 */
	void setRatings(float ratings);
	/*
	 * Sets all ratings.
	 *
	 * @param ratings
	 * 				the App's ratings
	 */
	void setAllRatings(vector<int> ratings);
	/*
	 * Sets the App's comments.
	 *
	 * @param comments
	 * 				the App's comments
	 */
	void setComments(vector<string> comments);
	/*
	 * Sets the App's transactions.
	 *
	 * @param transactions
	 * 				the App's transactions
	 */
	void setTransactions(vector<Transaction*> transactions);
	/*
	 * Sets the time.
	 *
	 * @param time
	 * 				time
	 */
	void setTime(time_t time);
	/*
	 * Sets the validation.
	 *
	 * @param validation
	 * 				the app's validation, or not
	 */
	void setValidation(bool validation);
	/*
	 * Sets the sale status.
	 *
	 * @param forsale
	 * 				the app's sale status
	 */
	void setSaleStatus(bool forsale);

	/*
	 * Converts the 't' value into a type on a string format.
	 *
	 * @param t
	 * 				the type
	 * @return the type
	 */
	string translateType(int t);
	/*
	 * Displays all of the App's info available.
	 * @return the information
	 */
	string displayInfo();
	/*
	 * Displays all of the App's comments.
	 * @return the app's comments
	 */
	void displayComments();
	/*
	 * Adds Transaction.
	 * @param transaction
	 *				the transaction
	 */
	void addTransaction(Transaction* transaction);
	/*
	 * Removes Transaction.
	 * @param transaction
	 *				the transaction
	 */
	bool removeTransaction(Transaction* transaction);
	/*
	 * Adds comment.
	 * @param comment
	 *				the comment
	 */
	void addComment(string comment);
	/*
	 * Adds rating.
	 * @param rating
	 *				the rating
	 */
	void addRating(int rating);
	/*
	 * Updates Apps' ratings.
	 */
	void updateRatings();
	/*
	 * == operator
	 * @param app
	 * 			App
	 */
	bool operator==(const App &app) const;
	/*
	 * < operator
	 * @param app
	 * 			App
	 */
	bool operator<(const App &app) const;
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

#endif /* APP_H_ */
