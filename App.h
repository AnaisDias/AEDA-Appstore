
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
	string type;
	string description;
	Developer* developer;
	// acrescentar mais membros
	float ratings; //1 NAO GOSTO - 5 ESPETACULAR float porque vai ser a media das classifica�oes atribuidas
	vector<int> allRatings;
	vector<string> comments;
	vector<Transaction*> transactions;

public:
	App();
	App(string name, int price, string type, string description);
	~App();
	static void resetIDs();


	/////////////////////
	int getID() const;
	string getName() const;
	float getPrice() const;
	string getType() const;
	string getDescription() const;
	float getRatings() const;
	vector<int> getAllRatings() const;
	Developer* getDeveloper() const;
	vector<string> getComments() const;
	vector<Transaction*> getTransactions() const;

	void setID(int id);
	void setName(string name);
	void setPrice(int price);
	void setType(string type);
	void setDescription(string description);
	void setDeveloper(Developer* developer);
	void setRatings(float ratings);
	void setAllRatings(vector<int> ratings);
	void setComments(vector<string> comments);
	void setTransactions(vector<Transaction*> transactions);
	/////////////////////

	void displayInfo();
	void displayComments();
	void addTransaction(Transaction* transaction);
	bool removeTransaction(Transaction* transaction);
	void addComment(string comment);
	void addRating(int rating);
	void updateRatings();
	bool operator==(const App &app) const;
	std::ostream & operator<<(std::ostream &out);

	std::ostream & writeToFile(std::ostream &out);



};

#endif /* APP_H_ */
