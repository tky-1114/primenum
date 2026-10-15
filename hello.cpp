#include <iostream>
#include <csignal>
#include <atomic>

std::atomic<bool> stop_flag(false);

// Ctrl+C が押されたときに呼ばれる
void signal_handler(int sig) {
    if (sig == SIGINT) {
        stop_flag = true;
    }
}

int main() {
    // Ctrl+C を監視
    signal(SIGINT, signal_handler);

    long long n = 2;

    while (!stop_flag) {
        // ここに計算処理を書く
        if (n % 1000000 == 0) {
            std::cout << "now: " << n << std::endl;
        }
        n++;
    }

    // Ctrl+C後にここに来る
    std::cout << "\nCtrl+C detected. Safe exit.\n";
    std::cout << "last n = " << n << std::endl;

    // 保存処理とかここでやる
    return 0;
}
