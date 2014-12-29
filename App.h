
#ifndef APP_H_
#define APP_H_

#include <string>
#include <vector>
#include "Developer.h"
#include "Transaction.h"

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
	vector<int> allRatings;
	vector<string> comments;
	vector<Transaction*> transactions;

public:
	App();
	App(string name, float price, int type, string description);
	~App();
	static void resetIDs();


	/////////////////////
	int getID() const;
	string getName() const;
	float getPrice() const;
	int getType() const;
	string getDescription() const;
	float getRatings() const;
	vector<int> getAllRatings() const;
	Developer* getDeveloper() const;
	vector<string> getComments() const;
	vector<Transaction*> getTransactions() const;

	void setID(int id);
	void setName(string name);
	void setPrice(int price);
	void setType(int type);
	void setDescription(string description);
	void setDeveloper(Developer* developer);
	void setRatings(float ratings);
	void setAllRatings(vector<int> ratings);
	void setComments(vector<string> comments);
	void setTransactions(vector<Transaction*> transactions);

	string translateType(int t);
	string displayInfo();
	void displayComments();
	void addTransaction(Transaction* transaction);
	bool removeTransaction(Transaction* transaction);
	void addComment(string comment);
	void addRating(int rating);
	void updateRatings();
	bool operator==(const App &app) const;
	//bool operator<(const App &app) const;
	friend bool operator<(App &app1,App &app2);
	std::ostream & operator<<(std::ostream &out);

	std::ostream & writeToFile(std::ostream &out);



};

#endif /* APP_H_ */
