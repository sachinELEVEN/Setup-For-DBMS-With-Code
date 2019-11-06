#include <iostream>
#include <string>
#include <curl/curl.h> //your directory may be different
#include "SQLFileHandler.cpp"
using namespace std;

bool verifyIfLogin(string);

int login(int );

SQLHandler Handler;

int main()
{
    
   
    string col1 ;
    string col2 ;
    string query;
  
   
    int choice = 0;
   
    cout<<"Login For Students - 1\n";
    cout<<"Login For HOD - 2\n";
    cout<<"Login For Placement System - 3\n";
    cout<<"Login For Company Representative - 4\n";
    
    cout<<"Find Name of the students who have been absent in 2019 - 1\n";
     cout<<"Name the Stduents who were present in DBMS in 2019  - 2\n";
   

    cin>>choice;
    
    

            login(choice);
            
       
     
    
    
}

string ID;
string pass;
int login(int from){
    
   
        
        cout<<"Please Enter LoginID\n";
        cin>>ID;
        cout<<"Please Enter Password\n";
        cin>>pass;
        
        //call to verify if user access is given or not
        switch(from){
            case 1 : verifyIfLogin("Student_P");break;
            case 2 : verifyIfLogin("Company_Rep");break;
            case 3 : verifyIfLogin("Placement_Cell");break;
            case 4 : verifyIfLogin("HOD");break;
            default: cout<<"Wrong Entry";
                
                
                
        }
        
        
     
    return 0;
}


bool verifyIfLogin(string fromTable){
    SQLHandler loginVer;

    loginVer.Address = "http://localhost:8080/LoginVer.php?query=";
    
   string query = "SELECT * FROM "+fromTable+" WHERE sid="+ID+" AND pass = '"+pass+"'";
              string  col1 = "sid";
              string  col2 = "name";
    loginVer.executeQuery(query,col1,col2);
   
    return false;
}
  

//Done6


 
