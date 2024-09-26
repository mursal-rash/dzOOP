#include <iostream>
#include <cctype> 

void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther) {
numLetters = 0;
numDigits = 0;
numOther = 0;

while (*str) {
if (std::isalpha(*str)) {
numLetters++;
} else if (std::isdigit(*str)) {
numDigits++;
} else {
numOther++;
}
str++; 
}
}

int main() {
const char* Str1 = "cocojambo656?"; 
int lette = 0, digi = 0, othe = 0;

countLetters(Str1, lette, digi, othe);

std::cout <<  lette << std::endl;
std::cout <<  digi << std::endl;
std::cout <<   othe << std::endl;

return 0;
}
