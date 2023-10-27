#ifndef CLASSES_H
#define CLASSES_H

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

class Demo{
    public:
        void demo();
};

class Spectrum_Range{
    private:
        string date;
        string company;
        string spectrum_range;
        string circle;
        string revenue;
        string spectrum_size;
    public:
        Spectrum_Range();
        Spectrum_Range(string, string, string, string, string, string);
        ~Spectrum_Range();
        void setDate(string);
        void setCompany(string);
        void setSpectrumRange(string);
        void setCircle(string);
        void setRevenue(string);
        void setSpectrumSize(string);
        string getDate();
        string getCompany();
        string getSpectrumRange();
        string getCircle();
        string getRevenue();
        string getSpectrumSize();
};

class Subscriber{
    private:
        string date;
        string company;
        string location;
        string subscribers;
    public:
        Subscriber();
        Subscriber(string date, string company, string location, string subscribers);
        ~Subscriber();
        void setDate(string date);
        void setCompany(string company);
        void setLocation(string location);
        void setSubscribers(string subscribers);
        string getDate();
        string getCompany();
        string getLocation();
        string getSubscribers();
};

class Spectrum_Request{
    private:
        string date;
        string company;
        string location;
        string request;
    public:
        Spectrum_Request();
        Spectrum_Request(string date, string company, string location, string request);
        ~Spectrum_Request();
        void setDate(string date);
        void setCompany(string company);
        void setLocation(string location);
        void setRequest(string request);
        string getDate();
        string getCompany();
        string getLocation();
        string getRequest();
};

class MVNO_Spectrum{
    private:
        string date;
        string MVNOcompany;
        string location;
        string request;
    public:
        MVNO_Spectrum();
        MVNO_Spectrum(string date, string MVNOcompany, string location, string request);
        ~MVNO_Spectrum();
        void setDate(string date);
        void setMVNOCompany(string MVNOcompany);
        void setLocation(string location);
        void setRequest(string request);
        string getDate();
        string getMVNOCompany();
        string getLocation();
        string getRequest();
};

#endif