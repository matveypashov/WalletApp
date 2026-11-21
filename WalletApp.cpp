#include <iostream>
#include "Wallet.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double bal = 1000.0;
    bal = deposit(bal, 500.0);
    bal = withdraw(bal, 300.0);
    cout << "Итоговый баланс: " << bal << endl;
    cout << "Кэшбэк 5%: " << calcPercent(bal, 0.05) << endl;
    cout << "Средний чек: " << getAvgCheck(1500.0, 3) << endl;
    return 0;
}