
#include "App.h"

App::App() {
	// TODO Auto-generated constructor stub

}

App::~App() {
	// TODO Auto-generated destructor stub
}

App::App(string name, int price, string type, string description) {
	this->name = name;
	this->price = price;
	this->type = type;
	this->description = description;
}


//////////////////////////////////////
//          GETS & SETS             //
//////////////////////////////////////


string App::getName() const {
	return name;
}

float App::getPrice() const {
	return price;
}

string App::getType() const {
	return type;
}

string App::getDescription() const {
	return description;
}

float App::getRatings() const {
	return ratings;
}

vector<int> App::getAllRatings() const{
	return allRatings;
}


Developer* App::getDeveloper() const{
	return developer;
}

vector<string> App::getComments() const{
	return comments;
}

vector<Transaction*> App::getTransactions() const{
	return transactions;
}

void App::setName(string name){
	this->name=name;
}

void App::setPrice(int price){
	this->price=price;
}

void App::setType(string type){
	this->type=type;
}

void App::setDescription(string description){
	this->description=description;
}

void App::setDeveloper(Developer* developer){
	this->developer=developer;
}

void App::setRatings(float ratings){
	this->ratings=ratings;
}

void App::setAllRatings(vector<int> ratings){
	this->allRatings=ratings;
}

void App::setComments(vector<string> comments){
	this->comments=comments;
}

void App::setTransactions(vector<Transaction*> transactions){
	this->transactions=transactions;
}

//OTHER FUNCTIONS

void App::displayInfo(){

}

void App::displayComments(){

}

void App::addTransaction(Transaction* transaction){
	transactions.push_back(transaction);
}

bool App::removeTransaction(Transaction* transaction){
	for(int i=0; i<transactions.size(); i++){
		if(transaction==transactions[i]){
			transactions.erase(transactions.begin() + i);
			return true;
		}
	}
	return false;
}

void App::addComment(string comment){
	comments.push_back(comment);
}

void App::addRating(int rating){
	allRatings.push_back(rating);
	updateRatings();
}

void App::updateRatings(){
	float updatedR=0;
	for(int i=0; i<allRatings.size(); i++){
		updatedR+=allRatings[i];
	}

	if(allRatings.size()!=0){
		updatedR= updatedR/ allRatings.size();
	}
	else updatedR=0;

	this->ratings=updatedR;
}

bool App::operator==(const App &app) const{
	if(this->name==app.name && this->developer==app.developer) return true;
	else return false;
}
