
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
#include <set> //To use set <string>


using namespace std;

#include "functions.h"

/*Definition of Functions*/

void Welcome()
{
    Sleep(1000); //Delay for 1 second
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Telecom Regulatory Authority of India (TRAI)"<<endl;
    cout<<"Welcome to TRAI Data Management Software!"<<endl;
    cout<<"-------------------------------------------------"<<endl;
}   

void Util_Add_SpectrumSize_to_Spectrum_Range(string Path_Spectrum_Range, string Path_Output_File){
    /*Add a new column 'SpectrumSize' to the output file and keep the value as 50Hz for all the rows*/
    // Open input file
    ifstream input_file(Path_Spectrum_Range);
    if (!input_file.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    // Create output file
    string output_path = Path_Output_File;
    ofstream output_file(output_path);
    if (!output_file.is_open()) {
        cout << "Error creating output file." << endl;
        input_file.close();
        return;
    }

    // Copy column headers to output file
    string line;
    getline(input_file, line);
    output_file << line << ",SpectrumSize (MHz)" << endl;

    // Process each line in input file
    while (getline(input_file, line)) {
        // Parse line into fields
        stringstream ss(line);
        string date, company, spectrum_range, circle, revenue;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, spectrum_range, ',');
        getline(ss, circle, ',');
        getline(ss, revenue, ',');
        
        // Write row to output file
        output_file << line << ",50" << endl;
    }

    // Close files
    input_file.close();
    output_file.close();
}

void Clear_Spectrum_Range(string Path_Spectrum_Range, string Path_Output_File){
    // Open input file
    ifstream input_file(Path_Spectrum_Range);
    if (!input_file.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    // Create output file
    string output_path = Path_Output_File;
    ofstream output_file(output_path);
    if (!output_file.is_open()) {
        cout << "Error creating output file." << endl;
        input_file.close();
        return;
    }

    // Copy column headers to output file
    string line;
    getline(input_file, line);
    output_file << line << endl;

    // Keep track of allocated spectrum ranges
    set<string> allocated_ranges;

    // Process each line in input file
    while (getline(input_file, line)) {
        // Parse line into fields
        stringstream ss(line);
        string date, company, spectrum_range, circle, revenue;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, spectrum_range, ',');
        getline(ss, circle, ',');
        getline(ss, revenue, ',');
        
        // Check if spectrum range has already been allocated
        if (allocated_ranges.count(circle + spectrum_range) == 0) {
            output_file << line << endl; // Write row to output file
            allocated_ranges.insert(circle + spectrum_range); // Add spectrum range to set of allocated ranges
        }
    }

    // Close files
    input_file.close();
    output_file.close();
}

void Clear_Subscribers(string Path_Subscribers, string Path_Output_File){
    // Open input file
    ifstream input_file(Path_Subscribers);
    if (!input_file.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    // Create output file
    string output_path = Path_Output_File;
    ofstream output_file(output_path);
    if (!output_file.is_open()) {
        cout << "Error creating output file." << endl;
        input_file.close();
        return;
    }

    // Copy column headers to output file
    string line;
    getline(input_file, line);
    output_file << line << endl;

    // Keep track of existing company and location combinations
    set<string> existing_combinations;

    // Process each line in input file
    while (getline(input_file, line)) {
        // Parse line into fields
        stringstream ss(line);
        string date, company, location, subscribers;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, location, ',');
        getline(ss, subscribers, ',');

        // Check if company and location combination already exists
        if (existing_combinations.count(company + location) == 0) {
            output_file << line << endl; // Write row to output file
            existing_combinations.insert(company + location); // Add combination to set of existing combinations
        }
    }

    // Close files
    input_file.close();
    output_file.close();
}

void Clear_Spectrum_Requests(string Path_Spectrum_Requests, string Path_Output_File){
    // Open input file
    ifstream input_file(Path_Spectrum_Requests);
    if (!input_file.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    // Create output file
    string output_path = Path_Output_File;
    ofstream output_file(output_path);
    if (!output_file.is_open()) {
        cout << "Error creating output file." << endl;
        input_file.close();
        return;
    }

    // Copy column headers to output file
    string line;
    getline(input_file, line);
    output_file << line << endl;

    // Keep track of existing company, location, and request combinations
    set<string> existing_combinations;

    // Process each line in input file
    while (getline(input_file, line)) {
        // Parse line into fields
        stringstream ss(line);
        string date, company, location, request;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, location, ',');
        getline(ss, request, ',');

        // Check if company, location, and request combination already exists
        if (existing_combinations.count(company + location + request) == 0) {
            output_file << line << endl; // Write row to output file
            existing_combinations.insert(company + location + request); // Add combination to set of existing combinations
        }
        
    }

    // Close files
    input_file.close();
    output_file.close();
}

int Count_Rows(string path_to_file){
    ifstream file(path_to_file);

    if (!file.is_open()) {
        cout << "Error opening file: "<< path_to_file << endl;
        return 0;
    }

    string line;
    int count = 0;
    while(getline(file, line)){
        count++;
    }
    file.close();
    return count;
}

bool Is_Valid_Choice(string& input, int start, int stop){

    int decimal_count = 0; //For checking any decimal point
    bool digit_found = false; //For checking if any non-digit entity is entered

    for (char c : input) { //Run though the 'for' loop for every character in the string 'input' 
        if (isdigit(c)) {
            digit_found = true;
        } else if (c == '.') {
            decimal_count++;
            if (decimal_count > 0) {
                cout<<"Decimal point found. Choice must be a whole number."<<endl;
                return false; 
            }
        } else if (c == '-') {
            cout<<"Negative choice found. Choice must be a whole number."<<endl;
            return false;      
        } else {
            cout<<"Invalid character(s) found. Choice must be a whole number."<<endl;
            return false; 
        }
    }

    if (!digit_found) {
        cout<<"No digits found."<<endl;
        return false; // No digits found
    }

    int value = stoi(input);
    return ((value >= start) && (value<=stop)); // Check if value is greater than start and less than stop

}

int Get_Valid_Choice(int start, int stop){
    string choice;
    while (true) {
        cout << "Enter your choice: ";
        getline(cin, choice); 

        if (Is_Valid_Choice(choice, start, stop)) {
            return stoi(choice);
        } else {
            cout << "Invalid input. Please enter a valid choice in digits (between "<<start<<" & "<<stop<<") only." << endl;
        }
    }
}

string Util_Get_List_Of_Unique_Circles(string path_to_spectrum_range_file){
    ifstream file(path_to_spectrum_range_file);
    string line;
    string circle_unique_list = "";
    getline(file, line); //Skip the first line
    while(getline(file, line)){
        stringstream ss(line);        
        string date, company, spectrum_range, circle, revenue, spectrum_size;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, spectrum_range, ',');
        getline(ss, circle, ',');
        getline(ss, revenue, ',');
        getline(ss, spectrum_size, ',');

        if (circle_unique_list.find(circle) == string::npos) {
            circle_unique_list += circle + ", ";
        }
    }
    file.close();
    circle_unique_list = circle_unique_list.substr(0, circle_unique_list.size() - 2); //Remove the last comma and space
    return circle_unique_list;
}

string Util_Get_List_Of_Unique_Bidders(string path_to_spectrum_requests_file){
    ifstream file(path_to_spectrum_requests_file);
    string line;
    string bidder_unique_list = "";
    getline(file, line); //Skip the first line
    while(getline(file, line)){
        stringstream ss(line);        
        string date, company, spectrum_range, circle, revenue, spectrum_size;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, spectrum_range, ',');
        getline(ss, circle, ',');
        getline(ss, revenue, ',');
        getline(ss, spectrum_size, ',');

        if (bidder_unique_list.find(company) == string::npos) {
            bidder_unique_list += company + ", ";
        }
    }
    file.close();
    bidder_unique_list = bidder_unique_list.substr(0, bidder_unique_list.size() - 2); //Remove the last comma and space
    return bidder_unique_list;
}

string Get_Valid_Circle(string cir_uni_lis){
    string circle;
    while (true) {
        cout << "Circle: ";
        getline(cin, circle); 

        if (cir_uni_lis.find(circle) != string::npos) {
            return circle;
        } else {
            cout << "Invalid input. Please enter a valid circle from the list only." << endl;
            cout << "List of valid circles: " << cir_uni_lis << endl;
        }
    }
}


bool Has_Usage_Density (float density){
    float threshold = 0.0037;  //Mean of usage density = 0.003722
    if (density < threshold) {
        return false;
    }
    else {
        return true;
    }
}

float Usage_Density (float spectrum_size, float number_of_users){
    float usage_density = spectrum_size/number_of_users;
    return usage_density;
}

void Print_Barred_Bidders(string cir, string spectrum_range_file_path, string subscribers_file_path){
    ifstream spectrum_range_file(spectrum_range_file_path);
    ifstream subscribers_file(subscribers_file_path);
    string line_spectrum_range, line_subscribers;
    string barred_bidders = "";
    
    while (getline(spectrum_range_file, line_spectrum_range)) {
        stringstream ss_spectrum_range(line_spectrum_range);        
        string date_sr, company_sr, spectrum_range_sr, circle_sr, revenue_sr, spectrum_size_sr;
        getline(ss_spectrum_range, date_sr, ',');
        getline(ss_spectrum_range, company_sr, ',');
        getline(ss_spectrum_range, spectrum_range_sr, ',');
        getline(ss_spectrum_range, circle_sr, ',');
        getline(ss_spectrum_range, revenue_sr, ',');
        getline(ss_spectrum_range, spectrum_size_sr, ',');

        if (circle_sr == cir) {
            while (getline(subscribers_file, line_subscribers)) {
                stringstream ss_subscribers(line_subscribers);
                string date_s, company_s, circle_s, subscribers_s;
                getline(ss_subscribers, date_s, ',');
                getline(ss_subscribers, company_s, ',');
                getline(ss_subscribers, circle_s, ',');
                getline(ss_subscribers, subscribers_s, ',');
                if (company_s == company_sr) {
                    float spectrum_size_float = stof(spectrum_size_sr);
                    float subscribers_float = stof(subscribers_s);
                    float usage_density_float = Usage_Density(spectrum_size_float, subscribers_float);
                    if (!Has_Usage_Density(usage_density_float) && barred_bidders.find(company_s) == string::npos) {
                        cout << "Company " << company_s << " has usage density " << usage_density_float << endl;
                        barred_bidders += company_s + ", ";
                    }
                }
            }

            // Restart parsing subscribers_file
            subscribers_file.clear();
            subscribers_file.seekg(0, ios::beg);
        }

    }


}

void Generate_Decision_Report(string spectrum_requests_file_path, string spectrum_range_file_path, string subscribers_file_path, string output_path){
    ifstream spectrum_requests_file(spectrum_requests_file_path);
    ifstream spectrum_range_file(spectrum_range_file_path);
    ifstream subscribers_file(subscribers_file_path);
    
    string line_spectrum_range, line_spectrum_requests, line_subscribers;

    // Create output file
    ofstream output_file(output_path);
    if (!output_file.is_open()) {
        cout << "Error creating output file." << endl;
        spectrum_requests_file.close();
        spectrum_range_file.close();
        subscribers_file.close();
        return;
    }

    // Copy column headers to output file
    string line_spectrum_requests_header;
    getline(spectrum_requests_file, line_spectrum_requests_header);
    output_file << line_spectrum_requests_header << ",Decision" << endl;

    while (getline(spectrum_requests_file, line_spectrum_requests)) {
        stringstream ss_spectrum_requests(line_spectrum_requests);        
        string date_sre, company_sre, circle_sre, spectrum_range_sre;
        getline(ss_spectrum_requests, date_sre, ',');
        getline(ss_spectrum_requests, company_sre, ',');
        getline(ss_spectrum_requests, circle_sre, ',');
        getline(ss_spectrum_requests, spectrum_range_sre, ',');

        int found = 0;

        while (getline(spectrum_range_file, line_spectrum_range)) {
            stringstream ss_spectrum_range(line_spectrum_range);        
            string date_sra, company_sra, spectrum_range_sra, circle_sra, revenue_sra, spectrum_size_sra;
            getline(ss_spectrum_range, date_sra, ',');
            getline(ss_spectrum_range, company_sra, ',');
            getline(ss_spectrum_range, spectrum_range_sra, ',');
            getline(ss_spectrum_range, circle_sra, ',');
            getline(ss_spectrum_range, revenue_sra, ',');
            getline(ss_spectrum_range, spectrum_size_sra, ',');
            
            if (company_sra == company_sre && circle_sra == circle_sre){ 
                while (getline(subscribers_file, line_subscribers)) {
                    stringstream ss_subscribers(line_subscribers);
                    string date_s, company_s, circle_s, subscribers_s;
                    getline(ss_subscribers, date_s, ',');
                    getline(ss_subscribers, company_s, ',');
                    getline(ss_subscribers, circle_s, ',');
                    getline(ss_subscribers, subscribers_s, ',');

                    if (company_s == company_sre && circle_s == circle_sre && found == 0) {
                        found++;
                        float spectrum_size_float = stof(spectrum_size_sra);
                        float subscribers_float = stof(subscribers_s);
                        float usage_density_float = Usage_Density(spectrum_size_float, subscribers_float);
                        if (Has_Usage_Density(usage_density_float)) {
                            output_file << line_spectrum_requests << ",Approved" << endl;
                            break;
                        }
                        else{
                            output_file << line_spectrum_requests << ",Rejected" << endl;
                            break;
                        }
                    }
                }

                // Restart parsing subscribers_file
                subscribers_file.clear();
                subscribers_file.seekg(0, ios::beg);
            }


        }

        // Restart parsing spectrum_range_file
        spectrum_range_file.clear();
        spectrum_range_file.seekg(0, ios::beg);


        if (found == 0){
                output_file << line_spectrum_requests << ",Approved" << endl;
            }
    }

    // Close files
    spectrum_requests_file.close();
    spectrum_range_file.close();
    subscribers_file.close();
    output_file.close();

}

void Print_Decision_Report(){
    ifstream file("Data_Modified/Decision_Report.csv");
    string line;
    while(getline(file, line)){
        stringstream ss(line);      
        cout << line << endl;        
    }
    file.close();
}

bool Util_Contained_In(string company, string circle, string spectrum_range, string file_path_spectrum_range){
    ifstream file(file_path_spectrum_range);
    string line;
    while(getline(file, line)){
        stringstream ss(line);        
        string date, company_sra, spectrum_range_sra, circle_sra, revenue, spectrum_size;
        getline(ss, date, ',');
        getline(ss, company_sra, ',');
        getline(ss, spectrum_range_sra, ',');
        getline(ss, circle_sra, ',');
        getline(ss, revenue, ',');
        getline(ss, spectrum_size, ',');

        if (company_sra == company && circle_sra == circle && spectrum_range_sra == spectrum_range) {
            return true;
        }
    }
    file.close();
    return false;
}

void Generate_Revenue_Report(string spectrum_range_file_path, string decision_report_file_path, string output_path){
    ifstream spectrum_range_file(spectrum_range_file_path);
    ifstream decision_report_file(decision_report_file_path);

    string line_spectrum_range, line_decision_report;

    // Create output file
    ofstream output_file(output_path);
    if (!output_file.is_open()) {
        cout << "Error creating output file." << endl;
        spectrum_range_file.close();
        decision_report_file.close();
        return;
    }

    // Copy all rows and columns of spectrum_range_file to output file
    while (getline(spectrum_range_file, line_spectrum_range)) {
        output_file << line_spectrum_range << endl;
    }

    spectrum_range_file.close();

    while (getline(decision_report_file, line_decision_report)) {
        stringstream ss_decision_report(line_decision_report);        
        string date_dre, company_dre, circle_dre, spectrum_range_dre, usage_density_dre, decision_dre;
        getline(ss_decision_report, date_dre, ',');
        getline(ss_decision_report, company_dre, ',');
        getline(ss_decision_report, circle_dre, ',');
        getline(ss_decision_report, spectrum_range_dre, ',');
        getline(ss_decision_report, decision_dre, ',');

        if (decision_dre == "Approved"){
            if (!Util_Contained_In(company_dre, circle_dre, spectrum_range_dre, spectrum_range_file_path)) {
                output_file << date_dre << "," << company_dre << "," << spectrum_range_dre << " MHz," << circle_dre << "," << "10" << "," << "50" << endl;
            }
        }
    }

    // Close files
    decision_report_file.close();
    output_file.close();

}


void Print_Revenue_Report(){
    ifstream file("Data_Modified/Revenue_Report.csv");
    string line;
    while(getline(file, line)){
        stringstream ss(line);      
        cout << line << endl;        
    }
    file.close();
}

void Exit_Protocol(){
    Sleep(1000); //Delay for 1 second
    cout<<"Thank you for using the TRAI Data Management Software."<<endl;
    cout<<"Hope you let us serve you again soon. Toodles!"<<endl;
    Sleep(2000); //Delay for 2 seconds
    abort(); //Exit the program
}
