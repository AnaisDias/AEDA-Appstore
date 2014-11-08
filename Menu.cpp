#include "Menu.h"

void Menu(AppStore as);

void AppsMenu(AppStore as) {

    int choice;

    cout << "Apps: " << endl;
    //add options for:
    //add apps
    //remove apps
    cout << "1 - Top 5 Rated Apps" << endl;
    cout << "2 - Search Apps by Name" << endl;
    cout << "3 - list by type" << endl;
    cout << "4 - rate apps" << endl;
    cout << "5 - search by id" << endl;
    cout << "6 - add app" << endl;
    cout << "7 - remove app" << endl;
    cout << "0 - Go back" << endl;

    cout << "Option: ";
    cin >> choice;

    switch(choice) {

        case 1: system("cls");
            	as.Top5Apps();
            	break;
        case 2: system("cls");
        		as.AppsListName();
            	break;
        case 3: system("cls");
            	//AppsListType();
        		break;
        case 4: system("cls");
        		//RateApps();
        		break;
        case 5: system("cls");
        		//ask for id
        		//findAppByID(id)
        		break;
        case 6: system("cls");
        		//addApplication(); uses addApp();
        		break;
        case 7: system("cls");
        		//removeApplication(); uses removeApp();
        		break;
        case 0: system("cls");
        		Menu(as);
        		break;
        default: break;

    }
}

void ClientMenu() {

    int choice;

    cout << "Client" << endl;
    //add options for client addition/removal
    cout << "1 - Clients List" << endl;
    cout << "2 - Purchased Apps (requires client ID)" << endl;
    cout << "3 - Add Client" << endl;
    cout << "4 - Remove Client" << endl;
    cout << "0 - Go back" << endl;
    cout << "Option: ";
    cin >> choice;

    switch(choice) {

        case 1: system("cls");
            	//ClientsList();
            	break;
        case 2: system("cls");
            	//PurchasedApps();
            	break;
        case 3: system("cls");
        		//AddClients();
        		break;
        case 4: system("cls");
        		//RemoveClients();
        		break;
        case 0: system("cls");
            	//Menu(as);
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

void ExitMenu() {
    cout << "Before you exit... Do you want to save?" << endl;
    cout << "1 - Yes" << endl;
    cout << "2 - No" << endl;
    cout << "3 - Cancel" << endl;

    char input;
    cout << "Option: ";
    cin >> input;

    switch (input) {
        case '1':
            system("cls");
            //SaveMenu();
            break;
        case '2':
            system("cls");
            cout << "bye";
            exit(0);
            break;
        case '3':
            system("cls");
            break;
        default:
            system("cls");
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
            ClientMenu();
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
            ExitMenu();
            break;

        default:
            system("cls");
            break;
    }
}

/////////////////////////
//////SUB MENUS /////////
/////////////////////////



