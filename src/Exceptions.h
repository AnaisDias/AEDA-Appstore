/*!
 * \file Exceptions.h
 *
 * \author FEUP AEDA1415
 * \author Sofia Reis
 * \author Anais Dias
 * \author Joao Viana
 *
 * \date Janeiro 2015
 *
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <string>

using namespace std;

class RepeatedAppName {
public:
	/*!
	 * App's Name
	 */
	string name;
	/*!
	 * Constructs and initializes an exception to an App with a repeated name
	 * @param n
	 * 				name of the App
	 */
	RepeatedAppName(string n) {
		name = n;
	}
	/*!
	 * Gets Name
	 * @return name
	 */
	string getName() {
		return name;
	}

};

class RatingOutOfRange {
public:
	/*!
	 * Rating
	 */
	int rat;
	/*!
	 * Constructs and initializes an exception to a rating out of range
	 * @param r
	 * 			App's rating
	 */
	RatingOutOfRange(int r) {
		rat = r;
	}
	/*!
	 * Gets rating
	 * @return rat
	 */
	int getRating() {
		return rat;
	}
};

class ClientDoesNotExist {
public:
	/*!
	 * Client's ID
	 */
	int id;
	/*!
	 * Constructs and initializes an exception to a Client that does not exist
	 * @param i
	 * 			Client's ID
	 */
	ClientDoesNotExist(int i) {
		id = i;
	}
	/*!
	 * Gets Client's ID
	 * @return id
	 */
	int getID() {
		return id;
	}
};

class AppDoesNotExist {
public:
	/*!
	 * App's ID
	 */
	int id;
	/*!
	 * Constructs and initializes an exception to an App that does not exist
	 * @param i
	 * 			App's ID
	 */
	AppDoesNotExist(int i) {
		id = i;
	}
	/*!
	 * Gets App's ID
	 * @return id
	 */
	int getID() {
		return id;
	}
};

class DeveloperDoesNotExist {
public:
	/*!
	 * Dev's ID
	 */
	int id;
	/*!
	 * Constructs and initializes an exception to a Developer that does not exist
	 * @param i
	 * 			Developer's ID
	 */
	DeveloperDoesNotExist(int i) {
		id = i;
	}
	/*!
	 * Gets Developer's ID
	 * @return id
	 */
	int getID() {
		return id;
	}
};

class TransactionDoesNotExist {
public:
	/*!
	 * Transaction's ID
	 */
	int id;
	/*!
	 *  Constructs and initializes an exception to a Transaction that does not exist
	 * @param i
	 * 			Transaction's ID
	 */
	TransactionDoesNotExist(int i) {
		id = i;
	}
	/*!
	 * Gets Transaction's ID
	 * @return id
	 */
	int getID() {
		return id;
	}
};

class FileDoesNotExist {
public:
	/*!
	 * File's name
	 */
	string name;
	/*!
	 * Constructs and initializes an exception to a file that does not exist
	 * @param i
	 * 			File's name
	 */
	FileDoesNotExist(string n) {
		name = n;
	}
	/*!
	 * Gets File name
	 * @return name
	 */
	string getFilename() {
		return name;
	}
};

#endif
