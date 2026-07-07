#include<iostream>
using namespace std;
int balance=0;
string pin="2006";
string *ptr=new string[100];
int TransactionNum=0;
bool CheckBalance(string verpin){
    if(verpin==pin){
        cout<<balance<<endl;
        return 1;
    }
    else{
        cout<<endl<<"PIN is incorrect !!!"<<endl;
        return 0;
    }
}
int Deposit(int amount,string verpin){
    if(verpin==pin&&amount<=100000){
        balance+=amount;
        *(ptr+TransactionNum)="credited: "+to_string(amount);
        TransactionNum++;
        cout<<endl<<amount<<" Deposited into the account !!!"<<endl;
        return 1;
    }
    else if(verpin!=pin){
        cout<<"PIN is incorrect !!!"<<endl;
        return 0;
    }
    else if(amount>100000){
        cout<<"Only 1 lakh can be deposited at a time !!!"<<endl;
        return -1;
    }
}

int Withdraw(int amount,string verpin){
     if(verpin==pin&&amount<=balance){
        balance-=amount;
        *(ptr+TransactionNum)="debited: "+to_string(amount);
        TransactionNum++;
        cout<<endl<<amount<<" Withdrawn from the account !!!"<<endl;
        return 1;
    }
    else if(verpin!=pin){
        cout<<"PIN is incorrect !!!"<<endl;
        return 0;
    }
    else if(amount>balance){
        cout<<"Insufficient Balance!!!"<<endl;
        return -1;
    }
  }
 bool SeeTransactionHistory(string verpin){
    if(verpin==pin){
    cout<<endl;
    for(int i=0;i<=TransactionNum;i++){
        string c="";
        char*ptr2=&(*(ptr+i))[0];
       for(int j=0;j<=(*(ptr+i)).length();j++){
        c=c+*(ptr2+j);
        if(c=="credited"){
       cout<<"\033[32m"<<*(ptr+i)<<"\033[0m"<<endl;
       break;
    }
        else if(c=="debited"){
            cout<<"\033[31m"<<*(ptr+i)<<"\033[0m"<<endl;
            break;
        }
}
    }
    return 1;

 }
   else{
    cout<<"PIN is incorrect !!!"<<endl;
    return 0;
   }
}


int main(){
    while(true){
        string checkpin;
        int unsigned(amount);
        int command;
        int verify=0;
        cout<<"-------------BANK MENU---------------"<<endl;
        cout<<"1.Check Balance"<<endl<<"2.Deposit Money"<<endl<<"3.Withdraw Money"<<endl<<"4.Transaction History"<<endl<<endl;
        cin>>command;
        if(command==2){
            cout<<"Enter the amount to be Deposited---> ";
            cin>>amount;
            while(verify==0||verify==-1){
                if(verify==0){
              cout<<"Enter the PIN---> ";
              cin>>checkpin;
              verify=Deposit(amount,checkpin);
                }
                else if(verify==-1){
               cout<<"Enter the amount to be Deposited---> ";
               cin>>amount;
               cout<<"Enter the PIN---> ";
               cin>>checkpin;
                verify=Deposit(amount,checkpin);
                }
        }
        }
        else if(command==1){
            while(verify==0){
              cout<<"Enter the PIN---> ";
              cin>>checkpin;
              verify=CheckBalance(checkpin);
            }
        }
        else if(command==3){
            cout<<"Enter the amount to be Withdrawn---> ";
            cin>>amount;
            while(verify==0||verify==-1){
                if(verify==0){
              cout<<"Enter the PIN---> ";
              cin>>checkpin;
              verify=Withdraw(amount,checkpin);
                }
                else if(verify==-1){
               cout<<"Enter the amount to be Withdrawn---> ";
               cin>>amount;
               cout<<"Enter the PIN---> ";
               cin>>checkpin;
                verify=Withdraw(amount,checkpin);
                }
        }
    }
        else if(command==4){
            while(verify==0){
              cout<<"Enter the PIN---> ";
              cin>>checkpin;
              verify=SeeTransactionHistory(checkpin);
            }
        }
    }
    return 0;
}