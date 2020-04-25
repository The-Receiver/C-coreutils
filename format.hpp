#include <iostream>
#include <string>

using namespace std;

//Works only if there are no args left
void verify_string(const string str){
    if (str[str.length() - 1] == '%'){
           cout << "\nbad format. Terminating. string:\n" << str << '\n';
           exit(EXIT_FAILURE);
    }   
    for (int i = 0, nexti = 1; i < str.length() - 1; i++, nexti++){
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
    string strbuilder = "";
    verify_string(str);
    for (int i = 0, nexti = 1; i < str.length(); i++, nexti++){
        char c = str[i];
        char n = str[nexti];
        //we know % is escaped
        if ( c == '%' ) {
            strbuilder += '%';
            nexti++;
            i++;
        } else strbuilder += c;
    }  cout << strbuilder;
}
 
template<typename T, typename... argT>
void format(const string str, const T val, const argT... args){
    int nexti = 1;
    for (int i = 0, nexti=1; i < str.length(); i++, nexti++) {
        char c = str[i];
        char n = str[nexti];
	    if (c == '%'){
            switch (n){
                case 'a':
                  cout << val;
                  if (i < str.length() - 2)
                    format(str.substr(nexti + 1, str.length()), args...); 
                  return;
                case 's':
                  cout << val;
                  if (i < str.length() - 2)
                    format(str.substr(nexti + 1, str.length()), val, args...); 
                  return;
                case '%':
                  cout << '%';
                  i++;
                  nexti++;
                  break;
                default:
                  //Error message will not print out full string
                  cout << "\nbad format. Terminating. string:\n" << str << '\n';
                  exit(EXIT_FAILURE);
            }
	    } else  cout << c;
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
 
 

 
