#include <iostream>
#include "iomanip"
using namespace std;

int main() {
    setlocale(0, "rus");
    double start, credit, percent;
    cout << "Введите начальную сумму:" << endl;
    cin >> start;
    cout << "Введите сумму кредита: " << endl;
    cin >> credit;
    cout << "Введите процентную ставку: " << endl;
    cin >> percent;

    cout << "Срок кредита: 5 лет" << endl;

    double remaining = credit - start;

    double month_percent = percent / 100 / 12;

    double payment = (remaining * month_percent) / (1 - pow(1 + month_percent, 1 - 60));

    bool dos = false;
    double dospay = 0, dosm = 0;
    cout << "Хотите ввести досрочный платеж? 1 - да, 0 - нет" << endl;
    cin >> dos;
    if (dos)
    {
        cout << "Введите сумму и месяц досрочного платежа: " << endl;
        cin >> dospay >> dosm;
    }

    cout << "Месяц \t Платеж \t Остаток \t Проценты" << endl;
    int i = 0;
    while (remaining > 0)
    {
        i++;

        double procent_sum = remaining * month_percent;
        remaining = remaining + procent_sum;
        if(dosm == i && dos)
        {
            cout << endl;
            cout << "Проведение досрочного платежа на сумму " << dospay << " руб." << endl << endl;
            remaining = remaining - dospay;
        }
        if (remaining < payment)
        {
            payment = remaining;
        }
        remaining -= payment;

        // Библиотека iomanip
        // setprecision - количество знаков после запятой
        // fixed - вывод без экспоненты
        cout << setprecision(2) << fixed << i << "\t" << payment << "\t" << remaining << "\t" << procent_sum << endl;
    }

    return 0;
}