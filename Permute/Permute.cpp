#include <iostream>
#include <list>
#include <string>
#include <algorithm>

//#include <bits/stdc++.h>

using namespace std;

// Permute string. Output List of strings.
// Recursive solution
list<string> Permute (string str)
{
    list<string> s;
    if(str.length() < 1)
    {
        s.push_back(str);
        return s;
    }

    for(unsigned int i = 0; i < str.length(); i++)
    {
        const char ch = str[i];
        string st = str;
        st.erase(i, 1);
        list<string>lst = Permute(st);
        for(list<string>::iterator it = lst.begin(); it != lst.end(); it++)
        {
            string temp = ch+(*it);
            if(find(s.begin(), s.end(), temp) == s.end())
                s.push_back(temp);
        }
    }

    return s;
}

int main (int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "Usage: Permute <string>" << endl;
        return 1;
    }

    list <string> npn;
    list <string>::iterator it;
    npn = Permute(argv[1]);

    for(it = npn.begin(); it != npn.end(); it++)
    {
        cout << *it << endl;
    }

    return 1;
}

