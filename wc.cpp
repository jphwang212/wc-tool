#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>
#include<sstream>
#include<locale>
using namespace std;

static void printSize(string file) {
    cout << filesystem::file_size(file) << " bytes " << "\t";
}
static void printLines(string file) {
    std::ifstream myfile(file);
    if (myfile.is_open()) {
        myfile.unsetf(std::ios_base::skipws);
        unsigned int line_count = std::count(std::istream_iterator<char>(myfile), std::istream_iterator<char>(), '\n'); 
        cout << line_count << " lines" << "\t";
    }
    myfile.close(); 
}
static void printWords(string file) {
    std::ifstream myfile(file);
    if (myfile.is_open()) {
        string line;
        int wordCount = 0;
        while (std::getline(myfile, line)) {
            std::stringstream ss(line);
            string word;
            while (ss >> word) {
                wordCount++;
            }
        }
        cout << wordCount << " words" << "\t";
    }
    myfile.close(); 
}
static void printCharacters(string file) {
    int charCount = 0;
    std::locale::global(std::locale(""));
    std::wifstream myfile(file);
    wchar_t ch;
    if (myfile.is_open()) {
        while (myfile.get(ch)) {
            charCount++;
        }
     }
    cout << charCount << " characters" << "\t";
    myfile.close();  
}
static void action(string flag, string file) {
    if (flag.compare("-c") == 0) {
        printSize(file);
    } else if (flag.compare("-l") == 0) {
        printLines(file);
    } else if (flag.compare("-w") == 0) {
        printWords(file);
    } else if (flag.compare("-m") == 0) {
        printCharacters(file); 
    } else if (flag.compare("") == 0) {
        printSize(file);
        printLines(file);
        printWords(file);
    }
    cout << file << "\n";
}
int main(int argc, char** argv) {
    string flag;
    string file;
    if (argc == 2) {
        flag = "";
        file = argv[1];
    } else if (argc == 3) { 
        flag = argv[1];
        file = argv[2];
    }
    action(flag, file);
    return 0;
}
