#include <iostream>
#include <iomanip>
using namespace std;

class Investment {
private:
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int years;

public:
	void getInput() {
		cout << "Initial Investment Amount: ";
		cin >> initialInvestment;

		cout << "Monthly Deposit: ";
		cin >> monthlyDeposit;

		cout << "Annual Interest (%): ";
		cin >> annualInterest;

		cout << "Number of Years: ";
		cin >> years;
	}

	void displayWithoutMonthly() {
		double balance = initialInvestment;
		double interest;

		cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
		cout << "=========================================================\n";
		cout << "Year\tYear End Balance\tInterest Earned\n";

		for (int i = 1; i <= years; i++) {
			interest = balance * (annualInterest / 100);
			balance += interest;

			cout << i << "\t$" << fixed << setprecision(2) << balance
				<< "\t\t$" << interest << endl;
		}
	}

	void displayWithMonthly() {
		double balance = initialInvestment;
		double interest;

		cout << "\nBalance and Interest With Additional Monthly Deposits\n";
		cout << "=========================================================\n";
		cout << "Year\tYear End Balance\tInterest Earned\n";

		for (int i = 1; i <= years; i++) {
			double yearlyInterest = 0;

			for (int j = 0; j < 12; j++) {
				interest = (balance + monthlyDeposit) * ((annualInterest / 100) / 12);
				yearlyInterest += interest;
				balance += monthlyDeposit + interest;
			}

			cout << i << "\t$" << fixed << setprecision(2) << balance
				<< "\t\t$" << yearlyInterest << endl;
		}
	}
};

int main() {
	Investment invest;

	invest.getInput();
	invest.displayWithoutMonthly();
	invest.displayWithMonthly();

	return 0;
}