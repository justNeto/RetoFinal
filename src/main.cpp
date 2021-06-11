#include <iostream>
#include <fstream>
#include <algorithm>
#include "Video.h"
#include "Episode.h"
#include "Movie.h"
#include "Season.h"
#include "Series.h"

using namespace std;

int main() {
    string path;  // Path to the file
    fstream file;
    string line;

    /* Welcome message */
    cout << "| Welcome to our program for reporting about content in X streaming platform |" << endl;
    cout << "| Enter file to load or write EXIT to finish the program |" << endl;

    /*
    Para generar reportes de la informacion de videos, series y peliculas primero se crean los respectivas series y temporadas que se usaran
    */

    while (true) {
        cin >> path;

        if (path == "EXIT") {
            break;
        }

        try {
            file.open(path); // Open the file
            if (!file) {
                throw 404;
            }
        } catch (...) {
            cout << "Please re-enter the path to the file " << endl;
            continue;
        }

        int option;

        cout << "| 1.- Print data information |" << endl;
        cout << "| 2.- Sort series by rating |" << endl;
        cout << "| 3.- Rate a video |" << endl;
        cout << "| 4.- Sort movies by rating |" << endl;
        cout << "| 5.- Exit the program |" << endl;

       while (!(std::cin >> option)) {
           cout << "Please introduce a number" << std::endl;
           cin.clear();
           cin.ignore(100, '\n');
       }

       // Open and get the data from the file - create the necesary structures
       if (option == 1) {
           string st;

           while (getline(file, line)) {
               string type;
               int aux1 = 0;
               int aux2 = 0;
               line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end()); // Erases the current spaces found in the matriz file into lines of strings

               for (int i = 0; i < line.length(); i++) {
                   if (line[i] == '|') {
                       aux1++;
                   } else {
                       st += line[i];
                   }

                   if (aux1 == 2) { // Found the a property
                       // Type of video
                       if (st == "Movie") {
                           type = st; // find the type and interrupt first loop
                       }
                   }
               }

               // After the type is found, do something
               if (type == "Movie") {
                   // Create Movie object
               } else if (type == "Video") {
                   // Create video object
               } else if (type == "Episode") {
                   // Create Episode object
               }
           }

           break;
       } else if (option == 2) {
           break;
       } else if (option == 3) {
           break;
       } else if (option == 4) {
           break;
       } else {
           cout << "Thanks for choosing our streaming service" << endl;
           exit(EXIT_FAILURE);
       }
   }
}
