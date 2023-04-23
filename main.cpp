#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    string filePath;
    char buffer[4];

    cout << "Enter the path to the file: ";
    cin >> filePath;
    cout << endl;

    fin.open(filePath, std::ios::binary);
    if (!fin.is_open()) {
        cerr << "Error! File is not open!";
        return 1;
    } else {
        fin.read(buffer, 4);
        if (buffer[0] == (char) -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') {
            cout << "This file is PNG-file!" << endl;
        } else {
            cerr << "This file is not a PNG-file!" << endl;
            fin.close();
            return 1;
        }

    }

    fin.close();
    return 0;
}
