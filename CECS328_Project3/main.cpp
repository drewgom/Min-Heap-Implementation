// Name: Andrew Gomez
// Class: CECS328
// Project: Project 3

#include <iostream>
#include "MenuOption.hpp"
#include "Implementations.hpp"
#include "Timer.hpp"
#include "Menu.hpp"
#include "Heap.hpp"


using namespace std;

int main() {
    string proj_3_description = "HEAP IMPLEMENATION";
    string proj_3_intruction = "Please enter the number of your desired menu option:";
    
    // The descriptions of each menu


    string step_1_description = "Display your heap";
    string step_2_description = "Create an empty min heap";
    string step_3_description = "Creates a min heap using user entered data";
    string step_4_description = "Generate a random heap";
    string step_5_description = "Insert your to your current heap";
    string step_6_description = "Pop an element off the heap";
    string step_7_description = "Run the Heap Sort Agorithm";
    string quit_description = "Quits the program";

    MenuOption op1(step_1_description, &Step1);
    MenuOption op2(step_2_description, &Step2);
    MenuOption op3(step_3_description, &Step3);
    MenuOption op4(step_4_description, &Step4);
    MenuOption op5(step_5_description, &Step5);
    MenuOption op6(step_6_description, &Step6);
    MenuOption op7(step_7_description, &Step7);
    MenuOption op8(quit_description, &Quit);
    
    // Creates a list of all the menu options
    MenuOption listOfOptions[] = {op1, op2, op3, op4, op5, op6, op7, op8};
    // Makes a new table object
    Menu Project3Menu(3, proj_3_description, proj_3_intruction, 8, listOfOptions);
    Project3Menu.display_menu();
    
    return 0;
}
