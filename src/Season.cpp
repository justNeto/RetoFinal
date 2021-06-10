#include "Season.h"

using namespace std;

double Season::getScore() {
  double sum = 0;
  int num = 1;

  for (Episode episode : season) {
    sum += episode.getScore();
    num++;
  }
  return sum/num;
}


Season::Season() {
  this->seasonNum = 1;
}

Season::Season(vector<Episode> season, bool onAir, int seasonNum) {
  this->season = season;
  this-> onAir = onAir;
  this->seasonNum = seasonNum;
}

int Season::getSeasonSize() {
    return season.size();
}

void Season::print() {
  int num = 1;
  cout << "Season number: " << getSeasonSize() << seasonNum << endl;
  cout << "Number of episodes: " << getSeasonSize() << endl;
  cout << "Average score of the season: " << getScore() << endl;

  cout << "List of episodes: " << endl;
  for (Episode episode : season) {
    cout << num << ".- " << episode.getName() << endl;
  }
}
