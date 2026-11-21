#include "Wallet.h"
#include <stdexcept>

double deposit(double balance, double amount) {
    if (amount <= 0.0) {
        throw std::invalid_argument("Сумма пополнения должна быть больше 0");
    }
    return balance + amount;
}

double withdraw(double balance, double amount) {
    if (amount <= 0.0 || amount > balance) {
        throw std::invalid_argument("Некорректная сумма снятия");
    }
    return balance - amount;
}

double calcPercent(double balance, double rate) {
    return balance * rate;
}

double getAvgCheck(double totalSum, int count) {
    if (count <= 0) {
        throw std::invalid_argument("Количество операций должно быть больше 0");
    }
    return totalSum / count;
}