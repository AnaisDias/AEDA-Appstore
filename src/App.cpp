#include <iostream>
#include "App.h"
#include "Exceptions.h"
#include <sstream>

int App::allIDs=0;

App::App() {
	id=allIDs;
	allIDs++;
	price=0;
	type=0;
	developer=NULL;
	description="";
	name="";
	ratings = 0;
	validated=false;
	forSale=true;
}

App::~App() {}

App::App(string name, float price, int type, string description) {
	this->name = name;
	this->price = price;
	this->type = type;
	this->description = description;
	this->id=allIDs;
	allIDs++;
	this->ratings = 0;
	this->validated=false;
	this->forSale=true;
}

void App::resetIDs(){
	allIDs=0;
}


//////////////////////////////////////
//          GETS & SETS             //
//////////////////////////////////////

int App::getID() const{
	return id;
}

string App::getName() const {
	return name;
}

float App::getPrice() const {
	return price;
}

int App::getType() const {
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

void App::setID(int id){
	this->id=id;
}
void App::setName(string name){
	this->name=name;
}

void App::setPrice(int price){
	this->price=price;
}

void App::setType(int type){
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

string App::displayInfo(){

	struct tm * timeinfo;
	timeinfo = localtime(&submission_time);

	stringstream out;
	out << " App ID: " << id << endl;
		out << " Name: " << name << endl;
		out << " Price: " << price << endl;
		out << " Type: " << type << ". " << translateType(type) << endl;
		out << " Rating: " << ratings << endl;
		out << " Submission: " << asctime(timeinfo) << endl;
		out << " Sale status: "; if(forSale){ out <<  "For sale" << endl;}
		else if(!forSale){ out << "Not for sale" << endl;}
		out << " Description: " << description << endl;
		if(developer!=NULL){
		out << " Developer: " << developer->getName() << endl << endl;
		}
	return out.str();
}

void App::displayComments(){
	for(unsigned int i=0; i<comments.size(); i++){
		cout << comments[i] << endl;
	}
	cout << endl;
}

void App::addTransaction(Transaction* transaction){
	transactions.push_back(transaction);
}

bool App::removeTransaction(Transaction* transaction){
	for(unsigned int i=0; i<transactions.size(); i++){
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
	if(rating<0 && rating>5) throw RatingOutOfRange(rating);
	allRatings.push_back(rating);
	updateRatings();
}

void App::updateRatings(){
	float updatedR=0;
	for(unsigned int i=0; i<allRatings.size(); i++){
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

bool App::operator<(const App &app) const{
	if(this->getRatings()>app.getRatings()) return true;
	else if(this->getRatings()==app.getRatings()){
		if(this->getPrice()>app.getPrice()) return true;
		else if(this->getPrice()==app.getPrice()){
			return this->getType()>app.getType();
		}
	}
	return false;
}

string App::translateType(int t){
	switch(t){
	case 1:
		return "Entertainment";
		break;
	case 2:
		return "Finances";
		break;
	case 3:
		return "Games";
		break;
	case 4:
		return "Fitness";
		break;
	case 5:
		return "Lifestyle";
		break;
	case 6:
		return "Music";
		break;
	case 7:
		return "Photography";
		break;
	case 8:
		return "Productivity";
		break;
	case 9:
		return "Social Networks";
		break;
	case 10:
		return "Sports";
		break;
	case 11:
		return "Traveling";
		break;
	case 12:
		return "Utilities";
		break;
	default:
		return "No type";
		break;

	}
}

std::ostream & App::operator<<(std::ostream &out){
	struct tm * timeinfo;
	timeinfo = localtime(&submission_time);
	out << "App ID: " << id << endl;
	out << "Name: " << name << endl;
	out << "Price: " << price << endl;
	out << "Type: " << type << ". " << translateType(type) << endl;
	out << "Rating: " << ratings << endl;
	out << "Description: " << description << endl;
	out << "Submission: " << asctime(timeinfo) << endl;
	out << "Developer: " << developer->getName() << endl << endl;
	return out;
}

std::ostream & App::writeToFile(std::ostream &out){
	out << id << "," << name << "," << price << "," ;
	out << type <<"," << description << "," << developer->getID() << ",";
	out << forSale << ",";
	out << validated << ",";
	out << submission_time << ",";
	out << allRatings.size() << ",";
	for(unsigned int i=0; i<allRatings.size();i++){
		out << allRatings[i] << ",";
	}
	out << "/endRatings," << comments.size() << ",";
	for(unsigned int i=0; i<comments.size();i++){
		out << comments[i] << ",";
	}
	out << "/endComments," << transactions.size() << ",";

	for(unsigned int i=0; i<transactions.size(); i++){
		out << transactions[i]->getID();
		if(i!=transactions.size()) out << ",";
	}
	out << "/endTransactions";
	return out;
}

void App::setTime(time_t time){
	this->submission_time = time;
}

time_t App::getTime() const{
	return submission_time;
}

bool App::getValidation() const{
	return validated;
}

void App::setValidation(bool validation){
	this->validated=validation;
}

bool App::getSaleStatus() const{
	return forSale;
}

void App::setSaleStatus(bool forsale){
	this->forSale=forsale;
}





