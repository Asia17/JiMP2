//
// Created by Joanna on 04.03.2018.
//

#include <string>
#include <iostream>
#include <fstream>
#include <Polybius.h>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        exit(1);
    }

    string input_fname = argv[1];
    string input_ofname = argv[2];
    int encrypt = atoi(argv[3]);     // encrypt = 1, decrypt = 0

    ifstream input_file(input_fname); // input == wczytywanie z pliku
    ofstream output_file(input_ofname); // output == zapisywanie

    char letter;
    char wyraz;
    if(!input_file)
        cout << "Nie można otworzyć pliku!" << endl; // dodac obsluge exit
        //exit(1);

    if (encrypt == 1) {
        string message = "";
        while (input_file >> letter) {
            cout << letter;
            message += letter;
        }
        string encrypted = PolybiusCrypt(message);
        output_file << encrypted;
    }
    else {
        string zaszyfrowane = "";
        while (input_file >> wyraz) {
            cout << wyraz;
            zaszyfrowane += wyraz;
        }
        string mess_odszyfrowana = PolybiusDecrypt(zaszyfrowane);
        output_file << mess_odszyfrowana;
    }

    input_file.close();
    output_file.close();

    return 0;
}