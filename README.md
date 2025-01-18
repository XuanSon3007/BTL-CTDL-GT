MÔ TẢ: Cho một danh sách các nhiệm vụ có thời hạn và tổng lợi nhuận kiếm được khi hoàn thành một nhiệm vụ,
      hãy tìm lợi nhuận tối đa kiếm được bằng cách thực hiện các nhiệm vụ trong thời hạn đã chỉ định. 
      Giả sử rằng mỗi nhiệm vụ cần một đơn vị thời gian để hoàn thành và một nhiệm vụ không thể thực hiện
       vượt quá thời hạn của nó. Ngoài ra, chỉ có một nhiệm vụ duy nhất sẽ được thực hiện tại một thời điểm.



MÔ TẢ GIẢI THUẬT
     B1: Sắp xếp công việc theo thứ tự lợi nhuận giảm dần
     B2: Tìm thời hạn tối đa trong số tất cả các công việc
     B3: Khởi tạo mảng kết quả có kích thước max_deadline với các ô trống
     B4: Đối với mỗi công việc theo thứ tự đã sắp xếp:
        - Tìm ô có sẵn mới nhất trước thời hạn của công việc
        - Nếu tìm thấy ô, chỉ định công việc cho ô đó
     B5: Trả về chuỗi công việc và tính tổng lợi nhuận 




