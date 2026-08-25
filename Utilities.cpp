#include "Utilities.h"
#include <cctype>

using namespace std;

string toLower(string text)
{
    for (char& c : text)
        c = tolower(c);

    return text;
}