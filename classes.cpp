//Header Files
#include <iostream> //To use cout and cin
#include <string> //To use string
#include <fstream> //To read from file
#include <sstream> //To use stringstream
#include <iomanip> //To use setprecision
#include <limits> //To use numeric_limits
#include <cctype> //To use isdigit()
#include <windows.h> //To use Sleep() in windows 


using namespace std;

#include "classes.h"
#include "functions.h"

/*Definition of Class Functions*/

void Demo::demo(){
    cout << "This is a demo function" << endl;
}

/*Definition of Spectrum_Range Class Functions*/

Spectrum_Range::Spectrum_Range(){
    // Default Constructor
}

Spectrum_Range::Spectrum_Range(string date, string company, string spectrum_range, string circle, string revenue, string spectrum_size){
    this->date = date;
    this->company = company;
    this->spectrum_range = spectrum_range;
    this->circle = circle;
    this->revenue = revenue;
    this->spectrum_size = spectrum_size;
}

Spectrum_Range::~Spectrum_Range(){
    // Destructor
}

void Spectrum_Range::setDate(string date){
    this->date = date;
}

void Spectrum_Range::setCompany(string company){
    this->company = company;
}

void Spectrum_Range::setSpectrumRange(string spectrum_range){
    this->spectrum_range = spectrum_range;
}

void Spectrum_Range::setCircle(string circle){
    this->circle = circle;
}

void Spectrum_Range::setRevenue(string revenue){
    this->revenue = revenue;
}

void Spectrum_Range::setSpectrumSize(string spectrum_size){
    this->spectrum_size = spectrum_size;
}


string Spectrum_Range::getDate(){
    return date;
}

string Spectrum_Range::getCompany(){
    return company;
}

string Spectrum_Range::getSpectrumRange(){
    return spectrum_range;
}

string Spectrum_Range::getCircle(){
    return circle;
}

string Spectrum_Range::getRevenue(){
    return revenue;
}

string Spectrum_Range::getSpectrumSize(){
    return spectrum_size;
}


/*Definition of Subscriber Class Functions*/

Subscriber::Subscriber(){
    // Default Constructor
}

Subscriber::Subscriber(string date, string company, string location, string subscribers){
    this->date = date;
    this->company = company;
    this->location = location;
    this->subscribers = subscribers;
}

Subscriber::~Subscriber(){
    // Destructor
}

void Subscriber::setDate(string date){
    this->date = date;
}

void Subscriber::setCompany(string company){
    this->company = company;
}

void Subscriber::setLocation(string location){
    this->location = location;
}

void Subscriber::setSubscribers(string subscribers){
    this->subscribers = subscribers;
}

string Subscriber::getDate(){
    return date;
}

string Subscriber::getCompany(){
    return company;
}

string Subscriber::getLocation(){
    return location;
}

string Subscriber::getSubscribers(){
    return subscribers;
}


/*Definition of Spectrum_Request Class Functions*/

Spectrum_Request::Spectrum_Request(){
    // Default Constructor
}

Spectrum_Request::Spectrum_Request(string date, string company, string location, string request){
    this->date = date;
    this->company = company;
    this->location = location;
    this->request = request;
}

Spectrum_Request::~Spectrum_Request(){
    // Destructor
}

void Spectrum_Request::setDate(string date){
    this->date = date;
}

void Spectrum_Request::setCompany(string company){
    this->company = company;
}

void Spectrum_Request::setLocation(string location){
    this->location = location;
}

void Spectrum_Request::setRequest(string request){
    this->request = request;
}

string Spectrum_Request::getDate(){
    return date;
}

string Spectrum_Request::getCompany(){
    return company;
}

string Spectrum_Request::getLocation(){
    return location;
}

string Spectrum_Request::getRequest(){
    return request;
}

/*Definition of MVNO_Spectrum Class Functions*/

MVNO_Spectrum::MVNO_Spectrum(){
    // Default Constructor
}

MVNO_Spectrum::MVNO_Spectrum(string date, string MVNOcompany, string location, string request){
    this->date = date;
    this->MVNOcompany = MVNOcompany;
    this->location = location;
    this->request = request;
}

MVNO_Spectrum::~MVNO_Spectrum(){
    // Destructor
}

void MVNO_Spectrum::setDate(string date){
    this->date = date;
}

void MVNO_Spectrum::setMVNOCompany(string MVNOcompany){
    this->MVNOcompany = MVNOcompany;
}

void MVNO_Spectrum::setLocation(string location){
    this->location = location;
}

void MVNO_Spectrum::setRequest(string request){
    this->request = request;
}

string MVNO_Spectrum::getDate(){
    return date;
}

string MVNO_Spectrum::getMVNOCompany(){
    return MVNOcompany;
}

string MVNO_Spectrum::getLocation(){
    return location;
}

string MVNO_Spectrum::getRequest(){
    return request;
}





