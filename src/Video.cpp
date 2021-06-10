#include "Video.h"

double Video::averageScore() {
    double sum = 0;
    int num = 1;
    for (double i : scores) {
        sum += i;
        num++;
    }
    return sum/num;
}

// Cosntructors

Video::Video() {
    ID = "00000";
    name = "default";
    genre = "default";
    duration = 0;
    scores = vector <double> {0};
}

Video::Video(string ID, string name, string genre, int duration, vector <double> scores) {
    this->ID = ID;
    this->name = name;
    this->genre = genre;
    this->duration = duration;
    this->scores = scores;
}

// Accessor

string Video::getID() {
    return ID;
}

string Video::getGenre() {
    return genre;
}

string Video::getName() {
    return name;
}

int Video::getDuration() {
    return duration;
}

double Video::getScore() {
    double average = averageScore();
    return average;
}

// Modifiers
void Video::setID(string ID) {
    this->ID = ID;
}

void Video::setName(string name) {
    this->name = name;
}

void Video::setGenre(string genre) {
    this->genre = genre;
}

void Video::setDuration(int duration) {
    this->duration = duration;
}

void Video::setScores(vector <double> scores) {
    this->scores = scores;
}

void Video::addScore(double score) {
    this->scores.push_back(score);
}

void Video::addScores(vector <double> scores) {
    for (double i : scores) {
        this->scores.push_back(i);
    }
}

void Video::print() {
    cout << "Hi" << endl;
}