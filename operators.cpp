#include <iostream> //To use cout and cin
#include <string> //To use string
#include <fstream> //To read from file
#include <sstream> //To use stringstream
#include <iomanip> //To use setprecision
#include <limits> //To use numeric_limits
#include <cctype> //To use isdigit()
#include <windows.h> //To use Sleep() in windows 
#include <cstdlib> //To use random number generator
#include <filesystem> //To use filesystem [system - > Create Folder]

using namespace std;

#include "classes.h"
#include "functions.h"

//Data Files
string Path_Spectrum_Range_raw = "Data/spectrumRange.csv"; //SRa
string Path_Subscribers_raw = "Data/subscribers.csv"; //S
string Path_Spectrum_Requests_raw = "Data/spectrumRequest.csv"; //SRe
string Path_MVNO_Spectrum_raw = "Data/MVNOSpectrum.csv"; //M

//Output Files
string Path_Decision_Report = "Data_Modified/Decision_Report.csv"; 
string Path_Revenue_Report = "Data_Modified/Revenue_Report.csv";

int main(){

    //Variable declarations
    int choice=1, start=1, stop=3;
    bool Login_Status = false;

    Welcome();

    // Setup
        string Path_Spectrum_Range_Without_Size = "Data_Modified/cleaned_spectrum_range.csv";
        string Path_Subscribers = "Data_Modified/cleaned_subscribers.csv";
        string Path_Spectrum_Requests = "Data_Modified/cleaned_spectrum_requests.csv";
        string Path_MVNO_Spectrum_without_operator = "Data_Modified/cleaned_MVNOSpectrum.csv";
        string Path_MVNO_Spectrum = "Data_Modified/cleaned_MVNO_Spectrum_operator_added.csv";
        string Path_Login_File = "Data_Modified/Login_Credentials.csv";

        Clear_Spectrum_Range(Path_Spectrum_Range_raw, Path_Spectrum_Range_Without_Size); //Removing Redundant Entries
        Clear_Subscribers(Path_Subscribers_raw, Path_Subscribers); //Removing Redundant Entries
        Clear_Spectrum_Requests(Path_Spectrum_Requests_raw, Path_Spectrum_Requests); //Removing Redundant Entries
        Generate_HashCode_in_LoginFile(Path_Login_File); //Generating Hash Code for MVNOs in Login File

        string Path_Spectrum_Range = "Data_Modified/updated_cleaned_spectrum_range.csv";
        Util_Add_SpectrumSize_to_Spectrum_Range(Path_Spectrum_Range_Without_Size, Path_Spectrum_Range);

        string list_of_unique_circles = Util_Get_List_Of_Unique_Circles(Path_Spectrum_Range);
        string list_of_unique_bidders = Util_Get_List_Of_Unique_Bidders(Path_Spectrum_Range);

        Clear_MVNOSpectrum(Path_MVNO_Spectrum_raw, Path_MVNO_Spectrum_without_operator, Path_MVNO_Spectrum, list_of_unique_bidders); //Removing Redundant Entries, Adding Telecom Operator Names (who are requested for Spectrum), Hashcode and Decision


    do {

        cout << "How do you want to enter the System? As a " << endl;
        cout << "1. Licensed Telecom Operator (LTO)" << endl;
        cout << "2. Mobile Virtual Network Operator (MVNO)" << endl;
        cout << "3. Want to exit." << endl;
        choice = Get_Valid_Choice(start, stop);

        switch (choice) {
        case 1: {Licensed_Telecom_Operator lto; //Create an object of class Licensed_Telecom_Operator
                Login_Status = lto.Login();
                if (!Login_Status) {
                    continue;
                } else {
                        lto.LTO_Menu();
                }
                break;
                }
        case 2: {Mobile_Virtual_Network_Operator mvno; //Create an object of class Mobile_Virtual_Network_Operator
                Login_Status = mvno.Login();
                if (!Login_Status) {
                    continue;
                } else {
                        mvno.MVNO_Menu();
                }
                break;
                }
        case 3: {Exit_Protocol();
                break;
                }
        default: {cout << "Invalid choice. Please try again." << endl;
                break;
                }
        }
    } while (choice != 3);

    return 0;
}