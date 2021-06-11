#include "Cartelera.h"

using namespace std;

double Cartelera::getScore() {
  double sum = 0;
  int num = 1;

  for (Movie movie : peliculas) {
    sum += movie.getScore();
    num++;
  }
  return sum/num;
}

void Cartelera::addEpisode(Movie movie) {
    peliculas.push_back(movie);
}

Cartelera::Cartelera() {
}

Cartelera::Cartelera(vector<Movie> peliculas) {
  this -> peliculas = peliculas;
}

int Cartelera::getCarteleraSize() {
    return peliculas.size();
}

void Cartelera::print() {
  int num = 1;
  cout << "Size of cartelera: " << getCarteleraSize() << endl;
  cout << "Average score of the cartelera: " << getScore() << endl;

  cout << "List of movies: " << endl;
  for (Movie movie : peliculas) {
    cout << num << ".- " << movie.getName() << endl;
  }
}
