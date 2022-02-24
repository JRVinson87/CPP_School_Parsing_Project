#pragma once
#include <string>

using namespace std;

// In file degree.h define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.
// create a category, the words are stand ins for ints
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Parallel Array - same order as enum to tie these strings to the enum index
static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE"};