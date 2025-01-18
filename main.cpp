// BÀI TOÁN: Job Sequencing Problem with Deadlines - Sắp xếp trình tự công việc với thời hạn cho trước





// Job Sequencing with Deadlines Solution

#include <iostream>


// Cấu trúc 1 công việc
struct Job {
    char id;        // id của công việc
    int deadline;   // Deadline để hoàn thành công việc
    int profit;     // Lợi nhuận khi hoàn thành công việc
};

// Hàm hoán đổi 2 công việc
void swap(Job& a, Job& b) {
    Job temp = a;   
    a = b;          
    b = temp;       
}

// Hàm sắp xếp công việc dựa vào lợi nhuận bằng Bubble sort
void sortByProfit(Job* jobs, int n) {
    
    for (int i = 0; i < n - 1; i++) {
        
        for (int j = 0; j < n - i - 1; j++) {
            // Nếu lợi nhuận của công việc hiện tại nhỏ hơn công việc kế tiếp -> hoán đổi
            if (jobs[j].profit < jobs[j + 1].profit) {
                swap(jobs[j], jobs[j + 1]);
            }
        }
    }
}

// Hàm tìm deadline lớn nhất trong tất cả các công việc
int findMaxDeadline(Job* jobs, int n) {
    int maxDeadline = jobs[0].deadline;  // Khởi tạo với deadline của công việc đầu tiên
    // Duyệt qua tất cả các công việc để tìm deadline lớn nhất
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Hàm chính để tìm thứ tự các công việc tối ưu hóa lợi nhuận
void findJobSequence(Job* jobs, int n, char* result, int& resultSize) {
    // Sắp xếp tất cả các công việc theo thứ tự giảm dần của lợi nhuận
    sortByProfit(jobs, n);
    
    // Tìm deadline lớn nhất để xác định kích thước của mảng kết quả
    int maxDeadline = findMaxDeadline(jobs, n);
    resultSize = maxDeadline;
    
    // Khởi tạo mảng kết quả với các ô trống được đánh dấu là '-'
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = '-';
    }
    
    // Tạo mảng boolean để theo dõi các ô đã được lấp đầy
    bool* slot = new bool[maxDeadline]();  // Tất cả các ô được khởi tạo là false
    
    // Duyệt qua tất cả các công việc
    for (int i = 0; i < n; i++) {
        // Tìm ô trống muộn nhất trước deadline của công việc
        for (int j = (jobs[i].deadline <= maxDeadline ? jobs[i].deadline - 1 : maxDeadline - 1); j >= 0; j--) {
            // Nếu ô trống
            if (!slot[j]) {
                result[j] = jobs[i].id;     // Gán công việc vào ô này
                slot[j] = true;             // Đánh dấu ô đã được lấp đầy
                break;                      // Chuyển sang công việc tiếp theo
            }
        }
    }
    
    // Giải phóng bộ nhớ cấp phát động
    delete[] slot;
}

// Hàm tính tổng lợi nhuận từ thứ tự công việc
int calculateTotalProfit(char* sequence, int seqSize, Job* jobs, int n) {
    int totalProfit = 0;  // Khởi tạo tổng lợi nhuận
    // Duyệt qua thứ tự công việc
    for (int i = 0; i < seqSize; i++) {
        // Nếu ô không trống
        if (sequence[i] != '-') {
            // Tìm công việc tương ứng và cộng lợi nhuận của nó
            for (int j = 0; j < n; j++) {
                if (jobs[j].id == sequence[i]) {
                    totalProfit += jobs[j].profit;
                    break;
                }
            }
        }
    }
    return totalProfit;
}

// Hàm chính - Điểm bắt đầu chương trình
int main() {
    // Khởi tạo mảng công việc với các thuộc tính (id, deadline, lợi nhuận)
    Job jobs[] = {
        {'a', 2, 100},  // Công việc 'a': deadline 2, lợi nhuận 100
        {'b', 1, 19},   // Công việc 'b': deadline 1, lợi nhuận 19
        {'c', 2, 27},   // Công việc 'c': deadline 2, lợi nhuận 27
        {'d', 1, 25},   // Công việc 'd': deadline 1, lợi nhuận 25
        {'e', 3, 15}    // Công việc 'e': deadline 3, lợi nhuận 15
    };
    
    // Tính số lượng công việc trong mảng
    int n = sizeof(jobs) / sizeof(jobs[0]);
    
    // Tạo mảng động để lưu thứ tự công việc
    char* sequence = new char[n];
    int sequenceSize;  // Biến lưu kích thước thứ tự kết quả
    
    // Tìm thứ tự công việc tối ưu
    findJobSequence(jobs, n, sequence, sequenceSize);
    
    // Tính tổng lợi nhuận từ thứ tự công việc
    int totalProfit = calculateTotalProfit(sequence, sequenceSize, jobs, n);
    
    // In ra thứ tự công việc tối ưu
    std::cout << "The optimized order of work is: ";
    for (int i = 0; i < sequenceSize; i++) {
        std::cout << sequence[i] << " ";
    }
    // In ra tổng lợi nhuận
    std::cout << "\nTotal profit: " << totalProfit << std::endl;
    
    // Giải phóng bộ nhớ cấp phát động
    delete[] sequence;
    
    return 0;  
}
