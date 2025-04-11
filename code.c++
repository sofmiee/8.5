#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
    // Конструктор
    BankAccount(string accNum, string owner, double initialBalance):
        accountNumber(accNum), ownerName(owner), balance(initialBalance) {}

    // Метод для пополнения счёта
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнение на " << amount << " успешно. Новый баланс: " << balance << "\n";
        }
        else {
            cout << "Сумма пополнения должна быть положительной.\n";
        }
    }

    // Метод для снятия средств
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снятие " << amount << " успешно. Новый баланс: " << balance << "\n";
        }
        else if (amount > balance) {
            cout << "Недостаточно средств для снятия.\n";
        }
        else {
            cout << "Сумма снятия должна быть положительной.\n";
        }
    }

    // Метод для получения текущего баланса
    double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate; // Процентная ставка

public:
    // Конструктор
    SavingsAccount(string accNum, string owner, double initialBalance, double rate)
        : BankAccount(accNum, owner, initialBalance), interestRate(rate) {}

    // Метод для начисления процентов
    void addInterest() {
        double interest = balance * (interestRate / 100);
        deposit(interest); // Используем метод deposit для добавления процентов
        cout << "Начислены проценты: " << interest << ". Новый баланс: " << getBalance() << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    // Создание объекта BankAccount
    BankAccount account1("123456", "Иван Иванов", 1000.0);
    account1.deposit(500);
    account1.withdraw(200);

    // Создание объекта SavingsAccount
    SavingsAccount savingsAccount("654321", "Петр Петров", 2000.0, 5.0);
    savingsAccount.deposit(300);
    savingsAccount.withdraw(100);
    savingsAccount.addInterest(); // Начисление процентов

    return 0;
}
