/*
 * CS 210 Project Three: Corner Grocer
 *
 * Author: John Distel
 * Date: 2025-10-19
 *
 * Description:
 *  1. Reads CS210_Project_Three_Input_File.txt and counts the frequency of each item.
 *  2. Immediately writes a backup file frequency.dat ("item count" per line).
 *  3. Presents a menu with:
 *      1) Query a single item's frequency
 *      2) Print all items with counts
 *      3) Print asterisk histogram
 *      4) Exit
 *  4. Implements one class with public/private sections and uses std::map.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iomanip>

using namespace std;

class ItemTracker {
public:
    // Load data, build frequency map, and write backup file
    void Initialize(const string& inputPath, const string& backupPath) {
        readInput(inputPath);
        writeBackup(backupPath);
    }

    // Return frequency for a single item
    int GetCount(const string& item) const {
        string key = toLower(item);
        auto it = freq.find(key);
        return (it == freq.end()) ? 0 : it->second;
    }

    // Print list "Item count"
    void PrintAll() const {
        for (const auto& kv : freq) {
            cout << toTitle(kv.first) << " " << kv.second << '\n';
        }
    }

    // Print histogram with aligned stars
    void PrintHistogram() const {
        for (const auto& kv : freq) {
            cout << left << setw(15) << toTitle(kv.first); // align names in a 15-char column
            for (int i = 0; i < kv.second; ++i) cout << '*';
            cout << '\n';
        }
    }

private:
    map<string, int> freq; // lowercase item -> count

    static string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); });
        return s;
    }

    static string toTitle(string s) {
        if (s.empty()) return s;
        s = toLower(s);
        s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));
        return s;
    }

    void readInput(const string& inputPath) {
        ifstream in(inputPath);
        if (!in) {
            throw runtime_error("Unable to open input file: " + inputPath);
        }
        string item;
        // Each line is one item. Ignore blank lines safely
        while (getline(in, item)) {
            // Trim CR/LF & spaces
            item.erase(remove_if(item.begin(), item.end(),
                [](unsigned char c) { return c == '\r' || c == '\n'; }),
                item.end());
            // Remove leading/trailing spaces
            auto notSpace = [](unsigned char c) { return !std::isspace(c); };
            item.erase(item.begin(), find_if(item.begin(), item.end(), notSpace));
            item.erase(find_if(item.rbegin(), item.rend(), notSpace).base(), item.end());

            if (!item.empty()) {
                freq[toLower(item)]++;
            }
        }
    }

    void writeBackup(const string& backupPath) const {
        ofstream out(backupPath);
        if (!out) {
            throw runtime_error("Unable to write backup file: " + backupPath);
        }
        for (const auto& kv : freq) {
            out << kv.first << " " << kv.second << '\n';
        }
    }
};

static int safeReadMenuChoice() {
    int choice;
    while (true) {
        cout << "\nMenu\n"
            "1. Search for item frequency\n"
            "2. Print all item frequencies\n"
            "3. Print histogram\n"
            "4. Exit\n"
            "Enter choice (1-4): ";
        if (cin >> choice && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear rest of line
            return choice;
        }
        cout << "Invalid choice. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    try {
        ItemTracker tracker;
        // Adjust paths
        const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
        const string BACKUP_FILE = "frequency.dat";

        tracker.Initialize(INPUT_FILE, BACKUP_FILE);

        while (true) {
            int choice = safeReadMenuChoice();
            if (choice == 1) {
                cout << "Enter item name: ";
                string query;
                getline(cin, query);
                cout << tracker.GetCount(query) << '\n';
            }
            else if (choice == 2) {
                tracker.PrintAll();
            }
            else if (choice == 3) {
                tracker.PrintHistogram();
            }
            else if (choice == 4) {
                cout << "Goodbye.\n";
                break;
            }
        }
    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}