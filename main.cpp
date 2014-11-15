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
<<<<<<< HEAD

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
=======
	AppStr.loadDevelopers();
	AppStr.loadApps2();
	AppStr.assignPublishedAppsToDevs();
	AppStr.loadClients();
	AppStr.loadTransactions();
	AppStr.assignTransactionsToApps();
	/*App *app1, *app2;
>>>>>>> b736a6f055f7c0da8e3ddbb6938dc41e87839f03
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
<<<<<<< HEAD
	AppStr.addDeveloper(dev2);
	AppStr.addClient(cli);
=======
	AppStr.addDeveloper(dev2);*/
>>>>>>> b736a6f055f7c0da8e3ddbb6938dc41e87839f03

	Menu(AppStr);
	AppStr.saveApps();
	AppStr.saveDevelopers();
	AppStr.saveClients();
	AppStr.saveTransactions();
<<<<<<< HEAD

=======
>>>>>>> b736a6f055f7c0da8e3ddbb6938dc41e87839f03

	return 0;
}

