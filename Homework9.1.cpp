#include <iostream>
#include <format>
using namespace std;

int main() {
    // Ввод данных
    setlocale(0, "rus");
    double initial_sum, credit_sum, interest_rate;
    cout << "Введите начальную сумму: ";
    cin >> initial_sum;
    cout << "Введите сумму кредита: ";
    cin >> credit_sum;
    cout << "Введите процентную ставку: ";
    cin >> interest_rate;

    // Расчет ежемесячного платежа
    double monthly_interest_rate = interest_rate / 12 / 100;
    double payment = (credit_sum * monthly_interest_rate) / (1 - 1 / pow(1 + monthly_interest_rate, initial_sum));

    cout << "Месячная ставка: " << monthly_interest_rate << endl;
    cout << "Плата в месяц: " << payment << endl;

    // Построение таблицы
    cout << "Месяц\tПлатеж\tОстаток\tПроценты" << endl;
    double remaining = credit_sum - initial_sum;
    int m = 0;
    while (remaining > 0)
    {
        double percent = remaining * monthly_interest_rate;
        remaining = remaining + percent;
        if (payment > remaining)
        {
            payment = remaining;
        }
        remaining -= payment;
        m++;
        cout << m << "\t" << payment << "\t" << (int)remaining << "\t" << percent << endl;
    }

    return 0;
}