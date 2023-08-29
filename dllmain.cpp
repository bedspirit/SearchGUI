// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include <filesystem>
#include <sys/stat.h>
#include <fstream>

using namespace std;

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

vector <string> searchResults;

bool sCheck;

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

    transform(t_searchData.begin(), t_searchData.end(), t_searchData.begin(), ::tolower);
    istringstream tokenStream(t_searchData);
    while (getline(tokenStream, token, ';'))
    {
        splitSearch.push_back(token);
    }
    for (unsigned i = 0; i < splitSearch.size(); i++) {
        inFS.open(t_fileName);
        ifstream file(t_fileName);
        sCheck = false;
        while (getline(file, dataFromFile)) {
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
    }
}

string searchOutput(string f_DateFrom, string f_DateTo, string f_FileName, string f_SearchFor) {
    vector<string> fileList;
    vector<string> filesInDir;
    vector<string> dirList;
    vector<string> fileNameMatch;
    searchResults.clear();
    string archiveLoc = "R:\\Archive\\";
    string fileName;

    for (const auto& entry : filesystem::directory_iterator(archiveLoc)) {
        if (filesystem::is_directory(entry)) {
            if ((dirDateYearToIntSearch(entry.path().string()) >= dateYearToIntSearch(f_DateFrom)) && (dirDateYearToIntSearch(entry.path().string()) <= dateYearToIntSearch(f_DateTo))) {
                dirList.push_back(entry.path().string());
            }
        }
    }
    stringstream ss(f_FileName);
    while (!ss.eof()) {
        getline(ss, fileName, ';');
        fileList.push_back(fileName);
    }
    for (int i = 0; i < dirList.size(); ++i) {
        if (dirFullDateYearToIntSearch(dirList[i]) >= dateFullDateYearToIntSearch(f_DateFrom) && dirFullDateYearToIntSearch(dirList[i]) <= dateFullDateYearToIntSearch(f_DateTo)) {
            for (int k = 0; k < fileList.size(); k++) {
                fileList[k] = fileList[k] + "*.html";
                for (const auto& entry : filesystem::directory_iterator(dirList[i])) {
                    if (entry.is_regular_file()) {
                        string entryFileName = entry.path().filename().string();
                        filesInDir.push_back(entryFileName);
                    }
                }
            }
            for (int k = 0; k < filesInDir.size(); k++) {
                if (find(fileList.begin(), fileList.end(), filesInDir[k]) != fileList.end()) {
                    fileNameMatch.push_back(filesInDir[k]);
                }
            }
            for (int k = 0; k < fileNameMatch.size(); k++) {
                LoadSearchResults(fileNameMatch[k], f_SearchFor);
            }
        }
    }
}

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
