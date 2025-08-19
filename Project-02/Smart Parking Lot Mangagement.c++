#include <iostream>
using namespace std;

struct Car {
    int regNo;
    Car* next;
};

Car* head = NULL;
int capacity = 5, count = 0;

void parkCar(int reg) {
    if(count >= capacity) { cout << "Parking Full\n"; return; }
    Car* newCar = new Car{reg, head};
    head = newCar;
    count++;
    cout << "Car " << reg << " parked.\n";
}

void exitCar(int reg) {
    Car *temp = head, *prev = NULL;
    while(temp && temp->regNo != reg) { prev = temp; temp = temp->next; }
    if(!temp) { cout << "Not Found\n"; return; }
    if(prev) prev->next = temp->next;
    else head = temp->next;
    delete temp;
    count--;
    cout << "Car " << reg << " exited.\n";
}

void display() {
    cout << "Active Cars: ";
    for(Car* t = head; t; t=t->next) cout << t->regNo << " ";
    cout << "\nSlots used: " << count << "/" << capacity << "\n";
}

int main() {
    int ch, reg;
    while(true) {
        cout << "\n1. Park\n2. Exit\n3. Display\n4. Quit\nChoice: ";
        cin >> ch;
        if(ch==1){ cout<<"Reg No: ";cin>>reg; parkCar(reg);}
        else if(ch==2){ cout<<"Reg No: ";cin>>reg; exitCar(reg);}
        else if(ch==3) display();
        else break;
    }
}
