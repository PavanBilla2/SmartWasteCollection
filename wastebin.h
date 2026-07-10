#ifndef WASTEBIN_H
#define WASTEBIN_H

#include <string>

using namespace std;

struct WasteBin
{
    int id;
    int wasteLevel;
    string priority;
    bool collected;
};

#endif