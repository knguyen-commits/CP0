#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool FileManager::loadMovies(string filename, MovieCollection& collection)
{
    ifstream inputFile(filename);

    if (!inputFile)
        return false;

    string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        string title;
        string genre;
        string yearString;
        string ratingString;

        getline(ss, title, ',');
        getline(ss, genre, ',');
        getline(ss, yearString, ',');
        getline(ss, ratingString);

        int year = stoi(yearString);
        double rating = stod(ratingString);

        Movie movie(title, genre, year, rating);
        collection.addMovie(movie);
    }

    inputFile.close();
    return true;
}