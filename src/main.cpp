#include "Menu.h"


using namespace std;

/**
\mainpage AppStore

Appstore it's an aplication where you can publish your apps and buy apps from another developers. This aplication was made for AEDA - Algoritmos e Estruturas de Dados.
* @author Sofia Reis, Anais Dias e Joao Viana
*/

int main(){


	AppStore AppStr = AppStore();

	AppStr.loadDevelopers();
	AppStr.loadApps();
	AppStr.assignPublishedAppsToDevs();
	AppStr.loadClients();
	AppStr.loadTransactions();
	AppStr.loadUsers();
	AppStr.assignTransactionsToApps();
	AppStr.assignTransactionsToClients();
	system("cls");
	InitialMenu(AppStr);

	return 0;
}

