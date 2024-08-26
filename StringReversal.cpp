#include <iostream>

void StringReversal(char* str);

using namespace std;
// String Reversal
int main(){
    char s[] = "mm #@ menna";
    char empty[] = "";
    StringReversal(s);
    StringReversal(empty);
    StringReversal(nullptr);
    return 0;
}
void StringReversal(char* str){
    // Handle null pointer
    if (str == nullptr) {
    cout << "empty pointer!";
    return;
    }
    // Handle empty string
    if (*str == '\0') {
        cout << "Empty string!" << endl;
        return;
    }
    char* start = str;
    char* end = str;
    // Move end to the last character
    while (*end != '\0') {
        ++end;
    }
    --end; // Adjust to the last character
    
    // Swap characters
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
    cout << "reversed string: ";
    while (*str != '\0') {
        cout <<*str;
        str++;
        }
    cout << endl;
}
