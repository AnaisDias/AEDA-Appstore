#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include "AppStore.h"
#include "App.h"
#include "Client.h"
#include "Transaction.h"
#include "Developer.h"

#include <iomanip>
#include <sstream>
#include <iostream>
#include "stdlib.h"

using namespace std;
class AppStore;

void Menu(AppStore appstore);
void AppsMenu(AppStore appstore);
void ClientMenu();
void DeveloperMenu(AppStore as);
void TransactionMenu(AppStore as);
void ExitMenu(AppStore as);



#endif /* SRC_MENU_H_ */
