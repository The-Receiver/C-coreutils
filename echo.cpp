#include<iostream> 
#include<getopt.h>

void print_usage(){
    std::cout << "Usage: echo [ns] <args>\n";
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]){
    
  bool space = false;
  bool newline = true; // toggle output of newline; 
  //incoming option
  char option;
  //do not print program name
  int optind = 1;
  while ((option = getopt(argc, argv, "ns:"))  != EOF){
      switch (option){
          case ('n'):
            newline = false;
            optind++; break;
          case ('s'):
            if (newline == true){
                std::cout << "error: -s option must be used with -n\n";
                exit(EXIT_FAILURE);
            }
            space = true; 
            optind++; break; 
          default:
            break;
      }
  }
  if (argc == 1){
      print_usage();
  } else{
    for (int i = optind; i < argc - 1; i++) 
        std::cout << argv[i] << " ";

    std::cout << argv[argc -1];
    if (newline) std::cout << '\n';
    if (space) std::cout << " ";     
  }
}
