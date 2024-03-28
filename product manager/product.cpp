/*
    File:product.c
    Created:24-03-06
    Author:ȫ�¿�
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
    cout << "ID : " << id << endl << "���� : " << price << " ��" << endl << "������(���ǻ�) : " << producer << endl;
}

string Product::mytype() { return "Product"; }

string Product::getInfo() { return "ID"; }

Product::~Product() { cout << "Product �Ҹ��� ����" << endl; }

Book::Book(string Bid, int Bprice, string Bproducer, string BISBN, string Bauthor, string Btitle)
    : Product(Bid, Bprice, Bproducer) {
    ISBN = BISBN;
    author = Bauthor;
    title = Btitle;
}

void Book::ShowProduct() {
    cout << "[Book]" << endl;
    Product::ShowProduct();
    cout << "ISBN : " << ISBN << endl << "���� : " << author << endl << "������ : " << title << endl;
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
    cout << "�𵨸� : " << model << endl << "RAM ũ�� : " << RAM << " G" << endl;
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
    cout << "�𵨸� : " << model << endl << "CPU : " << cpu << endl << "RAM ũ�� : " << RAM << " G" << endl;
    cout << "---------------" << endl;
}

string Computer::mytype() { return "Computer"; }

string Computer::getInfo() { return model; }

void addProduct(Product* products[], int& numProducts) {
    cout << "_____[��ǰ �߰�]_____" << endl;
    cout << "1. å 2. �ڵ��� 3. ��ǻ�� 4. �ڷΰ���" << endl;

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 4) {
        cout << "1~4�߿� �Է��ϼ���." << endl;
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
        cout << "���� > ";
        cin >> price;
        cout << "���ǻ� > ";
        cin >> producer;
        cout << "ISBN > ";
        cin >> ISBN;
        cout << "���� > ";
        cin >> author;
        cout << "������ > ";
        cin >> title;
        products[numProducts++] = new Book(id, price, producer, ISBN, author, title);
        break;

    case 2:
        cout << "ID > ";
        cin >> id;
        cout << "���� > ";
        cin >> price;
        cout << "������ > ";
        cin >> producer;
        cout << "�𵨸� > ";
        cin >> model;
        cout << "RAM ũ�� > ";
        cin >> RAM;
        products[numProducts++] = new Handphone(id, price, producer, model, RAM);
        break;

    case 3:
        cout << "ID > ";
        cin >> id;
        cout << "���� > ";
        cin >> price;
        cout << "������ > ";
        cin >> producer;
        cout << "�𵨸� > ";
        cin >> model;
        cout << "CPU > ";
        cin >> cpu;
        cout << "RAM ũ�� > ";
        cin >> RAM;
        products[numProducts++] = new Computer(id, price, producer, model, cpu, RAM);
        break;

    case 4:
        break;
    }
}

void printProducts(Product* products[], int numProducts) {
    cout << "_____[��ǰ ���]_____" << endl;
    cout << "1. å 2. �ڵ��� 3. ��ǻ�� 4. �ڷΰ���" << endl;

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 4) {
        cout << "1~4�߿� �Է��ϼ���." << endl;
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
    cout << "_____[��ǰ �˻�]_____" << endl;
    cout << "1. å 2. �ڵ��� 3. ��ǻ�� 4. �ڷΰ���" << endl;

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 4) {
        cout << "1~4�߿� �Է��ϼ���." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }

    string search;
    cout << "�˻�� �Է��ϼ���: ";
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
