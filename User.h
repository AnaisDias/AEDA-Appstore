/*
 * User.h
 *
 *  Created on: 30/12/2014
 *      Author: Sofia Reis
 */

#ifndef USER_H_
#define USER_H_

#include<string>

using namespace std;

class User {
	int type;
	string password;
	string username;
	int id;
	static int allIDs;
public:
	User(int type, string password, string username);
	~User();
	int getType();
	void setType(int type);
	string getUsername();
	void setUsername(string username);
	string getPassword();
	void setPassword(string password);
	int getId();
	void setId(int id);

	std::ostream & operator<<(std::ostream &out);
	std::ostream & writeToFile(std::ostream &out);

	string displayInfo();
};

#endif /* USER_H_ */
