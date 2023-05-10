#include<conio.h>    //21BCA0044 , 21BCA0001
#include<iostream>
#include<string>
using namespace std;
                      // PROJECT ATM 
class atm{
    long int account_numer;
    string name;
    int pin;
    double balance ;
    string mobile_number;
    //initializing
public :
 void set_data(    long int account_numer_1,string name_1,int pin_1,double balance_1 ,string mobile_number_1 )
 { account_numer=account_numer_1;
     name=name_1;
     pin=pin_1;
     balance =balance_1;
     mobile_number =mobile_number_1;
 }
 // print the detials
 long int  get_accountn_no()
 {
    return account_numer;
 }
 string get_name()
 {
    return name;
 }
int get_pin()
{
    return pin;
}

double get_balance()
{
    return balance;
}

string get_moblie()
{
    return mobile_number;
}

// modify the number

void set_mobile(string mobile_pre,string mobile_new)
{
    if(mobile_pre == mobile_number)
    {
        mobile_number = mobile_new;
        cout<<"MOBILE NUMBER HAS BEEN CHANGED \n";
        _getche();
    }

    else {
        cout<<"ERROR !!! \nENTER THE CORRECT OLD NUMBER \n TO CHANGE \n";
        _getch();
    }
}
// cash withdraw
void cash_withdraw( long int amount_1)
{
  if(amount_1 > 0 && amount_1 < balance)  // PROBLEM
  {
    balance -= amount_1;
    cout<<endl<<"PLEASE COLLACT THA MONEY :\n";
    cout<<endl<<"AVAILABLE BALANCE : \n"<<balance;
    _getch();
  }  

  else if(amount_1 > balance || amount_1 < 0) {
   cout<<endl<<"ERROR !!! \n" <<"INSUFFICIENT BALANCE \n"; 
  }

  else{
    cout<<endl<<"ERROR !!! \n" <<"INSUFFICIENT BALANCE \n"; 
  }
}
};
// MAIN

int main ()
{
    int choose =0;
    int enter_pin;
    long int enter_account_no;
    system("cls");
    int n,i;
    cout<<"\t\t- - - SERVER SIDE - - - \n\n";
    cout<<"ENTER THE NUMBER OF USERS ARE IN THE BANK \n";
    cin>>n;
    atm user[n];
    //SERVER SIDE
for(i=0;i<n;i++)
{   
    cout<<"user "<<i+1<<": \n";
   long int acc;
   cout<<"ENTER THE ACCOUNT NUMBER :\n"<<endl;
   cin>>acc;
   string nme,mob;
   cout<<"ENTER THE NAME :\n";
   cin>>nme;
   cout<<"ENTER THE MOBILE NUMBER :\n";
   cin>>mob;
   int p;

   cout<<"ENTER THE PIN :\n";
   cin>>p;
   double bal;
   cout<<"ENTER THE BALANCE :";
   cin>>bal;
    cout<<"*********************************************** \n";
    user[i].set_data(acc,nme,p,bal,mob);
}

for(i=0;i<n;i++){
    
    do
    {
    cout<<endl<<"\t\t- - - ATM - - - \n"<<endl;
    cout<<endl<<"ENTER THE ACCOUNT NUMBER : \n";
    cin>>enter_account_no;

    cout<<endl<<"ENTER THE PIN : \n";
    cin>>enter_pin;

    if((enter_account_no == user[i]. get_accountn_no()) && (enter_pin==user[i].get_pin()))
    { 
        do
        {
        long int amount =0;
         string oldmobilenumber , newmobilenumber;
         system("cls");
// output
           cout<<endl<<"ATM \n";
           cout<<endl<<"\t \t ELECT OPTION \n";
           cout<<endl<<"1.CHECK BALANCE";
           cout<<endl<<"2.CASH WITHDRAW";
           cout<<endl<<"3.SHOW DETIALS ";
           cout<<endl<<"4.CHANCE MOBILE NUMBER";
           cout<<endl<<"5.exit \n";
           cin>>choose;
//switch 
           switch (choose)
           {
            case 1 :
            cout<<endl<<"YOUR BANK BALNCE IS : \n"<<user[i].get_balance();
            _getch();
            break;

            case 2:
             cout<<endl<<"ENTER THE AMOUNT :\n";
             cin>>amount;
             user[i].cash_withdraw(amount);
             break;

            case 3:
                cout<<"\n--- DETAILS --- "<<endl;
                cout<<" \n -> ACCOUT NUMBER :"<<user[i].get_accountn_no();
                cout<<"\n-> NAME :"<<user[i].get_name();
                cout<<"\n-> BALANCE :"<<user[i].get_balance();
                cout<<"\n-> MOBILE NUMBER :"<<user[i].get_moblie();
                _getch();
                break;


            case 4 :
                cout<<endl<<"ENTER THE OLD MOBILE NUMBER \n";
                cin>>oldmobilenumber;

                cout<<endl<<"ENTER THE NEW MOBILE NUMBER \n";
                cin>> newmobilenumber;

            user[i].set_mobile( oldmobilenumber,newmobilenumber);
            break;

            case 5:
            exit(0);break;

            default:
            cout<<endl<<"ENTER THE VAILD CHOOSE\n";
            break;
           }
        } while (1); 
    }
else {
    cout<<"ENTER THE CORRECT ACCOUNT NUMBER OR ENTER THE CORRECT PIN FOR FURTHER PROCESS \n";
}

    } while (1);
}
}
