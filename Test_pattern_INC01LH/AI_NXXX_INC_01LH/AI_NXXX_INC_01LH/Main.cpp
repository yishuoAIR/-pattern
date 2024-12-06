#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// �ݹ麯���������п��ܵ����
void generate_combinations(const std::string& input, std::vector<char>& output, int index, int length, std::ofstream& file, const std::string& output1) {
    // ����Ѵ�����������һ���ַ�����ӡ��ǰ��ϲ��������1�����磺HLLHH��
    if (index == length) {
        // ���2��ÿ�����ǰ�� " INC" ���������Զ�������1���� HLLHH��
        std::cout << " INC";
        for (int i = 0; i < length; ++i) {
            std::cout << output[i];  // �����ǰ�����
        }
        std::cout << output1 << std::endl;  // ÿ����Ϻ�������1
        file << " INC";
        for (int i = 0; i < length; ++i) {
            file << output[i];  // д�뵱ǰ�����
        }
        file << output1 << std::endl;  // ÿ����Ϻ�������1���ļ�

        return;
    }

    // �����ǰ�ַ���X���滻Ϊ0��1
    if (input[index] == 'X') {
        output[index] = '0';  // ���滻Ϊ0
        generate_combinations(input, output, index + 1, length, file, output1);  // �ݹ鴦����һ���ַ�

        output[index] = '1';  // Ȼ���滻Ϊ1
        generate_combinations(input, output, index + 1, length, file, output1);  // �ݹ鴦����һ���ַ�
    }
    else {
        output[index] = input[index];  // �����0��1��ֱ�Ӹ���
        generate_combinations(input, output, index + 1, length, file, output1);  // �ݹ鴦����һ���ַ�
    }
}

int main() {
    std::string input;
    std::string output1;

    // ��ȡ�û�������ַ���
    std::cout << "���������0��1��X���ַ���: ";
    std::cin >> input;

    // ��ȡ�û��Զ�������1����
    std::cout << "���������1�����ݣ����� HLLHH �����Զ�������ݣ�: ";
    std::cin >> output1;

    int length = input.length();

    // ʹ�� std::vector<char> ����̬�洢���
    std::vector<char> output(length);

    // ���ļ���д��ģʽ��������ļ��������򴴽�
    std::ofstream file("output.txt", std::ios::out);
    if (!file.is_open()) {
        std::cerr << "�޷����ļ�!" << std::endl;
        return 1;  // ���ļ�ʧ�ܣ��˳�����
    }

    // ���1���Զ�������ݣ���HLLHH��
    std::cout << output1 << std::endl;
    file << output1 << std::endl;

    // ������ϲ������д���ļ�
    generate_combinations(input, output, 0, length, file, output1);

    // �ر��ļ�
    file.close();

    std::cout << "���������д���ļ� output.txt\n";

    return 0;
}
