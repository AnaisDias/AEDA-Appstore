/*!
 * \file User.h
 *
 * \author FEUP AEDA1415
 * \author Sofia Reis
 * \author Anais Dias
 * \author Joao Viana
 *
 * \date Janeiro 2015
 *
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

	 /*!
	 * Constructs and initializes an User with a specific type,
	 * password, username and id.
	 *
	 * @param type
	 * 				User's type
	 * @param password
	 * 				User's password
	 * @param username
	 * 				User's username
	 * @param id
	 * 				User's id
	 */
	User(int type, string password, string username, int id);
	/*!
	 * Destructs and erases the members of the User.
	 */
	~User();
	/*!
	 * Gets User's type
	 * @return type
	 */
	int getType();
	/*!
	 * Sets User's type
	 * @param type
	 * 			User's type
	 */
	void setType(int type);
	/*!
	 * Gets User's Username
	 * @return username
	 */
	string getUsername();
	/*!
	 * Sets User's username
	 * @param username
	 * 			User's username
	 */
	void setUsername(string username);
	/*!
	 * Gets User's Password
	 * @return password
	 */
	string getPassword();
	/*!
	 * Sets User's password
	 * @param password
	 * 			User's password
	 */
	void setPassword(string password);
	/*!
	 * Gets User's id
	 * @return id
	 */
	int getID();
	/*!
	 * Sets User's id
	 * @param id
	 * 			User's id
	 */
	void setID(int id);
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

	/*!
	 * Displays Information about the user.
	 */
	string displayInfo();
};

#endif /* USER_H_ */
