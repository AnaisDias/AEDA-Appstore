#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <string>

using namespace std;

class RepeatedAppName{
public:
	string name;
	RepeatedAppName(string n){name=n;}
	string getName(){return name;}

};

class RatingOutOfRange{
public:
	int rat;
	RatingOutOfRange(int r){rat=r;}
	int getRating(){return rat;}
};

class ClientDoesNotExist{
public:
	int id;
	ClientDoesNotExist(int i){id=i;}
	int getID(){return id;}
};


class AppDoesNotExist{
public:
	int id;
	AppDoesNotExist(int i){id=i;}
	int getID(){return id;}
};

class DeveloperDoesNotExist{
public:
	int id;
	DeveloperDoesNotExist(int i){id=i;}
	int getID(){return id;}
};

class TransactionDoesNotExist{
public:
	int id;
	TransactionDoesNotExist(int i){id=i;}
	int getID(){return id;}
};

class FileDoesNotExist{
public:
	string name;
	FileDoesNotExist(string n){name=n;}
	string getFilename(){return name;}
};

#endif
