#include <iostream>
#include <string>

using namespace std;

// PART 1
int main() {
    // Step 1: Define Variables:
    const char k_cAuthenticatorCodeCharacter1 = 'E';
    const char k_cAuthenticatorCodeCharacter2 = 'C';
    const char k_cAuthenticatorCodeCharacter3 = 'A';
    char input1, input2, input3;
    string messageCode = "", authenticatorCode = "";

    // Step 2: Prompt the user
    std::cout << "Enter the first character of the message code: " << std::endl;;
    std::cin >> input1;
    std::cout << "Enter the second character of the message code: " << std::endl;;
    std::cin >> input2;
    std::cout << "Enter the third character of the message code: " << std::endl;;
    std::cin >> input3;

    // Step 3: Concatenate characters and display
    messageCode += input1;
    messageCode += input2;
    messageCode += input3;
    authenticatorCode += k_cAuthenticatorCodeCharacter1;
    authenticatorCode += k_cAuthenticatorCodeCharacter2;
    authenticatorCode += k_cAuthenticatorCodeCharacter3;

    std::cout << std::endl;
    std::cout << "Authenticator Code: " << authenticatorCode << std::endl;
    std::cout << "Message Code: " << messageCode << std::endl;
    

    // PART 2
    // Reporting the Authenticity of the Code Using Character by Character Comparison
    bool authentic = true;
    if (!(input1 == k_cAuthenticatorCodeCharacter1 &&
          input2 == k_cAuthenticatorCodeCharacter2 &&
          input3 == k_cAuthenticatorCodeCharacter3)) {
        authentic = false;
    }

    if (authentic) {
        std::cout << std::endl;
        std::cout << "Message is authentic." << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Message is invalid." << std::endl;
    }

    // PART 3
    // Reporting the Authenticity of the Code Using String Comparison
    if (messageCode == authenticatorCode) {
        std::cout << "Concurrence: message is authentic." << std::endl;
    } else {
        std::cout << "Concurrence: message is invalid." << std::endl;
    }
    
    // PART 4
    // Characterizing the Received Message Code
    // Step 1: Declare and instantiate checksum to 0, then compute it as shown in the box below
    int checksum = (int(input1) + int(input2) + int(input3)) % 7;
    // Step 2: Create a constant checksum integer value called k_iValidCodeCheckdum
    const int k_iValidCodeChecksum = 5;

    // Step 3: checksum to k_iValidCodeCheckdum and display message
    //if (checksum == k_iValidCodeChecksum) {
    //    std::cout << "Message Code Checksum is valid." << endl;
    //} else {
    //    std::cout << "Message Code Checksum is invalid." << endl;
    //}

    // Step 4: Display the ASCII values of each character and sum
    std::cout << std::endl;
    std::cout << "Characterization of Message Code\n";
    std::cout << "---------------------------------\n";
    std::cout << "ASCII Values of Message Code Characters: ";
    std::cout << int(input1) << ", " ;
    std::cout << int(input2) << ", " ;
    std::cout << int(input3) << std::endl;

    int sum = int(input1) + int(input2) + int(input3);
    std::cout << "Sum of ASCII values for Message Code Characters: " << sum << std::endl;

    // Step 3: checksum to k_iValidCodeCheckdum and display message
    if (checksum == k_iValidCodeChecksum) {
        std::cout << "Message Code Checksum is valid: " << k_iValidCodeChecksum << endl;
    } else {
        std::cout << "Message Code Checksum is invalid." << endl;
    }

    // Step 5: Report which pairs don’t match, use != in branch condition
    if (input1 != k_cAuthenticatorCodeCharacter1) {
        cout << "First characters do not match: Message " << input1 << "; Authenticator " << k_cAuthenticatorCodeCharacter1 << endl;
    }
    if (input2 != k_cAuthenticatorCodeCharacter2) {
        cout << "Second characters do not match: Message " << input2 << "; Authenticator " << k_cAuthenticatorCodeCharacter2 << endl;
    }
    if (input3 != k_cAuthenticatorCodeCharacter3) {
        cout << "Third characters do not match: Message " << input3 << "; Authenticator " << k_cAuthenticatorCodeCharacter3 << endl;
    }

     // Step 6: Compare if message code and Authenticator strings do not match using > and <
    if (messageCode < authenticatorCode) {
        cout << "Message code (CKB) is lexicographically less than the Authenticator code (ECA)." << endl;
    } else if (messageCode > authenticatorCode) {
        cout << "Message code (NSA) is lexicographically greater than the Authenticator code (ECA)." << endl;
    }

    return 0;
}