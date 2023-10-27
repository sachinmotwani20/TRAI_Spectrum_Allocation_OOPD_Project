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
    int Count_Rows(string);
    int Get_Valid_Choice(int, int );
    bool Is_Valid_Choice(string& , int , int);
    string Util_Get_List_Of_Unique_Circles(string);
    string Util_Get_List_Of_Unique_Bidders(string);
    string Get_Valid_Circle(string);
    void Print_Barred_Bidders(string, string, string);
    void Generate_Decision_Report(string, string, string,string);
    void Print_Decision_Report();
    void Generate_Revenue_Report(string, string, string);
    void Print_Revenue_Report();
    void Exit_Protocol();
#endif