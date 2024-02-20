#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile( string& filename, vector<string>& names, vector<int>& scores, vector<char> &grades) {
    ifstream file;
    file.open(filename);
    string textline;
    while(getline(file,textline)){
        
        char format[] = "%[^:]: %d %d %d";
        char name[100];
        int a,b,c;
        sscanf(textline.c_str(),format,name,&a,&b,&c);
        names.push_back(name);
        scores.push_back(a+b+c);
        grades.push_back(score2grade(a+b+c));
        
    
    }
    }

void getCommand(string &command, string &key){
    cout << "Please input your command: ";
    cin >> command;
    string x;
    x = toUpperStr(command);
    if (x == "EXIT"){
        return;

    }
    else if(x =="GRADE" )
    {   
        
        cin >> key;
        }
    else if(x =="NAME"){
        cin.ignore();
        getline(cin,key);
    }


}

void searchName(const vector<string>& names, const vector<int>& scores, const vector<char>& grades, const string& key){

    bool found = false;
    for (size_t i = 0; i < names.size(); ++i) {
        if (toUpperStr(names[i]) == key) {
            found = true;
            cout << "---------------------------------"<<endl;
            cout << names[i] << "'s score = "  << scores[i] << endl << names[i] <<"'s grade = " << grades[i] << endl;
            cout << "---------------------------------\n";

        }
    }
    if (!found){
        cout << "---------------------------------"<<endl;
        cout << "Cannot found." << endl;
        cout << "---------------------------------\n";
    }
    }

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    bool found = false;
    cout<<"---------------------------------\n";
    for (size_t i = 0; i < grades.size(); i++) {
        if (grades[i] == key[0]) {
            found = true;
            
            cout <<  names[i] << " " << "(" << scores[i] << ")" << endl;
            
        }
    }
    
    if (!found){

        cout << "Cannot found." << endl;
    }
    cout<<"---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}