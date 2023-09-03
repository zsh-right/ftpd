#ifndef __UTIL_H__
#define __UTIL_H__

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define MODE (S_IRWXU | S_IRWXG | S_IRWXO)

void Stringsplit(string str, const char split, vector<string> &res);

void trim(string &s);

void trimToParentDir(string &s);

void power(int mode, char str[]);

int mk_dir(const char *dir);

int rm_dir(std::string dir_full_path);

void toUpper(std::string &str);

bool file_exist(const char *full_file_path);

#endif  // __UTIL_H__