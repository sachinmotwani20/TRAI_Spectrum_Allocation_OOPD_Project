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

#include "functions.h"

class User{
    private:
        string user_type;
        string user_id;
        string password;
        int hash_code;
    public:
        string Path_Spectrum_Requests = "Data_Modified/cleaned_spectrum_requests.csv";
        string Path_Spectrum_Range = "Data_Modified/updated_cleaned_spectrum_range.csv";
        string Path_Subscribers = "Data_Modified/cleaned_subscribers.csv";
        string Path_Decision_Report = "Data_Modified/Decision_Report.csv"; 
        string Path_MVNO_Spectrum = "Data_Modified/cleaned_MVNO_Spectrum_operator_added.csv";
        string Path_Login_File = "Data_Modified/Login_Credentials.csv";

        string list_of_unique_circles_class = Util_Get_List_Of_Unique_Circles(Path_Spectrum_Range);
        string list_of_unique_bidders_class = Util_Get_List_Of_Unique_Bidders(Path_Spectrum_Range);

        bool Login();
        //User Type
        string Get_User_Type();
        void Set_User_Type(string);
        //User ID
        string Get_User_Id(); 
        void Set_User_Id();
        bool Check_User_ID_in_File(string);
        bool Is_Valid_User_Id(string& , string);
        //Password
        string Get_Password();
        bool Verify_Password();
        bool Check_Password_in_File(string);
        //Hash Code
        int Get_Hash_Code();
        int Generate_Hash_Code();
    
};

class Licensed_Telecom_Operator : public User{
    public:
    Licensed_Telecom_Operator(){
        cout<<"Welcome, Licensed Telecom Operator!"<<endl;
        Set_User_Type("LTO");
    }
    
    void LTO_Menu();
    void Raise_Spectrum_Request();
    void Check_Spectrum_Request_Status(string, string, string, string);
    void View_MVNO_Requests();
    void Update_and_Review_Decision_on_MVNO_Requests();

};

class Mobile_Virtual_Network_Operator: public User{
    public:
    Mobile_Virtual_Network_Operator(){
        cout<<"Welcome, Mobile Virtual Network Operator!"<<endl;
        Set_User_Type("MVN");
    }
    void MVNO_Menu();
    void Raise_Spectrum_Sharing_Request();
    void Check_Spectrum_Sharing_Request_Status(string);
    
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
        string LTOperator;
        string hashcode;
        string decision;
    public:
        MVNO_Spectrum();
        MVNO_Spectrum(string date, string MVNOcompany, string location, string request, string LTOperator, string hashcode, string decision);
        ~MVNO_Spectrum();
        void setDate(string date);
        void setMVNOCompany(string MVNOcompany);
        void setLocation(string location);
        void setRequest(string request);
        void setLTOperator(string LTOperator);
        void setHashcode(string hashcode);
        void setDecision(string decision);
        string getDate();
        string getMVNOCompany();
        string getLocation();
        string getRequest();
        string getLTOperator();
        string getHashcode();
        string getDecision();
};

#endif