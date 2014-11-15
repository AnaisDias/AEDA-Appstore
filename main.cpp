#include "Menu.h"


using namespace std;


int main(){

	AppStore AppStr = AppStore();

	AppStr.loadDevelopers();
	AppStr.loadApps();
	AppStr.assignPublishedAppsToDevs();
	AppStr.loadClients();
	AppStr.loadTransactions();
	AppStr.assignTransactionsToApps();
	system("cls");

	Menu(AppStr);

	return 0;
}

