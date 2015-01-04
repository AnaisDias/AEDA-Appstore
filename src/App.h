
#ifndef APP_H_
#define APP_H_

#include <string>
#include <vector>
#include "Developer.h"
#include "Transaction.h"
#include <ctime>

/*
 *
 *
 */

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
	 * 				the name App
	 */
	void setName(string name);
	/*
	 * Set the App price.
	 *
	 * @param price
	 * 				the price App
	 */
	void setPrice(int price);
	void setType(int type);
	void setDescription(string description);
	void setDeveloper(Developer* developer);
	void setRatings(float ratings);
	void setAllRatings(vector<int> ratings);
	void setComments(vector<string> comments);
	void setTransactions(vector<Transaction*> transactions);
	void setTime(time_t time);
	void setValidation(bool validation);
	void setSaleStatus(bool forsale);

	string translateType(int t);
	string displayInfo();
	void displayComments();
	void addTransaction(Transaction* transaction);
	bool removeTransaction(Transaction* transaction);
	void addComment(string comment);
	void addRating(int rating);
	void updateRatings();
	bool operator==(const App &app) const;
	bool operator<(const App &app) const;
	std::ostream & operator<<(std::ostream &out);
	std::ostream & writeToFile(std::ostream &out);
};

#endif /* APP_H_ */
