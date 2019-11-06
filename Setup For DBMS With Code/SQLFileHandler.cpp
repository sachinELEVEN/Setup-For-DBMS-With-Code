//
//  SQLFileHandler.cpp
//  SailorBoat
//
//  Created by sachin jeph on 02/11/19.
//  Copyright © 2019 sachin jeph. All rights reserved.
//



#include <iostream>
#include<string>


#include <curl/curl.h> //your directory may be different
using namespace std;

string data; //will hold the url's contents

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer

    for (int c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}


class SQLHandler{

     public:
    string Address = "http://localhost:8080/SQLHandlerF1.php?query=";
    
    
    

  
   
    
    SQLHandler(string Addr){
        Address = Addr;
    }
    
    SQLHandler(){
        
    }
    
 int executeQuery(string query,string Col1="", string Col2=""){
        

             CURL* curl; //our curl object

             curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
             curl = curl_easy_init();

          
      //  string str1 = "http://localhost:8080/P1Bank.php?query=SELECT*FROM%20customer&col1=ifsc";
         string str1 = Address + query;
        string str2 = "&col1="+Col1+"&col2="+Col2+"";
        string str = str1 + str2;
        
        str = replaceSpaces(str);
           
             int n = str.length();
             char urlStr[n+1];
             
         
         
             strcpy(urlStr, str.c_str());
           
             curl_easy_setopt(curl, CURLOPT_URL,urlStr);//char *
          
     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
             curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

             curl_easy_perform(curl);
         cout<<"\n *******************************************************************************************************\n";
        
             cout<<"\n *******************************************************************************************************";
        
             cout<<"\n\n";
        
        //Response of the query
             cout << endl << data << endl;
             cin.get();

             curl_easy_cleanup(curl);
             curl_global_cleanup();

             return 0;
    }
    
    
    private  :
    
    string replaceSpaces(string str){
      
        for(int i = 0; i<str.length();++i){
            if (str[i] == ' '){
              str.replace(i,1,"%20");
                i+=3;
            }
        }
        
        return str;
        
    }
    
    

    
    
};
//Done1
