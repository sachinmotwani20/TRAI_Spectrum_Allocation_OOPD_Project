#ifndef FUNCTIONS_H
#define FUNCTIONS_H


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

//Function declarations/prototypes
    void Welcome();
    void Util_Add_SpectrumSize_to_Spectrum_Range(string, string);
    void Clear_Spectrum_Range(string, string);
    void Clear_Subscribers(string, string);
    void Clear_Spectrum_Requests(string, string);
    bool Check_Valid_HashCode(string, string, string);
    int Generate_Hash_Code(int);
    void Generate_HashCode_in_LoginFile(string);
    void Print_Login_Credentials();
    int Count_Rows(string);
    int Get_Valid_Choice(int, int );
    string Get_Valid_Spectrum_Range();
    string Get_Valid_Operator(string);
    string Get_Valid_Hashcode();
    bool Check_Valid_Spectrum_Range(string, string, string);
    string Get_Subscribers(string, string, string);
    bool Has_Usage_Density (float);
    float Usage_Density (float, float);
    bool Is_Valid_Choice(string& , int , int);
    string Util_Get_List_Of_Unique_Circles(string);
    string Util_Get_List_Of_Unique_Bidders(string);
    string Util_Get_Random_LTO(string, int);
    void Clear_MVNOSpectrum(string, string, string, string);
    string Get_Valid_Circle(string);
    void Print_Barred_Bidders(string, string, string);
    void Generate_Decision_Report(string, string, string,string);
    void Print_Decision_Report();
    void Generate_Revenue_Report(string, string, string);
    void Print_Revenue_Report();
    string Get_Current_Date();
    void Exit_Protocol();
#endif