#include "MovieCollection.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string toLower(string text)
{
    for (char& c : text)
        c = tolower(c);

    return text;
}

void MovieCollection::addMovie(const Movie& movie)
{
    movies.push_back(movie);
}

void MovieCollection::displayAllMovies() const
{
    if (movies.empty())
    {
        cout << "No movies found." << endl;
        return;
    }

    cout << left
         << setw(30) << "Title"
         << setw(15) << "Genre"
         << setw(8) << "Year"
         << "Rating" << endl;

    for (const Movie& movie : movies)
        movie.display();
}

void MovieCollection::searchByTitle(string title) const
{
    for (const Movie& movie : movies)
    {
        if (toLower(movie.getTitle()) == toLower(title))
        {
            movie.display();
            return;
        }
    }

    cout << "Movie not found." << endl;
}

void MovieCollection::displayByGenre(string genre) const
{
    bool found = false;

    for (const Movie& movie : movies)
    {
        if (toLower(movie.getGenre()) == toLower(genre))
        {
            movie.display();
            found = true;
        }
    }

    if (!found)
        cout << "No movies found." << endl;
}

double MovieCollection::calculateAverageRating() const
{
    if (movies.empty())
        return 0.0;

    double total = 0.0;

    for (const Movie& movie : movies)
        total += movie.getRating();

    return total / movies.size();
}

int MovieCollection::getNumberOfMovies() const
{
    return movies.size();
}