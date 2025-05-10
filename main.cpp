#include <iostream>
#include <cmath>
using namespace std;

class Figura {
protected:
    string color;
public:
    Figura(string c) : color(c) {}
    virtual double ploshcha() = 0; // абстрактна функція
};

// Коло
class Kolo : public Figura {
private:
    double radius;
public:
    Kolo(string c, double r) : Figura(c), radius(r) {}
    double ploshcha() override {
        return 3.14 * radius * radius;
    }
};

// Прямокутник
class Pryamokutnyk : public Figura {
private:
    double width, height;
public:
    Pryamokutnyk(string c, double w, double h) : Figura(c), width(w), height(h) {}
    double ploshcha() override {
        return width * height;
    }
};

// Трикутник
class Trykutnyk : public Figura {
private:
    double osnova, vysota;
public:
    Trykutnyk(string c, double o, double v) : Figura(c), osnova(o), vysota(v) {}
    double ploshcha() override {
        return 0.5 * osnova * vysota;
    }
};

int main() {
    string color;
    int vibor;

    cout << "Obberit figuru:\n1 - Kolo\n2 - Pryamokutnyk\n3 - Trykutnyk\n";
    cin >> vibor;

    cout << "Vvedit kolir figury: ";
    cin >> color;

    if (vibor == 1) {
        double r;
        cout << "Vvedit radius kola: ";
        cin >> r;
        Kolo k(color, r);
        cout << "Ploshcha kola = " << k.ploshcha() << endl;
    } else if (vibor == 2) {
        double w, h;
        cout << "Vvedit shirynu ta vysotu pryamokutnyka: ";
        cin >> w >> h;
        Pryamokutnyk p(color, w, h);
        cout << "Ploshcha pryamokutnyka = " << p.ploshcha() << endl;
    } else if (vibor == 3) {
        double o, v;
        cout << "Vvedit osnovu ta vysotu trykutnyka: ";
        cin >> o >> v;
        Trykutnyk t(color, o, v);
        cout << "Ploshcha trykutnyka = " << t.ploshcha() << endl;
    } else {
        cout << "Nepravylnyy vibor!" << endl;
    }

    return 0;
}
