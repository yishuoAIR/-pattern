#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// 递归函数生成所有可能的组合
void generate_combinations(const std::string& input, std::vector<char>& output, int index, int length, std::ofstream& file) {
    // 如果已处理到输入的最后一个字符，打印当前输出到文件
    if (index == length) {
        // 将输出字符串写入文件
        for (char c : output) {
            file << c;
        }
        file << "\n";  // 换行
        return;
    }

    // 如果当前字符是X，替换为0和1
    if (input[index] == 'X') {
        output[index] = '0';  // 先替换为0
        generate_combinations(input, output, index + 1, length, file);  // 递归处理下一个字符

        output[index] = '1';  // 然后替换为1
        generate_combinations(input, output, index + 1, length, file);  // 递归处理下一个字符
    }
    else {
        output[index] = input[index];  // 如果是0或1，直接复制
        generate_combinations(input, output, index + 1, length, file);  // 递归处理下一个字符
    }
}

int main() {
    std::string input;
    std::cout << "请输入包含0、1、X的字符串: ";
    std::cin >> input;  // 获取用户输入的字符串

    int length = input.length();

    // 使用 std::vector<char> 来动态存储输出
    std::vector<char> output(length);

    // 打开文件（写入模式），如果文件不存在则创建
    std::ofstream file("output.txt", std::ios::out);
    if (!file.is_open()) {
        std::cerr << "无法打开文件!" << std::endl;
        return 1;  // 打开文件失败，退出程序
    }

    // 生成组合并将结果写入文件
    generate_combinations(input, output, 0, length, file);

    // 关闭文件
    file.close();

    std::cout << "所有组合已写入文件 output.txt\n";

    return 0;
}
