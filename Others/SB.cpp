#include<bits/stdc++.h>
using namespace std;
int main(){
    // 假设已知某硬件寄存器的地址为0x40021000
    unsigned int *reg = (unsigned int*)0x402100;
    *reg = 0x01;  // 向该地址写入数据
}