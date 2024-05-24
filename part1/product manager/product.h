#pragma once
/*
    File:product.c
    Created:24-03-06
    Author:È«½Â¿í
*/

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Product {
private:
    string id;
    int price;
    string producer;

public:
    Product();
    Product(string Pid, int Pprice, string Pproducer);
    virtual void ShowProduct();
    virtual string mytype();
    virtual string getInfo();
    ~Product();
};

class Book : public Product {
private:
    string ISBN;
    string author;
    string title;

public:
    Book(string Bid, int Bprice, string Bproducer, string BISBN, string Bauthor, string Btitle);
    void ShowProduct() override;
    string mytype() override;
    string getInfo() override;
};

class Handphone : public Product {
private:
    string model;
    int RAM;

public:
    Handphone(string Hid, int Hprice, string Hproducer, string Hmodel, int HRAM);
    void ShowProduct() override;
    string mytype() override;
    string getInfo() override;
};

class Computer : public Product {
private:
    string model;
    string cpu;
    int RAM;

public:
    Computer(string Cid, int Cprice, string Cproducer, string Cmodel, string Ccpu, int CRAM);
    void ShowProduct() override;
    string mytype() override;
    string getInfo() override;
};
void addProduct(Product* products[], int& numProducts);
void printProducts(Product* products[], int numProducts);
void searchProducts(Product* products[], int numProducts);