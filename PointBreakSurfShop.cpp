// PointBreakSurfShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void ShowUsage(); // a function to show the user how to use the program.

void MakePurchase(int& iTotalSmall,
    int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS); // a function to sell surfboards.

void DisplayPurchase(const int iTotalSmall,
    const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS); //  function to show the number of surfboards 
                                                        //of each size sold.

void DisplayTotal(const int iTotalSmall,
    const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS); // a function to show the total amount of money made.
// say no to globals!

// but constants are okay here right?
const int COST_S = 175, COST_M = 190, COST_L = 200, COST_XXXS = 30; // if this is the price of real surfboards...dear god.

int main()
{
    // local variables (since main is technically a function
    const char SEL_S = 'S', SEL_P = 'P', SEL_C = 'C', SEL_T = 'T', SEL_Q = 'Q';
    char usageSelection = 'Z';
    int iTotalSmall = 0, iTotalMedium = 0, iTotalLarge = 0, iTotalXXXS = 0;




    // header
    cout << setw(59) << setfill('*') << "*" << endl; // first part of header

    // the middle part of the header
    cout << setw(4) << setfill('*') << "*" <<
        " Welcome to my Johnny Utah's PointBreak Surft Shop "
        << setw(4) << setfill('*') << "*" << endl;
    // end of the middle part

    cout << setw(59) << setfill('*') << "*" << endl; // last part of header


    cout << endl << endl; // creates two blank lines for next paragraph

    // end of header
     
     
    //getting users input:
    ShowUsage(); // runs the showUsage function.

    while (toupper(usageSelection) != 'Q') { //while start

        //getting input (looped)
        cout << "Please enter selection: ";
        cin >> usageSelection;/// gets the users input.
        // test: cout << usageSelection;
        cout << endl; // onto the next line.

        // switch
        switch (toupper(usageSelection)) { // switch strt
            case SEL_S: ShowUsage(); continue; // runs the showUsage function. 
            case SEL_P: MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS); continue; // runs the MakePurchase function
            case SEL_C: DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS); continue; // runs the DisplayPurchase function.
            case SEL_T: DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS); continue; // runs the DisplayTotal function.
            case SEL_Q: continue; // runs the showUsage function.
            default: continue;


        } // end of switch
    }// end of while

    return 0;
}


    /*while (char inpu != 'Q') {
        switch (std::toupper.input()) {*/
        
        
        
        
        
        
    

// this is the function showUsage, informs the enduser on what they should input in-order to excecute the desires results
// which will in-turn, call on other functions to give them said results.
void ShowUsage() {
    cout << "To show program usage 'S'" << endl;
    cout << "To  purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
} //hi

void MakePurchase(int& iTotalSmall,
    int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS)
{
    
    // constants for this function
    const char SMALL = 'S', MEDIUM = 'M', LARGE = 'L', XXXS = 'X'; // sizes
   

    // local vars for this function
    char type = ' ';
    int qty = 0;

    // ask end user for how many boards they want to purchase and the type
    
    //getting input (looped)
    cout << "Please enter the quanity and type "
        << "(S=small, M=medium, L=large, X=XXXS) of surfboard you" << "\n" << "would like to purchase:";

    cin >> qty ;/// gets the quantity
    cin >> type;/// gets the quantity
    cout << endl; // onto the next line.
    // switch
    switch (toupper(type)) { // switch strt (calculates the cost
    case SMALL: iTotalSmall += (COST_S * qty); break;
    case MEDIUM: iTotalMedium += (COST_M * qty); break;
    case LARGE: iTotalLarge += (COST_L * qty); break;
    case XXXS: iTotalXXXS += (COST_XXXS * qty); break;
    default: break;


    } // end of switch
    


    //iTotalSmall += 



} // a function to sell surfboards.

void DisplayPurchase(const int iTotalSmall,
    const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{   // divides cost by cost per, to get the qty ordered.
    if (iTotalXXXS != 0)
        cout << "The total number of XXXS surfboards (For the squirrel) is " << iTotalXXXS / COST_XXXS << endl;
    if (iTotalSmall != 0)
        cout << "The total number of small surfboards is "<< iTotalSmall/COST_S << endl;
    if (iTotalMedium != 0)
        cout << "The total number of medium surfboards is " << iTotalMedium/COST_M << endl;
    if (iTotalLarge != 0)
        cout << "The total number of large surfboards is " << iTotalLarge / COST_L << endl;
        


} //  function to show the number of surfboards 
  //  of each size sold.

void DisplayTotal(const int iTotalSmall,
    const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{// runs these if statements IF there is a balance for each type of board respectively. prints out the summary regardless
    // of what  was order and what was not at the end.
    double lrg, sml, med, xtrasml, tots; // placeholders for the values cconstant values so preceision and showpoints will work. Tots is the total
    lrg = iTotalLarge; // assiging values to placeholders
    sml = iTotalSmall;
    med = iTotalMedium;
    xtrasml = iTotalXXXS;
    tots = ((double) iTotalLarge + iTotalMedium + iTotalSmall + iTotalXXXS); // calculating totala
    cout << fixed;
    if (iTotalSmall != 0)
        cout << "The total number of small surfboards is " << iTotalSmall / COST_S << " at $" << showpoint << setprecision(2) << sml <<endl;
    if (iTotalMedium != 0)
        cout << "The total number of medium surfboards is " << noshowpoint <<
        iTotalMedium / COST_M << " at $" << showpoint << setprecision(2) << med << endl;
    if (iTotalLarge != 0)
        cout << "The total number of large surfboards is " << noshowpoint <<
        iTotalLarge / COST_L << " at $"  << showpoint << setprecision(2) << lrg << endl;
    if (iTotalXXXS != 0)
        cout << "The total number of XXXS surfboards is " << noshowpoint <<
        iTotalXXXS / COST_XXXS << " at $" << showpoint << setprecision(2) << xtrasml << endl;
    cout << "Amount due: $" << showpoint << setprecision(2)  << tots << endl;


} // a function to show the total amount of money made.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
