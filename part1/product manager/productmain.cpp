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

int main() {
    const int MAX_PRODUCTS = 100;
    Product* products[MAX_PRODUCTS];
    int numProducts = 0;

    while (true) {
        cout << "-----상품 관리 프로그램-----" << endl;
        cout << "1. 상품추가 2. 상품출력 3. 상품검색 4. 종료" << endl;
        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cout << "1~4중에 입력하세요." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            addProduct(products, numProducts);
            break;
        case 2:
            printProducts(products, numProducts);
            break;
        case 3:
            searchProducts(products, numProducts);
            break;
        case 4:
            return 0;
        }
    }

    return 0;
}
