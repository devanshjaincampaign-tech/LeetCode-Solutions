class Bank {
private:
    vector<long long> accounts;

    bool isValid(int account) {
        return account >= 1 && account <= accounts.size();
    }

public:
    Bank(vector<long long>& balance) {
        accounts = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (isValid(account1) && isValid(account2) && accounts[account1 - 1] >= money) {
            accounts[account1 - 1] -= money;
            accounts[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (isValid(account)) {
            accounts[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (isValid(account) && accounts[account - 1] >= money) {
            accounts[account - 1] -= money;
            return true;
        }
        return false;
    }
};