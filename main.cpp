#include "Menu.h"


using namespace std;


int main(){

	AppStore AppStr = AppStore();

	//AppStr.loadApps();
	//AppStr.loadTransactions();
	//AppStr.loadClients();
	//AppStr.loadDevelopers();

	//Transaction *trans;
	//trans = new Transaction();
	Client *cli;
	cli = new Client("casq", 19);
	//cli->addTransaction(trans);
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
	AppStr.addClient(cli);

	Menu(AppStr);
	AppStr.saveApps();
	AppStr.saveDevelopers();
	AppStr.saveClients();
	AppStr.saveTransactions();


	return 0;
}

