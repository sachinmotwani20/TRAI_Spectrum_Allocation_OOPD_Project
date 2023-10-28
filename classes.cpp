//Header Files
#include <iostream> //To use cout and cin
#include <string> //To use string
#include <fstream> //To read from file
#include <sstream> //To use stringstream
#include <iomanip> //To use setprecision
#include <limits> //To use numeric_limits
#include <cctype> //To use isdigit(), toupper()
#include <windows.h> //To use Sleep() in windows 


using namespace std;

#include "classes.h"
#include "functions.h"

bool User :: Check_Password_in_File(string provided_password){
    string File_Name = Path_Login_File;
    ifstream file(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening user database file: " << File_Name << endl;
    }

    string row;
    while (getline(file, row)) { 

        string user_type_in_file, user_id_in_file, password_in_file;
        stringstream input_string(row); //To parse the data read into the stringstream
        
        getline(input_string, user_type_in_file, ','); 
        getline(input_string, user_id_in_file, ','); 
        getline(input_string, password_in_file, ','); 

        if (user_id_in_file == user_id) { 
            if (password_in_file == provided_password) { //Check if the password matches
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}

bool User :: Verify_Password(){
    string provided_password;
    bool password_correct=false;
    int counter=0;
    while (true) {
        counter++;
        cout<<"Enter your password: ";
        getline(cin, provided_password);

        // Check Password
        password_correct = Check_Password_in_File(provided_password);
        if (password_correct) {
            cout<<"Password correct."<<endl;
            return true;
        } else {
            cout<<"Password incorrect."<<endl;
            if (counter==3) {
                cout<<"You have entered the wrong password 3 times. Please try again later."<<endl;
                return false;
            }
        }
        
    
    }
}



bool User :: Login(){
   bool verify_user=false;
   Set_User_Id();
   verify_user = Verify_Password();
    if (verify_user) {
        cout<<"Login successful."<<endl;
        verify_user = true; 
    } else {
        cout<<"Login unsuccessful."<<endl;
    }
    return verify_user;
}

string User :: Get_User_Type(){
    return user_type;
}

void User :: Set_User_Type(string user_type){
    this->user_type = user_type;
}

string User :: Get_User_Id(){
    return user_id;
}

void User :: Set_User_Id(){
    string user_id;
    bool valid_user_id=false;
    while (true) {
        cout<<"Enter your user ID: ";
        getline(cin, user_id);
        valid_user_id = Is_Valid_User_Id(user_id, Get_User_Type());
        if (valid_user_id) {
            cout<<"User ID valid."<<endl;
            break;
        } else {
            cout<<"User ID invalid."<<endl;
        }
    }
    this->user_id = user_id;
}

bool User :: Check_User_ID_in_File(string u_id){
    string File_Name = Path_Login_File;
    
    ifstream file(File_Name); //Open the file
    
    if (!file) {
        cout<<"No user database available."<<endl;
        ofstream New_File(File_Name); //Create a new file if it does not exist
        if (!New_File.is_open()) {
            cout << "Error opening user database file: " << File_Name << endl;
        }
        New_File<<" User_Type, User_ID, Password"<<endl;
        cout<<"New user database created. It is empty."<<endl;
        New_File.close();
        return false;
    } else {
        string row;
        
        while (getline(file, row)) { 

            string user_id_in_file, user_type_in_file;
            stringstream input_string(row); //To parse the data read into the stringstream
            
            getline(input_string, user_type_in_file, ',');
            getline(input_string, user_id_in_file, ',');
            if (user_id_in_file == u_id) { 
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

}

bool User :: Is_Valid_User_Id(string& user_id, string u_type){
    cout << "User ID: " << user_id << endl;
    cout << "User Type: " << u_type << endl;
    if (user_id.length() == 8) {
        if (u_type == "LTO") {
            if (isalpha(user_id[0]) && isalpha(user_id[1]) && isalpha(user_id[2])) {
                if (isdigit(user_id[3]) && isdigit(user_id[4]) && isdigit(user_id[5]) && isdigit(user_id[6]) && isdigit(user_id[7])) {
                    return true;
                }
            }
        }
        else {
            cout << "User ID does not match user type." << endl;
            return false;
        }
    }
    else if (user_id.length() == 2){
        if (u_type == "MVN") {
            if (isalpha(user_id[0]) && isdigit(user_id[1])) {
                return true;
            }
        }
        else {
            cout << "User ID does not match user type." << endl;
            return false;
        }
    }
    else {
        return false;
    }

return false;
}

string User :: Get_Password(){
    return password;
}

int User :: Get_Hash_Code(){
    return hash_code;
}

int User :: Generate_Hash_Code(){
    //To do: Check if the hashcode is unique
    

    return hash_code;
}


/*Definition of Licensed_Telecom_Operator Class Functions*/

void Licensed_Telecom_Operator :: Raise_Spectrum_Request(){
    string date = Get_Current_Date();
    cout << "Current Date: " << date << endl;
    string company = Get_User_Id();
    string location = Get_Valid_Circle(list_of_unique_circles_class);
    string request = Get_Valid_Spectrum_Range();

    string File_Name = Path_Spectrum_Requests;
    ofstream file(File_Name, ios::app); //Open the file
    if (!file.is_open()) {
        cout << "Error opening file: " << File_Name << endl;
    }

    file << date << "," << company << "," << location << "," << request << endl;
    file.close();
    cout << "Spectrum Request raised successfully." << endl;
    
}

void Licensed_Telecom_Operator :: Check_Spectrum_Request_Status(string path_spe_req, string path_spe_ran, string path_subs, string path_dec_report){
    Generate_Decision_Report(path_spe_req, path_spe_ran, path_subs, path_dec_report);

    //Print only current company's requests
    string File_Name = path_dec_report;
    ifstream file(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening file: " << File_Name << endl;
    }

    string row;
    while (getline(file, row)) { 

        string date_in_file, company_in_file, location_in_file, requested_spectrum_in_file, operator_in_file, hash_code_in_file, decision_in_file;
        stringstream input_string(row); //To parse the data read into the stringstream
        
        getline(input_string, date_in_file, ','); 
        getline(input_string, company_in_file, ','); 
        getline(input_string, location_in_file, ','); 
        getline(input_string, requested_spectrum_in_file, ','); 
        getline(input_string, decision_in_file, ',');

        //convert company_in_file.substr(0,3) to uppercase
        string com_in_fil = company_in_file.substr(0,3);
        for (int i=0; i<3; i++) {
            com_in_fil[i] = toupper(com_in_fil[i]);
        }

        //If first three letters of company_in_file matches first three letters of user_id 
        if ( com_in_fil == Get_User_Id().substr(0,3)) { 
            cout << "Date: " << date_in_file << endl;
            cout << "Company: " << company_in_file << endl;
            cout << "Location: " << location_in_file << endl;
            cout << "Requested Spectrum: " << requested_spectrum_in_file << endl;
            cout << "Decision: " << decision_in_file << endl;
            cout << endl;
        }

    }

    file.close();
    
}

void Licensed_Telecom_Operator :: View_MVNO_Requests(){
    string File_Name = Path_MVNO_Spectrum;
    ifstream file(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening file: " << File_Name << endl;
    }

    string row;
    while (getline(file, row)) { 

        string date_in_file, MVNOcompany_in_file, location_in_file, requested_spectrum_in_file, operator_in_file, hash_code_in_file, decision_in_file;
        stringstream input_string(row); //To parse the data read into the stringstream
        
        getline(input_string, date_in_file, ','); 
        getline(input_string, MVNOcompany_in_file, ','); 
        getline(input_string, location_in_file, ','); 
        getline(input_string, requested_spectrum_in_file, ','); 
        getline(input_string, operator_in_file, ',');
        getline(input_string, hash_code_in_file, ',');
        getline(input_string, decision_in_file, ',');

        //convert operator_in_file.substr(0,3) to uppercase
        string ope_in_fil = operator_in_file.substr(0,3);
        for (int i=0; i<3; i++) {
            ope_in_fil[i] = toupper(ope_in_fil[i]);
        }

        if (ope_in_fil == Get_User_Id().substr(0,3)) { 
            cout << "Date: " << date_in_file << endl;
            cout << "MVNO Company: " << MVNOcompany_in_file << endl;
            cout << "Location: " << location_in_file << endl;
            cout << "Requested Spectrum: " << requested_spectrum_in_file << endl;
            cout << "Operator: " << operator_in_file << endl;
            cout << "Hash Code: " << hash_code_in_file << endl;
            cout << "Decision: " << decision_in_file << endl;
            cout << endl;
        }

    }

    file.close();
}

void Licensed_Telecom_Operator :: Update_and_Review_Decision_on_MVNO_Requests(){
    string File_Name = Path_MVNO_Spectrum;
    ifstream file(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening file: " << File_Name << endl;
    }

    //Create a temp file
    string temp_file_name = "Data_Modified/temp.csv";
    ofstream temp_file(temp_file_name, ios::app); //Open the file
    if (!temp_file.is_open()) {
        cout << "Error opening file: " << temp_file_name << endl;
    }

    string row;
    while (getline(file, row)) { 

        string date_in_file, MVNOcompany_in_file, location_in_file, requested_spectrum_in_file, operator_in_file, hash_code_in_file, decision_in_file;
        stringstream input_string(row); //To parse the data read into the stringstream
        
        getline(input_string, date_in_file, ','); 
        getline(input_string, MVNOcompany_in_file, ','); 
        getline(input_string, location_in_file, ','); 
        getline(input_string, requested_spectrum_in_file, ','); 
        getline(input_string, operator_in_file, ',');
        getline(input_string, hash_code_in_file, ',');
        getline(input_string, decision_in_file, ',');

        //convert operator_in_file.substr(0,3) to uppercase
        string ope_in_fil = operator_in_file.substr(0,3);
        for (int i=0; i<3; i++) {
            ope_in_fil[i] = toupper(ope_in_fil[i]);
        }


        if ( ope_in_fil == Get_User_Id().substr(0,3)) { 
            if (decision_in_file == "Pending") {
                //Check if the hashcode matches
                if (Check_Valid_HashCode(MVNOcompany_in_file, hash_code_in_file, Path_Login_File)) {
                    // Check if operator has that spectrum frequency
                    if (Check_Valid_Spectrum_Range(operator_in_file, requested_spectrum_in_file, Path_Spectrum_Range)) {
                        //Check if the usage density is lower than the threshold
                        float usage_density = Usage_Density(stof(requested_spectrum_in_file), stof(Get_Subscribers(operator_in_file, location_in_file, Path_Subscribers)));
                        if (Has_Usage_Density(usage_density)) {
                            decision_in_file = "Rejected";
                        } else {
                            decision_in_file = "Approved";
                        }
                    } else {
                        decision_in_file = "Rejected";
                    }
                    
                } else {
                    decision_in_file = "Rejected";
                }
            }

        }
        temp_file << date_in_file << "," << MVNOcompany_in_file << "," << location_in_file << "," << requested_spectrum_in_file << "," << operator_in_file << "," << hash_code_in_file << "," << decision_in_file << endl;
    }

    file.close();
    temp_file.close();

    //Delete the original file
    remove(File_Name.c_str());

    //Rename the temp file
    rename(temp_file_name.c_str(), File_Name.c_str());

    cout << "Decision on MVNO Requests updated and reviewed successfully." << endl;

    //Print Decision
    
    file.open(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening file: " << File_Name << endl;
    }

    while (getline(file, row)) { 

        string date_in_file, MVNOcompany_in_file, location_in_file, requested_spectrum_in_file, operator_in_file, hash_code_in_file, decision_in_file;
        stringstream input_string(row); //To parse the data read into the stringstream
        
        getline(input_string, date_in_file, ','); 
        getline(input_string, MVNOcompany_in_file, ','); 
        getline(input_string, location_in_file, ','); 
        getline(input_string, requested_spectrum_in_file, ','); 
        getline(input_string, operator_in_file, ',');
        getline(input_string, hash_code_in_file, ',');
        getline(input_string, decision_in_file, ',');

        //convert operator_in_file.substr(0,3) to uppercase
        string ope_in_fil = operator_in_file.substr(0,3);
        for (int i=0; i<3; i++) {
            ope_in_fil[i] = toupper(ope_in_fil[i]);
        }

        if ( ope_in_fil == Get_User_Id().substr(0,3)) { 
            cout << "Date: " << date_in_file << endl;
            cout << "MVNO Company: " << MVNOcompany_in_file << endl;
            cout << "Location: " << location_in_file << endl;
            cout << "Requested Spectrum: " << requested_spectrum_in_file << endl;
            cout << "Operator: " << operator_in_file << endl;
            cout << "Hash Code: " << hash_code_in_file << endl;
            cout << "Decision: " << decision_in_file << endl;
            cout << endl;
        }

    }

}


void Licensed_Telecom_Operator :: LTO_Menu(){
    int choice=1, start=1, stop=5;
    do {
        cout << "What do you want to do?" << endl;
        cout << "1. Raise Spectrum Request to TRAI" << endl;
        cout << "2. Check Spectrum Request(s) Status to TRAI" << endl;
        cout << "3. View MVNO Requests for your Spectrum Sharing" << endl;
        cout << "4. Update and Review your Decision on MVNO Requests" << endl;
        cout << "5. Exit" << endl;
        choice = Get_Valid_Choice(start, stop);
            switch (choice) {
            case 1: {
                    cout<< "------------------------------------------"<<endl;
                    cout<< "Raise a Spectrum Request to TRAI: "<<endl;
                    cout<< "------------------------------------------"<<endl;
                    Raise_Spectrum_Request();
                    cout<< "------------------------------------------"<<endl;
                    cout<< "------------------------------------------"<<endl;
                    break;
                    }
            case 2: {
                    cout << "------------------------------------------"<<endl;
                    cout << "Your Spectrum Request(s) to TRAI: "<<endl;
                    cout << "------------------------------------------"<<endl;
                    Check_Spectrum_Request_Status(Path_Spectrum_Requests, Path_Spectrum_Range, Path_Subscribers, Path_Decision_Report);
                    cout << "------------------------------------------"<<endl;
                    cout << "------------------------------------------"<<endl;
                    break;
                    }
            case 3: {
                    cout << "------------------------------------------"<<endl;
                    cout << "MVNO Requests for your Spectrum Sharing: "<<endl;
                    cout << "------------------------------------------"<<endl;
                    View_MVNO_Requests();
                    cout << "------------------------------------------"<< endl;
                    cout << "------------------------------------------"<< endl;
                    break;
                    }
            case 4: {
                    cout << "------------------------------------------"<< endl;
                    cout << "Update and Review your Decision on MVNO Requests: "<<endl;
                    cout << "------------------------------------------"<< endl;
                    Update_and_Review_Decision_on_MVNO_Requests();
                    cout << "------------------------------------------"<< endl;
                    break;
                    }
            case 5: {Exit_Protocol();
                    break;
                    }
            default: {cout << "Invalid choice. Please try again." << endl;
                    break;
                    }
        }
    } while (choice != 5);

}

/*Definition of Mobile_Virtual_Network_Operator*/

void Mobile_Virtual_Network_Operator :: Raise_Spectrum_Sharing_Request(){
    string date = Get_Current_Date();
    cout << "Current Date: " << date << endl;
    string MVNOcompany = Get_User_Id();
    string location = Get_Valid_Circle(list_of_unique_circles_class);
    string request = Get_Valid_Spectrum_Range();
    string LToperator = Get_Valid_Operator(list_of_unique_bidders_class);
    string hashcode = Get_Valid_Hashcode();
    string decision = "Pending";

    string File_Name = Path_MVNO_Spectrum;
    ofstream file(File_Name, ios::app); //Open the file
    if (!file.is_open()) {
        cout << "Error opening file: " << File_Name << endl;
    }

    file << date << "," << MVNOcompany << "," << location << "," << request << "," << LToperator << "," << hashcode << "," << decision << endl;
    file.close();
    cout << "Spectrum Sharing Request raised successfully." << endl;

}

void Mobile_Virtual_Network_Operator :: Check_Spectrum_Sharing_Request_Status( string user_id){
    string File_Name = Path_MVNO_Spectrum;
    ifstream file(File_Name); //Open the file

    if (!file.is_open()) {
        cout << "Error opening file: " << File_Name << endl;
    }

    string row;
    while (getline(file, row)) { 

        string date_in_file, MVNOcompany_in_file, location_in_file, requested_spectrum_in_file, operator_in_file, hash_code_in_file, decision_in_file;
        stringstream input_string(row); //To parse the data read into the stringstream
        
        getline(input_string, date_in_file, ','); 
        getline(input_string, MVNOcompany_in_file, ','); 
        getline(input_string, location_in_file, ','); 
        getline(input_string, requested_spectrum_in_file, ','); 
        getline(input_string, operator_in_file, ',');
        getline(input_string, hash_code_in_file, ',');
        getline(input_string, decision_in_file, ',');

        if (MVNOcompany_in_file == user_id) { 
            cout << "Date: " << date_in_file << endl;
            cout << "MVNO Company: " << MVNOcompany_in_file << endl;
            cout << "Location: " << location_in_file << endl;
            cout << "Requested Spectrum: " << requested_spectrum_in_file << endl;
            cout << "Operator: " << operator_in_file << endl;
            cout << "Hash Code: " << hash_code_in_file << endl;
            cout << "Decision: " << decision_in_file << endl;
            cout << endl;
        }

    }

    file.close();
}

void Mobile_Virtual_Network_Operator :: MVNO_Menu(){
    int choice=1, start=1, stop=3;
    do {
        cout << "What do you want to do?" << endl;
        cout << "1. Raise Spectrum Sharing Request" << endl;
        cout << "2. Check Spectrum Sharing Request Status" << endl;
        cout << "3. Exit" << endl;
        choice = Get_Valid_Choice(start, stop);
        switch (choice) {
        case 1: {
                cout<< "------------------------------------------"<<endl;
                cout<< "Raise a Spectrum Sharing Request: "<<endl;
                cout<< "------------------------------------------"<<endl;
                Raise_Spectrum_Sharing_Request();
                cout<< "------------------------------------------"<<endl;
                break;
                }
        case 2: {
                cout<< "------------------------------------------"<<endl;
                cout<< "Your Spectrum Sharing Request(s): "<<endl;
                cout<< "------------------------------------------"<<endl;
                Check_Spectrum_Sharing_Request_Status(Get_User_Id());
                cout<< "------------------------------------------"<<endl;
                cout<< "------------------------------------------"<<endl;
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

MVNO_Spectrum::MVNO_Spectrum(string date, string MVNOcompany, string location, string request, string LTOperator, string hashcode, string decision){
    this->date = date;
    this->MVNOcompany = MVNOcompany;
    this->location = location;
    this->request = request;
    this->LTOperator = LTOperator;
    this->hashcode = hashcode;
    this->decision = decision;
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

void MVNO_Spectrum::setLTOperator(string LTOperator){
    this->LTOperator = LTOperator;
}

void MVNO_Spectrum::setHashcode(string hashcode){
    this->hashcode = hashcode;
}

void MVNO_Spectrum::setDecision(string decision){
    this->decision = decision;
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

string MVNO_Spectrum::getLTOperator(){
    return LTOperator;
}

string MVNO_Spectrum::getHashcode(){
    return hashcode;
}

string MVNO_Spectrum::getDecision(){
    return decision;
}





