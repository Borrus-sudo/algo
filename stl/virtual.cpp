#include <iostream>
using namespace std;

class Instrument {
    int a;

   public:
    Instrument(int a = 5) : a(a) {};
    // experiment with the presence and absence of virtual
    // this is where vtable comes in, which is also called late binding
    virtual void play() {
        cout << "Playing instrument " << this->a << endl;
    }
};

// public inheritance (whatever that was)
class Accordion : public Instrument {
    int a;

   public:
    Accordion(int a = 6) : a(a) {};
    void play() {
        cout << "Playing Accordion " << this->a << endl;
    }
};

int main() {
    Instrument* i1 = new Instrument();
    Instrument i2;
    Instrument* i3 = new Accordion();
    i1->play();
    i2.play();
    i3->play();  // without virtual keyword at  @ L11, this would output 5!, makes me wanna figure
                 // out how is this implemented in the lang?
    return 0;
}