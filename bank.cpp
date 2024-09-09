#include<iostream>
using namespace std;
class Digital_wallet{
    public:
    double balance;
    int reward_point;
    virtual void load(double money, int trans) = 0;
    virtual void payment(double money, int trans) = 0;
    virtual void payment_history()=0;

};
class Transaction : virtual public Digital_wallet{
    public:
    int transarr[5]= {0,0,0,0,0};
    int trans_id;
    Transaction (double bal=0,int rewrad=0,int trans_id=0){
        balance = bal;
        reward_point = rewrad;
        this->trans_id = trans_id;
        if (reward_point>1000){
            balance += (reward_point/1000) * 10;
        }
    }
    void load(double money,int trans){
        balance += money;
        transarr[trans%5] = money;
        cout<<"Deposited: Rs."<<money<<" New Bal: Rs."<<balance;
    }
    void payment(double money, int trans){
        if(balance<money) {
            cout<<"Insufficient Balance";
        }
        else {
            balance -= money;
            transarr[trans%5] = -money;
            cout<<"Payment successful of Rs."<<money<<" New Bal: Rs."<<balance<<endl;
            if(money > 2000) reward_point += 50;
        }
        if (reward_point>1000){
            balance += (reward_point/1000) * 10;
        }
    }
    void payment_history(){
        cout<<"Transaction id: "<<trans_id<<endl<<endl; 
        for (int i =0 ; i < 5 ; i++){
            cout<<i<<" transaction : "<<transarr[i]<<endl;
        }
    }
};
int main(){
    Digital_wallet* dw;
    Transaction tt(20000,10,1);
    dw = &tt;
    int i = 0;
    while(true){
        int a;
        cout<<"Enter task you want to perform \n 1 = payment \n 2 = load \n 3 = payment history \n 4 = exit application ";
        cin>>a;
        if(a == 1 ){
            double money;
            cout<<"Enter the amount : ";
            cin>>money;
            dw->payment(money,i);
        }
        else if( a == 2){
            double money;
            cout<<"Enter the amount : ";
            cin>>money;
            dw->load(money,i);
        } else if ( a == 3){
            dw->payment_history();
        } else if( a == 4){
            break;
        } else{
            cout<<"Enter valid input !!!"<<endl;
     
        }
        i++;
    }
    
}
