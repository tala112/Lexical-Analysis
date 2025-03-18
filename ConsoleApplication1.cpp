
/*
//n1 error
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

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool isIdentifier(const string& word) {
    if (word.empty() || !isAlpha(word[0])) return false;
    bool hasCapital = false;
    for (int i = 1; i < word.length(); i++) {
        if (isDigit(word[i]) && !hasCapital) return false;
        if (isAlpha(word[i]) && (word[i] >= 'A' && word[i] <= 'Z')) hasCapital = true;
        if (!(isAlpha(word[i]) || isDigit(word[i]))) return false;
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
                    continue;
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
                    continue;
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
                    continue;
                }
            }

            else if (isOperator(line[i])) {
                token += line[i++];
                col++;
                outfile << token << " row=" << row << ", col=" << startCol << endl;
            }
            else {
                outfile << "Error: unknown symbol " << line[i] << " row=" << row << ", col=" << startCol << endl;
                i++;
                col++;
                continue;
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
*/


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


bool isIdentifier(const string& word) {
    if (word.empty() || !(isCapital(word[0]))) return false;
    for (int i = 1; i < word.length(); i++) {
        if (!((isAlpha(word[i])) || ((isDigit(word[i])) && (isCapital(word[i - 1]))))) return false;
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


/*
//sum8 error not detected
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


bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// sum
bool isIdentifier(const string& word) {
    if (word.empty() || !(isAlpha(word[0]))) return false;
    for (int i = 1; i < word.length(); i++) {
        if (!(isAlpha(word[i]) || isDigit(word[i]))) return false;
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
*/
/*
//sum8 error not detected
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string keywords[] = {
    "Get", "Put", "If", "Then", "Else", "fi", "Repeat", "Until", "Continue", "Break",
    "Del", "Int", "String", "Main", "Return", "Decl", "Enddecl", "Close", "Open"
};

const char operators[] = { '(', ')', '{', '}', '[', ']', '/', '*', '+', '-', '^', '>', '<', ';', '=', '@' };

// دالة للتحقق مما إذا كانت الكلمة مفتاحية
bool isKeyword(const string& word) {
    for (const string& kw : keywords) {
        if (word == kw) return true;
    }
    return false;
}

// دالة للتحقق مما إذا كان الحرف حرفًا أبجديًا
bool isAlpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// دالة للتحقق مما إذا كان الحرف رقمًا
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// دالة للتحقق مما إذا كان المعرف صالحًا
bool isIdentifier(const string& word) {
    if (word.empty() || !(isAlpha(word[0]))) return false;  // يجب أن يبدأ بحرف
    for (size_t i = 1; i < word.length(); i++) {
        if (!(isAlpha(word[i]) || isDigit(word[i]))) return false;  // يجب أن يكون باقي الحروف أرقامًا أو حروفًا
    }
    return true;
}

// دالة للتحقق مما إذا كان العدد صحيحًا
bool isInteger(const string& word) {
    size_t i = 0;
    if (word[i] == '+' || word[i] == '-') i++;
    if (i == word.length()) return false;
    for (; i < word.length(); i++) {
        if (!isDigit(word[i])) return false;
    }
    return true;
}

// دالة للتحقق مما إذا كان العدد عشريًا
bool isReal(const string& word) {
    size_t i = 0, dotCount = 0;
    if (word[i] == '+' || word[i] == '-') i++;
    if (i == word.length()) return false;
    for (; i < word.length(); i++) {
        if (word[i] == '.') dotCount++;
        else if (!isDigit(word[i])) return false;
    }
    return dotCount == 1;
}

// دالة للتحقق مما إذا كان النص محاطًا بعلامة @
bool isString(const string& word) {
    return word.length() >= 2 && word.front() == '@' && word.back() == '@';
}

// دالة للتحقق مما إذا كان الرمز معاملًا
bool isOperator(char ch) {
    for (char op : operators) {
        if (ch == op) return true;
    }
    return false;
}

// الدالة الرئيسية لتحليل الملف
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
        size_t i = 0;

        // تجاهل التعليقات بالكامل
        if (line.find("##") != string::npos) continue;

        while (i < line.length()) {
            // تخطي المسافات البيضاء
            while (i < line.length() && (line[i] == ' ' || line[i] == '\t')) {
                i++;
                col++;
            }

            if (i >= line.length()) break;

            string token;
            int startCol = col;

            // تحليل الكلمات المفتاحية والمعرفات
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
            // تحليل القيم العددية (صحيحة وعشرية)
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
            // تحليل النصوص
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
            // تحليل المعاملات والفواصل
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
/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// قائمة الكلمات المحجوزة (بدون unordered_set)
const string keywords[] = {
    "Get", "Put", "If", "Then", "Else", "fi", "Repeat", "Until", "Continue", "Break",
    "Del", "Int", "String", "Main", "Return", "Decl", "Enddecl", "Close", "Open"
};

// قائمة المعاملات والفواصل (بدون unordered_set)
const string operators[] = {
    "(", ")", "{", "}", "[", "]", "/", "*", "+", "-", "^", ">", "<",
    ">=", "<=", "!=", "==", ";", "=", "&&", "||", "@"
};

// دالة للتحقق مما إذا كانت الكلمة مفتاحية
bool isKeyword(const string& word) {
    for (const string& kw : keywords) {
        if (word == kw) return true;
    }
    return false;
}

// دالة للتحقق مما إذا كان الحرف حرفًا أبجديًا (isalpha بدون cctype)
bool isAlpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// دالة للتحقق مما إذا كان الحرف رقمًا (isdigit بدون cctype)
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// دالة للتحقق مما إذا كان المعرف صالحًا
bool isIdentifier(const string& word) {
    if (word.empty() || !(word[0] >= 'A' && word[0] <= 'Z')) return false;
    for (size_t i = 1; i < word.length(); i++) {
        if (!isDigit(word[i])) return false;
    }
    return true;
}

// دالة للتحقق مما إذا كان العدد صحيحًا
bool isInteger(const string& word) {
    size_t i = 0;
    if (word[i] == '+' || word[i] == '-') i++; // السماح بالإشارة
    if (i == word.length()) return false; // لا يمكن أن يكون فقط "+" أو "-"
    for (; i < word.length(); i++) {
        if (!isDigit(word[i])) return false;
    }
    return true;
}

// دالة للتحقق مما إذا كان العدد عشريًا
bool isReal(const string& word) {
    size_t i = 0, dotCount = 0;
    if (word[i] == '+' || word[i] == '-') i++; // السماح بالإشارة
    if (i == word.length()) return false;
    for (; i < word.length(); i++) {
        if (word[i] == '.') dotCount++;
        else if (!isDigit(word[i])) return false;
    }
    return dotCount == 1;
}

// دالة للتحقق مما إذا كان النص محاطًا بعلامة @
bool isString(const string& word) {
    return word.length() >= 2 && word.front() == '@' && word.back() == '@';
}

// دالة للتحقق مما إذا كان الرمز من المعاملات أو الفواصل
bool isOperator(const string& symbol) {
    for (const string& op : operators) {
        if (symbol == op) return true;
    }
    return false;
}

// الدالة الرئيسية لتحليل الملف
void lexicalAnalysis(const string& inputFile, const string& outputFile) {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile.is_open()) {
        cerr << "Error: Cannot open input file!" << endl;
        return;
    }

    string line;
    int row = 1;

    while (getline(infile, line)) {
        int col = 1;
        size_t i = 0;

        while (i < line.length()) {
            // تخطي المسافات البيضاء
            while (i < line.length() && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')) {
                i++;
                col++;
            }

            if (i >= line.length()) break;

            // تجاهل التعليقات
            if (i < line.length() - 1 && line[i] == '#' && line[i + 1] == '#') {
                i += 2;
                while (i < line.length() - 1 && !(line[i] == '#' && line[i + 1] == '#')) i++;
                i += 2; // تخطي التعليق بالكامل
                continue;
            }

            string token;
            int startCol = col;

            // تحليل الكلمات (الكلمات المفتاحية أو المعرفات)
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
            // تحليل الأعداد الصحيحة والعشرية
            else if (isDigit(line[i]) || (line[i] == '-' && i + 1 < line.length() && isDigit(line[i + 1])) || (line[i] == '+' && i + 1 < line.length() && isDigit(line[i + 1]))) {
                while (i < line.length() && (isDigit(line[i]) || line[i] == '.')) {
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
            // تحليل النصوص
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
            // تحليل المعاملات والفواصل
            else {
                string op(1, line[i]);
                i++;
                col++;

                if (isOperator(op)) {
                    outfile << op << " row=" << row << ", col=" << startCol << endl;
                }
                else {
                    outfile << "Error: unknown symbol " << op << " row=" << row << ", col=" << startCol << endl;
                    return;
                }
            }
        }
        row++;
    }

    infile.close();
    outfile.close();
    cout << "Lexical analysis completed. Check " << outputFile << " for results." << endl;
}

int main() {
    string inputFile = "input.txt";  // ملف الإدخال
    string outputFile = "output.txt"; // ملف الإخراج

    lexicalAnalysis(inputFile, outputFile);
    return 0;
}
*/



/* pro
#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <regex>
using namespace std;

struct Token {
    string type;
    string lexeme;
    int row, col;
};

vector<string> keywords = {"Get", "Put", "If", "Then", "Else", "fi", "Repeat", "Until", "Continue", "Break", "Del", "Int", "String", "Main", "Return", "Decl", "Enddecl", "Close", "Open"};
vector<string> operators = {"(", ")", "{", "}", "[", "]", "/", "*", "+", "-", "^", ">", "<", ">=", "<=", "!=", "==", ";", "=", "&&", "||", "@"};

bool isKeyword(const string& word) {
    return find(keywords.begin(), keywords.end(), word) != keywords.end();
}

bool isOperator(const string& op) {
    return find(operators.begin(), operators.end(), op) != operators.end();
}

bool isIdentifier(const string& word) {
    return regex_match(word, regex("[A-Z][0-9]*"));
}

bool isInteger(const string& word) {
    return regex_match(word, regex("[-+]?[0-9]+"));
}

bool isReal(const string& word) {
    return regex_match(word, regex("[-+]?[0-9]+\.[0-9]+"));
}

bool isStringLiteral(const string& word) {
    return regex_match(word, regex("@.*@"));
}

void tokenize(const string& filename, const string& outputFile) {
    ifstream file(filename);
    ofstream out(outputFile);
    string line;
    vector<Token> tokens;
    int row = 0;
    int currentCol = 1;

    while (getline(file, line)) {
        row++;
        size_t i = 0;

        while (i < line.length()) {
            if (isspace(line[i])) {
                i++;
                continue;
            }

            if (line[i] == '#' && i + 1 < line.length() && line[i + 1] == '#') {
                size_t endPos = line.find("##", i + 2);
                if (endPos == string::npos) break;
                i = endPos + 2;
                continue;
            }

            string token;
            int startCol = currentCol ;

            if (isalpha(line[i])) {
                while (i < line.length() && (isalnum(line[i]) || line[i] == '_')) {
                    token += line[i];
                    i++;
                }
                if (isKeyword(token)) tokens.push_back({token, "", row, startCol});
                else if (isIdentifier(token)) tokens.push_back({"Identifier", token, row, startCol});
                else out << "Error: invalid identifier at row=" << row << ", col=" << startCol << endl;
            }
            else if (isdigit(line[i]) || (line[i] == '-' || line[i] == '+') && isdigit(line[i + 1])) {
                while (i < line.length() && (isdigit(line[i]) || line[i] == '.' || line[i] == '-' || line[i] == '+')) {
                    token += line[i];
                    i++;
                }
                if (isInteger(token)) tokens.push_back({"Integer_Value", token, row, startCol});
                else if (isReal(token)) tokens.push_back({"Real_Value", token, row, startCol});
                else out << "Error: invalid number at row=" << row << ", col=" << startCol << endl;
            }
            else if (line[i] == '@') {
                size_t endPos = line.find("@", i + 1);
                if (endPos != string::npos) {
                    token = line.substr(i + 1, endPos - i - 1);
                    tokens.push_back({"String_Value", token, row, startCol});
                    i = endPos + 1;
                } else {
                    out << "Error: unterminated string at row=" << row << ", col=" << startCol << endl;
                }
            }
            else {
                string op(1, line[i]);
                if (i + 1 < line.length() && isOperator(op + line[i + 1])) {
                    op += line[i + 1];
                    i++;
                }
                if (isOperator(op)) tokens.push_back({op, "", row, startCol});
                else out << "Error: unknown token at row=" << row << ", col=" << startCol << endl;
                i++;
            }
            currentCol++;
        }
    }

    for (const auto& t : tokens) {
        out << t.type;
        if (!t.lexeme.empty()) out << ", lexeme= " << t.lexeme;
        out << " row=" << t.row << ", col=" << t.col << endl;
    }

    file.close();
    out.close();
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    tokenize(inputFile, outputFile);
    cout << "Lexical analysis completed. Check output.txt" << endl;
    return 0;
}
*/