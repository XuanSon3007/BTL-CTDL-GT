# Bài Toán Sắp Xếp Công Việc với Thời Hạn - Phân Tích Cài Đặt

## Mô Tả Bài Toán
Bài toán Sắp Xếp Công Việc với Thời Hạn liên quan đến việc lập lịch các công việc để tối đa hóa lợi nhuận trong khi vẫn đảm bảo thời hạn của từng công việc. Mỗi công việc có:
- Một định danh duy nhất
- Một thời hạn phải hoàn thành
- Một giá trị lợi nhuận thu được khi hoàn thành công việc

## MÔ TẢ GIẢI THUẬT
     B1: Sắp xếp công việc theo thứ tự lợi nhuận giảm dần
     B2: Tìm thời hạn tối đa trong số tất cả các công việc
     B3: Khởi tạo mảng kết quả có kích thước max_deadline với các ô trống
     B4: Đối với mỗi công việc theo thứ tự đã sắp xếp:
        - Tìm ô có sẵn mới nhất trước thời hạn của công việc
        - Nếu tìm thấy ô, chỉ định công việc cho ô đó
     B5: Trả về chuỗi công việc và tính tổng lợi nhuận 

## Các Thành Phần Cài Đặt

### 1. Cấu Trúc Dữ Liệu
- Struct `Job` bao gồm:
  - `id` (char): Định danh duy nhất cho mỗi công việc
  - `deadline` (int): Thời hạn để hoàn thành công việc
  - `profit` (int): Lợi nhuận thu được từ việc hoàn thành công việc
- Mảng boolean `slot[]` để theo dõi các khoảng thời gian đã được sử dụng
- Mảng ký tự `sequence[]` để lưu trữ chuỗi công việc cuối cùng

### 2. Các Hàm Chính

#### 2.1 `sortByProfit`
- Sử dụng thuật toán Bubble Sort để sắp xếp công việc theo thứ tự giảm dần của lợi nhuận
- Độ phức tạp thời gian: O(n²)
- Đảm bảo các công việc có lợi nhuận cao nhất được xem xét trước

#### 2.2 `findMaxDeadline`
- Quét tất cả công việc để tìm thời hạn lớn nhất
- Được sử dụng để xác định kích thước của mảng kết quả
- Độ phức tạp thời gian: O(n)

#### 2.3 `findJobSequence`
Cài đặt thuật toán chính:
1. Sắp xếp công việc theo lợi nhuận (giảm dần)
2. Tìm thời hạn lớn nhất
3. Khởi tạo mảng kết quả với ký tự '-'
4. Với mỗi công việc:
   - Cố gắng đặt nó vào vị trí trễ nhất có thể trước thời hạn
   - Nếu vị trí còn trống, gán công việc và đánh dấu vị trí đã được sử dụng
   - Nếu không có vị trí trống, bỏ qua công việc
- Độ phức tạp thời gian: O(n²)

#### 2.4 `calculateTotalProfit`
- Tính tổng lợi nhuận từ chuỗi công việc cuối cùng
- Khớp các ID trong chuỗi với dữ liệu công việc gốc
- Độ phức tạp thời gian: O(n²)

## Phân Tích Đầu Vào/Đầu Ra

### Dữ Liệu Đầu Vào Mẫu
```cpp
Job jobs[] = {
    {'a', 2, 100},  // id: 'a', deadline: 2, lợi nhuận: 100
    {'b', 1, 19},   // id: 'b', deadline: 1, lợi nhuận: 19
    {'c', 2, 27},   // id: 'c', deadline: 2, lợi nhuận: 27
    {'d', 1, 25},   // id: 'd', deadline: 1, lợi nhuận: 25
    {'e', 3, 15}    // id: 'e', deadline: 3, lợi nhuận: 15
};
```

### Các Bước Xử Lý
1. Sắp xếp ban đầu theo lợi nhuận:
   ```
   a(100) > c(27) > d(25) > b(19) > e(15)
   ```

2. Phân bổ vị trí:
   - Công việc 'a' (deadline 2): Đặt vào vị trí 1
   - Công việc 'c' (deadline 2): Đặt vào vị trí 0
   - Công việc 'd' (deadline 1): Không thể đặt (vị trí đã đầy)
   - Công việc 'b' (deadline 1): Không thể đặt (vị trí đã đầy)
   - Công việc 'e' (deadline 3): Đặt vào vị trí 2

3. Chuỗi cuối cùng: "c a e"

### Đầu Ra
```
Thứ tự công việc tối ưu: c a e
Tổng lợi nhuận: 142 (100 + 27 + 15)
```

## Kiểm Thử Thuật Toán

### Các Trường Hợp Kiểm Thử Cần Xem Xét

1. Trường Hợp Cơ Bản (Cài Đặt Hiện Tại):
   - Nhiều công việc với thời hạn và lợi nhuận khác nhau
   - Kiểm tra hành vi lập lịch thông thường

2. Các Trường Hợp Biên Cần Thêm:
   - Danh sách công việc rỗng
   - Một công việc duy nhất
   - Tất cả công việc có cùng thời hạn
   - Tất cả công việc có cùng lợi nhuận
   - Không có lịch khả thi
   - Thời hạn tối đa có thể (INT_MAX)

### Đặc Điểm Hiệu Suất

1. Độ Phức Tạp:
   - Tổng thể: O(n²) do sắp xếp và phân bổ vị trí
   - Độ phức tạp không gian: O(n) cho các mảng phụ trợ

2. Sử Dụng Bộ Nhớ:
   - Cấp phát động cho mảng sequence và slot
   - Quản lý bộ nhớ đúng với delete[]
   - Không có rò rỉ bộ nhớ trong cài đặt hiện tại

## Cải Tiến Có Thể

1. Tối Ưu Hóa Thuật Toán:
   - Thay thế Bubble Sort bằng Quick Sort để đạt O(n log n)
   - Sử dụng hàng đợi ưu tiên cho việc chọn công việc
   - Triển khai cấu trúc dữ liệu tập hợp rời rạc để theo dõi vị trí

2. Cấu Trúc Mã:
   - Thêm kiểm tra đầu vào
   - Triển khai xử lý ngoại lệ
   - Thêm tài liệu cho giao diện công khai
   - Tạo các lớp riêng biệt để đóng gói tốt hơn

3. Tính Năng Bổ Sung:
   - Hỗ trợ phụ thuộc công việc
   - Nhiều ràng buộc tài nguyên
   - Thêm/xóa công việc thời gian thực
   - Theo dõi tiến độ và báo cáo trạng thái
