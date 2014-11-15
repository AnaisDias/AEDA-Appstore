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
void ClientMenu(AppStore appstore);
void DeveloperMenu(AppStore appstore);
void TransactionMenu(AppStore appstore);
void ExitMenu(AppStore appstore);
void SaveMenu(AppStore appstore);



#endif /* SRC_MENU_H_ */
