#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Function to find the longest common substring
string longestCommonSubstring(const string& str1, const string& str2) {
    int len1 = str1.length();  // Length of first string
    int len2 = str2.length();  // Length of second string
    
    // Step 1: Create a 2D vector for our lookup table
    // The table size is (len1 + 1) x (len2 + 1) to accommodate empty string case
    vector<vector<int>> lcsTable(len1 + 1, vector<int>(len2 + 1, 0));
    
    int maxLength = 0;  // Length of the longest common substring found so far
    int endIndex = 0;   // Ending index of the longest common substring in str1
    
    // Step 2: Fill the table using dynamic programming
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // If characters match, extend the substring
            if (str1[i - 1] == str2[j - 1]) {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
                
                // Update maxLength and endIndex if a longer substring is found
                if (lcsTable[i][j] > maxLength) {
                    maxLength = lcsTable[i][j];
                    endIndex = i - 1;
                }
            }
            // If characters don't match, lcsTable[i][j] remains 0
        }
    }
    
    // Step 3: Print the table for visualization
    cout << "    ";
    for (char c : str2) cout << c << "   ";
    cout << "\n";
    
    for (int i = 0; i <= len1; i++) {
        if (i == 0) cout << "  ";
        else cout << str1[i - 1] << " ";
        for (int j = 0; j <= len2; j++) {
            cout << setw(3) << lcsTable[i][j] << " ";
        }
        cout << "\n";
    }
    
    // Step 4: Extract and return the longest common substring
    return str1.substr(endIndex - maxLength + 1, maxLength);
}

int main() {
    string str1, str2;
    
    // Get input from user
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    
    // Check if strings are the same length
    if (str1.length() != str2.length()) {
        cout << "Error: The strings must have the same length." << endl;
        return 1;
    }
    
    // Find and print the longest common substring
    string lcs = longestCommonSubstring(str1, str2);
    
    // Output results
    cout << "\nLongest Common Substring: " << lcs << endl;
    cout << "Length: " << lcs.length() << endl;
    
    return 0;
}
