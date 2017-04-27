#include <iostream>
#include <string>

using namespace std;

string reverseString(string input, int length)
{
    string reversed = "";

    if (length == 1) { // break case
        reversed += input[length - 1];
        return reversed;
    } else { // recursive case
        reversed += input[length - 1];
        reversed += reverseString(input, length - 1);
    }

    return reversed;
}

/*
 * Second function exists to calculate
 * string length automatically.
*/
string rStr(string input) { return reverseString(input, input.length()); }

int main()
{
    /* Iterative implementation
    string input = "Pie";
    int length = input.length();

    while (length > 0) {
        cout << input[length - 1];
        length--;
    }
    */

    int menuChoice;
    do {
        cout << "============================================= \n"
            << "\tA recursive string reverser. \n"
            << "============================================= \n"
            << "\t1. Custom text \n"
            << "\t2. Lorem ipsum \n"
            << "\t0. Exit program \n" << endl;

        while (true) {
            cout << ">> ";
            cin >> menuChoice;

            if (!cin.good() || (menuChoice < 0 || menuChoice > 2)) {
                cout << "Invalid entry. Must choose 1, 2, or 0 to exit." << endl;
                cin.clear();
                cin.ignore(128, '\n');
            } else {
                break;
            }
        }

        cin.ignore();
        string input;
        string reversed;

        switch (menuChoice) {
            case 0:
                cout << "Peyton Seigo, April 2017." << endl;
                return 0;
            case 1:
                cout << "\nEnter a string to reverse: " << flush;
                getline(cin, input);
                reversed = rStr(input);

                cout << "\nORIGINAL STRING: " << input
                    << "\nREVERSED STRING: " << reversed << endl;
                break;
            case 2:
                input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam ac dolor vitae lectus pellentesque accumsan quis non orci. Morbi mollis eros augue, sed tincidunt libero pretium ut. Vivamus quam urna, faucibus sit amet commodo vitae, venenatis eget metus. Sed quis enim eu purus vestibulum sollicitudin.";
                reversed = rStr(input);

                cout << "\nORIGINAL STRING: " << input << endl
                    << "\nREVERSED STRING: " << reversed << endl;
                break;
        }

        cout << '\n';
    } while (menuChoice != 0);
    return 0;
}
