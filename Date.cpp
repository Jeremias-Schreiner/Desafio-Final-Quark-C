#include "Date.h"
#include<ctime>
#pragma warning(disable:4996)

using namespace std;

string Date::getCurrentDate() {

    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);

    return buf;
}