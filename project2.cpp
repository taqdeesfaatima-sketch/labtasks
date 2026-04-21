#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    //Product arrays
    const int n=1000;
    string product[n];
    float price[n];
    int quantity[n];

    int choice, user;

    string itemName[n];
    string category[n];
    float costPrice[n];
    float salePrice[n];
    string supplierName[n];
    string expiryDate[n];
    string status[n];
    float totalSale[n];
    int soldQty[n];
    int index=0;
    string shopName,address,phone,email;

    while(true) //main loop
    {
      // system("cls");

      cout<<"=================================="<<endl;
      cout<<"======SHOP MANAGEMENT SYSTEM======"<<endl;
      cout<<"=================================="<<endl;
      cout<<endl;
      cout<<"Main Menu:"<<endl;
      cout<<"1. Admin Login"<<endl;
      cout<<"2.Customer"<<endl;
      cout<<"3.Exit"<<endl;
      cout<<endl;
      cout<<"Choose option:";
      int userOption;
      cin>>userOption;
      cout<<"You entered:"<<userOption<<endl;

      //=================ADMIN MENU=================
      if(userOption==1)
      {
       for(int attempt=0;attempt<3;attempt++)
       {
        // system("cls");
        cout<<"==============================================================="<<endl;
        cout<<"                Admin Login (Attempt"<<attempt+1<<"/3)         "<<endl;    
        cout<<"==============================================================="<<endl;
        cout<<"Enter Username:";
        string username;
        cin>>username;
        cout<<"Enter Password:";
        string password;
        cin>>password;

        if(username=="admin" &&password=="1234")
        {
        cout<<"\n Login Successful!Welcome Admin."<<endl;
        getch();

        while(true)
        {
        //  system("cls");
        cout << "====================================================" << endl;
        cout << "                   Admin Menu                       " << endl;
        cout << "====================================================" << endl;
        cout << "  1.  Show All Products" << endl;
        cout << "  2.  Search Product by Name" << endl;
        cout << "  3.  Add New Product" << endl;
        cout << "  4.  Update Product Record" << endl;
        cout << "  5.  Delete Product Record" << endl;
        cout << "  6.  Sell Product (Update Stock)" << endl;
        cout << "  7.  Generate Sales Report" << endl;
        cout << "  8.  Show Low Stock Products" << endl;
        cout << "  9.  Show Profit on Each Product" << endl;
        cout << "  10. Logout" << endl;
        cout << endl;
        cout << " Choose option : " ;

        int adminOption;
        cin>>adminOption;

        //----Option 1:Show All Products----
        if(adminOption == 1)
        {
        for(int i=0;i<index;i++)
        {
         for(int j=0;j<index-i-1;j++) 
         {
          if(productName[j]>productName[j+1] && productName[j+1]!="")
          {
           string tName = productName[j];
           productName[j] = productName[j + 1];
           productName[j + 1] = tName; 

           string tCat=category[j];
           category[j]=category[j+1];
           category[j+1]=tCat;

           int tQty = quantity[j];
           quantity[j] = quantity[j + 1];
           quantity[j + 1] = tQty;

           float tBP=buyPrice[j];
           buyPrice[j]=buyPrice[j+1];
           buyPrice[j+1]=tBP;

           float tSP=sellPrice[j];
           sellPrice[j]=sellPrice[j+1];
           sellPrice[j+1]=tSP;

           string tSup = supplierName[j];
           supplierName[j] = supplierName[j + 1];
           supplierName[j + 1] = tSup;

           string tExp = expiryDate[j];
           expiryDate[j] = expiryDate[j + 1];
           expiryDate[j + 1] = tExp;

           string tStat = status[j];
           status[j] = status[j + 1];
           status[j + 1] = tStat;
          }
         }
        }
        //system("cls");
        cout<<"============================================================================="<<endl;
        cout<<"                             ALL PRODUCTS(A-Z SORTED)                        "<<endl;
        cout<<"============================================================================="<<endl;
        cout << "No.\tName\t\tCategory\tQty\tBuy\tSell\tSupplier\tExpiry\t\tStatus" << endl;
        cout<<"-----------------------------------------------------------------------------"<<endl;
        for(int i=0;i<index;i++)
        {
         if (productName[i] != "") 
        {
            cout << i + 1 << "\t" << productName[i] << "\t\t" << category[i] << "\t" << quantity[i] << "\t" << buyPrice[i] << "\t" << sellPrice[i] << "\t" << supplierName[i] << "\t" << expiryDate[i] << "\t" << status[i] << endl;
        }
    }

    cout << "\nPress any key to return to Admin Menu...";
    getch();
 
  }
         //----Option 2:Search Product----
         else if(adminOption==2)
         {
          //system("cls");
         cout<<"Enter product name to search:";
         string name;
         cin>>name;
         bool found=false;
         int foundIndex=-1;
         for(int i=0;i<index;i++)
         {
         if(productName[i]==name)
         {
         foundIndex=i;
         found=true;
         }
         }
         if(!found)
         {
         cout<<"Product not found:" <<endl;
         }
         else
         {
         cout<<"\n ---Product Record---"<<endl;
         cout << "\n  --- Product Record ---" << endl; 
         cout << "  Name      : " << productName[foundIndex] << endl;
         cout << "  Category  : " << category[foundIndex] << endl;
         cout << "  Quantity  : " << quantity[foundIndex] << endl;
         cout << "  Buy Price : Rs. " << buyPrice[foundIndex] << endl;
         cout << "  Sell Price: Rs. " << sellPrice[foundIndex] << endl;
         cout << "  Supplier  : " << supplierName[foundIndex] << endl;
         cout << "  Expiry    : " << expiryDate[foundIndex] << endl;
         cout << "  Status    : " << status[foundIndex] << endl;
         cout << "  Sold Qty  : " << soldQty[foundIndex] << endl;
         cout << "  Total Sale: Rs. " << totalSale[foundIndex] << endl;
         }
         }
         //----Option 3:Add New Product----
         else if(adminOption==3)
         {
          //system("cls");
         cout<<"=================================================================="<<endl;
         cout<<"                     Add New Product                              "<<endl;
         cout<<"=================================================================="<<endl;
         if(index>=1000)
         {
         cout<<"Storage full.Cannot add more products."<<endl;
         }
         else
         {
         cout<<  "  Product Name     : "; string pname;    cin >> pname;
         cout << "  Category         : "; string cat;      cin >> cat;
         cout << "  Quantity         : "; int qty;         cin >> qty;
         cout << "  Buy Price (Rs.)  : "; float bprice;    cin >> bprice;
         cout << "  Sell Price (Rs.) : "; float sprice;    cin >> sprice;
         cout << "  Supplier Name    : "; string supplier; cin >> supplier;
         cout << "  Expiry Date      : "; string expiry;   cin >> expiry;

        productName[index]   = pname;
        category[index]      = cat;
        quantity[index]      = qty;
        buyPrice[index]      = bprice;
        sellPrice[index]     = sprice;
        supplierName[index]  = supplier;
        expiryDate[index]    = expiry;
        totalSale[index]     = 0;
        soldQty[index]       = 0;
        status[index]        = (qty <= 10) ? "Low Stock" : "Available";
        index++;
        cout<<"\n Product added successfully!"<<endl;
         }
         } 
         //----Option 4:Update Product Record----
         else if(adminOption==4)
         {
         // system("cls");
         cout<<"Enter product name to update:";
         string name;
         cin>>name;
         bool found=false;
         int foundIndex=-1;
         for(int i=0;i<index;i++)
         {
         if(productName[i]==name)
         {
         foundIndex=i;
         found=true;
         }
         }
         if(found)
         {
         cout<<"\n---Old Record---"<<endl;
         cout<<"Name:"<<productName[foundIndex]
             <<"|Qty:"<<quantity[foundIndex]
             <<"|Sell Price:"<<sellPrice[foundIndex]
             <<"|Status:"<<status[foundIndex]<<endl;
         cout<<"\n Enter new details:"<<endl;
         cout<<"New Name       :"; string newName;     cin>>newName;
         cout<<"New Category   :"; string newCat ;     cin>>newCat ;
         cout<<"New Quantity   :"; int newQty ;     cin>>newQty ;
         cout<<"New Buy Price  :"; float  newBuy ;     cin>>newBuy ;
         cout<<"New Sell Price :"; float  newSell;     cin>>newSell;
         cout<<"New Supplier   :"; string newSupplier; cin>>newSupplier;
         cout<<"New Expiry Date:"; string newExpiry;   cin>>newExpiry;
         productName[foundIndex]  = newName;
         category[foundIndex]     = newCat;
         quantity[foundIndex]     = newQty;
         buyPrice[foundIndex]     = newBuy;
         sellPrice[foundIndex]    = newSell;
         supplierName[foundIndex] = newSupplier;
         expiryDate[foundIndex]   = newExpiry;
         status[foundIndex]       = (newQty <= 10) ? "Low Stock" : "Available"; 
         
         cout<<"\n Record updated successfully!"<<endl;
         }
         else
         {
         cout<<"Product not found."<<endl;
         }
         }
         //----Option 5: Delete Product Record----
         else if(adminOption==5)
         {
          //system("cls");
         cout<<"Enter product name to delete:";
         string name;
         cin>>name;
         bool found=false;
         int foundIndex=-1;
         for(int i=0;i<index;i++)
         {
         if(productName[i]==name)
         {
         foundIndex=i;
         found=true;
         }
         }
         if(found)
         {
          productName[foundIndex]  = "";
          category[foundIndex]     = "";
          quantity[foundIndex]     = 0;
          buyPrice[foundIndex]     = 0;
          sellPrice[foundIndex]    = 0;
          supplierName[foundIndex] = "";
          expiryDate[foundIndex]   = "";
          totalSale[foundIndex]    = 0;
          soldQty[foundIndex]      = 0;
          status[foundIndex]       = "";
          cout << "  Product '" << name << "' deleted successfully." << endl;
         }
          else
          {
          cout<<"Product not found."<<endl;
          }
        }
          //----Option 6:Sell Product----
          else if(adminOption==6)
          {
           //system("cls");
          cout<<"Enter product name to sell:";
          string name;
          cin>>name;
          bool found=false;
          int foundIndex=-1;
          for(int i=0;i<index;i++)
          {
            if(productName[i]==name)
            {
          foundIndex=i;
          found=true;
          }
          }
          if(found)
          {
          cout<<"Available Quantity:"<<quantity[foundIndex]<<endl;
          cout<<"Enter quantity to sell:";
          int sellQty;
          cin>>sellQty;

          if(sellQty>quantity[foundIndex])
          {
          cout<<"Error! Not enough stock."<<endl;
          }
          else
          {
          quantity[foundIndex] -=sellQty;
          soldQty[foundIndex]  +=sellQty;
          totalSale[foundIndex]+=sellQty * sellPrice[foundIndex];
          status[foundIndex]    =(quantity[foundIndex]<=10 )? "Low Stock" : "Available";
          if(quantity[foundIndex]==0) status[foundIndex]="Out of Stock";
          cout<<"\n ==== SALE RECEIPT ====" <<endl;
          cout << "  Product   : " << productName[foundIndex] << endl;
          cout << "  Qty Sold  : " << sellQty << endl;
          cout << "  Price/Unit: Rs. " << sellPrice[foundIndex] << endl;
          cout << "  Total     : Rs. " << sellQty * sellPrice[foundIndex] << endl;
          cout << "  Remaining : " << quantity[foundIndex] << endl;
          cout << "  ========================" << endl;
            }
          }
          else
          {
          cout<<"Product not found."<<endl;
          }
          }
          //----Option 7: Sales Report----
          else if(adminOption==7)
          {
          // system("cls");
          cout<<"===================================================================="<<endl;
          cout<<"                         Sales Report                               "<<endl;
          cout<<"===================================================================="<<endl;
          cout<<"Name\t\tSold Qty\tTotal sale (Rs.)"<<endl;
          cout<<"----\t\t--------\t----------------"<<endl;
          float grandTotal=0;
          for(int i=0; i<index;i++)
          {
          if(productName[i] !="")
          {
          cout<<productName[i]<<"\t\t"<<soldQty[i]<<"\t\t"<<totalSale[i]<<endl;
          grandTotal +=totalSale[i];
          
          }
          }
          cout<<"-----------------------------------------"<<endl;
          cout<<"Grand Total Sales: Rs."<<grandTotal<<endl;
          }
          
          //----Option 8: Low Stock Products----
          else if(adminOption==8)
          {
             //system("cls");
            cout<<"=================================================================="<<endl;
            cout<<"                Low Stock/ Out of Stock                          "<<endl;
            cout<<"=================================================================="<<endl;
            cout << "Name\t\tCategory\tQuantity\tStatus" << endl;
            cout << "----\t\t--------\t--------\t------" << endl;
            bool anyFound = false;
            for (int i = 0; i < index; i++)
            {
            if ((status[i] == "Low Stock" || status[i] == "Out of Stock") && productName[i] != "")
            {
            cout << productName[i] << "\t\t" << category[i] << "\t\t" << quantity[i] << "\t\t" << status[i] << endl;
            anyFound = true;
            }
            }
           if (!anyFound) cout << "  All products are well stocked!" << endl;
          }
           //----Option 9:Profit Report----
           else if(adminOption==9)
           {
            //system("cls");
           cout<<"====================================================================="<<endl;
           cout<<"                             Profit Report                           "<<endl;
           cout<<"====================================================================="<<endl;
           cout << "Name\t\tBuy Rs.\tSell Rs.\tProfit/Unit\tSold\tTotal Profit" << endl;
           cout << "----\t\t-------\t--------\t-----------\t----\t------------" << endl;
           float totalProfit = 0;
           for (int i = 0; i < index; i++)
           {
           if (productName[i] != "")
           {
           float profitPerUnit = sellPrice[i] - buyPrice[i];
           float profit = profitPerUnit * soldQty[i];
           totalProfit += profit;
           cout << productName[i] << "\t\t" << buyPrice[i] << "\t" << sellPrice[i]
                << "\t\t" << profitPerUnit << "\t\t" << soldQty[i] << "\t" << profit << endl;
           }
           }
           cout << "-------------------------------------------" << endl;
           cout << "Total Profit: Rs. " << totalProfit << endl;
           }
           //----Option 10:Logout----
           else if(adminOption==10)
           {
           cout<<"Logging out..."<<endl;
           break;
           }
           else
           {
           cout<<"Wrong option selected!"<<endl;
           }
           cout<<"\n Press  any key to continue...";
           getch();
           }
           getch();
           break;
          }
           else
           {
           cout<<"\n Invalid Username or Password!"<<endl;
           cout<<"Press any key to try again...";
           getch();
           }
         }
           getch();
         }

         else if(userOption==2)
         {
         while(true)
         {
          //system("cls");
         cout<<"===================================================================================="<<endl;
         cout<<"                    Customer Menu                                                   "<<endl;
         cout<<"===================================================================================="<<endl;
         cout<<"1.  View All Available Products"<<endl;
         cout<<"2.  Search Product by Name"<<endl;
         cout<<"3.  View Product Price"<<endl;
         cout<<"4.  Check Product Availability"<<endl;
         cout<<"5.  Buy Product"<<endl;
         cout<<"6.  View Products by Category"<<endl;
         cout<<"7.  View Cheapest Product"<<endl;
         cout<<"8.  View Most Expensive Product"<<endl;
         cout<<"9.  View Shop Contact Info"<<endl;
         cout<<"10. Back Main Menu"<<endl;
         cout<<endl;
         cout<<"Choose option:";
         int customerOption;
         cin>>customerOption;

         //----Option 1.View All Product----
         if(customerOption==1)
         {
          for(int i=0;i<index;i++)
          {
            for(int j=0;j<index-1;j++)
            {
             if(productName[j]>productName[j+1] && productName[j+1]!="")
             {
              //Swap Name
              string tName=productName[j];
              productName[j]=productName[j+1];
              productName[j+1]=tName;

              //Swap Category
              string tCat=category[j];
              category[j]=category[j+1];
              category[j+1]=tCat;

              //Swap Sell Price
              float tSP=sellPrice[j];
              sellPrice[j]=sellPrice[j+1];
              sellPrice[j+1]=tSP;

              //Swap Quantity
              int tQty=quantity[j];
              quantity[j]=quantity[j+1];
              quantity[j+1]=tQty;

              //Swap Status
              string tStat=status[j];
              status[j]=status[j+1];
              status[j+1]=tStat;

              float tBP = buyPrice[j];
              buyPrice[j] = buyPrice[j+1];
              buyPrice[j+1] = tBP;

             string tSup = supplierName[j];
             supplierName[j] = supplierName[j + 1];
             supplierName[j + 1] = tSup;

             string tExp = expiryDate[j];
             expiryDate[j] = expiryDate[j + 1];
             expiryDate[j + 1] = tExp;
             } 
            }
          
          //system("cls");
         cout << "===================================================================="<<endl;
         cout << "                      AVAILABLE PRODUCTS (A-Z)                      "<<endl;
         cout << "===================================================================="<<endl;
         cout << "No.\tName\t\tCategory\tPrice (Rs.)\tQty\tStatus" << endl;
         cout << "---\t----\t\t--------\t-----------\t---\t------" << endl;
         for (int i = 0; i < index; i++)
         {
         if (productName[i] != "")
         {
         cout << i+1 << "\t" << productName[i] << "\t\t" << category[i]
         << "\t\t" << sellPrice[i] << "\t\t" << quantity[i] << "\t" << status[i] << endl;
         }
         }

         cout<<"\nPress any key to return to Customer Menu...";
         getch();
        }
         //----Option 2: Search Product----
         else if(customerOption==2)
         {
          //system("cls");
         cout<<" Enter product name:";
         string name;
         cin>>name;
         bool found=false;
         for(int i=0; i<index;i++)
         {
         if(productName[i]==name)
         {
         cout<<"\n---Product Info---"<<endl;
         cout<<"Name     :"<<productName[i]<<endl;
         cout<<"Category :"<<category[i]<<endl;
         cout<<"Price    : Rs."<<sellPrice[i]<<endl;
         cout<<"Available:"<<quantity[i]<<"units"<<endl;
         cout<<"Expiry   :"<<expiryDate[i]<<endl;
         cout<<"Status   :"<<status[i]<<endl;
         found=true;
         break;
         }
         }
         if(!found) cout<<"Product not found."<<endl;
         }

         //----Option 3:View Price----
         else if(customerOption==3)
         {
         //system("cls");
         cout<<"Enter product name to check price:";
         string name;
         cin>>name;
         bool found=false;
         for(int i=0;i<index;i++)
         {
         if(productName[i]==name)
         {
         cout<<"Price of "<<productName[i]<<":Rs."<<sellPrice[i]<<"per unit"<<endl;
         found=true;
         break;
         }
         }
         if(!found) cout<<"Product not found."<<endl;
         }

         //----Option 4: Check Availability----
         else if(customerOption==4)
         {
          //system("cls");
         cout<<"Enter product name to check availability:";
         string name;
         cin>>name;
         bool found=false;
         for(int i=0;i<index;i++)
         {
         if(productName[i]==name)
         {
          cout << "  " << productName[i] << " - Status: " << status[i]
               << " | Quantity: " << quantity[i] << " units" << endl;
          found = true;
          break;
          }           
          }
          if (!found) cout << "  Product not found." << endl;
          }
         //----Option 5: Buy Product----
         
           else if(customerOption == 5)
          {
               //system("cls");
              cout << "Enter product name to buy: ";
              string name;
              cin >> name;
              bool found = false;
              int foundIndex = -1;
              for(int i = 0; i < index; i++)
              {
                  if(productName[i] == name)
                  {
                      foundIndex = i;
                      found = true;
                  }
              }
              if(found)
              {
                  cout << "Available Quantity: " << quantity[foundIndex] << endl;
                  cout << "Enter quantity to buy: ";
                  int buyQty;
                  cin >> buyQty;
                  if(buyQty > quantity[foundIndex])
                  {
                      cout << "Error! Not enough stock." << endl;
                  }
                  else
                  {
                      quantity[foundIndex]  -= buyQty;
                      soldQty[foundIndex]   += buyQty;
                      totalSale[foundIndex] += buyQty * sellPrice[foundIndex];
                      status[foundIndex] = (quantity[foundIndex] <= 10) ? "Low Stock" : "Available";
                      if(quantity[foundIndex] == 0) status[foundIndex] = "Out of Stock";
                      cout << "Total Bill: Rs. " << buyQty * sellPrice[foundIndex] << endl;
                      cout << "Thank you for shopping!" << endl;
                  }
              }
              else
              {
                  cout << "Product not found." << endl;
              }
            }
          //----Option 6:View By Category----
          else if(customerOption==6)
          {
           //system("cls");
          cout<<"Enter category:";
          string cat;
          cin>>cat;
          cout<<"\n Products in category:"<<cat<<endl;
          cout<<"Name\t\tPrice\t\tQty\tStatus"<<endl;
          cout<<"----\t\t-----\t\t---\t------" << endl;
          bool anyFound=false;
          for(int i=0;i<index;i++)
          {
          if(category[i]==cat && productName[i] !="")
          {
          cout<<" " <<productName[i]<<"\t\t"<<sellPrice[i]<<"\t\t"<<quantity[i]<<"\t"<<status[i]<<endl;
          anyFound=true;
          }
          }
          if(!anyFound)  cout<<"No products found in this category."<<endl;
          }
          //----Option 7:Cheapest Product----
          else if(customerOption==7)
          {
           //system("cls");
          int cheapIndex=0;
          for(int i=1;i<index;i++)
          {
          if(productName[i]!="" && sellPrice[i]<sellPrice[cheapIndex])
          cheapIndex=i;
          }
          cout<<"Cheapest Product:"<<endl;
          cout<<"Name  :"<<productName[cheapIndex]<<endl;
          cout<<"Price :Rs. "<<sellPrice[cheapIndex]<<endl;
          cout<<"Status:"<<status[cheapIndex]<<endl;
          }

          //----Option 8: Most Expensive Product----
          else if(customerOption==8)
          {
           //system("cls");
          int expIndex=0;
          for(int i=1;i<index;i++)
          {
          if(productName[i]!="" && sellPrice[i]>sellPrice[expIndex])
          expIndex=i;
          }
          cout<<"Most Expensive Product:"<<endl;
          cout<<"Name  :"<<productName[expIndex]<<endl;
          cout<<"Price :Rs."<<sellPrice[expIndex]<<endl;
          cout<<"Status:"<<status[expIndex]<<endl; 
          }

          //----Option 9:Shop Contact Info----
          else if(customerOption==9)
          {
           //system("cls");
          cout<<"========================================================================="<<endl;
          cout<<"                      Shop Contact Information                           "<<endl;
          cout<<"========================================================================="<<endl;
          cin.ignore();
          cout<<"Enter Shop Name:";
          getline(cin,shopName);

          cout<<"Enter Address:";
          getline(cin,address);

          cout<<"Enter Phone:";
          getline(cin,phone);

          cout<<"Enter Email:";
          getline(cin,email);

          cout<<"\n----Shop Details----\n";
          cout<<"Shop Name :"<<shopName<<endl;
          cout<<"Address   :"<<address<<endl;
          cout<<"Phone     :"<<phone<<endl;
          cout<<"Email     :"<<email<<endl;
          }
          //----Option 10:Back----
          else if(customerOption==10)
          {
            break;
          }
          else
          {
            cout<<"Wrong option selected!"<<endl;
          }

          cout<<"\n Press any key to continue...";
          getch();
        }
         
         }
         //======================EXIT=====================
         else if (userOption==3)
         {
          break;
         }
         else
         {
          cout<<"Wrong option selected!"<<endl;
          cin.ignore();
          getch();
         }
         }
         cout<<endl<<"Thank you for using Shop Mnanagement System!"<<endl;
         getch();
         system("pause");
         return 0;
         }

        


        
       

       
   