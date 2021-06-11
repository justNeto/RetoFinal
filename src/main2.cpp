#include <iostream>
#include <fstream>
#include <algorithm>
#include "Video.h"
#include "Episode.h"
#include "Movie.h"
#include "Season.h"
#include "Series.h"

using namespace std;

int main () {
    /* Welcome message */
    cout << "| Welcome to our program for reporting about content in X streaming platform |" << endl;
    cout << "| Enter file to load or write EXIT to finish the program |" << endl;

    vector <Episode> lista;
    vector <Movie> cartelera;

    cartelera.push_back(Movie("Denis Villeneuve", "BR47", "Blade Runner 2049", "Action", 164, 2017, vector <double> {4,3.5,4}));
    cartelera.push_back(Movie("Joseph Kosinski", "TR02", "Tron: Legacy", "Action", 127, 2010, vector <double> {3.4,2.8,2.1}));
    cartelera.push_back(Movie("Joe Russo, Anthony Russo", "EG04", "Avengers: Endgame", "Action", 182, 2019, vector <double> {4.2}));

    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());
    lista.push_back(Episode());

    vector <Episode> s1 = {lista[5], lista[6], lista[7]};
    vector <Episode> s2= {lista[8], lista[9], lista[10]};


    while (true) {
        int option;

        cout << "| 1.- Load files |" << endl;
        cout << "| 2.- Show videos by rating or genre |" << endl;
        cout << "| 3.- Show episodes of series by rating |" << endl;
        cout << "| 4.- Show movies by rating |" << endl;
        cout << "| 5.- Rate a movie |" << endl;
        cout << "| 0.- Exit the program |" << endl;

        while (!(std::cin >> option)) {
            cout << "Please introduce a number" << std::endl;
            cin.clear();
            cin.ignore(100, '\n');
        }

        if (option == 0) {
            cout << "Thanks for choosing our streaming service" << endl;
            break;
        } else if (option == 1) {
            // TODO
        } else if (option == 2) {
            cout << "How would you like to sort all videos? By genre (0) or rating (1)?" << endl;
            int opt;
            try {
                while (!(std::cin >> opt)) {
                    cout << "Please introduce a number" << std::endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }                
                // Input should be wither 1 or 0
                if (opt != 0 && opt != 1) {
                    throw "Error: No valid response was received.";
                }
            } catch (const char* msj) {
                cout << msj << endl;
            }

            if (opt == 0) {
                cout << "What genre are you looking for in the videos?" << endl;
                string genre;
                while (!(std::cin >> genre)) {
                    cout << "Please introduce a genre" << std::endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                int index = 1;
                for (Movie m : cartelera) {
                    if (m.getGenre() == genre) {
                        cout << index << ".- (Movie) " << m.getName() << endl;
                        index++;
                    }
                }
                for (Episode e : lista) {
                    if (e.getGenre() == genre) {
                        cout << index << ".- (Episode) " << e.getName() << endl;
                        index++;
                    }
                }
            } else if (opt == 1) {
                cout << "What rate are you looking for in the videos?" << endl;
                int rate;
                // Rate to look for must be between 0 and 5
                try {
                    while (!(std::cin >> rate)) {
                        cout << "Please introduce a number" << std::endl;
                        cin.clear();
                        cin.ignore(100, '\n');
                    }                
                    // When an index not registered is input
                    if (rate > 5) {
                        throw "Error: No video can have a rate higher than 5.";
                    }
                } catch (const char* msj) {
                    cout << msj << endl;
                    break;
                }
                int index = 1;
                for (Movie m : cartelera) {
                    if (m.getScore() > rate) {
                        cout << index << ".- (Movie) " << m.getName() << endl;
                        index++;
                    }
                }
                for (Episode e : lista) {
                    if (e.getScore() > rate) {
                        cout << index << ".- (Episode) " << e.getName() << endl;
                        index++;
                    }
                }
            }

        } else if (option == 3) {
            
        } else if (option == 4) {
            cout << "What rate are you looking for in the movies?" << endl;
            int rate;

            // Rate to look for must be between 0 and 5
            try {
                while (!(std::cin >> rate)) {
                    cout << "Please introduce a number" << std::endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }                
                // When an index not registered is input
                if (rate > 5) {
                    throw "Error: No video can have a rate higher than 5.";
                }
            } catch (const char* msj) {
                cout << msj << endl;
                break;
            }

            for (Movie m : cartelera) {
                if (m.getScore() >= rate) {
                    m.print();
                    cout << "//////" << endl;
                }
            }

        } else if (option == 5) {
            cout << "These are the movies to rate:\nChose one please." << endl;
            int i = 1;
            int index;
            double score;
            for (Movie m : cartelera) {
                cout << i << ".- " << m.getName() << endl;
                // m.print();
                i++;
            }

            // Index to choose must be within bounds
            try {
                while (!(std::cin >> index)) {
                    cout << "Please introduce a number" << std::endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }                
                // When an index not registered is input
                if (index > i) {
                    throw "Error: Index out of bounds.";
                }
            } catch (const char* msj) {
                cout << msj << endl;
                break;
            }
            
            cout << "How would you rate the movie?" << endl;
            // Rate to give must be bewtween 0 and 5
            try {
                while (!(std::cin >> score)) {
                    cout << "Please introduce a number" << std::endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }                
                // When a score is higher than expected
                if (score > 5) {
                    throw "Error: Rate between 1 and 5.";
                }
            } catch (const char* msj) {
                cout << msj << endl;
                break;
            }

            cartelera[index-1].addScore(score);
            cout << "Review added, this movie now has a score of: " << cartelera[index-1].getScore() << endl;
        }
    }
}