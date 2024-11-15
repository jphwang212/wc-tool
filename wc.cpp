#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>
#include<sstream>
#include<locale>
#include<codecvt>
using namespace std;

static void action(string flag, string file) {
    if (flag.compare("-c") == 0) {
        cout << filesystem::file_size(file) << " " << file << "\n";
    } else if (flag.compare("-l") == 0) {
        std::ifstream myfile(file);
        if (myfile.is_open()) {
            myfile.unsetf(std::ios_base::skipws);
            unsigned int line_count = std::count(std::istream_iterator<char>(myfile), std::istream_iterator<char>(), '\n'); 
            cout << line_count << " lines " << file << "\n";
        }
        myfile.close();
    } else if (flag.compare("-w") == 0) {
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
            cout << wordCount << " words " << file << "\n";
        }
        myfile.close();
    } else if (flag.compare("-m") == 0) {
        char current_char;
        int charCount = 0;
        std::ifstream myfile(file);
        myfile.imbue(std::locale("en_US.UTF-8"));
        if (myfile.is_open()) {
            while (myfile.get(current_char)) {
                charCount++;
            }
        }

        cout << charCount << " characters " << file << "\n";
        myfile.close(); 
    }
}
int main(int argc, char** argv) {
    string flag;
    string file; 
    if(argc == 3) {
        flag = argv[1];
        file = argv[2];
        action(flag, file);
    } else {
        cout << "Incorrect arguments\n";
    }
    cout << "Program compiled successfully.";
    return 0;
}
