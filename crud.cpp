#include <iostream>   // Provides input/output functionality.
#include <iomanip>    // Provides formatting tools for output.
#include <fstream>		//Allows reading from and writing to files.
#include <sstream>    //Allows working with strings 
#include <limits>  // Include limits for numeric_limits
using namespace std;

int main() {
    int check = 1, repeat = 1;
    string name, str;
    int age;
    fstream fin, fout;

    while (repeat == 1) {
        cout << "Press 1 to enter data in the record." << endl;
        cout << "Press 2 to delete an entry in the record." << endl;
        cout << "Press 3 to update an entry in the record." << endl;
        cout << "Press 4 to view data." << endl;
        cin >> check;

        // Add data to the file
        if (check == 1) {
            fout.open("data.csv", ios::app);
            if (!fout) {
                cerr << "Error opening file!" << endl;
                return 1;
            }
            int repeatInput = 1;
            while (repeatInput == 1) {
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                fout << name << "," << age << endl;
                cout << "To add more data press (1), to exit press any other key: ";
                cin >> repeatInput;
            }
            fout.close();
        }

        // Delete data from the database
        else if (check == 2) {
            string sname, dname;
            cout << "Enter the name you want to delete: ";
            cin.ignore();
            getline(cin, dname);

            fin.open("data.csv", ios::in);
            fout.open("data_temp.csv", ios::out);

            if (!fin || !fout) {
                cerr << "Error opening file!" << endl;
                return 1;
            }

            while (getline(fin, str)) {
                stringstream ss(str);
                getline(ss, sname, ',');
                getline(ss, str, ',');
                if (sname != dname) {
                    fout << sname << "," << str << endl;
                }
            }

            fin.close();
            fout.close();
            remove("data.csv");
            rename("data_temp.csv", "data.csv");
        }

        // Update data in the database
        else if (check == 3) {
            string uname, updated_name;
            int updated_age;
            cout << "Enter the name you want to update: ";
            cin.ignore();
            getline(cin, name);

            fin.open("data.csv", ios::in);
            fout.open("data_temp.csv", ios::out);

            if (!fin || !fout) {
                cerr << "Error opening file!" << endl;
                return 1;
            }

            while (getline(fin, str)) {
                stringstream ss(str);
                getline(ss, uname, ',');
                getline(ss, str, ',');
                if (uname == name) {
                    cout << "Enter new name: ";
                    getline(cin, updated_name);
                    cout << "Enter new age: ";
                    cin >> updated_age;
                    fout << updated_name << "," << updated_age << endl;
                } else {
                    fout << uname << "," << str << endl;
                }
            }

            fin.close();
            fout.close();
            remove("data.csv");
            rename("data_temp.csv", "data.csv");
        }

        // View data from the database
        else if (check == 4) {
            string dis_name, dis_age;
            fin.open("data.csv", ios::in);
            if (!fin) {
                cerr << "Error opening file!" << endl;
                return 1;
            }

            cout << setw(15) << left << "Name" << "  Age" << endl;
            while (getline(fin, str)) {
                stringstream ss(str);
                getline(ss, dis_name, ',');
                getline(ss, dis_age, ',');
                cout << setw(15) << left << dis_name << "  " << dis_age << endl;
            }
            fin.close();
        }

        // Validate input for repeat to prevent infinite loop
        cout << "Press 1 if you want to alter it further, press any other key to exit: ";
        if (!(cin >> repeat)) {
            // Clear the error flag on cin in case of invalid input
            cin.clear();
            // Ignore invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            repeat = 0; // Exit the loop
        }
    }

    cout << endl << "Thank you for using our database :)" << endl;
    return 0;
}


