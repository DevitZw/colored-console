 #include<stdio.h>

 //Escape codes, you can find them online
 #define RED "\x1b[31m"
 #define GREEN "\x1b[32m"
 #define YELLOW "\x1b[33m"
 #define BLUE "\x1b[34m"
 #define MAGENTA "\x1b[35m"
 #define CYAN "\x1b[36m"
 #define GRAY "\x1b[90m"
 
 #define RESET "\x1b[0m"


int main() {

//Remember to use the RESET, otherwise you will not reset the terminal color.
printf(RED "\nThis is a test." RESET);
return 0;
}
