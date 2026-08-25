#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include <vector>
#include <string>
#include "Movie.h"

using namespace std;

class MovieCollection
{
private:
    vector<Movie> movies;

public:
    void addMovie(const Movie& movie);
    void displayAllMovies() const;
    void searchByTitle(string title) const;
    void displayByGenre(string genre) const;
    double calculateAverageRating() const;
    int getNumberOfMovies() const;
};

#endif