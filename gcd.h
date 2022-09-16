//
// Created by 17634 on 2022/9/15.
//

#ifndef ALGORITHM_GCD_H
#define ALGORITHM_GCD_H


// LCM:least common multiple 最小公倍数
// GCD:greatest common divisor 最大公约数

//LCM(A,B)×GCD(A,B)=A×B    即A和B的最小公倍数与最大公约数之积为AxB

//求法有以下四种：此处仅给出 ·辗转相除法· 代码，其他代码实现见
//https://holmofy.blog.csdn.net/article/details/76401074
//分解因式法
//辗转相除法
//更相减损法
//Stein算法

int gcd(int a, int b) { //辗转相除法
    return b == 0 ? a : gcd(b, a % b);
}

#endif //ALGORITHM_GCD_H
