//
// Created by 韩正博 on 18/4/18.
//

#include "Stack.h"

bool isnumber(char x) {
    if (x >= '0' && x <= '9')
        return true;
    return false;
}

int priority(char x) {
    if (x == '(' || x == ')')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '+' || x == '-')
        return 2;
    else if (x == '#')
        return 0;
}

int mystoi(string x) {
    int len = x.size();
    int result = 0;
    for (int i = 0; i < len; i++) {
        result = 10 * result + x[i] - '0';
    }
    return result;
}

void calculate(string s) {
    Stack<int> number;
    Stack<char> operate;
    char top;
    int numberA;
    int numberB;

    int len = s.size();

    for (int i = 0; i < len; i++) {
        if (isnumber(s[i])) {
            string temp;
            while (isnumber(s[i])) {
                temp += s[i];
                i++;
            }
            i--;
            int tempnumber = mystoi(temp);
            number.push(tempnumber);
            temp.clear();
        } else { //s[i]为操作符
            if (operate.isEmpty())
                operate.push(s[i]);
            else {
                top = operate.getTopElement();
                if (priority(top) < priority(s[i]) || s[i] == '(') {
                    operate.push(s[i]);
                } else {
                    while (priority(top) >= priority(s[i])) {
                        if (priority(top) == 0 && priority(s[i]) == 0) {
                            int answer = number.getTopElement();
                            number.pop();
                            operate.pop();
                            cout << "\n答案是：" << answer << endl;
                            return;
                        } else if (top == '(' && s[i] == ')') {
                            i++;
                        } else {
                            numberA = number.getTopElement();
                            number.pop();
                            numberB = number.getTopElement();
                            number.pop();
                        }
                        if (top == '+') {
                            numberB += numberA;
                            number.push(numberB);
                        } else if (top == '-') {
                            numberB -= numberA;
                            number.push(numberB);
                        } else if (top == '*') {
                            numberB *= numberA;
                            number.push(numberB);
                        } else if (top == '/') {
                            numberB /= numberA;
                            number.push(numberB);
                        }
                        operate.pop();
                        top = operate.getTopElement();
                    }
                    operate.push(s[i]);
                }
            }
        }
    }
}

int main(void) {
    string expression;
    cout << "输入一个用'#'开头和结尾的表达式：" << endl;
    cin >> expression;
    calculate(expression);
    return 0;
}
