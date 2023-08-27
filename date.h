#pragma once
#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <vector>
#include "SearchResults.h"

using namespace std;

struct Date
{
    int d, m, y;
};
int getDifference(Date dt1, Date dt2);
int dateYearToIntSearch(string t_Date);
int dirDateYearToIntSearch(string t_Date);
int dirFullDateYearToIntSearch(string t_Date);
int dirFullDateYearToIntSearchTwo(string t_Date);
int dateFullDateYearToIntSearch(string t_Date);
void ClearSearchResults();
void LoadSearchResults(string t_fileName, string t_searchData);
void writeSpreadSheet(string t_dataS, string t_fileN, string t_dateFrom, string t_dateTo);
vector<string> split(const string& s, char delimiter);
void read_record(string t_Picker);
void deleteFile(const char* t_FileDel);

vector<SearchResults> getSomeSearchResults(int t_Whatever);

#endif
