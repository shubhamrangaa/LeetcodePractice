#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string reverseWords(string s)
{
    string rev = "";
    vector<string> matrix = {""};

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i + 1] == ' ')
        {
            matrix[matrix.size() - 1] += s[i];
            matrix.push_back("");
        }
        else
            matrix[matrix.size() - 1] += s[i];
    }
    if (matrix[matrix.size() - 1] == "")
        matrix.pop_back();
    for (int i = matrix.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            rev += matrix[i];
            continue;
        }
        rev += matrix[i] + " ";
    }
    return rev;
}

int main()
{
    string s = "  Bob    Loves  Alice   ";
    reverseWords(s);
}