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
<<<<<<< HEAD
void ClientMenu();
void DeveloperMenu(AppStore as);
void TransactionMenu(AppStore as);
void ExitMenu(AppStore as);
=======
void ClientMenu(AppStore appstore);
void DeveloperMenu();
void TransactionMenu();
void ExitMenu(AppStore appstore);
void SaveMenu(AppStore appstore);
>>>>>>> b736a6f055f7c0da8e3ddbb6938dc41e87839f03



#endif /* SRC_MENU_H_ */
