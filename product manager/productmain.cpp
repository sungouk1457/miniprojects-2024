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

int main() {
    const int MAX_PRODUCTS = 100;
    Product* products[MAX_PRODUCTS];
    int numProducts = 0;

    while (true) {
        cout << "-----��ǰ ���� ���α׷�-----" << endl;
        cout << "1. ��ǰ�߰� 2. ��ǰ��� 3. ��ǰ�˻� 4. ����" << endl;
        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cout << "1~4�߿� �Է��ϼ���." << endl;
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
