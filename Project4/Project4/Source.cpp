#include <iostream>

using namespace std;

void print_usage(int size, int capacity) {
    cout << "您已經使用了 " << size << " 個元素的空間，總共分配了 " << capacity << " 個元素的空間。\n";
}

int main() {
    int capacity = 2;  // 初始容量
    int size = 0;      // 當前使用的大小
    int* arr = new int[capacity];  // 動態分配初始陣列

    cout << "請輸入數字（輸入非數字以停止）：\n";

    while (true) {
        cout << "輸入數字：";
        int input;
        if (cin >> input) {
            // 當前陣列已滿，擴展陣列
            if (size == capacity) {
                capacity *= 2;  // 每次擴展翻倍
                int* newArr = new int[capacity];  // 創建新陣列
                for (int i = 0; i < size; i++) {
                    newArr[i] = arr[i];  // 複製舊陣列的數據
                }
                delete[] arr;  // 釋放舊陣列的記憶體
                arr = newArr;  // 更新指標指向新陣列
            }
            arr[size++] = input;  // 將數字添加到陣列中
        }
        else {
            break;  // 如果輸入非數字，則停止
        }
    }

    // 清除錯誤狀態
    cin.clear();
    // 忽略剩餘的輸入
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // 顯示使用的空間和總共分配的空間
    print_usage(size, capacity);

    // 釋放記憶體
    delete[] arr;

    return 0;
}
