#include "../include/Interface.h"


/*
    Project: Data Structures Project 1
    Authors: Karol Nalepa, Michał Marszałek
    Start date: 14.03.2026
    Submission date:
    Reviewed by: Marta Lampasiak

    Description:
    Main entry point of the application.
    Creates the interface object and starts the main program loop.
    All menu handling and program logic are delegated to the Interface class.
*/




int main() {


    
    Interface app;


    // Hand control to the interactive menu loop.
    app.run();

    return 0;
}
