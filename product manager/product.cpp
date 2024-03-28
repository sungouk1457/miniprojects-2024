/*
    File:product.c
    Created:24-03-06
    Author:홍승욱
*/
#include"product.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


Product::Product() { price = 0; }

Product::Product(string Pid, int Pprice, string Pproducer) {
    id = Pid;
    price = Pprice;
    producer = Pproducer;
}

void Product::ShowProduct() {
    cout << "ID : " << id << endl << "가격 : " << price << " 원" << endl << "제조사(출판사) : " << producer << endl;
}

string Product::mytype() { return "Product"; }

string Product::getInfo() { return "ID"; }

Product::~Product() { cout << "Product 소멸자 실행" << endl; }

Book::Book(string Bid, int Bprice, string Bproducer, string BISBN, string Bauthor, string Btitle)
    : Product(Bid, Bprice, Bproducer) {
    ISBN = BISBN;
    author = Bauthor;
    title = Btitle;
}

void Book::ShowProduct() {
    cout << "[Book]" << endl;
    Product::ShowProduct();
    cout << "ISBN : " << ISBN << endl << "저자 : " << author << endl << "도서명 : " << title << endl;
    cout << "---------------" << endl;
}

string Book::mytype() { return "Book"; }

string Book::getInfo() { return title; }

Handphone::Handphone(string Hid, int Hprice, string Hproducer, string Hmodel, int HRAM)
    : Product(Hid, Hprice, Hproducer) {
    model = Hmodel;
    RAM = HRAM;
}

void Handphone::ShowProduct() {
    cout << "[Handphone]" << endl;
    Product::ShowProduct();
    cout << "모델명 : " << model << endl << "RAM 크기 : " << RAM << " G" << endl;
    cout << "---------------" << endl;
}

string Handphone::mytype() { return "Handphone"; }

string Handphone::getInfo() { return model; }

Computer::Computer(string Cid, int Cprice, string Cproducer, string Cmodel, string Ccpu, int CRAM)
    : Product(Cid, Cprice, Cproducer) {
    model = Cmodel;
    cpu = Ccpu;
    RAM = CRAM;
}

void Computer::ShowProduct() {
    cout << "[Computer]" << endl;
    Product::ShowProduct();
    cout << "모델명 : " << model << endl << "CPU : " << cpu << endl << "RAM 크기 : " << RAM << " G" << endl;
    cout << "---------------" << endl;
}

string Computer::mytype() { return "Computer"; }

string Computer::getInfo() { return model; }

void addProduct(Product* products[], int& numProducts) {
    cout << "_____[상품 추가]_____" << endl;
    cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 4) {
        cout << "1~4중에 입력하세요." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }

    string id, producer;
    int price, RAM;
    string model, cpu;
    string ISBN, author, title;

    switch (choice) {
    case 1:
        cout << "ID > ";
        cin >> id;
        cout << "가격 > ";
        cin >> price;
        cout << "출판사 > ";
        cin >> producer;
        cout << "ISBN > ";
        cin >> ISBN;
        cout << "저자 > ";
        cin >> author;
        cout << "도서명 > ";
        cin >> title;
        products[numProducts++] = new Book(id, price, producer, ISBN, author, title);
        break;

    case 2:
        cout << "ID > ";
        cin >> id;
        cout << "가격 > ";
        cin >> price;
        cout << "제조사 > ";
        cin >> producer;
        cout << "모델명 > ";
        cin >> model;
        cout << "RAM 크기 > ";
        cin >> RAM;
        products[numProducts++] = new Handphone(id, price, producer, model, RAM);
        break;

    case 3:
        cout << "ID > ";
        cin >> id;
        cout << "가격 > ";
        cin >> price;
        cout << "제조사 > ";
        cin >> producer;
        cout << "모델명 > ";
        cin >> model;
        cout << "CPU > ";
        cin >> cpu;
        cout << "RAM 크기 > ";
        cin >> RAM;
        products[numProducts++] = new Computer(id, price, producer, model, cpu, RAM);
        break;

    case 4:
        break;
    }
}

void printProducts(Product* products[], int numProducts) {
    cout << "_____[상품 출력]_____" << endl;
    cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 4) {
        cout << "1~4중에 입력하세요." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }

    for (int i = 0; i < numProducts; ++i) {
        if (choice == 1 && typeid(*products[i]) == typeid(Book)) {
            products[i]->ShowProduct();
        }
        else if (choice == 2 && typeid(*products[i]) == typeid(Handphone)) {
            products[i]->ShowProduct();
        }
        else if (choice == 3 && typeid(*products[i]) == typeid(Computer)) {
            products[i]->ShowProduct();
        }
    }
}

void searchProducts(Product* products[], int numProducts) {
    cout << "_____[상품 검색]_____" << endl;
    cout << "1. 책 2. 핸드폰 3. 컴퓨터 4. 뒤로가기" << endl;

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 4) {
        cout << "1~4중에 입력하세요." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }

    string search;
    cout << "검색어를 입력하세요: ";
    cin >> search;

    for (int i = 0; i < numProducts; ++i) {
        if ((choice == 1 && typeid(*products[i]) == typeid(Book)) ||
            (choice == 2 && typeid(*products[i]) == typeid(Handphone)) ||
            (choice == 3 && typeid(*products[i]) == typeid(Computer))) {
            if (products[i]->getInfo().find(search) != string::npos) {
                products[i]->ShowProduct();
            }
        }
    }
}
