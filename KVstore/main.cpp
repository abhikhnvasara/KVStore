//
//  main.cpp
//  test
//
//  Created by Abhijit Khinvasara on 1/28/15.
//  Copyright (c) 2015 Swacho Inc. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>


using namespace std;
typedef map<string, int> kv_map;

void setToKVStore(kv_map &db, const vector<string> &input)
{
    string key=input[1];
    int value=stoi(input[2]);
    
    db[key] = value;
    cout << "key=>" << key << " value=>" << db[key] << " added" << endl;
}

void getFromKVStore(kv_map &db, string key)
{
    cout << "key: " << key << endl;
    int val = db[key];
    
    if (val)
        cout << val << endl;
    else
        cout << "Not found!!" << endl;
}

void printKVStore(kv_map &db)
{
    for (kv_map::iterator it = db.begin(); it != db.end(); ++it)
        cout << it->first << " => " << it->second << endl;
}

int main(int argc, const char * argv[]) {
    
    kv_map db;
    string operation;
    
    
    while(1){
        
        /* Get the command */
        string commandline_input;
        cout << "operation (get/set/delete/count/print/begin/commit/rollback/q): ";
        getline(cin, commandline_input);
        
        /* split the line in vector of strings */
        istringstream iss(commandline_input);
        string ss;
        int i=0;
        vector <string> input;
        
        while (getline(iss, ss, ' '))
        {
            input.push_back(ss);
            //cout << input[i++] << endl;
            i++;
        }
        
        operation = input[0];
        
        /* Do the workbased on command */
        if (operation == "set")
            setToKVStore(db, input);
        
        else if (operation == "get")
            getFromKVStore(db, input[1]);
        
        else if (operation == "print")
            printKVStore(db);
        
        else if (operation == "q")
            break;
        
    }
    return 0;
}