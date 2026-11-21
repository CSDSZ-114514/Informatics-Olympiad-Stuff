#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for reverse

// 函数：二进制字符串加法
// 输入：两个二进制字符串
// 输出：它们的和的二进制字符串
std::string addBinary(std::string a, std::string b) {
    std::string res = "";
    int i = a.length() - 1, j = b.length() - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        res += std::to_string(sum % 2);
        carry = sum / 2;
    }

    std::reverse(res.begin(), res.end());
    // 移除前导零，除非结果本身是 "0"
    size_t first_one = res.find('1');
    if (first_one == std::string::npos) { // All zeros
        return "0";
    }
    return res.substr(first_one);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    // 找到第一个 '1' 的位置
    size_t first_one_pos = s.find('1');

    // Case 1: 字符串中全是 '0' 或者为空
    if (first_one_pos == std::string::npos) {
        std::cout << "0\n";
        return 0;
    }

    std::string num1_str = "";
    std::string num2_str = "";

    // 将第一个 '1' 分配给 num1_str
    num1_str += '1';

    // 遍历原始字符串剩余部分
    for (size_t i = first_one_pos + 1; i < s.length(); ++i) {
        if (s[i] == '0') {
            num1_str += '0'; // 0 分配给 num1_str
        } else { // s[i] == '1'
            num2_str += '1'; // 1 分配给 num2_str
        }
    }
    
    // 如果 num2_str 为空 (没有第二个或后续的 '1')，它应被视为二进制数 0
    if (num2_str.empty()) {
        num2_str = "0";
    }

    // 执行二进制加法
    std::string result_binary = addBinary(num1_str, num2_str);

    std::cout << result_binary << "\n";

    return 0;
}