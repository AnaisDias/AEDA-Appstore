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
void DeveloperMenu();
void TransactionMenu();
void ExitMenu();



#endif /* SRC_MENU_H_ */
