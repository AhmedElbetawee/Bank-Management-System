// project 3 ...
// Bank System
#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
    string owner_name;
    int Account_number;
    int balance;
    public:
        BankAccount(string n, int num, int bal)
        {
            owner_name = n;
            Account_number = num;
            balance = bal;
        }
        string get_name()
        {
            return owner_name;
        }
        int get_Account_number()
        {
            return Account_number;
        }

        int get_balance()
        {
            return balance;
        }

        void print()
        {
            cout <<"Name is : "<<owner_name<<"\n";
            cout <<"Account number is : "<<Account_number<<"\n";
            cout <<"Balance is : "<<balance<<"\n";
        }

        void add_balance(int bal)
        {
            balance += bal;
        }
        void subtract_balance(int bal)
        {
            balance -= bal;
        }


};

class System_Bank
{
    vector <BankAccount> accounts;
    public:
        void show_menu()
        {
            cout <<"1- Create Account\n";
            cout <<"2- Remove Account\n";
            cout <<"3- Search Account\n";
            cout <<"4- Display All Account\n";
            cout <<"5- Deposit\n";
            cout <<"6- Withdraw\n";
            cout <<"7- Transfer Money\n";
            cout <<"8- Exit\n";
        }

        string Creat_Account()
        {
            string n; int num, bal;
            cout<<"Enter name of Account "; cin>>n;
            cout<<"Enter number of Account "; cin>>num;
            cout<<"Enter balance of Account "; cin>>bal;
            BankAccount b1(n,num,bal);
            for (int i=0; i<accounts.size(); i++)
            {
                if (accounts[i].get_Account_number() == num)
                    return "the Account number is founded\n";  
            }
            accounts.push_back(b1);
            return "the Account is created\n";
        }

        string Remove_Account()
        {
            int num;
            cout<<"Enter number of Account "; cin>>num;
            for (int i=0; i<accounts.size(); i++)
            {
                if (accounts[i].get_Account_number() == num)
                {
                    accounts.erase(accounts.begin() + i);
                    return "the Account is removed\n";
                }
            }
            return "the Account number is not founded\n";  
        }

        string Search_Account()
        {
            int num;
            cout<<"Enter number of Account "; cin>>num;
            for (int i=0; i<accounts.size(); i++)
            {
                if (accounts[i].get_Account_number() == num)
                {
                    accounts[i].print();
                    return "the Account is founded\n";
                }
            }
            return "the Account number is not founded\n";  
        }

        string Display_all_account()
        {
            if (accounts.empty())
            {
                return "NO Accounts\n";
            }
            for (int i=0; i<accounts.size(); i++)
            {
                accounts[i].print();
            }            
            return "this is display of all acount\n";
        }

        string Deposit()
        {
            int num, amount;
            cout<<"Enter number of Account "; cin>>num;
            cout<<"Enter amount of money "; cin>>amount;

            for (int i=0; i<accounts.size(); i++)
            {
                if (accounts[i].get_Account_number() == num)
                {
                    accounts[i].add_balance(amount);
                    return "the balance is added\n";
                }
            }
            return "the number Account is not founded\n";
        }
        
        string withdraw() 
        {
            int num, amount;
            cout<<"Enter number of Account "; cin>>num;
            cout<<"Enter amount of money "; cin>>amount;

            for (int i=0; i<accounts.size(); i++)
            {
                if (accounts[i].get_Account_number() == num)
                {
                    if (accounts[i].get_balance() >= amount)
                    {
                        accounts[i].subtract_balance(amount);
                        return "the balance is subracted\n";
                    }
                    else
                        return "Insufficient Balance\n";
                }
            }
            return "the number Account is not founded\n";
        }

        string Tenasfer_money()
        {
            int n_from, n_to;
            int amount;
            cout <<"Enter From Account number "; cin>>n_from;
            cout <<"Enter To Account number "; cin>>n_to;
            cout <<"Enter amount of money "; cin>>amount;
            bool ok_from = false;
            bool ok_to = false;
            int index_from =0;
            int index_to =0;
            for (int i=0; i<accounts.size(); i++)
            {
                if(accounts[i].get_Account_number() == n_from)
                {
                    ok_from = true;
                    index_from = i;
                }
                if(accounts[i].get_Account_number() == n_to)
                {
                    ok_to = true;
                    index_to = i;
                }
                if (ok_from && ok_to)
                {
                    if (accounts[index_from].get_balance() >= amount)
                    {
                        accounts[index_from].subtract_balance(amount);
                        accounts[index_to].add_balance(amount);
                        return "Transfer comleted\n";
                    }
                    else 
                        return "Insufficient Balance\n";
                        
                }
            }
            return "fail operation make sure to number of account\n";
        }

};

int main()
{
    int num =0; 
    System_Bank s1;
    while(num != 8)
    {
        s1.show_menu();
        cout <<"Enter number from 1 to 8 "; cin>>num;

        if (num == 1)
        {
            cout <<s1.Creat_Account();
        }
        else if (num == 2)
        {
            cout <<s1.Remove_Account();
        }        
        else if (num == 3)
        {
            cout <<s1.Search_Account();
        }        
        else if (num == 4)
        {
            cout <<s1.Display_all_account();
        }        
        else if (num == 5)
        {
            cout <<s1.Deposit();
        }
        else if (num == 6)
        {
            cout <<s1.withdraw();
        }
        else if (num == 7)
        {
            cout <<s1.Tenasfer_money();
        }
    }
}