/*
    Q4. A retail store has a preferred customer plan where customers may earn discounts on all
        their purchases. The amount of a customer’s discount is determined by the amount of
        the customer’s cumulative purchases in the store.
        • When a preferred customer spends $500, he or she gets a 5% discount on all future
          purchases.
        • When a preferred customer spends $1,000, he or she gets a 6% discount on all future
          purchases.
        • When a preferred customer spends $1,500, he or she gets a 7% discount on all future
          purchases.
        • When a preferred customer spends $2,000 or more, he or she gets a 10% discount on
          all future purchases.
        Design a class named PreferredCustomer, which is derived from the CustomerData
        class you created in problem 9. The PreferredCustomer class should have the following
        member variables:
        • purchasesAmount (a double)
        • discountLevel (a double)
        The purchasesAmount variable holds the total of a customer’s purchases to date. The
        discountLevel variable should be set to the correct discount percentage, according to
        the store’s preferred customer plan. Write appropriate member functions for this class
        and demonstrate it in a simple program.
*/

#include <iostream>
#include <string>

using namespace std;

class CustomerData {
    static int cid;
    const int ID;
    string name;
    long long contact;
    double totalPurchase;

  public:
    CustomerData() : ID(cid++), name(""), contact(0), totalPurchase(0) {}
    CustomerData(string n) : ID(cid++), name(n), contact(0), totalPurchase(0) {}
    CustomerData(string n, long long c) : ID(cid++), name(n), contact(c), totalPurchase(0) {}
    CustomerData(string n, long long c, double t) : ID(cid++), name(n), contact(c), totalPurchase(t) {}

    void updateName(string n) {
        name = n;
    }

    const string& getName() {
        return name;
    }

    void updateContact(long long c) {
        contact = c;
    }

    long long getContact() {
        return contact;
    }

    void addPurchaseAmount(double d) {
        totalPurchase += d;
    }

    double getTotalPurchase() {
        return totalPurchase;
    }
};
int CustomerData::cid(1);

class PreferredCustomer : public CustomerData {
    double purchasesAmount;
    double discountValue;

  public:
    PreferredCustomer() : purchasesAmount(0), discountValue(0) {}
    PreferredCustomer(double p) : purchasesAmount(p), discountValue(0) {}
    PreferredCustomer(string n, double p) : CustomerData(n), purchasesAmount(p), discountValue(0) {}
    PreferredCustomer(string n, long long c, double p) : CustomerData(n, c), purchasesAmount(p), discountValue(0) {}

    void addPurchaseAmount(double a) {
        cout << a;
        purchasesAmount += a;
    }

    double getPurchaseAmount() {
        return purchasesAmount;
    }

    void print() {
        CustomerData::addPurchaseAmount(purchasesAmount);
        if (getTotalPurchase() >= 2000) discountValue = 10.0;
        else if (getTotalPurchase() >= 1500) discountValue = 7.0;
        else if (getTotalPurchase() >= 1000) discountValue = 6.0;
        else if (getTotalPurchase() >= 500) discountValue = 5.0;

        cout << "Customer name: " << getName() << '\n';
        cout << "Discount applicable: " << discountValue << "%\n";
        cout << "Total payable amount: " << (purchasesAmount - (purchasesAmount * discountValue / 100)) << '\n';
    }
};

int main() {
    cout << "Enter customer name: ";
    string n;
    getline(cin >> ws, n);

    PreferredCustomer pc(n, 0);

    int amount = 0;
    do {
        cout << "Enter amount (0 to exit): ";
        cin >> amount;
        pc.addPurchaseAmount(amount);
    } while (amount != 0);

    pc.print();

    return 0;
}

/*
        -- OUTPUT --

Test 1:
Enter customer name: aa
Enter amount (0 to exit): 100
Enter amount (0 to exit): 100
Enter amount (0 to exit): 320
Enter amount (0 to exit): 400 
Enter amount (0 to exit): 0
Customer name: aa
Discount applicable: 5%
Total payable amount: 874

Test 2:
Enter customer name: rr
Enter amount (0 to exit): 345
Enter amount (0 to exit): 643
Enter amount (0 to exit): 134
Enter amount (0 to exit): 433
Enter amount (0 to exit): 0
Customer name: rr
Discount applicable: 7%
Total payable amount: 1446.15

*/