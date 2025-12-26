#include <iostream>
#include <string>
using namespace std;

const int MAX_DRIVERS = 22;

class Formula {
public:
    int num;
    string name;
    string team;
    int points;
    int position;

    static Formula db[MAX_DRIVERS];  // shared database
    static int countDrivers;

    void addDriver() {
        if(countDrivers >= MAX_DRIVERS) {
            cout << "Database full.\n";
            return;
        }

        Formula f;
        cout << "Enter Driver No: ";
        cin >> f.num;

        if(findIndexByNum(f.num) != -1) {
            cout << "Driver No already exists.\n";
            return;
        }

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, f.name);

        cout << "Enter Team: ";
        getline(cin, f.team);

        cout << "Enter Position: ";
        cin >> f.position;

        f.points = calculatePoints(f.position);

        db[countDrivers++] = f;

        cout << "Driver added!\n";
    }

    void showAll() {
        if(countDrivers == 0) {
            cout << "No Records.\n";
            return;
        }

        cout << "\nDriver No\tName\tTeam\tPoints\n";
        cout << "--------------------------------------\n";
        for(int i=0; i<countDrivers; i++) {
            cout << db[i].num << "\t"
                 << db[i].name << "\t"
                 << db[i].team << "\t"
                 << db[i].points << "\n";
        }
        cout << "--------------------------------------\n";
    }

    void searchDriver() {
        int n;
        cout << "Enter Driver No: ";
        cin >> n;

        int idx = findIndexByNum(n);
        if(idx == -1) {
            cout << "Not found.\n";
            return;
        }

        Formula f = db[idx];
        cout << "Driver No: " << f.num << "\n";
        cout << "Name: " << f.name << "\n";
        cout << "Team: " << f.team << "\n";
        cout << "Points: " << f.points << "\n";
    }

    void updateTeam() {
        int n;
        cout << "Enter Driver No: ";
        cin >> n;

        int idx = findIndexByNum(n);
        if(idx == -1) {
            cout << "Not found.\n";
            return;
        }

        cout << "Current Team: " << db[idx].team << "\n";
        cin.ignore();
        cout << "Enter New Team: ";
        getline(cin, db[idx].team);
        cout << "Updated.\n";
    }

    void deleteDriver() {
        int n;
        cout << "Enter Driver No: ";
        cin >> n;

        int idx = findIndexByNum(n);
        if(idx == -1) {
            cout << "Not found.\n";
            return;
        }

        for(int i=idx; i<countDrivers-1; i++)
            db[i] = db[i+1];

        countDrivers--;
        cout << "Deleted.\n";
    }

    void showMenu() {
        cout << "\n==============================\n";
        cout << "F1 Drivers Management\n";
        cout << "==============================\n";
        cout << "1) Add Driver\n";
        cout << "2) Show All Drivers\n";
        cout << "3) Search by Num\n";
        cout << "4) Update Team\n";
        cout << "5) Delete Driver\n";
        cout << "6) Exit\n";
        cout << "Choose (1-6): ";
    }

private:
    int findIndexByNum(int n) {
        for(int i=0; i<countDrivers; i++)
            if(db[i].num == n) return i;
        return -1;
    }

    int calculatePoints(int pos) {
        switch(pos) {
            case 1: return 25;
            case 2: return 18;
            case 3: return 15;
            case 4: return 12;
            case 5: return 10;
            case 6: return 8;
            case 7: return 6;
            case 8: return 4;
            case 9: return 2;
            case 10: return 1;
            default: return 0;
        }
    }
};

// Static members initialization
Formula Formula::db[MAX_DRIVERS];
int Formula::countDrivers = 0;

int main() {
    Formula f;

    while(true) {
        f.showMenu();
        int choice;
        cin >> choice;

        if(choice == 1) f.addDriver();
        else if(choice == 2) f.showAll();
        else if(choice == 3) f.searchDriver();
        else if(choice == 4) f.updateTeam();
        else if(choice == 5) f.deleteDriver();
        else if(choice == 6) { cout << "Goodbye!\n"; break; }
        else cout << "Invalid option.\n";
    }

    return 0;
}

