#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// 递归函数生成所有可能的组合
void generate_combinations(const std::string& input, std::vector<char>& output, int index, int length, std::ofstream& file, const std::string& output1) {
    // 如果已处理到输入的最后一个字符，打印当前组合并加上输出1（例如：HLLHH）
    if (index == length) {
        // 输出2：每个组合前加 " INC" 并附加上自定义的输出1（如 HLLHH）
        std::cout << " INC";
        for (int i = 0; i < length; ++i) {
            std::cout << output[i];  // 输出当前的组合
        }
        std::cout << output1 << std::endl;  // 每个组合后添加输出1
        file << " INC";
        for (int i = 0; i < length; ++i) {
            file << output[i];  // 写入当前的组合
        }
        file << output1 << std::endl;  // 每个组合后添加输出1到文件

        return;
    }

    // 如果当前字符是X，替换为0和1
    if (input[index] == 'X') {
        output[index] = '0';  // 先替换为0
        generate_combinations(input, output, index + 1, length, file, output1);  // 递归处理下一个字符

        output[index] = '1';  // 然后替换为1
        generate_combinations(input, output, index + 1, length, file, output1);  // 递归处理下一个字符
    }
    else {
        output[index] = input[index];  // 如果是0或1，直接复制
        generate_combinations(input, output, index + 1, length, file, output1);  // 递归处理下一个字符
    }
}

int main() {
    std::string input;
    std::string output1;

    // 获取用户输入的字符串
    std::cout << "请输入包含0、1、X的字符串: ";
    std::cin >> input;

    // 获取用户自定义的输出1内容
    std::cout << "请输入输出1的内容（例如 HLLHH 或你自定义的内容）: ";
    std::cin >> output1;

    int length = input.length();

    // 使用 std::vector<char> 来动态存储输出
    std::vector<char> output(length);

    // 打开文件（写入模式），如果文件不存在则创建
    std::ofstream file("output.txt", std::ios::out);
    if (!file.is_open()) {
        std::cerr << "无法打开文件!" << std::endl;
        return 1;  // 打开文件失败，退出程序
    }

    // 输出1：自定义的内容（如HLLHH）
    std::cout << output1 << std::endl;
    file << output1 << std::endl;

    // 生成组合并将结果写入文件
    generate_combinations(input, output, 0, length, file, output1);

    // 关闭文件
    file.close();

    std::cout << "所有组合已写入文件 output.txt\n";

    return 0;
}
