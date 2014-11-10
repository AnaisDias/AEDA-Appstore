#include "Menu.h"

void Menu(AppStore as);

void AppsMenu(AppStore as) {

	int choice;

	cout << "Apps: " << endl;

	cout << "1 - Top 5 Rated Apps" << endl;
	cout << "2 - Search Apps by Name" << endl;
	cout << "3 - List Apps by Type" << endl;
	cout << "4 - Show all apps" << endl;
	cout << "5 - Rate apps" << endl;
	cout << "6 - Add app" << endl;
	cout << "7 - Remove app" << endl;
	cout << "0 - Go back" << endl;

	cout << "Option: ";
	cin >> choice;

	switch(choice) {

		case 1: system("cls");
				as.Top5Apps();
				AppsMenu(as);
				break;
		case 2: system("cls");
				as.AppsListName();
				AppsMenu(as);
				break;
		case 3: system("cls");
				as.AppsListType();
				AppsMenu(as);
				break;
		case 4: system("cls");
				as.AllAppsList();
				AppsMenu(as);
				break;
		case 5: system("cls");
				as.RateApps();
				AppsMenu(as);
				break;
		case 6: system("cls");
				as.AddApplicationMenu();
				AppsMenu(as);
				break;
		case 7: system("cls");
				as.RemoveApplicationMenu();
				AppsMenu(as);
				break;
		case 0: system("cls");
				Menu(as);
				break;
		default: break;

	}
}

void ClientMenu(AppStore as) {

	int choice;

	cout << "Client" << endl;
	//add options for client addition/removal
	cout << "1 - Clients List" << endl;
	cout << "2 - Purchased Apps (requires client ID)" << endl;
	cout << "3 - Add Client" << endl;
	cout << "4 - Remove Client" << endl;
	cout << "0 - Go back" << endl;
	cout << "Option: ";
	cin.get();
	cin >> choice;

    switch(choice) {

        case 1: system("cls");
            	as.ClientsList();
            	ClientMenu(as);
            	break;
        case 2: system("cls");
            	as.PurchasedApps();
            	ClientMenu(as);
            	break;
        case 3: system("cls");
        		as.AddClients();
        		ClientMenu(as);
        		break;
        case 4: system("cls");
        		as.RemoveClients();
        		ClientMenu(as);
        		break;
        case 0: system("cls");
            	Menu(as);
            	break;
        default: break;
    }
}

void DeveloperMenu() {

    int choice;

    cout << "Developer: " << endl;
    cout << "1 - Individual Developers" << endl;
    cout << "2 - Enterprises" << endl;
    cout << "3 - Apps Created (requires developer's ID)" << endl;
    cout << "4 - Show all sales (requires developer's ID)" << endl;
    cout << "5 - Add Developer/Enterprise" << endl;
    cout << "6 - Remove Developer/Enterprise" << endl;
    cout << "0 - Go back" << endl;
    cout << "Option: ";
    cin >> choice;

    switch(choice) {

        case 1: system("cls");
            	//IndividualDevList()
            	break;
        case 2: system("cls");
            	//EnterpriseList()
            	break;
        case 3: system("cls");
            	//AppsCreated();
            	break;
        case 4: system("cls");
        		//SalesData();
            	break;
        case 5: system("cls");
        		//AddDev(); //uses addDeveloper;
        		break;
        case 6: system("cls");
        		//RemoveDev(); //uses removeDeveloper;

        case 0: system("cls");
            	//Menu(as);
            	break;
        default: break;

    }

}

void TransactionMenu() {
    cout << "Transactions" << endl;
    cout << "1 - List by Apps" << endl;
    cout << "2 - List by CLients" << endl;
    cout << "3 - List by Developers" << endl;
    cout << "0 - Go back";
    cout << "OPTION: ";
    int choice;
    cin >> choice;

    switch(choice) {

        case 1: system("cls");
            //TransApps();
            break;
        case 2: system("cls");
            //TransClients();
            break;
        case 3: system("cls");
            //TransDev();
            break;
        case 0: system("cls");
            //Menu(as);
            break;
        default: break;

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
	case '0':
		system("cls");
		ExitMenu(as);
		break;

	case '1':
		system("cls");
		as.saveClients();
		SaveMenu(as);
		break;
	case '2':
		system("cls");
		as.saveDevelopers();
		SaveMenu(as);
			break;
	case '3':
		system("cls");
		as.saveApps();
		SaveMenu(as);
			break;
	case '4':
		system("cls");
		as.saveTransactions();
		SaveMenu(as);
			break;
	case '5':
		system("cls");
		as.saveClients();
		as.saveDevelopers();
		as.saveApps();
		as.saveTransactions();
		system("cls");
		cout << "\n All saved.\n" << endl;
		SaveMenu(as);
		break;
	case '9':
		exit(0);
		break;
	default:
		system("cls");
		SaveMenu(as);
		break;
	}

}
void Menu(AppStore as) {
    // Fazer load dos ficheiros;
    AppStore store = AppStore();

    int choice;

    cout << "APPSTORE" << endl;
    cout << "1 - APPS" << endl;
    cout << "2 - USERS" << endl;
    cout << "3 - DEVELOPERS" << endl;
    cout << "4 - TRANSACTIONS" << endl;
    cout << "0 - EXIT" << endl;
    cout << "Option: ";
    cin >> choice;

    switch (choice) {

        case 1:
            system("cls");
            AppsMenu(as);
            Menu(as);
            break;

        case 2:
            system("cls");
            ClientMenu(as);
            Menu(as);
            break;

        case 3:
            system("cls");
            DeveloperMenu();
            Menu(as);
            break;

        case 4:
            system("cls");
            TransactionMenu();
            Menu(as);
            break;

        case 0:
            system("cls");
            ExitMenu(as);
            break;

        default:
            system("cls");
            break;
    }
}

/////////////////////////
//////SUB MENUS /////////
/////////////////////////



