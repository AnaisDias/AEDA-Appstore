#include "Menu.h"

void Menu(AppStore as);

void AppsMenu(AppStore as) {

	char choice;

	cout << "\n APPS " << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	cout << "   1 - Top 10 Rated Apps" << endl;
	cout << "   2 - Search Apps by Name" << endl;
	cout << "   3 - List Apps by Type" << endl;
	cout << "   4 - Show all apps" << endl;
	cout << "   5 - Rate apps" << endl;
	cout << "   6 - Add app" << endl;
	cout << "   7 - Remove app" << endl;
	cout << endl;
	cout << "   0 - Go back" << endl;
	cout << endl;
	cout << " Option: ";
	cin >> choice;

	switch(choice) {

	case '1':
		system("cls");
		as.top10Apps();
		system("cls");
		AppsMenu(as);
		break;
	case '2':
		system("cls");
		as.AppsListName();
		system("cls");
				AppsMenu(as);
		break;
	case '3':
		system("cls");
		as.AppsListType();
		system("cls");
				AppsMenu(as);
		break;
	case '4':
		system("cls");
		as.AllAppsList();system("cls");
		AppsMenu(as);
		break;
	case '5':
		system("cls");
		as.RateApps();system("cls");
		AppsMenu(as);
		break;
	case '6':
		system("cls");
		as.AddApplicationMenu();system("cls");
		AppsMenu(as);
		break;
	case '7':
		system("cls");
		as.RemoveApplicationMenu();
		system("cls");
		AppsMenu(as);
		break;
	case '0':
		system("cls");
		Menu(as);
		break;
	default:
		system("cls");
		AppsMenu(as);
		break;

	}
}

void ClientMenu(AppStore as) {

	char choice;

		cout << "\n CLIENTS" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << endl;
		cout << "   1 - Show All Clients" << endl;
		cout << "   2 - Purchased Apps (requires client ID)" << endl;
		cout << "   3 - Add Client" << endl;
		cout << "   4 - Remove Client" << endl;
		cout << endl;
		cout << "   0 - Go back" << endl;
		cout << endl;
		cout << " Option: ";
		cin >> choice;

    switch(choice) {

        case '1':
        	system("cls");
        	as.ClientsList();
        	system("cls");
        	ClientMenu(as);
        	break;
        case '2':
        	system("cls");
        	as.PurchasedApps();
        	system("cls");
        	ClientMenu(as);
        	break;
        case '3':
        	system("cls");
        	as.AddClients();
        	system("cls");
        	ClientMenu(as);
        	break;
        case '4':
        	system("cls");
        	as.RemoveClients();
        	system("cls");
        	ClientMenu(as);
        	break;
        case '0':
        	system("cls");
        	Menu(as);
        	break;
        default:
        	system("cls");
        	ClientMenu(as);
        	break;
    }
}

void DeveloperMenu(AppStore as) {

	char choice;

	cout << "\n DEVELOPERS " << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	cout << "   1 - Show all Developers" << endl;
	cout << "   2 - Individual Developers" << endl;
	cout << "   3 - Enterprises Developers" << endl;
	cout << "   4 - Apps Created (requires developer's ID)" << endl;
	cout << "   5 - Show all sales (requires developer's ID)" << endl;
	cout << "   6 - Add Developer" << endl;
	cout << "   7 - Remove Developer" << endl;
	cout << endl;
	cout << "   0 - Go back" << endl;
	cout << endl;
	cout << " Option: ";
	cin >> choice;

	switch(choice) {

	case '1':
		system("cls");
		as.ShowAllDev();
		system("cls");
		DeveloperMenu(as);
		break;
	case '2': system("cls");
	as.IndividualDevList();
	system("cls");
	DeveloperMenu(as);
	break;
	case '3': system("cls");
	as.EnterpriseList();
	system("cls");
	DeveloperMenu(as);
	break;
	case '4': system("cls");
	as.AppsCreated();
	system("cls");
	DeveloperMenu(as);
	break;
	case '5':
		system("cls");
		as.SalesData();
		system("cls");
		DeveloperMenu(as);
		break;
	case '6':
		system("cls");
		as.AddDev();
		system("cls");
		DeveloperMenu(as);//uses addDeveloper;
		break;
	case '7':
		system("cls");
		as.RemoveDev();
		system("cls");
		DeveloperMenu(as);//uses removeDeveloper;
		break;
	case '0':
		system("cls");
		Menu(as);
		break;
	default:
		system("cls");
		DeveloperMenu(as);
		break;

	}

}

void TransactionMenu(AppStore as) {
	cout << "\n TRANSACTIONS" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	cout << "   1 - List by Apps" << endl;
	cout << "   2 - List by CLients" << endl;
	cout << "   3 - List by Developers" << endl;
	cout << "   4 - Show All Transactions" << endl;
	//cout << "   5 - Add Transactions" << endl;
	//cout << "   6 - Remove Transaction" << endl;
	cout << endl;
	cout << "   0 - Go back";
	cout << endl;
	cout << endl;
	cout << " Option: ";
	char choice;
	cin >> choice;

    switch(choice) {

    case '1':
    	system("cls");
    	as.TransApps();
    	system("cls");
    	TransactionMenu(as);
    	break;
    case '2':
    	system("cls");
    	as.TransClients();
    	system("cls");
    	TransactionMenu(as);
    	break;
    case '3':
    	system("cls");
    	as.TransDev();
    	system("cls");
    	TransactionMenu(as);
    	break;
    case'4':
    	system("cls");
    	as.ShowAllTransactions();
    	system("cls");
    	 TransactionMenu(as);
    	break;
    case '0':
    	system("cls");
    	Menu(as);
    	break;
    default:
    	system("cls");
    	TransactionMenu(as);
    	break;

    }
}

void SaveMenu(AppStore as);

void ExitMenu(AppStore as) {
	cout << "\n Before you exit... Do you want to save?" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	cout << "   1 - Yes" << endl;
	cout << "   2 - No" << endl;
	cout << "   3 - Cancel" << endl;

	char input;
	cout << "\n Option: ";
	cin >> input;

	switch (input) {
	case '1':
		system("cls");
		SaveMenu(as);
		break;
	case '2':
		exit(0);
		break;
	case '3':
		system("cls");
		Menu(as);
		break;
	default:
		system("cls");
		ExitMenu(as);
		break;
	}
}

void SaveMenu(AppStore as)
{
	cout << "\n Choose what you want to save." << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	cout << "   1. Clients" << endl;
	cout << "   2. Developers" << endl;
	cout << "   3. Apps" << endl;
	cout << "   4. Transactions" << endl;
	cout << "   5. Save Everything." << endl;
	cout << endl;
	cout << "   0. Go Back" << endl;
	cout << "   9. Exit" << endl;
	cout << endl;
	char input;
	cout << " Option: "; cin >> input;

	switch(input)
	{
	case '0':system("cls");
			ExitMenu(as);
			break;

	case '1':system("cls");
			as.saveClients();
			SaveMenu(as);
			break;

	case '2':system("cls");
			as.saveDevelopers();
			SaveMenu(as);
			break;

	case '3':system("cls");
			as.saveApps();
			SaveMenu(as);
			break;

	case '4':system("cls");
			as.saveTransactions();
			SaveMenu(as);
			break;

	case '5':system("cls");
			as.saveClients();
			as.saveDevelopers();
			as.saveApps();
			as.saveTransactions();
			system("cls");
			cout << "\n All saved.\n" << endl;
			SaveMenu(as);
			break;

	case '9':exit(0);
			break;

	default:system("cls");
			SaveMenu(as);
			break;
	}

}

void Register(AppStore as)
{
	char choice;
	string username;
	string password;

		cout << "\n Register OR 0 TO EXIT" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "\n   USERNAME:" << endl;
		cout << "   PASSWORD:" << endl;
		cout << "   0 - EXIT\n" << endl;
		cout << " Option: ";
		cin >> choice;

		switch (choice) {

		case '0':
			system("cls");
			ExitMenu(as);
			break;
		default:
			system("cls");
			Register(as);
			break;
		}
}

void LogInMenu(AppStore as)
{
	char choice;
	string username;
	string password;

		cout << "\n LOG IN OR 0 TO EXIT" << endl;
		cout << " ---------------------------------------------------------" << endl;
		cout << "\n   USERNAME:" << endl;
		cout << "   PASSWORD:" << endl;
		cout << "   0 - EXIT\n" << endl;
		cout << " Option: ";
		cin >> choice;

		switch (choice) {
		case '0':
			system("cls");
			ExitMenu(as);
			break;
		default:
			system("cls");
			LogInMenu(as);
			break;
		}
}

void InitialMenu(AppStore as)
{
	char choice;

	cout << "\n Hi, Welcome to the Appstore!" << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << "\n   1 - LOG IN" << endl;
	cout << "   2 - REGISTER" << endl;
	cout << "   0 - EXIT\n" << endl;
	cout << " Option: ";
	cin >> choice;

	switch (choice) {

	case '1':
		system("cls");
		LogInMenu(as);
		//Menu(as);
		break;

	case '2':
		system("cls");
		Register(as);
		//Menu(as);
		break;
	case '0':
		system("cls");
		ExitMenu(as);
		break;
	default:
		system("cls");
		InitialMenu(as);
		break;
	}
}

void Menu(AppStore as) {
    AppStore store = AppStore();

    char choice;

    cout << "\n APPSTORE" << endl;
    cout << " ---------------------------------------------------------" << endl;
    cout << "\n   1 - APPS" << endl;
    cout << "   2 - CLIENTS" << endl;
    cout << "   3 - DEVELOPERS" << endl;
    cout << "   4 - TRANSACTIONS\n" << endl;
    cout << "   0 - EXIT\n" << endl;
    cout << " Option: ";
    cin >> choice;

    switch (choice) {

        case '1':	system("cls");
            	AppsMenu(as);
            	Menu(as);
            	break;

        case '2':	system("cls");
        		ClientMenu(as);
        		Menu(as);
        		break;

        case '3': system("cls");
            	DeveloperMenu(as);
            	Menu(as);
            	break;

        case '4': system("cls");
        		TransactionMenu(as);
        		Menu(as);
        		break;

        case '0':	system("cls");
            	ExitMenu(as);
            	break;

        default:
        	system("cls");
        	Menu(as);
            break;
    }
}



