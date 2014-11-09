#include "Menu.h"


using namespace std;


int main(){
	//loads
	//chamar load developers
	//chamar load apps
	//chamar assignappstodevs
	//chamar load trans
	//chamar load transactions
	//chamar assigntransactionstoapps

	AppStore AppStr = AppStore();
	App *app1, *app2;
	app1 = new App("appawesome",0.99,1,"great app");
	app2 = new App();
	Developer *dev1, *dev2;
	dev1 = new Developer("James", "dev street", 5247);
	dev2 = new Developer();
	app1->setDeveloper(dev1);
	app2->setDeveloper(dev2);
	AppStr.addApp(app1);
	AppStr.addApp(app2);
	AppStr.addDeveloper(dev1);
	AppStr.addDeveloper(dev2);

	Menu(AppStr);
	AppStr.saveApps();
	AppStr.saveDevelopers();


	return 0;
}

