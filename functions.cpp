
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
#include <ctime> //To use time() for random number generator

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

    // Keep track of existing company, spectrum range, and circle combinations
    string existing_combinations = "";

    // Process each line in input file
    while (getline(input_file, line)) {
        // Parse line into fields
        stringstream ss(line);
        string date, company, spectrum_range, circle, revenue, spectrum_size;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, spectrum_range, ',');
        getline(ss, circle, ',');
        getline(ss, revenue, ',');

        // Check if company, spectrum range, and circle combination already exists
        if (existing_combinations.find(company + spectrum_range + circle) == string::npos) {
            output_file << line << endl; // Write row to output file
            existing_combinations += company + spectrum_range + circle; // Add combination to string of existing combinations
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
    string existing_combinations;

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
        if (existing_combinations.find(company + location) == string::npos) {
            output_file << line << endl; // Write row to output file
            existing_combinations += company + location; // Add combination to string of existing combinations
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

    // Keep track of existing company, location, and spectrum_request combinations
    string existing_combinations;

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
        if (existing_combinations.find(company + location + request) == string::npos) {
            output_file << line << endl; // Write row to output file
            existing_combinations += company + location + request; // Add combination to string of existing combinations
        }
        
    }

    // Close files
    input_file.close();
    output_file.close();
}

bool Check_Valid_HashCode(string MVNO_Comp, string hash_code, string path_login_file){
    ifstream file(path_login_file);
    string line;
    while(getline(file, line)){
        stringstream ss(line);        
        string user_type, user_id, password, hash_code_in_file;
        getline(ss, user_type, ',');
        getline(ss, user_id, ',');
        getline(ss, password, ',');
        getline(ss, hash_code_in_file, ',');

        if (user_type == "MVN" && user_id == MVNO_Comp && hash_code_in_file == hash_code) {
            return true;
        }
    }
    file.close();
    return false;

}

int Generate_Hash_Code(int seed){
    //Generate a 4-digit random number
    srand(time(0)+seed);
    int random_number = rand() % 10000 + seed;
    return random_number;
}



void Generate_HashCode_in_LoginFile(string path_to_file){
    ifstream file(path_to_file);
    string line;
    getline(file, line);

    if (line.find("HashCode") != string::npos) {
        file.close();
        return;
    }
    else {
        // Restart file pointer
        file.clear();
        file.seekg(0, ios::beg);

        // Generate ouput file
        string output_path = "Data_Modified/temp.csv";
        ofstream output_file(output_path);
        if (!output_file.is_open()) {
            cout << "Error creating output file." << endl;
            file.close();
            return;
        }

        if (!file.is_open()) {
            cout << "Error opening file: "<< path_to_file << endl;
            return;
        }

        string line;
        getline(file, line); //Skip the first line
        output_file << line << ",HashCode" << endl; //Write the first line to the output file

        int flag = 0;
        while(getline(file, line)){
            stringstream ss(line);        
            string user_type, user_id, password;
            getline(ss, user_type, ',');
            getline(ss, user_id, ',');
            getline(ss, password, ',');

            if (user_type == "LTO") {
                output_file << line << "," << "N/A" << endl;
            } else {
                output_file << line << "," << Generate_Hash_Code(++flag) << endl;
            }
        }
        file.close();
        output_file.close();

        //Delete the original file and rename the output file to the original file name
        remove(path_to_file.c_str());
        rename(output_path.c_str(), path_to_file.c_str());
    }

    file.close();


}

void Print_Login_Credentials(){
    ifstream file("Data_Modified/Login_Credentials.csv");
    string line;
    while(getline(file, line)){
        stringstream ss(line);      
        cout << line << endl;        
    }
    file.close();    
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
   
    int size = bidder_unique_list.size();

   //Remove spaces from bidder_unique_list
    for (int i = 0; i < size; i++) {
        if (bidder_unique_list[i] == ' ') {
            bidder_unique_list.erase(i, 1);
        }
    }

   return bidder_unique_list;
}

string Util_Get_Random_LTO( string unique_bidders_list, int seed){
    //Randomly return one bidder from the provided comma separated string without using vector or set
    if (unique_bidders_list == "") {
        cout << "Error: No bidders available." << endl;
        return "Error";
    }
    
    // Count the number of bidders
    int bidderCount = 1;
    for (char c : unique_bidders_list) {
        if (c == ',') {
            bidderCount++;
        }
    }
    
    // Generate a random number between 0 and bidderCount - 1
    srand(time(0) + seed);
    int randomIndex = rand() % bidderCount;

    // Find the bidder at the random index
    int currentIndex = 0;
    string bidder = "";
    for (char c : unique_bidders_list) { 
        if (c == ',') {
            currentIndex++;
        } else if (currentIndex == randomIndex) {
            bidder += c;
        }
    }

    return bidder;    
}

string Find_Corresponding_HashCode(string company, string path_to_file){
    ifstream file(path_to_file);
    string line;
    getline(file, line); //Skip the first line
    while(getline(file, line)){
        stringstream ss(line);        
        string user_type, user_id, password, hash_code;
        getline(ss, user_type, ',');
        getline(ss, user_id, ',');
        getline(ss, password, ',');
        getline(ss, hash_code, ',');

        if (user_type == "MVN" && user_id == company) {
            return hash_code;
        }
    }
    file.close();
    return "Error";
}

void Clear_MVNOSpectrum(string path_to_MVNO_file, string path_to_output_file_without_LTO,string path_to_output_file, string unique_bidders_list){
    // Open file
    ifstream input_file(path_to_MVNO_file);
    if (!input_file.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    // Create output file
    string output_path = path_to_output_file_without_LTO;
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

    // Keep track of existing company, spectrum range, and circle combinations
    string existing_combinations = "";

    // Process each line in input file
    while (getline(input_file, line)) {
        // Parse line into fields
        stringstream ss(line);
        string date, company, circle, requested_spectrum_range;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, circle, ',');
        getline(ss, requested_spectrum_range, ',');
        // Check if company, spectrum range, and circle combination already exists then don't add the line to the file
        if (existing_combinations.find(company + requested_spectrum_range + circle) == string::npos) {
            output_file << line << endl; // Write row to output file
            existing_combinations += company + requested_spectrum_range + circle; // Add combination to string of existing combinations
        }   
    }

    // Close files
    input_file.close();
    output_file.close();

    //To_do Add a new column 'TelecomOperator' to the output file and randomly add one telecom operator for each row
    ifstream input_file2(path_to_output_file_without_LTO);
    if (!input_file2.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    // Create output file
    string output_path2 = path_to_output_file;
    ofstream output_file2(output_path2);
    if (!output_file2.is_open()) {
        cout << "Error creating output file." << endl;
        input_file2.close();
        return;
    }

    // Copy column headers to output file
    string line2;
    getline(input_file2, line2);
    output_file2 << line2 << ",TelecomOperator,HashCode,Decision" << endl;

    // Process each line in input file
    int flag = 50;
    while (getline(input_file2, line2)) {
        // Parse line into fields
        stringstream ss(line2);
        string date, company, circle, requested_spectrum_range;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, circle, ',');
        getline(ss, requested_spectrum_range, ',');

        string Tel_Operator = Util_Get_Random_LTO(unique_bidders_list, ++flag);
        string HashCode = Find_Corresponding_HashCode(company, "Data_Modified/Login_Credentials.csv");

        output_file2 << line2 << "," << Tel_Operator << "," << HashCode << ",Pending"<<endl; // Write row to output file    
    }

    // Close files
    input_file2.close();
    output_file2.close();
    
}

string Get_Valid_Circle(string cir_uni_lis="Patna,Lucknow,Kolkata,Jaipur,Delhi,Chandigarh"){
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

string Get_Valid_Spectrum_Range(){
    string Spectrum_Range;
    while (true){
        cout<< "Spectrum Range: ";
        getline(cin, Spectrum_Range);

        //Spectrum range must be an integer between 1 and 9999 
        if (Is_Valid_Choice(Spectrum_Range, 1, 9999)){
            return Spectrum_Range;
        }
        else{
            cout<<"Invalid input. Please enter a valid spectrum range."<<endl;
        }
    }
}

string Get_Valid_Operator(string unique_operator_list){
    string Operator;
    while (true){
        cout<< "Operator: ";
        getline(cin, Operator);

        //Operator must be from the list of unique operators
        if (unique_operator_list.find(Operator) != string::npos){
            return Operator;
        }
        else{
            cout<<"Invalid input. Please enter a valid operator from the list only."<<endl;
            cout<<"List of valid operators: "<<unique_operator_list<<endl;
        }
    }
}

string Get_Valid_Hashcode(){
    string Hashcode;
    while (true){
        cout<< "Hashcode: ";
        getline(cin, Hashcode);

        //Hashcode must be an integer between 1000 and 9999 
        if (Is_Valid_Choice(Hashcode, 1000, 9999)){
            return Hashcode;
        }
        else{
            cout<<"Invalid input. Please enter a valid hashcode."<<endl;
        }
    }
}

bool Check_Valid_Spectrum_Range (string LTOperator, string Spectrum_Range, string path_to_spectrum_range_file){
    ifstream file(path_to_spectrum_range_file);
    string line;
    while(getline(file, line)){
        stringstream ss(line);        
        string date, company, spectrum_range, circle, revenue, spectrum_size;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, spectrum_range, ',');
        getline(ss, circle, ',');
        getline(ss, revenue, ',');
        getline(ss, spectrum_size, ',');

        //Remove ' MHz' from the end of "spectrum_range"
        spectrum_range = spectrum_range.substr(0, spectrum_range.size() - 4);
        if (company == LTOperator && spectrum_range == Spectrum_Range) {
            return true;
        }

    }

    file.close();
    cout<<"Invalid spectrum range: "<< Spectrum_Range <<endl;
    return false;    
}

string Get_Subscribers(string LTOperator, string Circle, string path_to_subscribers_file){
    ifstream file(path_to_subscribers_file);
    string line;
    while(getline(file, line)){
        stringstream ss(line);        
        string date, company, circle, subscribers;
        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, circle, ',');
        getline(ss, subscribers, ',');

        if (company == LTOperator && circle == Circle) {
            return subscribers;
        }

    }

    file.close();
    return "Error";    
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

string Get_Current_Date(){
    //Get current data in the format MM-YY
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string month = to_string(1 + ltm->tm_mon);
    string year = to_string(1900 + ltm->tm_year);
    year = year.substr(2,2); //Last two digit of year
    string current_date = month + "-" + year;
    return current_date;
}

void Exit_Protocol(){
    Sleep(1000); //Delay for 1 second
    cout<<"Thank you for using the TRAI Data Management Software."<<endl;
    cout<<"Hope you let us serve you again soon. Toodles!"<<endl;
    Sleep(2000); //Delay for 2 seconds
    abort(); //Exit the program
}
