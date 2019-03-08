#include <iostream>
#include <cstring>

using namespace std;

const int MAXLEN = 1e3 + 5;

class Product
{
    char *name = new char[MAXLEN];
    int days;
    double fat;
    bool isFood;
    double price;
public:
    Product() {}
    Product(const char *_name, int _days, double _fat, bool _isFood, double _price)
    {
        strcpy(this->name,_name);
        this->days = _days;
        this->fat = _fat;
        this->isFood = _isFood;
        this->price = _price;
    }
    ~Product()
    {
        delete[] this->name;
    }
    void print()
    {
        cout << this->name << endl;
        cout << this->days << endl;
        cout << this->fat << endl;
        cout << this->isFood << endl;
        cout << this->price << endl;
    }
    char *getName() const
    {
        return this->name;
    }
    int getDays()
    {
        return this->days;
    }
    double getFat()
    {
        return this->fat;
    }
    bool getIsFood()
    {
        return this->isFood;
    }
    double getPrice()
    {
        return this->price;
    }
    void setName(const char *_name)
    {
        strcpy(this->name, _name);
    }
    void setDays(int _days)
    {
        this->days = _days;
    }
    void setFat(double _fat)
    {
        this->fat = _fat;
    }
    void setIsFood(bool _isFood)
    {
        this->isFood = _isFood;
    }
    void setPrice(double _price)
    {
        this->price = _price;
    }
    bool operator == (const Product &cmp) const
    {
        return (!strcmp(this->name, cmp.name));
    }
    bool isExpired()
    {
        return (this->isFood && (this->days < 6) );
    }
};

class Store
{
    int numberProducts;
    Product *products = new Product[MAXLEN];
    double money;
public:
    Store()
    {
        this->numberProducts = 0;
        this->money = 0;
    }
    Store(int _numberProducts, const Product *_products, double _money)
    {
        this->numberProducts = _numberProducts;
        for(int i = 0; i < _numberProducts; i++)
            this->products[i] = _products[i];
        this->money = _money;
    }
    ~Store()
    {
        delete[] this->products;
    }
    void print()
    {
        cout << this->numberProducts << endl;
        for(int i = 0; i < this->numberProducts; i++)
        {
            this->products[i].print();
            cout<<endl;
        }
        cout<< this->money << endl;
    }
    int getNumberProducts()
    {
        return this->numberProducts;
    }
    Product *getProducts()
    {
        return this->products;
    }
    double getMoney()
    {
        return this->money;
    }
    void setNumberProducts(int _numberProducts)
    {
        this->numberProducts = _numberProducts;
    }
    void setProducts(const Product *_products)
    {
        for(int i = 0; i < this->numberProducts; i++)
        {
            this->products[i] = _products[i];
        }
    }
    void setMoney(double _money)
    {
        this->money = _money;
    }
    Product productByName(const char *name)
    {
        for(int i = 0; i < this->numberProducts; i++)
        {
            if(strcmp(this->products[i].getName(),name) == 0)
            {
                return this->products[i];
            }
        }
        cout << "Doesn't exist" << endl;
        return Product("",0,0,0,0);
    }
    Product lowestFat()
    {
        Product ret;
        double mn = 101;
        for(int i = 0; i < this->numberProducts; i++)
        {
            if(!this->products[i].getIsFood())
                continue;
            double cur = this->products[i].getFat();
            if(cur < mn)
            {
                mn = cur;
                ret = this->products[i];
            }
        }
        if(mn == 101)
            cout << "No food" << endl;
        return ret;
    }
    void sellProduct(const char *name)
    {
        for(int i = 0; i < this->numberProducts; i++)
        {
            if(!strcmp(this->products[i].getName(),name))
            {
                this->numberProducts --;
                this->money += this->products[i].getPrice();
                for(;i < this->numberProducts; i++)
                    this->products[i] = this->products[i+1];
                return;
            }
        }
    }
    double lostMoney()
    {
        double sum = 0;
        for(int i = 0; i < this->numberProducts; i++)
        {
            if(this->products[i].isExpired())
            {
                sum += this->products[i].getPrice();
            }
        }
        return sum;
    }
};

int main()
{
    Product p[] = {Product("qdki", 5, 75, true, 2.45),Product("gyba", 1000, 0, false, 1.10)};
    //p[0].print();
    Store s = Store(2,p,0);
    //s.print();
    //s.sellProduct("qdki");
    cout << s.lostMoney() << endl;
	return 0;
}
