//Header Files
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
string Path_MVNO_Spectrum = "Data/MVNOSpectrum.csv"; //M

//Output Files
string Path_Decision_Report = "Data_Modified/Decision_Report.csv"; 
string Path_Revenue_Report = "Data_Modified/Revenue_Report.csv";

int main(){
        //Variable declarations
        int choice=1, start=1, stop=8;

        Welcome();

        // Setup
        string Path_Spectrum_Range_Without_Size = "Data_Modified/cleaned_spectrum_range.csv";
        string Path_Subscribers = "Data_Modified/cleaned_subscribers.csv";
        string Path_Spectrum_Requests = "Data_Modified/cleaned_spectrum_requests.csv";

        Clear_Spectrum_Range(Path_Spectrum_Range_raw, Path_Spectrum_Range_Without_Size); //Removing Redundant Entries
        Clear_Subscribers(Path_Subscribers_raw, Path_Subscribers); //Removing Redundant Entries
        Clear_Spectrum_Requests(Path_Spectrum_Requests_raw, Path_Spectrum_Requests); //Removing Redundant Entries

        string Path_Spectrum_Range = "Data_Modified/updated_cleaned_spectrum_range.csv";
        Util_Add_SpectrumSize_to_Spectrum_Range(Path_Spectrum_Range_Without_Size, Path_Spectrum_Range);

        string list_of_unique_circles = Util_Get_List_Of_Unique_Circles(Path_Spectrum_Range);
        string list_of_unique_bidders = Util_Get_List_Of_Unique_Bidders(Path_Spectrum_Range);

        do {

                // Read data from spectrumRange.csv
                const int MAX_RECORDS_SRa = Count_Rows(Path_Spectrum_Range);
                Spectrum_Range records_SRa[MAX_RECORDS_SRa];
                ifstream file_SRa(Path_Spectrum_Range);
                string line;
                int i = 0;
                while(getline(file_SRa, line)){
                        stringstream ss(line);
                        string date, company, spectrum_range, circle, revenue, spectrum_size;
                        getline(ss, date, ',');
                        getline(ss, company, ',');
                        getline(ss, spectrum_range, ',');
                        getline(ss, circle, ',');
                        getline(ss, revenue, ',');
                        getline(ss, spectrum_size, ',');
                        Spectrum_Range record_SRa(date, company, spectrum_range, circle, revenue, spectrum_size);
                        records_SRa[i++] = record_SRa;
                }
                file_SRa.close(); 

                // Read data from subscribers.csv
                const int MAX_RECORDS_S = Count_Rows(Path_Subscribers);
                Subscriber records_S[MAX_RECORDS_S];
                ifstream file_S(Path_Subscribers);
                i = 0;
                while(getline(file_S, line)){
                        stringstream ss(line);
                        string date, company, location, subscribers;
                        getline(ss, date, ',');
                        getline(ss, company, ',');
                        getline(ss, location, ',');
                        getline(ss, subscribers, ',');
                        Subscriber record_S(date, company, location, subscribers);
                        records_S[i++] = record_S;
                }
                file_S.close();

                // Read data from spectrumRequest.csv
                const int MAX_RECORDS_SRe = Count_Rows(Path_Spectrum_Requests);
                Spectrum_Request records_SRe[MAX_RECORDS_SRe];
                ifstream file_SRe(Path_Spectrum_Requests);
                i = 0;
                while(getline(file_SRe, line)){
                        stringstream ss(line);
                        string date, company, location, request;
                        getline(ss, date, ',');
                        getline(ss, company, ',');
                        getline(ss, location, ',');
                        getline(ss, request, ',');
                        Spectrum_Request record_SRe(date, company, location, request);
                        records_SRe[i++] = record_SRe;
                }

                file_SRe.close();


                // Read data from MVNOSpectrum.csv
                const int MAX_RECORDS_M = Count_Rows(Path_MVNO_Spectrum);
                MVNO_Spectrum records_M[MAX_RECORDS_M];
                ifstream file_M(Path_MVNO_Spectrum);
                i = 0;
                while(getline(file_M, line)){
                        stringstream ss(line);
                        string date, MVNOcompany, location, request;
                        getline(ss, date, ',');
                        getline(ss, MVNOcompany, ',');
                        getline(ss, location, ',');
                        getline(ss, request, ',');
                        MVNO_Spectrum record_M(date, MVNOcompany, location, request);
                        records_M[i++] = record_M;
                }
                file_M.close();

                cout << "Please select an option from the menu below:" << endl;
                cout << "1. Print 'Spectrum Range' Data" << endl;
                cout << "2. Print 'Subscribers' Data" << endl;
                cout << "3. Print 'Spectrum Requests' Data" << endl;
                cout << "4. Print 'MVNO Spectrum' Data" << endl;
                cout << "5. Print List of Bidders with Usage Density at a particular circle (Not Allowed to Bid)" << endl;
                cout << "6. Print Report of Decisions on Spectrum Requests" << endl;
                cout << "7. Print Revenue Report" << endl;
                cout << "8. Exit" << endl;
                // cout << "Enter your choice: ";
                choice = Get_Valid_Choice(start, stop);

                switch (choice) {
                case 1: {
                        cout << "-------------------------------" << endl;
                        cout << "Printing 'Spectrum Range' Data" << endl;
                        cout << "-------------------------------" << endl;
                        for (int i = 0; i < MAX_RECORDS_SRa; i++) {
                                cout << i <<" "<<records_SRa[i].getDate() << " " << records_SRa[i].getCompany() << " " << records_SRa[i].getSpectrumRange() << " "<< records_SRa[i].getCircle() <<" "<< records_SRa[i].getRevenue() <<" "<< records_SRa[i].getSpectrumSize() << endl;
                        
                        }
                        cout << "-------------------------------" << endl;
                        cout << "-------------------------------" << endl;
                        break;
                        }
                case 2: {
                        cout << "-------------------------------" << endl;
                        cout << "Printing 'Subscribers' Data" << endl;
                        cout << "-------------------------------" << endl;
                        for (int i = 0; i < MAX_RECORDS_S; i++) {
                                cout << i <<" "<< records_S[i].getDate() << " " << records_S[i].getCompany() << " " << records_S[i].getLocation() << " " << records_S[i].getSubscribers() << endl;
                        }
                        cout << "-------------------------------" << endl;
                        cout << "-------------------------------" << endl;
                        break;
                        }
                case 3: {
                        cout << "-------------------------------" << endl;
                        cout << "Printing 'Spectrum Requests' Data" << endl;
                        cout << "-------------------------------" << endl;
                        for (int i = 0; i < MAX_RECORDS_SRe; i++) {
                                cout << i <<" "<< records_SRe[i].getDate() << " " << records_SRe[i].getCompany() << " " << records_SRe[i].getLocation() << " " << records_SRe[i].getRequest() << endl;
                        }
                        cout << "-------------------------------" << endl;
                        cout << "-------------------------------" << endl;
                        break;
                        }
                case 4: {
                        cout << "-------------------------------" << endl;
                        cout << "Printing 'MVNO Spectrum' Data" << endl;
                        cout << "-------------------------------" << endl;
                        for (int i = 0; i < MAX_RECORDS_M; i++) {
                                cout << i <<" "<< records_M[i].getDate() << " " << records_M[i].getMVNOCompany() << " " << records_M[i].getLocation() << " " << records_M[i].getRequest() << endl;
                        }
                        cout << "-------------------------------" << endl;
                        cout << "-------------------------------" << endl;
                        break;
                        }
                case 5: {
                        cout << "-------------------------------" << endl;
                        cout << "Printing 'List of Bidders' with usage density in a particular circle (Not allowed for Fresh Bidding)" << endl;
                        cout << "-------------------------------" << endl;
                        string circle = Get_Valid_Circle(list_of_unique_circles);
                        Print_Barred_Bidders(circle, Path_Spectrum_Range, Path_Subscribers);
                        cout << "-------------------------------" << endl;
                        cout << "-------------------------------" << endl;
                        break;
                        }
                case 6: {
                        cout<< "-------------------------------" << endl;
                        cout<< "Printing Report of the Decisions on Spectrum Requests" << endl;
                        cout<< "-------------------------------" << endl;
                        Generate_Decision_Report(Path_Spectrum_Requests, Path_Spectrum_Range, Path_Subscribers, Path_Decision_Report);
                        Print_Decision_Report();
                        cout<< "-------------------------------" << endl;
                        cout<< "-------------------------------" << endl;
                        break;
                        }                    
                case 7: {
                        cout << "-------------------------------" << endl;
                        cout << "Printing Revenue Report" << endl;
                        cout << "-------------------------------" << endl;
                        Generate_Revenue_Report(Path_Spectrum_Range, Path_Decision_Report, Path_Revenue_Report);
                        Print_Revenue_Report();                        
                        break;
                        }
                
                case 8: {
                        cout << "Exiting..." << endl;
                        Exit_Protocol();
                        break;
                        }
                default: {
                        cout<<"Invalid choice."<<endl;
                        break;
                        }
                }
        } while (choice != stop);

        Exit_Protocol();
        return 0;
}