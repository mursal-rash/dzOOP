#include <iostream>
#include <string>
#include <string_view>

int main() {
    int* intPtr = new int(123);
    std::string* stringPtr = new std::string("Cats and Dogs");
    int* intArray = new int[5]{10, 20, 30, 40, 50};
    std::string* stringArray = new std::string[3]{"Cat", "Dog", "Mouse"};
    std::string_view* stringViewArray = new std::string_view[3]{
        stringArray[0], 
        stringArray[1], 
        stringArray[2]
    };

    std::cout << "Int: " << *intPtr << std::endl;
    std::cout << "String: " << *stringPtr << std::endl;

    std::cout << "Int Array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "String Array: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "String View Array: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << stringViewArray[i] << " ";
    }
    std::cout << std::endl;

    delete intPtr;
    delete stringPtr;
    delete[] intArray;
    delete[] stringArray;
    delete[] stringViewArray;

    return 0;
}
