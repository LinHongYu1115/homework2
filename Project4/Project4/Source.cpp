#include <iostream>

using namespace std;

void print_usage(int size, int capacity) {
    cout << "�z�w�g�ϥΤF " << size << " �Ӥ������Ŷ��A�`�@���t�F " << capacity << " �Ӥ������Ŷ��C\n";
}

int main() {
    int capacity = 2;  // ��l�e�q
    int size = 0;      // ��e�ϥΪ��j�p
    int* arr = new int[capacity];  // �ʺA���t��l�}�C

    cout << "�п�J�Ʀr�]��J�D�Ʀr�H����^�G\n";

    while (true) {
        cout << "��J�Ʀr�G";
        int input;
        if (cin >> input) {
            // ��e�}�C�w���A�X�i�}�C
            if (size == capacity) {
                capacity *= 2;  // �C���X�i½��
                int* newArr = new int[capacity];  // �Ыطs�}�C
                for (int i = 0; i < size; i++) {
                    newArr[i] = arr[i];  // �ƻs�°}�C���ƾ�
                }
                delete[] arr;  // �����°}�C���O����
                arr = newArr;  // ��s���Ы��V�s�}�C
            }
            arr[size++] = input;  // �N�Ʀr�K�[��}�C��
        }
        else {
            break;  // �p�G��J�D�Ʀr�A�h����
        }
    }

    // �M�����~���A
    cin.clear();
    // �����Ѿl����J
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // ��ܨϥΪ��Ŷ��M�`�@���t���Ŷ�
    print_usage(size, capacity);

    // ����O����
    delete[] arr;

    return 0;
}
