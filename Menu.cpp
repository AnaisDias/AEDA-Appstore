#include "Menu.h"
#include <unistd.h>

void Menu(AppStore as);
void saveMenu(AppStore as);

void AppsMenu(AppStore as) {

	char choice;

	cout << "\n APPS " << endl;
	cout << " ---------------------------------------------------------" << endl;
	cout << endl;
	cout << "   1 - Top 5 Rated Apps" << endl;
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
			as.Top5Apps();
			//AppsMenu(as);
			break;

		case '2':
			system("cls");
			as.AppsListName();
			//system("cls");
			//AppsMenu(as);
			break;

		case '3':
			system("cls");
			as.AppsListType();
			AppsMenu(as);
			break;
		case '4':
			system("cls");
			as.AllAppsList();
			system("cls");
			AppsMenu(as);
			break;
		case '5': system("cls");
				as.RateApps();
				AppsMenu(as);
				break;
		case '6': system("cls");
				as.AddApplicationMenu();
				AppsMenu(as);
				break;
		case '7': system("cls");
				as.RemoveApplicationMenu();
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
	cout << "   1 - Clients List" << endl;
	cout << "   2 - Purchased Apps (requires client ID)" << endl;
	cout << "   3 - Add Client" << endl;
	cout << "   4 - Remove Client" << endl;
	cout << endl;
	cout << "   0 - Go back" << endl;
	cout << endl;
	cout << " Option: ";
	cin >> choice;

    switch(choice) {

    char input;

        case '1':
        	system("cls");
        	as.ClientsList();

        	cout << endl;
        	cout <<"   0 - Go Back" << endl;
        	cout << endl;

        	cout << "Option: ";
        	cin >> input;

        	if(input == '0'){
        		system("cls");
        		ClientMenu(as);
        	}
        	//EXCEPTION - Invalid Input

            break;
        case '2':
        	system("cls");
            as.PurchasedApps();

            cout << endl;
            cout <<"   0 - Go Back" << endl;
            cout << endl;

            cout << "Option: ";
            cin >> input;

            if(input == '0'){
            	system("cls");
            	ClientMenu(as);
            }
            //EXCEPTION - Invalid Input
            break;
        case '3':
        	system("cls");
        	as.AddClients();
        	cout << endl;
        	cout <<"   0 - Go Back" << endl;
        	cout << endl;

        	cout << "Option: ";
        	cin >> input;

        	if(input == '0'){
        		system("cls");
        		ClientMenu(as);
        	}
        	//EXCEPTION - Invalid Input
        		break;
        case '4':
        	system("cls");
        	as.RemoveClients();
        	cout << endl;
        	cout <<"   0 - Go Back" << endl;
        	cout << endl;

        	cout << "Option: ";
        	cin >> input;

        	if(input == '0'){
        		system("cls");
        		ClientMenu(as);
        	}
        	//EXCEPTION - Invalid Input
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
    cout << "   1 - Individual Developers" << endl;
    cout << "   2 - Enterprises" << endl;
    cout << "   3 - Apps Created (requires developer's ID)" << endl;
    cout << "   4 - Show all sales (requires developer's ID)" << endl;
    cout << "   5 - Add Developer/Enterprise" << endl;
    cout << "   6 - Remove Developer/Enterprise" << endl;
    cout << endl;
    cout << "   0 - Go back" << endl;
    cout << endl;
    cout << " Option: ";
    cin >> choice;

    switch(choice) {

        case '1': system("cls");
            	//IndividualDevList()
            	break;
        case '2': system("cls");
            	//EnterpriseList()
            	break;
        case '3': system("cls");
            	//AppsCreated();
            	break;
        case '4': system("cls");
        		//SalesData();
            	break;
        case '5': system("cls");
        		//AddDev(); //uses addDeveloper;
        		break;
        case '6': system("cls");
        		//RemoveDev(); //uses removeDeveloper;

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
    cout << "   4 - List All Transactions" << endl;
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
            //TransApps();
            break;
        case '2':
        	system("cls");
            //TransClients();
            break;
        case '3':
        	system("cls");
            //TransDev();
            break;
        case '4':
        	system("cls");
        	//display all transactions
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
            saveMenu(as);
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

void saveMenu(AppStore as)
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
		saveMenu(as);
		break;
	case '2':
		system("cls");
		as.saveDevelopers();
		saveMenu(as);
			break;
	case '3':
		system("cls");
		as.saveApps();
		saveMenu(as);
			break;
	case '4':
		system("cls");
		as.saveTransactions();
		saveMenu(as);
			break;
	case '5':
		system("cls");
		as.saveClients();
		as.saveDevelopers();
		as.saveApps();
		as.saveTransactions();
		system("cls");
		cout << "\n All saved.\n" << endl;
		saveMenu(as);
		break;
	case '9':
		exit(0);
		break;
	default:
		system("cls");
		saveMenu(as);
		break;
	}

}

void Menu(AppStore as) {

    AppStore store = AppStore();

    char choice;

    cout << "\n APPSTORE" << endl;
    cout << " ---------------------------------------------------------" << endl;
    cout << endl;
    cout << "   1 - APPS" << endl;
    cout << "   2 - CLIENTS" << endl;
    cout << "   3 - DEVELOPERS" << endl;
    cout << "   4 - TRANSACTIONS" << endl;
    cout << endl;
    cout << "   0 - EXIT" << endl;
    cout << endl;
    cout << " Option: ";
    cin >> choice;

    switch (choice) {

        case '1':
            system("cls");
            AppsMenu(as);
            //Menu(as);
            break;

        case '2':
            system("cls");
            ClientMenu(as);
            Menu(as);
            break;

        case '3':
            system("cls");
            DeveloperMenu(as);
            Menu(as);
            break;

        case '4':
            system("cls");
            TransactionMenu(as);
            Menu(as);
            break;

        case '0':
            system("cls");
            ExitMenu(as);
            break;

        default:
            system("cls");
            Menu(as);
            break;
    }
}
