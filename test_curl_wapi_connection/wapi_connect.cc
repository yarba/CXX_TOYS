// to build this (debug), type the following:
// g++ -g wapi_connect.cc -o wapi_connect -lcurl
//
// if you want to build vs non-system curl (custom location), 
// you may want to list all libraries explicitly, e.g.
// g++ -g wapi_connect.cc -o wapi_connect \
// /usr/local/Anaconda3-5.0.1/lib/libcurl.so \ 
// /usr/local/Anaconda3-5.0.1/lib/libssl.so \ 
// /usr/local/Anaconda3-5.0.1/lib/libcrypto.so \ 
// /usr/local/Anaconda3-5.0.1/lib/libssh2.so \


#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>  // will pick up system default
// #include "curl.h" // this way, it'll pick up from location specified with -I
// #include "/usr/local/Anaconda3-5.0.1/include/curl/curl.h"

using namespace std;

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
  ((string*)stream)->append((char*)ptr, 0, size*count);
  return size*count;
}

int main(void) {

  curl_global_init(CURL_GLOBAL_DEFAULT);
  
  CURL* curl = curl_easy_init();

  string response = "";
  string url = "";
 
  if (curl) 
  {

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
    url = "https://g4devel.fnal.gov:8181/WebAPI/get?format=json&record=2"; // secure connection by default
    // url = "http://g4validation.fnal.gov:8080/DoSSiER/WebAPI/get?format=json&record=2"; 
    curl_easy_setopt( curl, CURLOPT_URL, url.c_str() );
    //
    // to disable "secure" access (e.g. via 8181) set to false both (!!!) CURLOPT_SSL_VERIFYPEER and CURLOPT_SSL_VERIFYHOST
    // NOTE: the "PROXY" ones will NOT do anything (i.e. CURLOPT_PROXY_SSL_VERIFYPEER & CURLOPT_PROXY_SSL_VERIFYHOST don't matter)
    // available starting curl v7.52.0
    // 
    // Interactive use on tev.fnal.gov: 
    //     /usr/local/Anaconda3-5.0.1/bin/curl -k "http://g4devel.fnal.gov:8181/WebAPI/get?format=json&record=2" (with quatation marks)
    //
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt( curl, CURLOPT_SSL_VERIFYHOST, 0L );
    
    //char* version = curl_version();
    std::string version( curl_version() );
    std::cout << " CURL VERSION: " << version << std::endl;

    CURLcode ok = curl_easy_perform(curl);
    if ( ok != 0 )
    {
       cout << " BAD CURLcode = " << ok << endl;
       return 0;
    }
    
    cout << " CURLcode = " << ok << " is GOOD " << endl;

    // The "response" variable should now contain the contents of the HTTP response

    cout << response << endl;

    stringstream ss(response.c_str()); 

  }
    
  curl_easy_cleanup(curl);
  
  curl_global_cleanup();

  return 0;

}

