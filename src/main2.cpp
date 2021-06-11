#include <iostream>
#include <fstream>
#include <algorithm>
#include "Video.h"
#include "Episode.h"
#include "Movie.h"
#include "Season.h"
#include "Series.h"
#include "Cartelera.h"

using namespace std;

int main () {
    /* Welcome message */
    cout << "| Welcome to our program for reporting about content in X streaming platform |" << endl;
    cout << "| Enter file to load or write EXIT to finish the program |" << endl;

    Cartelera c = Cartelera();
    c.addEpisode(Movie("Denis Villeneuve", "BR47", "Blade Runner 2049", "Action", 164, 2017, vector <double> {4,3.5,4}));
    c.addEpisode(Movie("Joseph Kosinski", "TR02", "Tron: Legacy", "Action", 127, 2010, vector <double> {3.4,2.8,2.1}));
    c.addEpisode(Movie("Joe Russo, Anthony Russo", "EG04", "Avengers: Endgame", "Action", 182, 2019, vector <double> {4.2}));

    vector <Episode> lista;
    vector <Series> programas;

    lista.push_back(Episode("E", "01234", "Casa de los Dibujos",  "Comedy", 10, vector <double> {4,5,4}));
    lista.push_back(Episode("E", "03745", "Lo que se",  "Thriller", 10, vector <double> {3.2,4.2,4}));
    lista.push_back(Episode("E", "92834", "Black Noir",  "Drama", 10, vector <double> {2.3,5,4}));
    lista.push_back(Episode("E", "12643", "Nada igual en el mundo",  "Drama", 10, vector <double> {4,5,4}));
    lista.push_back(Episode("E", "01234", "Carnicero, panadero, eres un buen compañero",  "Drama", 10, vector <double> {3.9,3.6,4.1}));
    lista.push_back(Episode("R", "37263", "Los Heroes",  "Action", 10, vector <double> {4,5,4}));
    lista.push_back(Episode("R", "01234", "Estrella",  "Action", 10, vector <double> {3,3,4}));
    lista.push_back(Episode("R", "03482", "Homelander",  "Action", 10, vector <double> {1,3,5}));
    lista.push_back(Episode("R", "01234", "Arrogante",  "Action", 10, vector <double> {4,2.4,4}));
    lista.push_back(Episode("R", "01234", "La Hembra",  "Action", 10, vector <double> {4,3.5,5}));
    lista.push_back(Episode("R", "34052", "Final",  "Action", 10, vector <double> {3,5,4}));

    vector <Episode> s1 = {lista[5], lista[6], lista[7]};
    vector <Episode> s2 = {lista[8], lista[9], lista[10]};

    Season seas1 = Season(s1,false,3);
    Season seas2 = Season(s2,true,3);

    vector <Season> seasons;
    seasons.push_back(seas1);
    seasons.push_back(seas2);

    Series theB = Series("The Boys", seasons, true);
    programas.push_back(theB);


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
        } 
        else if (option == 1) {
            // TODO
        } 
        else if (option == 2) {
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
                for (Movie m : c.getList()) {
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
            } 
            else if (opt == 1) {
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
                for (Movie m : c.getList()) {
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

        } 
        else if (option == 3) {
            cout << "Choose a Series: " << endl;
            int index = 1;

            for (Series s : programas) {
                cout << index << ".- " << s.getName() << endl;
                index++;
            }
            int opt;
            // Rate to look for must be between 0 and 5
            try {
                while (!(std::cin >> opt)) {
                    cout << "Please introduce a number" << std::endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }                
                // When an index not registered is input
                if (opt > index) {
                    throw "Error: No series in index chosen.";
                }
            } catch (const char* msj) {
                cout << msj << endl;
                break;
            }

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

            for(Episode e : s1) {
                if (e.getScore() > rate) {
                    e.print();
                    cout << "/////" << endl;
                }
            }
            for(Episode e : s2) {
                if (e.getScore() > rate) {
                    e.print();
                    cout << "/////" << endl;
                }
            }

        } 
        else if (option == 4) {
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

            for (Movie m : c.getList()) {
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
            for (Movie m : c.getList()) {
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

            c.addScore(index-1,score);
            cout << "Review added, this movie now has a score of: " << c.getList()[index-1].getScore() << endl;
        }
    }
}