# SStudio-test
 Nộp bài test đầu vào Sun.studio.

# Ghi chú và Giải thích:
+ Ngày làm bài chính thức (trong 3 giờ) là ngày 19/05/2023. Bắt đầu thực hiện từ 13h00. Đến 16h00 nộp bài, chỉ hoàn thành được Test 1. Test 2 chỉ xong phần initialize và Test 3 chưa làm.
+ Sau đó em cảm thấy bản thân chưa đủ tốt nên tiếp tục làm thêm test 2 và test 3 (mất khoảng 4~5 giờ).

+ Khoảng 16h30 ngày 22/05/2023, em được yêu cầu bổ sung test còn thiếu. Sáng ngày 23/05/2023 em mới đọc được email yêu cầu trên, tuy nhiên do vướng lịch thi trên trường nên 14h45 cùng ngày mới upload và submit thêm test 2 và test 3 "hoàn chỉnh", cùng file Readme.

# Ghi chú nội dung các bài test:
+ Test 1: Thực hiện thuật toán tìm ra những tổ hợp nhặt que đúng (nhặt 3 que có tổ hợp nhặt là [3 0 0], [2 0 1], [1 1 0], [0 0 1] ứng với [số lần nhặt 1 que - số lần nhặt 2 que - số lần nhặt 3 que]). Sau đó thực hiện tổ hợp.

+ Test 2: Trong 3 tiếng đầu em không thể giải xong vì implement DFS khi travel trên 2D array bị sai. Thực hiện thuật toán từ tọa độ cho trước tìm tất cả những index xung quanh có cùng giá trị tại tọa độ, lưu hết vào 1 set.

+ Test 3: Viết lại bằng C++. Một class gameManager chứa 1 loại data vector<string> có dạng A | B trong đó A là giá trị (màu bóng) và B là số lần bóng đã di chuyển. Có một số function thêm dùng để debug như hiển thị số lần bóng di chuyển, in ống theo hàng dọc (như trong phần đặc tả), ... Dù không viết trong Typescript nhưng em đã cố gắng adapt sang C++ với các tính năng và function yêu cầu.