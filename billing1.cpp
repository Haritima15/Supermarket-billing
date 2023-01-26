#include <iostream>
#include <fstream>

using namespace std;

class Shopping
{
    private:
        int pCode;
        float pPrice , discount;
        string pName;
    
    public:
        void MainMenu();
        void Administrator();
        void Buyer();
        void Add();
        void Edit();
        void Remove();
        void ShowList();
        void Buy();
        void Receipt(int[],int[]);
};

void Shopping :: MainMenu()
{
    m:
    int choice;
    string email , password;

    cout<<"\n\n";
    cout<<"|-----------------------------------------|\n";
    cout<<"|         Supermarket Main Menu           |\n";
    cout<<"|-----------------------------------------|\n";
    cout<<"|         1) Adminstrator                 |\n";
    cout<<"|                                         |\n";
    cout<<"|         2) Buyer                        |\n";
    cout<<"|                                         |\n";
    cout<<"|         3) Exist                        |\n";
    cout<<"|-----------------------------------------|\n";

    cout<<"\nPlease Select:";
    cin>>choice;

    switch (choice)
    {
        case 1:
            cout<<"\n_________Login___________";
            cout<<"\n\nEmail:";
            cin>>email;
            cout<<"Password:";
            cin>>password;

            if(email == "admin@gmail.com" && password == "admin@123")
            {
                Administrator();
            }
            else
            {
                cout<<"\nInvalid admin Username and Password";
            }
            break;
        case 2:
            Buyer();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"\nWrong choice!!! Please select from the given option";
            break;
    }

    goto m;
    
}

void Shopping :: Administrator()
{
    m:
    int choice;
    cout<<"\n\n";
    cout<<"|-----------------------------------------|\n";
    cout<<"|          Aministrator Menu              |\n";
    cout<<"|-----------------------------------------|\n";
    cout<<"|          1) Add the product             |\n";
    cout<<"|                                         |\n";
    cout<<"|          2) Modify the product          |\n";
    cout<<"|                                         |\n";
    cout<<"|          3) Delete the product          |\n";
    cout<<"|                                         |\n";
    cout<<"|          4) Back to main menu           |\n";
    cout<<"|-----------------------------------------|\n";

    cout<<"\nPlease Select:";
    cin>>choice;

    switch(choice)
    {
        case 1:
            Add();
            break;
        case 2:
            Edit();
            break;
        case 3:
            Remove();
            break;
        case 4:
            MainMenu();
            break;
        default:
            cout<<"\nWrong choice!!! Please select from the given option";
            break;
    }

    goto m;

}

void Shopping :: Buyer()
{
    m:
    int choice;
    cout<<"\n\n";

    cout<<"|--------------------------------------|\n";
    cout<<"|           Buyer Menu                 |\n";
    cout<<"|--------------------------------------|\n";
    cout<<"|           1) Buy the product         |\n";
    cout<<"|                                      |\n";
    cout<<"|           2) Go back                 |\n";
    cout<<"|--------------------------------------|\n";

    cout<<"\nPlease Select:";
    cin>>choice;

    switch(choice)
    {
        case 1:
            Buy();
            break;
        case 2:
            MainMenu();
            break;
        default:
            cout<<"\nWrong choice!!! Please select from the given option";
            break;
        
    }

    goto m;
}

void Shopping :: Add()
{
    fstream data;
    int token=0 , dCode;
    float dPrice , dDiscount;
    string dName;

    m:
    cout<<"\n\n";
    cout<<"_____Enter new product details_____";
    cout<<"\nProduct Code: ";
    cin>>pCode;
    cout<<"\nProduct Name:";
    cin>>pName;
    cout<<"\nProdut Price:";
    cin>>pPrice;
    cout<<"\nDiscount on product:";
    cin>>discount;

    data.open("database.txt" , ios::in);

    if(!data)
    {
        data.open("database.txt" , ios::out | ios::app);
        data<<" "<<pCode<<" "<<pName<<" "<<pPrice<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>dCode>>dName>>dPrice>>dDiscount;

        while(!data.eof())
        {
            if(dCode == pCode)
            {
                cout<<"\nDuplicate data!!!Enter again";
                goto m;
            }
            
            data>>dCode>>dName>>dPrice>>dDiscount;

        }

        data.open("database.txt" , ios::out | ios::app);
        data<<" "<<pCode<<" "<<pName<<" "<<pPrice<<" "<<discount<<"\n";
        data.close();
        cout<<"\n\nRecord inserted!!!";
    }

}

void Shopping :: Remove()
{
    fstream data,data1;
    int token=0 , dCode , searchCode;
    float dPrice , dDiscount;
    string dName;

    ShowList();
    cout<<"\n______Delete record______";
    cout<<"\n\nEnter the product code to be Deleted:";
    cin>>searchCode;

    data.open("database.txt" , ios::in);
    if(!data)
    {
        cout<<"\nFile not exists";
    }
    else
    {
        data1.open("database1.txt" , ios::out | ios::app);
        data>>pCode>>pName>>pPrice>>discount;
        
        while(!data.eof())
        {
            if(searchCode == pCode)
            {
                token++;
            }
            else{
                data1<<" "<<pCode<<" "<<pName<<" "<<pPrice<<" "<<discount<<"\n";
            }

            data>>pCode>>pName>>pPrice>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt" , "database.txt");

        if(token == 0)
            cout<<"\nRecord not found!!!!";
        else  
        {
            cout<<"\nRecord Deleted!!!!";
            ShowList();
        }  
            

    }
    
}

void Shopping :: Edit()
{
    fstream data,data1;
    int token=0 , dCode , searchCode;
    float dPrice , dDiscount;
    string dName;

    ShowList();
    cout<<"\n______Modify the record______";
    cout<<"\n\nEnter the product code to be modify:";
    cin>>searchCode;

    data.open("database.txt" , ios::in);
    if(!data)
    {
        cout<<"\nFile not exists";
    }
    else
    {
        data1.open("database1.txt" , ios::out | ios::app);
        data>>pCode>>pName>>pPrice>>discount;
        
        while(!data.eof())
        {
            if(searchCode == pCode)
            {
                cout<<"\n\n";
                cout<<"_____Enter new product details_____";
                cout<<"\nProduct Code: ";
                cin>>dCode;
                cout<<"\nProduct Name:";
                cin>>dName;
                cout<<"\nProdut Price:";
                cin>>dPrice;
                cout<<"\nDiscount on product:";
                cin>>dDiscount;
                data1<<" "<<dCode<<" "<<dName<<" "<<dPrice<<" "<<dDiscount<<"\n";
                
                token++;
            }
            else{
                data1<<" "<<pCode<<" "<<pName<<" "<<pPrice<<" "<<discount<<"\n";
            }

            data>>pCode>>pName>>pPrice>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt" , "database.txt");

        if(token == 0)
            cout<<"\nRecord not found!!!!";
        else  
        {
            cout<<"\nRecord Modified!!!!";
            ShowList();
        }  
            

    }
    
}

void Shopping :: ShowList()
{
    fstream data;
    data.open("database.txt" , ios::in);

    cout<<"\n\n";
    cout<<"|-----------------------------------------------------------------------------------------------------------\n";
    cout<<"|Code\t\t\tName\t\t\t\t\tPrice\t\t\tDiscount\t\t\t\t\n";
    cout<<"|-----------------------------------------------------------------------------------------------------------\n";

    data>>pCode>>pName>>pPrice>>discount;

    while(!data.eof())
    {
        cout<<"|"<<pCode<<"\t\t\t"<<pName<<"\t\t\t\t\t"<<pPrice<<"\t\t\t"<<discount<<"\t\t\t\t\n";
        data>>pCode>>pName>>pPrice>>discount;
    }
    data.close();
}

void Shopping :: Buy()
{
    int arrCode[100] , arrQuant[100];
    char ch;
    fstream data;

    
    data.open("database.txt" , ios::in);
    if(!data)
        cout<<"\nEmpty database!!!";
    else
    {
        data.close();
        ShowList();
        m:
        cout<<"\n_______Place Order_______";
        int c=0;
        do
        {
            cout<<"\nEnter the Product code to order:";
            cin>>arrCode[c];
            cout<<"\nEnter the quantity:";
            cin>>arrQuant[c];

            for(int i=0;i<c;i++)
            {
                if(arrCode[c]==arrCode[i])
                {
                    cout<<"\nDuplicate product code please try again!!!";
                    goto m;
                }
            }
            c++;
            cout<<"\nTo buy another product press y else press n:";
            cin>>ch;
        } while (ch == 'y' || ch == 'Y');
        
        Receipt(arrCode,arrQuant);
    }
}

void Shopping :: Receipt(int arrCode[] , int arrQuant[])
{
    int total=0 , dis , ammount;
    fstream data;

    cout<<"\n\n";
    cout<<"|----------------------------------------------RECEIPT----------------------------------------------------------\n";
    cout<<"|Product no\t\t\t"<<"Product Name\t\t\t\t\t"<<"Quantity\t\t"<<"Ammount\t\t"<<"Ammount after discount\t\t"<<"    \n";
    cout<<"|---------------------------------------------------------------------------------------------------------------\n";

    data.open("database.txt" , ios::in);
    for (int i = 0; i < sizeof(arrCode) / sizeof(int); i++)
    {
        data>>pCode>>pName>>pPrice>>discount;
        while (!data.eof())
        {
            if(pCode==arrCode[i])
            {
                ammount = pPrice * arrQuant[i];
                dis = ammount - ((ammount * discount) / 100);
                total = total + dis;
                cout<<"|"<<pCode<<"\t\t\t"<<pName<<"\t\t\t\t\t"<<arrQuant[i]<<"\t\t"<<ammount<<"\t\t"<<dis<<"\t\t"<<"    \n";
            }
            data>>pCode>>pName>>pPrice>>discount;
        }
        
    }
    cout<<"|--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Total:"<<total;

    data.close();
}

int main()
{
    Shopping s;
    s.MainMenu();

    return(0);
}