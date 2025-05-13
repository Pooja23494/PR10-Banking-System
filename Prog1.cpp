// Banking System

#include <iostream>
using namespace std;

class BankAccount
{
protected:
    long int accountNumber;
    string accountHolderName;
    char accountType;
    double balance;

public:
    void setAccount(long int accountNumber, string accountHolderName, char accountType, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->accountType = accountType;
        this->balance = balance;
    }
    void deposit(double depositAmount, double balance)
    {
        this->balance += depositAmount;
        cout << "Deposit of Amount " << depositAmount << " Successful." << endl;
        cout << "New Balance is: " << this->balance << endl;
    }
    void withdraw(double withdrawAmount, double balance)
    {
        this->balance -= withdrawAmount;
        cout << "Withdraw of Amount " << withdrawAmount << " Successful." << endl;
        cout << "New Balance is: " << this->balance << endl;
    }
    void getBalance()
    {
        cout << "Current Balance: " << this->balance << endl;
    }
    void displayAccountInfo()
    {
        cout << endl;
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Account Holder Name: " << this->accountHolderName << endl;
        cout << "Account Type: " << this->accountType << endl;
        cout << "Balance: " << this->balance << endl;
    }
};

class SavingAccount : public BankAccount
{
protected:
    float interestRate;

public:
    void calculateInterest(float interestRate, double balance)
    {
        cout<<"Your Balance: "<<this->balance<<endl;
        this->balance += this->balance * interestRate;
        cout << "Interest Applied. New balance is: " << this->balance << endl;
    }
};

class CheckingAccount : public BankAccount
{
protected:
    double overdraftLimit;

public:
    void checkOverdraft(double overdraftLimit, double withdrawAmount, double balance)
    {
        if ( withdrawAmount <= balance + overdraftLimit && this->balance > 0)
        {
            BankAccount::withdraw(withdrawAmount, balance);
        }
        else
        {
            cout << "Withdrawal amount exceed balance and over draft limit." << endl;
        }
    }
};

class FixedDepositeAccount : public BankAccount
{
protected:
    int term;
    float interestRate;

public:
    void calcalculateInterest(float interestRate, double balance, int term)
    {
        cout<<"Enter term: ";
        cin>>term;
        
        cout<<"Your Balance: "<<this->balance<<endl;
        this->balance += this->balance * interestRate *term / 12;
        cout << "Interest Applied. New balance is: " << this->balance << endl;
    }
};

int main()
{

    long int accountNumber;
    string accountHolderName;
    double balance;
    char accountType;
    int choice;

    cout << "Please Enter Detail for create your Account" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Account Holder Name: ";
    cin >> accountHolderName;
    cout << "Enter Account Type (Saving = s, Checking = c, Fixed Deposit = f): ";
    cin >> accountType;
    cout << "Enter Balance: ";
    cin >> balance;
    cout << "-------------------------------------------" << endl;

    if (accountType == 's' || accountType == 'S')
    {
        SavingAccount saving;
        saving.setAccount(accountNumber, accountHolderName, accountType, balance);
        cout << "Saving Account create successfully." << endl;
        float interestRate=0.05;
        cout<<endl;
        
        do
        {
            cout << "***************************************"<<endl;
            cout << "Enter 1 for Deposit" << endl;
            cout << "Enter 2 for Withdraw" << endl;
            cout << "Enter 3 for Calculate interest" << endl;
            cout << "Enter 4 for Get Balance" << endl;
            cout << "Enter 5 for Display Account Information" << endl;
            cout << "Enter 0 for Exit" << endl;
            cout << "***************************************";
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                double depositAmount;

                cout << "Enter Amount you want to deposit: ";
                cin >> depositAmount;
                saving.deposit(depositAmount, balance);
                break;

            case 2:
                double withdrawAmount;

                cout << "Enter Amount you want to withdraw: ";
                cin >> withdrawAmount;
                if (withdrawAmount < balance)
                {
                    saving.withdraw(withdrawAmount, balance);
                }
                else
                {
                    cout << "Withdrawal Amount must be less than your account balance." << endl;
                }
                break;

            case 3:
                saving.calculateInterest(interestRate,balance);
                break;

            case 4:
                saving.getBalance();
                break;

            case 5:
                saving.displayAccountInfo();
                break;

            default:
                cout << "Exit.";
                break;
            }
        } while (choice != 0);
    }
    else if(accountType == 'c' || accountType == 'C')
    {
        CheckingAccount check;
        check.setAccount(accountNumber, accountHolderName, accountType, balance);
        cout << "Checking Account create successfully." << endl;
        double overdraftLimit=5000;
        cout<<endl;
        do
        {
            cout << "***************************************"<<endl;
            cout << "Enter 1 for Deposit" << endl;
            cout << "Enter 2 for Withdraw" << endl;
            cout << "Enter 3 for Get Balance" << endl;
            cout << "Enter 4 for Display Account Information" << endl;
            cout << "Enter 0 for Exit" << endl;
            cout << "***************************************";
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                double depositAmount;

                cout << "Enter Amount you want to deposit: ";
                cin >> depositAmount;
                check.deposit(depositAmount, balance);
                break;

            case 2:
                double withdrawAmount;

                cout << "Enter Amount you want to withdraw: ";
                cin >> withdrawAmount;
                check.checkOverdraft(overdraftLimit,withdrawAmount,balance);
                break;

            case 3:
                check.getBalance();
                break;

            case 4:
                check.displayAccountInfo();
                break;

            default:
                cout << "Exit.";
                break;
            }
        } while (choice != 0);
    }
    else
    {
        FixedDepositeAccount fixed;
        fixed.setAccount(accountNumber, accountHolderName, accountType, balance);
        cout << "Fixed Deposit Account create successfully." << endl;
        float interestRate=0.07;
        int term;
        cout<<endl;
        
        do
        {
            cout << "***************************************"<<endl;
            cout << "Enter 1 for Deposit" << endl;
            cout << "Enter 2 for Withdraw" << endl;
            cout << "Enter 3 for Calculate interest" << endl;
            cout << "Enter 4 for Get Balance" << endl;
            cout << "Enter 5 for Display Account Information" << endl;
            cout << "Enter 0 for Exit" << endl;
            cout << "***************************************";
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                double depositAmount;

                cout << "Enter Amount you want to deposit: ";
                cin >> depositAmount;
                fixed.deposit(depositAmount, balance);
                break;

            case 2:
                cout<<"Withdrawal not allowed untill the end of the term."<<endl;
                break;

            case 3:
                fixed.calcalculateInterest(interestRate,balance,term);
                break;

            case 4:
                fixed.getBalance();
                break;

            case 5:
                fixed.displayAccountInfo();
                break;

            default:
                cout << "Exit.";
                break;
            }
        } while (choice != 0);
    }

    return 0;
}