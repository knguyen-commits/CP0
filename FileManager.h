#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "MovieCollection.h"

using namespace std;

class FileManager
{
public:
    static bool loadMovies(string filename, MovieCollection& collection);
};

#endif