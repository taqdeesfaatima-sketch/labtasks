#include <iostream>
#include <conio.h>
using namespace std;
      const int Max=1000;
      string productName[Max], category[Max], supplierName[Max], expiryDate[Max], status[Max], shopName, shopAddress, shopPhone, shopEmail;
      int quantity[Max], soldQty[Max], index_ = 0;
      float buyPrice[Max], sellPrice[Max], totalSale[Max];
      // Function Declarations
      void sortProductAZ();
      bool adminLogin();
      void adminMenu();
      void showAllProducts();
      void searchProductAdmin();
      void addProduct();
      void updateProduct();
      void deleteProduct();
      void sellProduct();
      void salesReport();
      void lowStockReport();
      void profitReport();

      void customerMenu();
      void viewAllProductsCustomer();
      void searchProductCustomer();
      void viewPrice();
      void checkAvailability();
      void buyProduct();
      void viewByCategory();
      void cheapestProduct();
      void mostExpensiveProduct();
      void shopContactInfo();

      void sortProductAZ()
      {
        for(int i=0;i<index_;i++)
        {
          for(int j=0;j<index_ -i-1;j++)
          {
            if(productName[j]>productName[j+1] && productName[j+1]!="")
            {
             swap(productName[j], productName[j+1]);
             swap(category[j],    category[j+1]);
             swap(quantity[j],    quantity[j+1]);
             swap(buyPrice[j],    buyPrice[j+1]);
             swap(sellPrice[j],   sellPrice[j+1]);
             swap(supplierName[j],supplierName[j+1]);
             swap(expiryDate[j],  expiryDate[j+1]);
             swap(status[j],      status[j+1]);
             swap(totalSale[j],   totalSale[j+1]);
             swap(soldQty[j],     soldQty[j+1]); 
            }
          }
        }
      }

      int findProduct(const string& name)
      {
        for(int i=0; i<index_;i++)
        if(productName[i]==name)
        return i;
      return -1;
      }

      void pauseScreen()
      {
        cout<<"\n Press any key to continue...";
        getch();
      }
      // ============================================================
      //                  ADMIN FUNCTIONS
      // ============================================================
 

      bool adminLogin()
      {
        for(int attempt=0;attempt<3;attempt++)
        {
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
        return true;
        }
      }
        cout<<"\n Too many failed  attempts.Returning to Main Menu."<<endl;
        getch();
        return false; 
       }
      

       //----Option 1----
       void showAllProducts()
       {
       sortProductAZ();
       cout<<"============================================================================="<<endl;
       cout<<"                             ALL PRODUCTS(A-Z SORTED)                        "<<endl;
       cout<<"============================================================================="<<endl;
       cout << "No.\tName\t\tCategory\tQty\tBuy\tSell\tSupplier\tExpiry\t\tStatus" << endl;
         for(int i=0;i<index_;i++)
          {
            if (productName[i] != "") 
         {
            cout << i + 1 << "\t" << productName[i] << "\t\t" << category[i] << "\t" << quantity[i] << "\t" << buyPrice[i] << "\t" << sellPrice[i] << "\t" << supplierName[i] << "\t" << expiryDate[i] << "\t" << status[i] << endl;
            cout<<"\nPress any key to return to Admin Menu...";
            getch();
      
         }
        }
       }
   
         //----Option 2----
         void searchProductAdmin()
         {
          cout<<"Enter product name to search:";
         string name;
         cin>>name;

         int idx=findProduct(name);
         if(idx==-1)
         {
          cout<<"Product not found."<<endl;
          return;
         }
         cout<<"\n ---Product Record---"<<endl;
         cout << "\n  --- Product Record ---" << endl; 
         cout << "  Name      : " << productName[idx]<< endl;
         cout << "  Category  : " << category[idx] << endl;
         cout << "  Quantity  : " << quantity[idx] << endl;
         cout << "  Buy Price : Rs. " << buyPrice[idx] << endl;
         cout << "  Sell Price: Rs. " << sellPrice[idx] << endl;
         cout << "  Supplier  : " << supplierName[idx] << endl;
         cout << "  Expiry    : " << expiryDate[idx] << endl;
         cout << "  Status    : " << status[idx] << endl;
         cout << "  Sold Qty  : " << soldQty[idx] << endl;
         cout << "  Total Sale: Rs. " << totalSale[idx] << endl;
         
         }
         
         //----Option 3----
         void addProduct()
         {
         cout<<"=================================================================="<<endl;
         cout<<"                     Add New Product                              "<<endl;
         cout<<"=================================================================="<<endl;
         if(index_>=1000)
         {
         cout<<"Storage full.Cannot add more products."<<endl;
         return;
         }
        
         cout<<  "  Product Name     : "; string pname;    cin >> pname;
         cout << "  Category         : "; string cat;      cin >> cat;
         cout << "  Quantity         : "; int qty;         cin >> qty;
         cout << "  Buy Price (Rs.)  : "; float bprice;    cin >> bprice;
         cout << "  Sell Price (Rs.) : "; float sprice;    cin >> sprice;
         cout << "  Supplier Name    : "; string supplier; cin >> supplier;
         cout << "  Expiry Date      : "; string expiry;   cin >> expiry;

        productName[index_]   = pname;
        category[index_]      = cat;
        quantity[index_]      = qty;
        buyPrice[index_]      = bprice;
        sellPrice[index_]     = sprice;
        supplierName[index_]  = supplier;
        expiryDate[index_]    = expiry;
        totalSale[index_]     = 0;
        soldQty[index_]       = 0;
        status[index_]        = (qty <= 10) ? "Low Stock" : "Available";
        index_++;
        cout<<"\n Product added successfully!"<<endl;
         }
          
         //----Option 4----
         void updateProduct()
         {
         cout<<"Enter product name to update:";
         string name;
         cin>>name;
         int idx=findProduct(name);
         if(idx==-1)
         {
         cout<<"Product not found."<<endl;
         return;
         }
         
         cout<<"\n---Old Record---"<<endl;
         cout<<"Name:"<<productName[idx]
             <<"|Qty:"<<quantity[idx]
             <<"|Sell Price:"<<sellPrice[idx]
             <<"|Status:"<<status[idx]<<endl;
         cout<<"\n Enter new details:"<<endl;
         cout<<"New Name       :"; string newName;     cin>>newName;
         cout<<"New Category   :"; string newCat ;     cin>>newCat ;
         cout<<"New Quantity   :"; int newQty ;     cin>>newQty ;
         cout<<"New Buy Price  :"; float  newBuy ;     cin>>newBuy ;
         cout<<"New Sell Price :"; float  newSell;     cin>>newSell;
         cout<<"New Supplier   :"; string newSupplier; cin>>newSupplier;
         cout<<"New Expiry Date:"; string newExpiry;   cin>>newExpiry;
         productName[idx]  = newName;
         category[idx]     = newCat;
         quantity[idx]     = newQty;
         buyPrice[idx]     = newBuy;
         sellPrice[idx]    = newSell;
         supplierName[idx] = newSupplier;
         expiryDate[idx]   = newExpiry;
         status[idx]       = (newQty <= 10) ? "Low Stock" : "Available"; 
         
         cout<<"\n Record updated successfully!"<<endl;
         }
        
         
         //----Option 5----
         void deleteProduct() 
         {
         cout<<"Enter product name to delete:";
         string name;
         cin>>name;
         int idx=findProduct(name);
         if(idx==-1)
         {
         cout<<"Product not found."<<endl;
         return;
         }
          productName[idx]  = "";
          category[idx]     = "";
          quantity[idx]     = 0;
          buyPrice[idx]     = 0;
          sellPrice[idx]    = 0;
          supplierName[idx] = "";
          expiryDate[idx]   = "";
          totalSale[idx]    = 0;
          soldQty[idx]      = 0;
          status[idx]       = "";
          cout << "  Product '" << name << "' deleted successfully." << endl;
        }
          
          //----Option 6----
          void sellProduct()
          {
          cout<<"Enter product name to sell:";
          string name;
          cin>>name;
          int idx=findProduct(name);
          if(idx==-1)
          {
          cout<<"Product not found."<<endl;
          return;
          }

          cout<<"Available Quantity:"<<quantity[idx]<<endl;
          cout<<"Enter quantity to sell:";
          int sellQty;
          cin>>sellQty;

          if(sellQty>quantity[idx])
          {
          cout<<"Error! Not enough stock."<<endl;
          }
         
          quantity[idx] -=sellQty;
          soldQty[idx]  +=sellQty;
          totalSale[idx]+=sellQty * sellPrice[idx];
          status[idx]    =(quantity[idx]<=10 )? "Low Stock" : "Available";
          if(quantity[idx]==0) status[idx]="Out of Stock";
          cout<<"\n ==== SALE RECEIPT ====" <<endl;
          cout << "  Product   : " << productName[idx] << endl;
          cout << "  Qty Sold  : " << sellQty << endl;
          cout << "  Price/Unit: Rs. " << sellPrice[idx] << endl;
          cout << "  Total     : Rs. " << sellQty * sellPrice[idx] << endl;
          cout << "  Remaining : " << quantity[idx] << endl;
          cout << "  ========================" << endl;
            }
         
          //----Option 7----
          void salesReport()
          {
          cout<<"===================================================================="<<endl;
          cout<<"                         Sales Report                               "<<endl;
          cout<<"===================================================================="<<endl;
          cout<<"Name\t\tSold Qty\tTotal sale (Rs.)"<<endl;
          cout<<"----\t\t--------\t----------------"<<endl;
          float grandTotal=0;
          for(int i=0; i<index_;i++)
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
        
          
          //----Option 8----
          void lowStockReport()
          {
            cout<<"=================================================================="<<endl;
            cout<<"                Low Stock/ Out of Stock                          "<<endl;
            cout<<"=================================================================="<<endl;
            cout << "Name\t\tCategory\tQuantity\tStatus" << endl;
            cout << "----\t\t--------\t--------\t------" << endl;
            bool anyFound = false;
            for (int i = 0; i < index_; i++)
            {
            if ((status[i] == "Low Stock" || status[i] == "Out of Stock") && productName[i] != "")
            {
            cout << productName[i] << "\t\t" << category[i] << "\t\t" << quantity[i] << "\t\t" << status[i] << endl;
            anyFound=true;
            }
          }
        }
      
           //----Option 9----
           void profitReport()
           {
           cout<<"====================================================================="<<endl;
           cout<<"                             Profit Report                           "<<endl;
           cout<<"====================================================================="<<endl;
           cout << "Name\t\tBuy Rs.\tSell Rs.\tProfit/Unit\tSold\tTotal Profit" << endl;
           cout << "----\t\t-------\t--------\t-----------\t----\t------------" << endl;
           float totalProfit = 0;
           for (int i = 0; i < index_; i++)
           
           if (productName[i] != "")
           {
           float profitPerUnit = sellPrice[i] - buyPrice[i];
           float profit = profitPerUnit * soldQty[i];
           totalProfit += profit;
           cout << productName[i] << "\t\t" << buyPrice[i] << "\t" << sellPrice[i]
                << "\t\t" << profitPerUnit << "\t\t" << soldQty[i] << "\t" << profit << endl;
           }
           
           cout << "-------------------------------------------" << endl;
           cout << "Total Profit: Rs. " << totalProfit << endl;
           }
           // ---- Admin Menu Loop ----
          void adminMenu()
         {
          while (true)
         {
           cout << "====================================================" << endl;
           cout << "                   Admin Menu                       " << endl;
           cout << "====================================================" << endl;
           cout << "  1.  Show All Products"          << endl;
           cout << "  2.  Search Product by Name"     << endl;
           cout << "  3.  Add New Product"            << endl;
           cout << "  4.  Update Product Record"      << endl;
           cout << "  5.  Delete Product Record"      << endl;
           cout << "  6.  Sell Product (Update Stock)"<< endl;
           cout << "  7.  Generate Sales Report"      << endl;
           cout << "  8.  Show Low Stock Products"    << endl;
           cout << "  9.  Show Profit on Each Product"<< endl;
           cout << "  10. Logout"                     << endl;
           cout << "\n  Choose option: ";
 
          int opt; cin >> opt;
 
          switch (opt)
          {
            case 1:  showAllProducts();    break;
            case 2:  searchProductAdmin(); break;
            case 3:  addProduct();         break;
            case 4:  updateProduct();      break;
            case 5:  deleteProduct();      break;
            case 6:  sellProduct();        break;
            case 7:  salesReport();        break;
            case 8:  lowStockReport();     break;
            case 9:  profitReport();       break;
            case 10:
                cout << "Logging out..." << endl;
                getch();
                return;
            default:
                cout << "Wrong option selected!" << endl;
        }
 
          pauseScreen();
    }
}

// ============================================================
//                  CUSTOMER FUNCTIONS
// ============================================================

         //----Option 1----
         void viewAllProductsCustomer()
         
        {
        sortProductAZ();
        cout << "====================================================================" << endl;
        cout << "                   AVAILABLE PRODUCTS (A-Z)                         " << endl;
        cout << "====================================================================" << endl;
        cout << "No.\tName\t\tCategory\tPrice (Rs.)\tQty\tStatus" << endl;
        cout << "---\t----\t\t--------\t-----------\t---\t------" << endl;
 
        for (int i = 0; i < index_; i++)
        {
        if (productName[i] != "")
       cout << i + 1 << "\t" << productName[i] << "\t\t" << category[i]
                 << "\t\t" << sellPrice[i] << "\t\t" << quantity[i] << "\t" << status[i] << endl;
 
      cout << "\nPress any key to return to Customer Menu...";
      getch();
        }
      }
      
        // ---- Option 2 ----
      void searchProductCustomer()
      {
    cout << "Enter product name: ";
    string name; cin >> name;
 
    int idx = findProduct(name);
    if (idx == -1) { cout << "Product not found." << endl; return; }
 
    cout << "\n--- Product Info ---"         << endl;
    cout << "Name     : " << productName[idx] << endl;
    cout << "Category : " << category[idx]    << endl;
    cout << "Price    : Rs. " << sellPrice[idx] << endl;
    cout << "Available: " << quantity[idx] << " units" << endl;
    cout << "Expiry   : " << expiryDate[idx]  << endl;
    cout << "Status   : " << status[idx]      << endl;
        }
        
         // ---- Option 3 ----
        void viewPrice()
      {
     cout << "Enter product name to check price: ";
     string name; cin >> name;
 
     int idx = findProduct(name);
     if (idx == -1) { cout << "Product not found." << endl; return; }
 
    cout << "Price of " << productName[idx] << ": Rs. " << sellPrice[idx] << " per unit" << endl;
        }
         // ---- Option 4 ----
        void checkAvailability()
      {
       cout << "Enter product name to check availability: ";
       string name; cin >> name;
 
      int idx = findProduct(name);
      if (idx == -1) { cout << "Product not found." << endl; return; }
 
      cout << "  " << productName[idx] << " - Status: " << status[idx]
           << " | Quantity: " << quantity[idx] << " units" << endl;
      }

         
         // ---- Option 5 ----
        void buyProduct()
        {
        cout << "Enter product name to buy: ";
        string name; cin >> name;
 
        int idx = findProduct(name);
        if (idx == -1) { cout << "Product not found." << endl; return; }
 
        cout << "Available Quantity: " << quantity[idx] << endl;
        cout << "Enter quantity to buy: ";
        int buyQty; cin >> buyQty;
 
        if (buyQty > quantity[idx]) { cout << "Error! Not enough stock." << endl; return; }
 
        quantity[idx]  -= buyQty;
        soldQty[idx]   += buyQty;
        totalSale[idx] += buyQty * sellPrice[idx];
        status[idx]     = (quantity[idx] <= 10) ? "Low Stock" : "Available";
        if (quantity[idx] == 0) status[idx] = "Out of Stock";
 
        cout << "Total Bill: Rs. " << buyQty * sellPrice[idx] << endl;
        cout << "Thank you for shopping!" << endl;
       }
 
         // ---- Option 6 ----
         void viewByCategory()
        {
         cout << "Enter category: ";
         string cat; cin >> cat;
 
        cout << "\n Products in category: " << cat << endl;
        cout << "Name\t\tPrice\t\tQty\tStatus" << endl;
        cout << "----\t\t-----\t\t---\t------" << endl;
 
        bool anyFound = false;
        for (int i = 0; i < index_; i++)
        if (category[i] == cat && productName[i] != "")
        {
        cout << " " << productName[i] << "\t\t" << sellPrice[i]
                    << "\t\t" << quantity[i] << "\t" << status[i] << endl;
            anyFound = true;
        }
 
       if (!anyFound) cout << "No products found in this category." << endl;
        }
         // ---- Option 7 ----
          void cheapestProduct()
          {
           if (index_ == 0) { cout << "No products available." << endl; return; }
 
           int cheapIdx = 0;
           for (int i = 1; i < index_; i++)
           if (productName[i] != "" && sellPrice[i] < sellPrice[cheapIdx])
            cheapIdx = i;
 
           cout << "Cheapest Product:" << endl;
           cout << "Name  : " << productName[cheapIdx] << endl;
           cout << "Price : Rs. " << sellPrice[cheapIdx] << endl;
           cout << "Status: " << status[cheapIdx]        << endl;
           }
 
         // ---- Option 8 ----
         void mostExpensiveProduct()
        {
        if (index_ == 0) { cout << "No products available." << endl; return; }
 
        int expIdx = 0;
        for (int i = 1; i < index_; i++)
        if (productName[i] != "" && sellPrice[i] > sellPrice[expIdx])
            expIdx = i;
 
        cout << "Most Expensive Product:" << endl;
        cout << "Name  : " << productName[expIdx] << endl;
        cout << "Price : Rs. " << sellPrice[expIdx] << endl;
        cout << "Status: " << status[expIdx]        << endl;
        }
 
         // ---- Option 9 ----
         void shopContactInfo()
         {
        cout << "=========================================================================" << endl;
        cout << "                     Shop Contact Information                            " << endl;
        cout << "=========================================================================" << endl;
        cin.ignore();
        cout << "Enter Shop Name: ";  getline(cin, shopName);
        cout << "Enter Address  : ";  getline(cin, shopAddress);
        cout << "Enter Phone    : ";  getline(cin, shopPhone);
        cout << "Enter Email    : ";  getline(cin, shopEmail);
 
        cout << "\n---- Shop Details ----\n";
        cout << "Shop Name : " << shopName    << endl;
        cout << "Address   : " << shopAddress << endl;
        cout << "Phone     : " << shopPhone   << endl;
        cout << "Email     : " << shopEmail   << endl;
        }
 
        // ---- Customer Menu Loop ----
        void customerMenu()
        {
        while (true)
        {
        cout << "====================================================================================" << endl;
        cout << "                          Customer Menu                                             " << endl;
        cout << "====================================================================================" << endl;
        cout << "1.  View All Available Products" << endl;
        cout << "2.  Search Product by Name"      << endl;
        cout << "3.  View Product Price"          << endl;
        cout << "4.  Check Product Availability"  << endl;
        cout << "5.  Buy Product"                 << endl;
        cout << "6.  View Products by Category"   << endl;
        cout << "7.  View Cheapest Product"       << endl;
        cout << "8.  View Most Expensive Product" << endl;
        cout << "9.  View Shop Contact Info"      << endl;
        cout << "10. Back to Main Menu"           << endl;
        cout << "\nChoose option: ";
 
        int opt; cin >> opt;
 
        switch (opt)
        {
            case 1:  viewAllProductsCustomer(); break;
            case 2:  searchProductCustomer();   break;
            case 3:  viewPrice();               break;
            case 4:  checkAvailability();       break;
            case 5:  buyProduct();              break;
            case 6:  viewByCategory();          break;
            case 7:  cheapestProduct();         break;
            case 8:  mostExpensiveProduct();    break;
            case 9:  shopContactInfo();         break;
            case 10: return;
            default: cout << "Wrong option selected!" << endl;
        }
 
        pauseScreen();
    }
  }

 
// ============================================================
//                        MAIN
// ============================================================
int main()
{
    while (true)
    {
        cout << "==================================" << endl;
        cout << "======SHOP MANAGEMENT SYSTEM======" << endl;
        cout << "==================================" << endl;
        cout << "\nMain Menu:"  << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Customer"    << endl;
        cout << "3. Exit"        << endl;
        cout << "\nChoose option: ";
 
        int userOption; cin >> userOption;
 
        if (userOption == 1)
        {
            if (adminLogin())
                adminMenu();
        }
        else if (userOption == 2)
        {
            customerMenu();
        }
        else if (userOption == 3)
        {
            break;
        }
        else
        {
            cout << "Wrong option selected!" << endl;
            cin.ignore();
            getch();
        }
    }
 
    cout << "\nThank you for using Shop Management System!" << endl;
    getch();
    return 0;
}
      