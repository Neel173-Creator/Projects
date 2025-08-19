#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Transaction {
    string type;   // "income" or "expense"
    double amount;
    string category;
};

void saveToFile(vector<Transaction>& records) {
    ofstream fout("finance.txt");
    for(auto &t : records) {
        fout << t.type << " " << t.amount << " " << t.category << "\n";
    }
    fout.close();
}

void loadFromFile(vector<Transaction>& records) {
    ifstream fin("finance.txt");
    records.clear();
    Transaction t;
    while(fin >> t.type >> t.amount >> t.category) {
        records.push_back(t);
    }
    fin.close();
}

int main() {
    vector<Transaction> records;
    int choice;
    while(true) {
        cout << "\n1. Add Transaction\n2. Show All\n3. Filter >100\n4. Sort by Amount\n5. Save & Exit\nChoice: ";
        cin >> choice;
        if(choice == 1) {
            Transaction t;
            cout << "Enter type(income/expense): "; cin >> t.type;
            cout << "Enter amount: "; cin >> t.amount;
            cout << "Enter category: "; cin >> t.category;
            records.push_back(t);
        } else if(choice == 2) {
            for(auto &t : records) cout << t.type << " " << t.amount << " " << t.category << "\n";
        } else if(choice == 3) {
            for(auto &t : records) if(t.amount > 100) cout << t.type << " " << t.amount << " " << t.category << "\n";
        } else if(choice == 4) {
            sort(records.begin(), records.end(), [](Transaction &a, Transaction &b){return a.amount < b.amount;});
        } else if(choice == 5) {
            saveToFile(records);
            break;
        }
    }
}
