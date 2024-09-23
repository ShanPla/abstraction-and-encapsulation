#include <iostream>
#include <limits>
using namespace std;

	int choice, subchoice;
		
class Account{

	private:
		double balance, deposit, withdraw;
		bool valid = false;
		
	protected:
		Account(double empBalance) : balance(empBalance){}
		
	public:
		
		virtual void accBalance() = 0;
		
		int getBalance(){
			return balance;
		}
		int getDeposit(){
			return deposit;
		}
		int getWithdraw(){
			return withdraw;
		}
		
		void Deposit(){
		
			valid = false;
			while(!(valid)){
			
			cout<<"Please input the amount to be deposited: ";
			cin>>deposit;
			
			if(cin.fail()){	
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("CLS");		
		}
			if(deposit>0){
				valid = true;
			}
			
			else if(deposit<1){
				cout<<"\nInput must exceed 0php."<<endl;
			}	
		}
		balance += deposit;
		}
		
		void Withdraw(){
			
			valid = false;
			while(!(valid)){
			
			cout<<"Please input the amount to be withdrawed: ";
			cin>>withdraw;
			
			if(cin.fail()){	
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("CLS");		
		}
			if(withdraw>0){
				valid = true;
			}
			
			else if(withdraw<1){
				cout<<"\nInput must exceed 0php."<<endl;
			}	
		}
		balance -= withdraw;
		}
		
};

class SavingsAccount : public Account{
	
	private:
		double savings;
	
	public:
		SavingsAccount(double balance) : Account(balance){}
	
		void accBalance() override {
			
			savings = getBalance();
        	cout << "This is the Savings Account balance: " << savings << " php." << endl;
    }
		
	};
	
class CurrentAccount : public Account{
	
	private:
		double savings;
	
	public:
		CurrentAccount(double balance) : Account(balance){}
	
		void accBalance() override {
			
			savings = getBalance();
        	cout << "This is the Current Account balance: " << savings << " php." << endl;
    }
		
	};	
	
void SubMenu(){

		cout<<"\n\tSub Menu"<<endl;
		cout<<"[1] - Deposit"<<endl;
		cout<<"[2] - Withdraw"<<endl;
		cout<<"[3] - Check Balance"<<endl;
		cout<<"[4] - Back"<<endl;

}

int main(){
	
	SavingsAccount savings(1000);
	CurrentAccount current(0);
	
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
		
	}
	
	switch (choice){
			case 1:
				cout<<"\nSavings Account"<<endl;
				break;
			case 2: 
				cout<<"\nCurrent Account"<<endl;
				break;
			case 3:
				cout<<"Terminating program...";
				entry = true;
				break;
			default:
				system("CLS");
				cout << "Invalid Input. Please try again." << endl;
		}
	
	if(choice == 1 || choice == 2){
	
	bool subvalid = false;
		
	while (!(subvalid)){
		
		SubMenu();
			
		cout<<"Enter choice: ";
		cin>>subchoice;
		
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("CLS");
		}
		
		if(choice == 1){
		
		switch (subchoice){
			case 1:
				savings.Deposit();
				break;
			case 2:
				savings.Withdraw();
				break;
			case 3:
				savings.accBalance();
				break;
			case 4:
				system("CLS");
				cout << "Going Back...\n" << endl;
				subvalid = true;
				break;
			default:
				system("CLS");
				cout << "Invalid Input. Please try again." << endl;
			}
	}
		if(choice == 2){
		
		switch (subchoice){
			case 1:
				current.Deposit();
				break;
			case 2:
				current.Withdraw();
				break;
			case 3:
				current.accBalance();
				break;
			case 4:
				system("CLS");
				cout << "Going Back...\n" << endl;
				subvalid = true;
				break;
			default:
				system("CLS");
				cout << "Invalid Input. Please try again." << endl;
			}
		}
	}
}
}
}

