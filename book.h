#pragma once
#include <iostream>
#include <string>


namespace SeowonLim2348078 {


class book {
    std::string title;
    int id;    
    int price;


    // 1-3. testID 및 testPrice
    void testID() const // id: 1~1000
    {
        if (id < 1 || id > 1000) {
            std::cout << "Invalid book id \n";
        }
    }


    void testPrice() const // price: 0~50000 won
    {
        if (price < 0 || price > 50000) {
            std::cout << "Invalid book price\n";
        }
    }


public:
    book(const std::string& t = "no title yet", int d = 1, int p = 0)
        : title{t}, id{d}, price{p}
    {
        testID();
        testPrice();
    }    


    void input() // book b; b.input();
    {
        std::cout << "Enter book title: ";
        std::getline(std::cin >> std::ws, title);
        std::cout << "Enter book id: ";
        std::cin >> id;
        testID();
        std::cout << "Enter book price: ";
        std::cin >> price;
        testPrice();
    }


    friend std::istream& operator>>(std::istream& is, book& b)
    {
        std::cout << "Enter book title: ";
        std::getline(is >> std::ws, b.title);
        std::cout << "Enter book id: ";
        is >> b.id;
        b.testID();
        std::cout << "Enter book price: ";
        is >> b.price;
        b.testPrice();        
        return is;
    }        


    void setID(int d) { id = d; testID(); }
    void setPrice(int p) { price = p; testPrice(); }
    void setTitle(const std::string& t) { title = t; }


    void print() const
    {
        std::cout << title << "(" << id << "): " << price << " won\n";
    }


    friend std::ostream& operator<<(std::ostream& os, const book& b)
    {
        os << b.title << ", " << b.id << ", " << b.price << " won\n";
        return os;
    }


    const std::string& getTitle() const { return title; }
    int getID() const { return id; }
    int getPrice() const { return price; }


    // 1-4. 전위 증가 연산자 (참조 리턴 & this 활용)
    book& operator++()
    {
        ++(this->price);
        this->testPrice();
        return *this;
    }


    // 1-4. 후위 증가 연산자 (값 리턴 & this 활용)
    book operator++(int)
    {
        book temp{*this};
        ++(*this);
        return temp;            
    }


    // 1-5. 복합 할당 연산자 += (멤버 함수, int 매개변수, this 활용, 참조 리턴)
    book& operator+=(int m)
    {
        this->price += m;
        this->testPrice();
        return *this;
    }


    friend bool operator==(const book& b1, const book& b2)
    {
        return b1.id == b2.id && b1.price == b2.price;
    }


    friend int operator+(const book& b1, const book& b2)
    {
        return b1.price + b2.price;
    }
};


} // namespace SeowonLim2348078
