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

/*
 * AppStore's Menu
 * @param appstore
 * 			AppStore
 */
void Menu(AppStore appstore);
/*
 * Apps Menu
 * @param appstore
 * 			AppStore
 */
void AppsMenu(AppStore appstore);
/*
 * Clients Menu
 * @param appstore
 * 			AppStore
 */
void ClientMenu(AppStore appstore);
/*
 * Developers Menu
 * @param appstore
 * 			AppStore
 */
void DeveloperMenu(AppStore appstore);
/*
 * Transactions Menu
 * @param appstore
 * 			AppStore
 */
void TransactionMenu(AppStore appstore);
/*
 * Exit Menu
 * @param appstore
 * 			AppStore
 */
void ExitMenu(AppStore appstore);
/*
 * Save Menu
 * @param appstore
 * 			AppStore
 */
void SaveMenu(AppStore appstore);
/*
 * Log in Menu
 * @param appstore
 * 			AppStore
 */
void LogInMenu(AppStore as);
/*
 * Register Menu
 * @param appstore
 * 			AppStore
 */
void Register(AppStore as);
/*
 * Initial Menu
 * @param appstore
 * 			AppStore
 */
void InitialMenu(AppStore as);


#endif /* SRC_MENU_H_ */
