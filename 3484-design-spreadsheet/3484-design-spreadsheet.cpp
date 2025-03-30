class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(26, vector<int>(rows, 0));
    }

    void setCell(string cell, int value) {
        int c = cell[0] - 'A';  // Convert column letter to index (0-based)
        int num = stoi(cell.substr(1)) - 1;  // Convert row number (1-based) to index (0-based)
        sheet[c][num] = value;
    }

    void resetCell(string cell) {
        int c = cell[0] - 'A';
        int num = stoi(cell.substr(1)) - 1;
        sheet[c][num] = 0;
    }

    int getValue(string formula) {
        string num1, num2;
        int flag = 0; // 0 for first number, 1 for second number

        for (char ch : formula) {
            if (ch == '=') {
                continue;  // Skip '='
            } else if (ch == '+') {
                flag = 1;  // Switch to parsing the second number
            } else {
                if (flag == 0) {
                    num1.push_back(ch);
                } else {
                    num2.push_back(ch);
                }
            }
        }

        int a, b;
        if (isalpha(num1[0])) { // Check if it's a cell reference
            int c = num1[0] - 'A';
            int num = stoi(num1.substr(1)) - 1;
            a = sheet[c][num];
        } else {
            a = stoi(num1);
        }

        if (isalpha(num2[0])) {
            int c = num2[0] - 'A';
            int num = stoi(num2.substr(1)) - 1;
            b = sheet[c][num];
        } else {
            b = stoi(num2);
        }

        return a + b;
    }
};