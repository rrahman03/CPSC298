#include <iostream>
#include <fstream>
#include <string>

class CentralPolygonalNumbers {
public:
    // default constructor
    CentralPolygonalNumbers() : m_nMax(0) {
        mp_iNumbers = new int[m_nMax + 1];  // allocate space for one number
        mp_iNumbers[0] = 1;  // the first number in the sequence when n = 0
    }

    // parameterized constructor
    CentralPolygonalNumbers(int nMax) : m_nMax(nMax) {
        mp_iNumbers = new int[m_nMax + 1];  // allocate memory
        mp_iNumbers[0] = 1;  // start of the sequence
        int p = 1;  // initialize the first piece count
        for (int n = 1; n <= m_nMax; ++n) {
            p += n;  // compute the next piece count
            mp_iNumbers[n] = p;  // store it in the array
        }
    }

    // destructor
    ~CentralPolygonalNumbers() {
        delete[] mp_iNumbers;  
        std::cout << "~CentralPolygonalNumbers called" << std::endl;
    }

    // display sequence
    void display() {
        for (int i = 0; i <= m_nMax; ++i) {
            std::cout << "n: " << i << ", maximum number of pieces: " << mp_iNumbers[i] << std::endl;
        }
    }

    // save sequence to a file
    bool save(const std::string& strFilename) {
        std::ofstream outFile(strFilename + ".txt");
        if (!outFile) {
            std::cerr << "Error opening file for output." << std::endl;
            return false;
        }
        for (int i = 0; i <= m_nMax; ++i) {
            outFile << mp_iNumbers[i] << (i != m_nMax ? ", " : "");
        }
        outFile.close();
        return true;
    }

private:
    int m_nMax;
    int* mp_iNumbers;
};
