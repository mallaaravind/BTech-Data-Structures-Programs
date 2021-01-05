//Implementation of hash functions
#include<iostream>
#include<math.h>
using namespace std;
class Hash
{
    int key;
    int size;
    public:
    void modular();
    void truncation();
    void folding();
};
void Hash :: modular()
{
    cout<<"\nEnter the size of hash table (L): ";
    cin>>size;
    cout<<"\nEnter the key to be hashed (k): ";
    cin>>key;
    cout<<"\nThe hash value generated by modular approach: "<<key%size;
}
void Hash :: truncation()
{
    cout<<"\nEnter the size of hash table (L): ";
    cin>>size;
    cout<<"\nEnter the key to be hashed (k): ";
    cin>>key;
    cout<<"\nChoose two positions to determine its index value: ";
    int pos1,pos2,count=1,n=key,sum=0,k;
    cin>>pos1>>pos2;
    while(n!=0)
    {
        k=n%10;
        sum=sum*10+k;
        n=n/10;
    }
    n=sum;
    sum=0;
    while(n!=0)
    {
        k=n%10;
        if((pos1==count)||(pos2==count))
            sum=sum*10+k;
        n=n/10;
        count++;
    }
    cout<<"\nThe index of key using truncation method: "<<sum;
}
void Hash :: folding()
{
    cout<<"\nEnter the size of hash table (L): ";
    cin>>size;
    cout<<"\nEnter the key to be hashed (k): ";
    cin>>key;
    cout<<"\nEnter the partsize of key for folding method: ";
    int partsize,n=key,count=0;
    cin>>partsize;
    while(n!=0)
    {
        n=n/10;
        count++;
    }
    if(count%partsize!=0)
        cout<<"\nThe partsize is not perfectly divisible by key value";
    else
    {
        int totalparts=count/partsize;
        cout<<"\nThe key is divided into "<<totalparts<<" parts";
        int n=key,count=0,count1=0,tmp=0,sum=0,k;
        while(n!=0)
        {
            k=n%10;
            tmp=tmp+k*pow(10,count);
            count++;
            if(count==partsize)
            {
                cout<<"\n Part: "<<tmp;
                sum=sum+tmp;
                tmp=0;
                count=0;
            }
            n=n/10;
            count1++;
        }
        cout<<"\nSum of the parts = "<<sum;
        cout<<"\nThe hash value generated by folding approach: "<<sum%size;
    }
}
int main()
{
    int k;
    Hash h1;
    while(true)
    {
        cout<<"\nSelect an option";
        cout<<"\n 1. Modular method\n 2. Trincation method\n 3. Folding method\n 4. Exit\n";
        cin>>k;
        switch(k)
        {
            case 1:h1.folding();
                    break;
            case 2:h1.truncation();
                    break;
            case 3:h1.modular();
                    break;
            case 4:exit(0);
        }
    }
}