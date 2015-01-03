#include "Menu.h"


using namespace std;


int main(){


	AppStore AppStr = AppStore();

	AppStr.loadDevelopers();
	AppStr.loadApps();
	AppStr.assignPublishedAppsToDevs();
	AppStr.loadClients();
	AppStr.loadTransactions();
	AppStr.loadUsers();
	AppStr.assignTransactionsToApps();
	system("cls");
	InitialMenu(AppStr);

	return 0;
}

