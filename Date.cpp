#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cstdio>
#include <stdlib.h>
#include <tchar.h>
#include <cstring>
#include <string>
#include <windows.h>
#include <cctype>
#include <algorithm>
#include <sstream>
#include "SearchResults.h"

using namespace std;
vector <SearchResults> searchResults;
bool sCheck;
// A date has day 'd', month 'm' and year 'y' 
struct Date
{
    int d, m, y;
};

// To store number of days in all months from January to Dec. 
const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31 };

// This function counts number of leap years before the 
// given date 
int countLeapYears(Date d)
{
    int years = d.y;

    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (d.m <= 2)
        years--;

    // An year is a leap year if it is a multiple of 4, 
    // multiple of 400 and not a multiple of 100. 
    return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1' 

    // initialize count using years and day 
    long int n1 = dt1.y * 365 + dt1.d;

    // Add days for months in given date 
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days, 
    // Add a day for every leap year 
    n1 += countLeapYears(dt1);

    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2' 

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts 
    return (n2 - n1);
}
int dateYearToIntSearch(string t_Date) { //this converts the last 4 digits of the date (the year) to an int for comparisons
	int dateYear;
	dateYear = ((t_Date[4] - 48) * 1000 + (t_Date[5] - 48) * 100 + (t_Date[6] - 48) * 10 + (t_Date[7] - 48));
	return dateYear;
}
int dirDateYearToIntSearch(string t_Date) { //this converts the year directories from the Archives in the RDrive to integers for comparisons
	int dirDateYear;
	dirDateYear = (t_Date[11] - 48) * 1000 + (t_Date[12] - 48) * 100 + (t_Date[13] - 48) * 10 + (t_Date[14] - 48);
	return dirDateYear;
}
int dirFullDateYearToIntSearch(string t_Date) { //this converts the date directories from the Archives in the RDrive to integers for comparisons
	int dirFullDateYear;
	dirFullDateYear = (t_Date[20] - 48) * 10000000 + (t_Date[21] - 48) * 1000000 + (t_Date[22] - 48) * 100000 + (t_Date[23] - 48) * 10000 + (t_Date[16] - 48) * 1000 + (t_Date[17] - 48) * 100 + (t_Date[18] - 48) * 10 + t_Date[19] - 48;
	return dirFullDateYear;
}
int dirFullDateYearToIntSearchTwo(string t_Date) { //this converts the date directories from the Archives in the RDrive to integers for comparisons
    int dirFullDateYear;
    dirFullDateYear = (t_Date[15] - 48) * 10000000 + (t_Date[16] - 48) * 1000000 + (t_Date[17] - 48) * 100000 + (t_Date[18] - 48) * 10000 + (t_Date[11] - 48) * 1000 + (t_Date[12] - 48) * 100 + (t_Date[13] - 48) * 10 + t_Date[14] - 48;
    return dirFullDateYear;
}
int dateFullDateYearToIntSearch(string t_Date) { //this converts the date to int for comparisons
	int dateFullDateYear;
	dateFullDateYear = (t_Date[4] - 48) * 10000000 + (t_Date[5] - 48) * 1000000 + (t_Date[6] - 48) * 100000 + (t_Date[7] - 48) * 10000 + (t_Date[0] - 48) * 1000 + (t_Date[1] - 48) * 100 + (t_Date[2] - 48) * 10 + t_Date[3] - 48;
	return dateFullDateYear;
}
void ClearSearchResults(){
    searchResults.clear();
}
void LoadSearchResults(string t_fileName, string t_searchData) {
    //cout << "loaded" << endl;
    ifstream inFS;
    string dataFromFile = "notNull";
    int offset;
    vector<string> splitSearch;
    size_t found;
    int sResult = 0;
    string token;

    string fileName = t_fileName;
    //string saveLocation = "htmldata.txt";

    //CopyFileA(fileName.c_str(), saveLocation.c_str(), FALSE);

    //ifstream file("htmldata.txt");
    //inFS.open("htmldata.txt");
    transform(t_searchData.begin(), t_searchData.end(), t_searchData.begin(), ::tolower);
    istringstream tokenStream(t_searchData);
    while (getline(tokenStream, token, ';'))
    {
        splitSearch.push_back(token);
    }

    //ifstream file(t_fileName);

    /*
    for (int i = 0; i < 21; ++i) {
        getline(file, dataFromFile);
    }
    */
    //size_t eXit = dataFromFile.find("** END-OF-JOB **");
    for (unsigned i = 0; i < splitSearch.size(); i++) {
        inFS.open(t_fileName);
        ifstream file(t_fileName);
        sCheck = false;
        while (getline(file, dataFromFile)) {
        //while (eXit == string::npos) {
          // cout << "while" << endl;
           // cout << dataFromFile << endl;
            //cout << t_searchData << endl;
        /*
            if (dataFromFile.length() == 0) {
                break;
                cout << "break" << endl;
            }
        */
            transform(dataFromFile.begin(), dataFromFile.end(), dataFromFile.begin(), ::tolower);
             found = dataFromFile.find(splitSearch[i]);
             if (found != string::npos) {
                 sCheck = true;
                 sResult = sResult + 1;
                 break;
             }
             
        }
        inFS.close(); // Done with file, so close it
        if (sCheck == false) {
            break;
        }
    }
    if (sResult == splitSearch.size()) {
        SearchResults newSearchResults(t_fileName);
        searchResults.push_back(newSearchResults);
        //cout << "found" << endl;
    }
}
vector<SearchResults> getSomeSearchResults(int t_Whatever) {
    return searchResults;
}
void writeSpreadSheet(string t_dataS, string t_fileN, string t_dateFrom, string t_dateTo) {
    string saveFileName ="savedSearches//" + t_dataS + "_" + t_fileN + "_" + t_dateFrom + "_" + t_dateTo + ".csv";
    ofstream outdata(saveFileName);
    for (int i = 0; i < searchResults.size(); ++i) {
        outdata << searchResults.at(i).GetSearchLocation() << endl;
    }
    outdata.close();
}
vector<string> split(const string& s, char delimiter) //this allows you to break apart a string with a delimiter of your choice.  stores them in a vector
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
void read_record(string t_Picker) {
    searchResults.clear();
    fstream fin;
    fin.open(t_Picker, ios::in);
    vector<string> row;
    string line;
    while (getline(fin, line)) {
        searchResults.push_back(line);
    }
}
void deleteFile(const char* t_FileDel) {
    remove(t_FileDel);
}
