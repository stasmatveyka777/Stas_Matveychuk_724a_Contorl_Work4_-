#include <iostream>
using namespace std;

class TransportnyyZasib {
protected:
    double shvydkist;
    double potuzhnist;
public:
    TransportnyyZasib(double s, double p) : shvydkist(s), potuzhnist(p) {}
    virtual void info() = 0;
};

// Легковий автомобіль
class LehkoveAuto : public TransportnyyZasib {
public:
    LehkoveAuto(double s, double p) : TransportnyyZasib(s, p) {}
    void info() override {
        cout << "Lehkove Auto - Shvydkist: " << shvydkist << ", Potuzhnist: " << potuzhnist << endl;
    }
};

// Вантажівка
class Vantazhivka : public TransportnyyZasib {
private:
    double maksVaha;
public:
    Vantazhivka(double s, double p, double m) : TransportnyyZasib(s, p), maksVaha(m) {}
    void info() override {
        cout << "Vantazhivka - Shvydkist: " << shvydkist << ", Potuzhnist: " << potuzhnist
             << ", Maksymalna vaha: " << maksVaha << " kg" << endl;
    }
};

// Мотоцикл
class Mototsykl : public TransportnyyZasib {
public:
    Mototsykl(double s, double p) : TransportnyyZasib(s, p) {}
    void info() override {
        cout << "Mototsykl - Shvydkist: " << shvydkist << ", Potuzhnist: " << potuzhnist << endl;
    }
};

int main() {
    int vibor;
    double s, p, m;

    cout << "Obberit transportnyy zasib:\n1 - Lehkove Avto\n2 - Vantazhivka\n3 - Mototsykl\n";
    cin >> vibor;

    cout << "Vvedit shvydkist: ";
    cin >> s;

    cout << "Vvedit potuzhnist: ";
    cin >> p;

    if (vibor == 1) {
        LehkoveAuto a(s, p);
        a.info();
    } else if (vibor == 2) {
        cout << "Vvedit maksymalnu vagu (kg): ";
        cin >> m;
        Vantazhivka v(s, p, m);
        v.info();
    } else if (vibor == 3) {
        Mototsykl m(s, p);
        m.info();
    } else {
        cout << "Nepravylnyy vibor!" << endl;
    }

    return 0;
}
