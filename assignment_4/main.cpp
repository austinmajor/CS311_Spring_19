#include <iostream>

using namespace std;

class Patron
{
private:
  string name;
  string card_number;
  int fees;

public:
  Patron(string name, string card_number, int fees = 0)
  {
    this->name = name;
    this->card_number = card_number;
    this->fees = fees;
  }

  string getName()
  {
    return name;
  }

  string getCardNumber()
  {
    return card_number;
  }

  int getFeesToPay()
  {
    return fees;
  }

  void setFeesToPay(int fees)
  {
    this->fees = fees;
  }

  bool isOwingFee()
  {
    if (fees > 0)
      return true;
    else
      return false;
  }
};

int main()
{
  Patron *p1 = new Patron("Austin", "U00001");
  int fee;
  char ch;

  cout << "User name: " << p1->getName();

  cout << endl
       << "Card number: " << p1->getCardNumber();

  if (p1->isOwingFee())
  {
    cout << "As per the records the user is already having fees of " << p1->getFeesToPay() << " to pay.";
  }

  else
  {
    cout << endl
         << "Is this user owing a fee? Enter 'y' or 'n'.. ";
    cin >> ch;

    if (ch == 'y' || ch == 'Y')
    {
      cout << "Enter the fees that user " << p1->getName() << "$ has to pay: ";
      cin >> fee;

      p1->setFeesToPay(fee);
    }
  }

  cout << endl
       << "Modified details are as follows...." << endl;

  cout << "User name: " << p1->getName();

  cout << endl
       << "Card number: " << p1->getCardNumber();

  cout << endl
       << "Fees to pay: " << p1->getFeesToPay() << "$" << endl;
}