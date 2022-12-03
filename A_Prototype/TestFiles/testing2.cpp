#include <algorithm>    // for std::sort
#include <cctype>       // for std::isupper, std::tolower
#include <iostream>     // for std::cout
#include <string>       // for std::string
using namespace std;

int main() {
    string s;
    getline (cin,s);
    sort( s.begin(), s.end(), [](char x, char y) { 
        // Custom sorting criteria.
        // Return true if x precedes y.

        // This may work, but requires more testing...
        if (isupper(x)) {
            if (tolower(x) == y) {
                return true;    
            }   
        }
        return tolower(x) < tolower(y);
    });

    cout << s << '\n';
}
