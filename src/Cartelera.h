#ifndef CARTELERA_H_INCLUDED
#define CARTELERA_H_INCLUDED

#include <iostream>
#include <vector>
#include "Movie.h"
using namespace std;

class Cartelera {
    private:
      vector<Movie> peliculas;

    public:
        Cartelera();
        Cartelera(vector<Movie> peliculas);

        void addEpisode(Movie movie);
        double getScore();
        int getCarteleraSize();
        void print();
        void addScore(int index, double score);
        vector <Movie> getList();
};

#endif