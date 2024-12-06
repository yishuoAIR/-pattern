#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// �ݹ麯���������п��ܵ����
void generate_combinations(const std::string& input, std::vector<char>& output, int index, int length, std::ofstream& file) {
    // ����Ѵ�����������һ���ַ�����ӡ��ǰ������ļ�
    if (index == length) {
        // ������ַ���д���ļ�
        for (char c : output) {
            file << c;
        }
        file << "\n";  // ����
        return;
    }

    // �����ǰ�ַ���X���滻Ϊ0��1
    if (input[index] == 'X') {
        output[index] = '0';  // ���滻Ϊ0
        generate_combinations(input, output, index + 1, length, file);  // �ݹ鴦����һ���ַ�

        output[index] = '1';  // Ȼ���滻Ϊ1
        generate_combinations(input, output, index + 1, length, file);  // �ݹ鴦����һ���ַ�
    }
    else {
        output[index] = input[index];  // �����0��1��ֱ�Ӹ���
        generate_combinations(input, output, index + 1, length, file);  // �ݹ鴦����һ���ַ�
    }
}

int main() {
    std::string input;
    std::cout << "���������0��1��X���ַ���: ";
    std::cin >> input;  // ��ȡ�û�������ַ���

    int length = input.length();

    // ʹ�� std::vector<char> ����̬�洢���
    std::vector<char> output(length);

    // ���ļ���д��ģʽ��������ļ��������򴴽�
    std::ofstream file("output.txt", std::ios::out);
    if (!file.is_open()) {
        std::cerr << "�޷����ļ�!" << std::endl;
        return 1;  // ���ļ�ʧ�ܣ��˳�����
    }

    // ������ϲ������д���ļ�
    generate_combinations(input, output, 0, length, file);

    // �ر��ļ�
    file.close();

    std::cout << "���������д���ļ� output.txt\n";

    return 0;
}
