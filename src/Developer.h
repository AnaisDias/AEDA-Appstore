#ifndef DEVELOPER_H_
#define DEVELOPER_H_

#include <string>
#include "App.h"

using namespace std;

class App;
class AppStore;

class Developer {
	static int allIDs;
	int id;
	string name;
	string address;
	int nif;
	float earnings;
	vector<App*> appsPublished;

public:
	/*
	 * Constructs and initializes a Developer by default.
	 */
	Developer();
	/*
	 * Constructs and initializes an Developer with a specific name,
	 * address and nif.
	 *
	 * @param name
	 * 				name of the Developer
	 * @param address
	 * 				address of the Developer
	 * @param nif
	 * 				nif of the Developer
	 */
	Developer(string name, string address, int nif);
	/*
	 * Destructs and erases the members of the Developer.
	 */
	~Developer();
	/*
	 * Developer's type
	 */
	virtual int devtype() {
	}
	/*
	 * Writes to .txt file
	 * @param out
	 * 			output
	 */
	virtual std::ostream & writeToFile(std::ostream &out);
	/*
	 * Developer's management menu
	 * @param as
	 * 			AppStore's pointer
	 */
	virtual void DevManagementMenu(AppStore* as) {
	}

	/*
	 * Gets the Developer's ID.
	 *
	 * @return the Developer's ID
	 */
	int getID() const;
	/*
	 * Gets the Developer's name.
	 *
	 * @return the Developer's name
	 */
	string getName() const;
	/*
	 * Gets the Developer's address.
	 *
	 * @return the Developer's address
	 */
	string getAddress() const;
	/*
	 * Gets the Developer's NIF.
	 *
	 * @return the Developer's NIF
	 */
	int getNif() const;
	/*
	 * Gets the Developer's Apps.
	 *
	 * @return the Developer's Apps
	 */
	vector<App*> getApps() const;

	/*
	 * Sets the Dev's ID.
	 *
	 * @param id
	 * 				the Dev's ID.
	 */
	void setID(int id);
	/*
	 * Sets the Dev's name.
	 *
	 * @param name
	 * 				the Dev's name.
	 */
	void setName(string name);
	/*
	 * Sets the Dev's address.
	 *
	 * @param address
	 * 				the Dev's address.
	 */
	void setAddress(string address);
	/*
	 * Sets the Dev's nif.
	 *
	 * @param nif
	 * 				the Dev's nif.
	 */
	void setNif(int nif);
	/*
	 * Sets the Dev's apps.
	 *
	 * @param apps
	 * 				the Dev's apps.
	 */
	void setApps(vector<App*> apps);
	/*
	 * Adds Dev's earnings
	 *
	 * @param earn
	 * 				Dev's earn
	 */
	void addEarnings(float earn) {
		earnings += earn;
	}
	;
	/*
	 * Adds app
	 *
	 * @param app
	 * 			app
	 */
	void addApp(App* app);
	/*
	 * Removes app
	 *
	 * @param app
	 * 			app
	 */
	bool removeApp(App* app);
	/*
	 * Displays Dev's Info
	 */
	virtual string displayInfo();
	/*
	 * Display all of Devs' Sales
	 */
	void displayAllSales();
	/*
	 * == operator
	 * @param dev
	 * 			Developer
	 */
	bool operator==(const Developer &dev) const;
	/*
	 * Writes to .txt file
	 * @param out
	 * 			output
	 */
	std::ostream & operator<<(std::ostream &out);
	/*
	 * Displays Dev's Name
	 */
	string displayNameDev();
};

class Individual: public Developer {
public:
	/*
	 * Constructs and initializes an Individual Developer with a specific name,
	 * address and nif
	 *
	 * @param name
	 * 				name of the Company
	 * @param address
	 * 				address of the Company
	 * @param nif
	 * 				nif of the Company
	 */
	Individual(string name, string address, int nif);
	/*
	 * Writes to .txt file
	 * @param out
	 * 			output
	 */
	std::ostream & writeToFile(std::ostream &out);
	/*
	 * Displays Individual Developer's Info
	 * @return Individual Developer's Info
	 */
	string displayInfo();
	/*
	 * Devtype
	 * @return developer's type
	 */
	int devtype() {
		return 1;
	}
	/*
	 * Developer's Management Menu
	 * @param as
	 * 			AppStore's pointer
	 */
	void DevManagementMenu(AppStore* as);
};

class Company: public Developer {
	string businessName;
	int code;

public:
	/*
	 * Constructs and initializes a Company by default.
	 */
	Company();
	/*
	 * Constructs and initializes a Company with a specific businessname,
	 * code, name, address and nif.
	 *
	 * @param businessname
	 * 				businessname of the Company
	 * @param code
	 * 				code of the Company
	 * @param name
	 * 				name of the Company
	 * @param address
	 * 				address of the Company
	 * @param nif
	 * 				nif of the Company
	 */
	Company(string businessname, int code, string name, string address,
			int nif);
	/*
	 * Writes to .txt file.
	 * @param out
	 * 			output
	 */
	std::ostream & writeToFile(std::ostream &out);
	/*
	 * Developer's type.
	 * @return dev's type
	 */
	int devtype() {
		return 2;
	}
	/*
	 * Displays Company's Info
	 * @return Company's Info
	 */
	string displayInfo();
	/*
	 * Gets Company's businessName
	 * @return Company's businessName
	 */
	string getCompanyName() {
		return businessName;
	}
	/*
	 * Gets Company's code
	 * @return Company's code
	 */
	int getCode() {
		return code;
	}
	/*
	 * Sets Company's businessName
	 */
	void setCompanyName(string businessname) {
		this->businessName = businessname;
	}
	/*
	 * Sets Company's code
	 */
	void setCode(int code) {
		this->code = code;
	}
	/*
	 * Developer's Management Menu
	 * @param as
	 * 			AppStore's pointer
	 */
	void DevManagementMenu(AppStore* as);

};

#endif /* DEVELOPER_H_ */
