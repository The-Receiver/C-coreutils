#include <iostream>
#include <string>

using namespace std;

#include <iostream>

void verify_string(const string str){

    int nexti = 1;
   
    for (int i = 0; i < str.length(); i++){
        if (i == str.length() - 1 && str[i] == '%') {
            cout << "\nbad format. Terminating. string:\n" << str << '\n';
            exit(EXIT_FAILURE);
        }
        char c = str[i];
        char n = str[nexti];
        if (c == '%' && n != '%') {
            cout << "\nbad format. Terminating. string:\n" << str << '\n';
            exit(EXIT_FAILURE);
        } else if (c == '%'){
            i++;
            nexti++;
        }   nexti++;
    }
}
 
void format(const string str){
    int nexti = 1;
    string strbuilder = "";
    verify_string(str);
    for (int i = 0; ; i++){
        char c = str[i];
        if (i == str.length()){
            cout << strbuilder;
            return;
        }
        char n = str[nexti];
        if ( c == '%' && n == '%') {
            strbuilder += '%';
            nexti++;
            i++;
        } else strbuilder += c;
        nexti++; 
    }
}
 
template<typename T, typename... argT>
void format(const string str, const T val, const argT... args){
    int nexti = 1;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        char n = str[nexti];
        if ( c == '%' && n == 'a') {
            cout << val;
            if (i < str.length() - 2) {
                format(str.substr(nexti + 1, str.length()), args...); 
                return;
            }
            return;
        } else if (c == '%' && n == '%'){
            cout << '%';
            i++;
            nexti++;
        } else cout << c;
        nexti++;
    }
}

template<typename T, typename... argT>
void formatln(const string str, const T val, const argT... args){
    format(str, val, args...);
    cout << '\n';
}

void formatln(const string str){
    format(str);
    cout << '\n';
}
 
 

 