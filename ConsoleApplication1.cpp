
//made by Tala Fahed & Jana Hassoun
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string keywords[] = {
    "Get", "Put", "If", "Then", "Else", "fi", "Repeat", "Until", "Continue", "Break",
    "Del", "Int", "String", "Main", "Return", "Decl", "Enddecl", "Close", "Open"
};

const char operators[] = { '(', ')', '{', '}', '[', ']', '/', '*', '+', '-', '^', '>', '<', ';', '=', '@' };


bool isKeyword(const string& word) {
    for (const string& kw : keywords) {
        if (word == kw) return true;
    }
    return false;
}


bool isAlpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
bool isCapital(char ch) {
	return (ch >= 'A' && ch <= 'Z');
}


bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}
//HI

bool isIdentifier(const string& word) {
    if (word.empty() || !(isCapital(word[0])) ) return false;
    for (int i = 1; i < word.length(); i++) {
        if (!( (isAlpha(word[i]))||((isDigit(word[i]))&&(isCapital(word[i-1]))) )) return false;
    }
    return true;
}

bool isInteger(const string& word) {
    int i = 0;
    if (word[i] == '+' || word[i] == '-') i++;
    if (i == word.length()) return false;
    for (; i < word.length(); i++) {
        if (!isDigit(word[i])) return false;
    }
    return true;
}

bool isReal(const string& word) {
    int i = 0, dotCount = 0;
    if (word[i] == '+' || word[i] == '-') i++;
    if (i == word.length()) return false;
    for (; i < word.length(); i++) {
        if (word[i] == '.') dotCount++;
        else if (!isDigit(word[i])) return false;
    }
    return dotCount == 1;
}


bool isString(const string& word) {
    return word.length() >= 2 && word.front() == '@' && word.back() == '@';
}


bool isOperator(char ch) {
    for (char op : operators) {
        if (ch == op) return true;
    }
    return false;
}

void lexicalAnalysis(const string& inputFile, const string& outputFile) {
    ifstream infile(inputFile);
    ofstream outfile(outputFile);

    if (!infile.is_open()) {
        cerr << "Error: Cannot open input file!" << endl;
        return;
    }

    string line;
    int row = 1;

    while (getline(infile, line)) {
        int col = 1;
        int i = 0;

        if (line.find("##") != string::npos) continue;

        while (i < line.length()) {

            while (i < line.length() && (line[i] == ' ' || line[i] == '\t')) {
                i++;
                col++;
            }

            if (i >= line.length()) break;

            string token;
            int startCol = col;


            if (isAlpha(line[i])) {
                while (i < line.length() && (isAlpha(line[i]) || isDigit(line[i]))) {
                    token += line[i++];
                    col++;
                }

                if (isKeyword(token)) {
                    outfile << token << " row=" << row << ", col=" << startCol << endl;
                }
                else if (isIdentifier(token)) {
                    outfile << "Identifier, lexeme=" << token << " row=" << row << ", col=" << startCol << endl;
                }
                else {
                    outfile << "Error: invalid identifier " << token << " row=" << row << ", col=" << startCol << endl;
                    return;
                }
            }

            else if (isDigit(line[i]) || (line[i] == '-' && i + 1 < line.length() && isDigit(line[i + 1])) || (line[i] == '+' && i + 1 < line.length() && isDigit(line[i + 1]))) {
                while (i < line.length() && (isDigit(line[i]) || line[i] == '.' || line[i] == '-' || line[i] == '+')) {
                    token += line[i++];
                    col++;
                }

                if (isInteger(token)) {
                    outfile << "Integer_Value, lexeme=" << token << " row=" << row << ", col=" << startCol << endl;
                }
                else if (isReal(token)) {
                    outfile << "Real_Value, lexeme=" << token << " row=" << row << ", col=" << startCol << endl;
                }
                else {
                    outfile << "Error: invalid number " << token << " row=" << row << ", col=" << startCol << endl;
                    return;
                }
            }

            else if (line[i] == '@') {
                token += line[i++];
                col++;
                while (i < line.length() && line[i] != '@') {
                    token += line[i++];
                    col++;
                }
                if (i < line.length()) {
                    token += line[i++];
                    col++;
                }

                if (isString(token)) {
                    outfile << "String_Value, lexeme=" << token.substr(1, token.length() - 2) << " row=" << row << ", col=" << startCol << endl;
                }
                else {
                    outfile << "Error: invalid string " << token << " row=" << row << ", col=" << startCol << endl;
                    return;
                }
            }

            else if (isOperator(line[i])) {
                token += line[i++];
                col++;
                outfile << token << " row=" << row << ", col=" << startCol << endl;
            }
            else {
                outfile << "Error: unknown symbol " << line[i] << " row=" << row << ", col=" << startCol << endl;
                return;
            }
        }
        row++;
    }

    infile.close();
    outfile.close();
    cout << "Lexical analysis completed. Check " << outputFile << " for results." << endl;
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    lexicalAnalysis(inputFile, outputFile);
    return 0;
}
