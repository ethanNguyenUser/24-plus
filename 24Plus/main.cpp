//
//  main.cpp
//  24
//  Program plays the "24" card game for you so you don't have to
//  Created by Ethan Nguyen on 10/16/21.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int solutions = 0;
int value = 0;

int factorial(int num){
    if(num <= 1)
        return 1;
    return num * factorial(num - 1);
}

//takes one string operator and two operands and returns result
int op2(int a, int ope, int b){
    if(ope == 0)
        return a + b;
    else if(ope == 1)
        return a - b;
    else if(ope == 2)
        return a * b;
    else if(ope == 3 && a % b == 0 && b != 0)
        return a / b;
    //    else if()
    //        return a;
    else if(ope == 4 && pow(a, b) < 500)
        return pow(a, b);
    return -99999;
}

int op1(int num, int ope){
    if(ope == 0)
        return num;
    if(ope == 1){
        double root = sqrt(num);
        if(root == (int) root)
            return root;
        return -99999;

    }
    if(ope == 2 && num <= 10)
        return factorial(num);
    return -99999;
}

//Two operand operators
string numToOp2(int ope){
    if(ope == 0)
        return "+";
    else if(ope == 1)
        return "-";
    else if(ope == 2)
        return "*";
    else if(ope == 3)
        return "/";
    return "^";
}

// One operand operators
string numToOp1(int num, int ope){
    if(ope == 0)
        return "";
    if(ope == 1){
        return "^(1/2)";
    }
    if(ope == 2)
        return "!";
    return "junk";
}

//runs through all permutations of operators
bool permutateOp(int a, int b, int c, int d){
    int total = 0;
    int op1a;
    int op1b;
    int op1c;
    int op1d;
    //one operand operators
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int l = 0; l < 3; l++){
                for(int m = 0; m < 3; m++){
                    //two operand operators
                    for(int n = 0; n < 4; n++){
                        for(int o = 0; o < 4; o++){
                            for(int p = 0; p < 4; p++){
                                //one operand operators
                                op1a = op1(a, i);
                                op1b = op1(b, j);
                                op1c = op1(c, l);
                                op1d = op1(d, m);
                                if(op1a == -99999 || op1b == -99999 || op1c == -99999 || op1d == -99999)
                                    continue;

                                //set total with two operand operators
                                total = op2(op2(op2(op1a, n, op1b), o, op1c), p, op1d);
                                //                                if(total == value){
                                //                                    cout << "((" + to_string(a) + numToOp1(a, i) + " " + numToOp2(n) + " " + to_string(b) + numToOp1(b, j) + ") " + numToOp2(o) + " " + to_string(c) + numToOp1(c, l)  + ") " + numToOp2(p) + " " + to_string(d) + numToOp1(d, m) + " = 4\n";
                                //                                    solutions++;
                                ////                                    return true;
                                //                                }
                                if(total == value){
                                    cout << "((" + to_string(a) + numToOp1(a, i) + " " + numToOp2(n) + " " + to_string(b) + numToOp1(b, j) + ") " + numToOp2(o) + " " + to_string(c) + numToOp1(c, l) + ") " + numToOp2(p) + " " + to_string(d) + numToOp1(d, m) + " = " << value << "\n";
                                    solutions++;
                                    //                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void combinateNum(int operands[]){
    solutions = 0;
    for(int k = 0; k < 4; k++){
        for(int j = 0; j < 4; j++){
            if(j == k)
                continue;
            for(int l = 0; l < 4; l++){
                if(l == j || l == k)
                    continue;
                for(int m = 0; m < 4; m++){
                    if(m == l || m == j || m == k)
                        continue;
                    if(permutateOp(operands[k], operands[j], operands[l], operands[m]))
                        return;
                }
            }
        }
    }
    cout << "There were about " << solutions << " solutions" << endl;
}

void play24(){
    int a = 2;
    int b = 2;
    int c = 2;
    int d = 2;

    while(a != 0 || b != 0 || c != 0 || d != 0){
        cout << "Enter value to become: ";
        cin >> value;

        cout << "Enter a: ";
        cin >> a;

        cout << "Enter b: ";
        cin >> b;

        cout << "Enter c: ";
        cin >> c;

        cout << "Enter d: ";
        cin >> d;

        int operands[4] = {a, b, c, d};
        combinateNum(operands);
    }
}

int main(){
    play24();
    return 0;
}

