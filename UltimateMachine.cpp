#include <iostream>

// Definition of the CUltimateMachine class
class CUltimateMachine {
public:
    // Constructor
    CUltimateMachine() : m_bState(false) {
        std::cout << "CUltimateMachine constructor (ctor) called" << std::endl;
    }

    // Destructor
    ~CUltimateMachine() {
        std::cout << "CUltimateMachine destructor (dtor) called" << std::endl;
    }

    // Display the current state of the machine
    void displayState() const {
        if (m_bState)
            std::cout << "Ultimate Machine is ON" << std::endl;
        else
            std::cout << "Ultimate Machine is OFF" << std::endl;
    }

    // Function to turn on the machine
    void turnOn() {
        m_bState = true;  // Turn the machine on
        displayState();   // Display the state after turning on
        m_bState = false; // Immediately turn the machine off
        displayState();   // Display the state after turning off
    }

private:
    bool m_bState; // State of the machine: true is on, false is off
};

// Main function
int main() {
    std::cout << "The Ultimate Machine Simulation" << std::endl;
    CUltimateMachine ultMachine;  // Create an instance of the Ultimate Machine
    ultMachine.displayState();    // Display initial state (should be off)
    ultMachine.turnOn();          // Simulate turning the machine on
    return 0;
}
