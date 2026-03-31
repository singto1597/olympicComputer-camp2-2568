#include <iostream>
#include <vector>
#include <thread>

// ฟังก์ชันสำหรับรัน Loop นรก ปั่น CPU
void burn_cpu() {
    while (true) {
        // วนลูปไปเรื่อยๆ ไม่ต้องทำอะไร เพื่อให้ CPU Core นี้ทำงาน 100%
    }
}

int main() {
    std::cout << "Starting the ultimate test..." << std::endl;

    // --- ส่วนที่ 1: กิน RAM 4GB ---
    // คำนวณขนาด 4GB = 4 * 1024 * 1024 * 1024 bytes
    size_t size_to_eat = 4ULL * 1024 * 1024 * 1024; 
    
    // จอง RAM
    char* ram_eater = new char[size_to_eat];

    // ทริคสำคัญ: แค่ใช้คำสั่ง new OS บางตัวมันจะยังไม่ให้ RAM จริงๆ (เรียกว่า Lazy Allocation)
    // เราต้อง "เขียน" ข้อมูลลงไปในทุกๆ Page ของ RAM เพื่อบังคับให้ OS จ่าย Physical RAM มาให้เราจริงๆ
    for (size_t i = 0; i < size_to_eat; i += 4096) { 
        ram_eater[i] = 'X'; 
    }
    std::cout << "4GB Memory locked and loaded!" << std::endl;

    // while(true){};
    // --- ส่วนที่ 2: ปั่น CPU ให้ทะลุ 100% ---
    // เช็คว่าคอมเครื่องนี้มี CPU กี่ Threads จะได้สร้างตัวปั่นให้ครบทุกหัว
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    std::cout << "Igniting " << num_threads << " CPU threads..." << std::endl;

    // // ปล่อยเธรดผีดิบออกไปทำงาน
    for (unsigned int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(burn_cpu));
    }

    // // สั่งให้โปรแกรมหลักรอเธรดลูกทำงาน (ซึ่งมันรัน Infinite loop ก็คือรอตลอดกาล)
    for (auto& t : threads) {
        t.join();
    }

    // คืนค่า Memory (ถึงแม้โค้ดจะมาไม่ถึงตรงนี้ก็ตาม 555)
    delete[] ram_eater;
    return 0;
}