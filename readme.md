### Stuff in C++

#### Echo
usage: echo [ns] args  
Options:  
n: Do not print newline at end  
s: Add space at end of command instead of newline  
todo:  
- fix command-line parsing  

#### Format
usage:  
format string, "%%" for escaped %, "%a" for next argument in list.  
todo:  
- support for an option %s for the same argument as before  
- support for floating-point formatting  
- (optional) support for python-style {0} {1} {n} format specification      
format("%a strings are %a%% cool and nice\n", "format", "100")  


