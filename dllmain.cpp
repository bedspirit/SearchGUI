#include "pch.h"
#include <iostream>
#include <filesystem>
#include <sys/stat.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

vector <string> searchResults;

bool wildcardMatch(char str[], char pattern[])
{
    int m = strlen(str);
    int n = strlen(pattern);
    // lookup table for storing results of
    // subproblems
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    // empty pattern can match with empty string
    prev[0] = true;

    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++) {

        bool flag = true;
        for (int ii = 1; ii < i; ii++) {
            if (pattern[ii - 1] != '*') {
                flag = false;
                break;
            }
        }
        curr[0] = flag; // for every row we are assigning
        // 0th column value.
        for (int j = 1; j <= m; j++) {
            // Two cases if we see a '*'
            // a) We ignore ‘*’ character and move
            //    to next  character in the pattern,
            //     i.e., ‘*’ indicates an empty sequence.
            // b) '*' character matches with ith
            //     character in input
            if (pattern[i - 1] == '*')
                curr[j] = curr[j - 1] || prev[j];

            // Current characters are considered as
            // matching in two cases
            // (a) current character of pattern is '?'
            // (b) characters actually match
            else if (pattern[i - 1] == '?'
                || str[j - 1] == pattern[i - 1])
                curr[j] = prev[j - 1];

            // If characters don't match
            else
                curr[j] = false;
        }
        prev = curr;
    }

    return prev[m];
}

int dateYearToIntSearch(string t_Date) { //this converts the last 4 digits of the date (the year) to an int for comparisons
    int dateYear;
    dateYear = ((t_Date[4] - 48) * 1000 + (t_Date[5] - 48) * 100 + (t_Date[6] - 48) * 10 + (t_Date[7] - 48));
    return dateYear;
}
bool sCheck;

string searchOutput(string f_datesFromGUI, bool f_Today, string f_FileName) {
    vector<string> fileList;
    vector<string> filesInDir;
    vector<string> dirList;
    vector<string> fileNameMatch;
    searchResults.clear();
    //string todayLoc = "R:\\";
    //string archiveLoc = "R:\\Archive\\";
    string todayLoc = "C:\\Users\\bedsp\\Documents\\R\\";
    string archiveLoc = "C:\\Users\\bedsp\\Documents\\R\\Archive\\";
    string fileName;
    string outPut = "";

    stringstream ss(f_FileName);
    while (!ss.eof()) {
        getline(ss, fileName, ';');
        fileList.push_back("*" + fileName + "*");
    }
    if (f_Today) {
        for (const auto& entry : filesystem::directory_iterator(todayLoc)) {
            if (entry.is_regular_file()) {
                string entryFileName = entry.path().filename().string();
                filesInDir.push_back(entryFileName);
            }
        }
        for (int i = 0; i < filesInDir.size(); ++i) {
            char* elem2 = new char[filesInDir[i].length()+ 1];
            strcpy(elem2, filesInDir[i].c_str());
            for (int i = 0; i < fileList.size(); ++i) {
                char* elem1 = new char[fileList[i].length() + 1];
                strcpy(elem1, fileList[i].c_str());
                if (wildcardMatch(elem2, elem1)) {
                    fileNameMatch.push_back(elem2);
                }
            }
        }
    }
    filesInDir.clear();
    if (filesystem::exists(archiveLoc + f_datesFromGUI) && filesystem::is_directory(archiveLoc + f_datesFromGUI)) {
        for (const auto& entry : filesystem::directory_iterator(archiveLoc + f_datesFromGUI)) {
            if (entry.is_regular_file()) {
                string entryFileName = entry.path().filename().string();
                filesInDir.push_back(entryFileName);
            }
        }
        for (int i = 0; i < filesInDir.size(); ++i) {
            char* elem2 = new char[filesInDir[i].length() + 1];
            strcpy(elem2, filesInDir[i].c_str());
            for (int i = 0; i < fileList.size(); ++i) {
                char* elem1 = new char[fileList[i].length() + 1];
                strcpy(elem1, fileList[i].c_str());
                if (wildcardMatch(elem2, elem1)) {
                    fileNameMatch.push_back(elem2);
                }
            }
        }
    }
    else {
        if (filesystem::exists(archiveLoc + to_string(dateYearToIntSearch(f_datesFromGUI)) + "\\" + f_datesFromGUI) && filesystem::is_directory(archiveLoc + to_string(dateYearToIntSearch(f_datesFromGUI)) + "\\" +  f_datesFromGUI)) {
            for (const auto& entry : filesystem::directory_iterator(archiveLoc + to_string(dateYearToIntSearch( f_datesFromGUI)) + "\\" +  f_datesFromGUI)) {
                if (entry.is_regular_file()) {
                    string entryFileName = entry.path().filename().string();
                    filesInDir.push_back(entryFileName);
                }
            }
         for (int i = 0; i < filesInDir.size(); ++i) {
            char* elem2 = new char[filesInDir[i].length()+ 1];
            strcpy(elem2, filesInDir[i].c_str());
            for (int i = 0; i < fileList.size(); ++i) {
                char* elem1 = new char[fileList[i].length() + 1];
                strcpy(elem1, fileList[i].c_str());
                if (wildcardMatch(elem2, elem1)) {
                    fileNameMatch.push_back(elem2);
                }
            }
        }
        }
    }
    for (int i = 0; i < fileNameMatch.size(); i++) {
        outPut = outPut + fileNameMatch[i] + ",";
    }
    if (outPut.size() > 0) {
        outPut.pop_back();
    }
    return outPut;
}

int main() {
    string dateArray = "08262023";
    string resultArray = searchOutput(dateArray, false, "0211;0271");
    std::cout << resultArray << "\n";

    dateArray = "08272023";
    resultArray = searchOutput(dateArray, false, "0211;0271");
    std::cout << resultArray << "\n";

    dateArray = "08282023";
    resultArray = searchOutput(dateArray, false, "0211;0271");
    std::cout << resultArray << "\n";

    dateArray = "08292023";
    resultArray = searchOutput(dateArray, true, "0211;0271");
    std::cout << resultArray << "\n";

    return 0;
}
