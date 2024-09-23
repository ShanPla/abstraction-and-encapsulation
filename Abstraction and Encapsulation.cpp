#include <iostream>
#include <limits>
using namespace std;
		
class Account{

	private:
		double balance, deposit, withdraw;
		bool isvalid = false;
		
	protected:
		Account(double empBalance) : balance(empBalance){}
		
	public:
		
		virtual void accBalance() = 0;
		
		double getBalance(){
			return balance;
		}
		double getDeposit(){
			return deposit;
		}
		double getWithdraw(){
			return withdraw;
		}
		
		void Deposit(){
		
			isvalid = false;
			while(!(isvalid)){
			
			cout<<"\nPlease input the amount to be deposited: ";
			cin>>deposit;
			
			if(cin.fail()){	
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("CLS");		
		}
			if(deposit>0){
				cout<<"Successfully deposited!"<<endl;
				isvalid = true;
			}
			
			else if(deposit<1){
				cout<<"\nInput must exceed 0php."<<endl;
			}	
		}
		balance += deposit;
		}
		
		void Withdraw(){
			
			isvalid = false;
			while(!(isvalid)){
			
			cout<<"\nYour balance is: "<<balance<<endl;
			cout<<"Please input the amount to be withdrawed: ";
			cin>>withdraw;
			
			if(cin.fail()){	
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("CLS");		
		}
			if(withdraw>balance){
				cout<<"\nError. Amount to be withdrawn must not exceed balance."<<endl;
				return;
			}
			if(withdraw>0){
				cout<<"Successfully withdrawn!"<<endl;
				isvalid = true;
			}
			
			else if(withdraw<1){
				cout<<"\nInput must exceed 0php."<<endl;
			}	
		}
		balance -= withdraw;
		}		
};

class SavingsAccount : public Account{
		
	public:
		SavingsAccount(double balance) : Account(balance){}
	
		void accBalance() override {
			
        	cout << "This is the Savings Account balance: " << getBalance() << " php." << endl;
    }		
	};
	
class CurrentAccount : public Account{
	
	public:
		CurrentAccount(double balance) : Account(balance){}
	
		void accBalance() override {
			
        	cout << "This is the Current Account balance: " << getBalance() << " php." << endl;
    }		
	};	
	
void SubMenu(Account &account) {
	
    int subchoice;
    bool subvalid = false;

    while (!subvalid) {
        cout << "\n\tSub Menu" << endl;
        cout << "[1] - Deposit" << endl;
        cout << "[2] - Withdraw" << endl;
        cout << "[3] - Check Balance" << endl;
        cout << "[4] - Back" << endl;
        cout << "Enter choice: ";
        cin >> subchoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        }
		 else 
		 {
            switch (subchoice) 
			{
                case 1:
                    account.Deposit();
                    break;
                case 2:
                    account.Withdraw();
                    break;
                case 3:
                    account.accBalance();
                    break;
                case 4:
                	system("CLS");
                    cout << "Going back to main menu...\n";
                    subvalid = true;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        }
    }
}

int main(){
	
	SavingsAccount savings(1000);
	CurrentAccount current(10);
	int choice;
	bool entry = false;

	while(entry == false){
		
		cout<<"\tMain Menu"<<endl;
		cout<<"[1] - Saving Account"<<endl;
		cout<<"[2] - Current Account"<<endl;
		cout<<"[3] - Exit"<<endl;
	
		cout<<"Input choice: ";
		cin>>choice;

		if(cin.fail()){
		
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("CLS");
			continue;
	}
	
	switch (choice){
			case 1:
				cout<<"\nSavings Account"<<endl;
				SubMenu(savings);
				break;
			case 2: 
				cout<<"\nCurrent Account"<<endl;
				SubMenu(current);
				break;
			case 3:
				cout<<"Terminating program...";
				entry = true;
				break;
			default:
				system("CLS");
				cout << "Invalid Input. Please try again." << endl;
		}
	}
	return 0;
}