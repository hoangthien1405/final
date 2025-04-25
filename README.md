#  Dino Runner Game (SDL2 + C++)

---

##  Giới thiệu

Dino Runner là một trò chơi mini đơn giản được xây dựng bằng **C++ và thư viện SDL2**, lấy cảm hứng từ trò chơi Dinosaur khi mất mạng trên trình duyệt Chrome.  
Trong game, bạn sẽ điều khiển chú khủng long vượt qua chướng ngại vật, ăn tim để tăng mạng sống, và cố gắng sống sót lâu nhất có thể!

---

##  Gameplay

- **Nhấn SPACE** để Dino nhảy qua chướng ngại vật.
- **Ăn tim (Heart)** để tăng mạng (tối đa 3 mạng).
- **Level tăng sau mỗi 20 giây**, tốc độ game cũng nhanh dần.
- **Va chạm chướng ngại vật** sẽ mất mạng, hết mạng thì **Game Over**.

---

##  Điều khiển

| Hành động             | Phím |
|------------------------|------|
| Nhảy                  | `Space` |
| Bắt đầu chơi          | `Enter` hoặc Click vào nút `START` |
| Chơi lại sau Game Over | `Enter` |

---

##  Cấu trúc thư mục (Giải thích cực kỳ chi tiết)

###  1. `Source/` — **Mã nguồn chính**

| File                 | Vai trò |
|----------------------|---------|
| `main.cpp`           | Hàm `main()`, tạo đối tượng `Game`, chạy game. |
| `game.cpp/h`         | Điều phối toàn bộ game: Init, Run, Event, Update, Render, Reset. |
| `dino.cpp/h`         | Quản lý nhân vật Dino: nhảy, reset trạng thái. |
| `obstacle.cpp/h`     | Quản lý cây xương rồng: spawn và reset chướng ngại vật. |
| `bird.cpp/h`         | Quản lý chim bay: spawn sau một số cây cactus. |
| `heart.cpp/h`        | Quản lý trái tim: spawn random, ăn để tăng mạng. |
| `mylib.cpp/h`        | Hàm tiện ích: load hình ảnh, font chữ, render text. |

---

###  2. `Images/` — **Tài nguyên hình ảnh**

| Ảnh            | Mô tả |
|-----------------|------|
| `dino.png`      | Hình ảnh Dino (nhân vật). |
| `cactus.png`    | Hình cây xương rồng (Obstacle). |
| `bird.png`      | Hình ảnh chim bay. |
| `heart.png`     | Hình trái tim để ăn thêm mạng. |
| `ground.png`    | Mặt đất Dino chạy trên. |
| `sky.png`       | Bầu trời làm nền. |
| `start.png`     | Nút "START" trong menu. |
| `gameover.png`  | Hình "GAME OVER" khi thua. |

---

###  3. `Fonts/` — **Font chữ**

| File            | Vai trò |
|-----------------|---------|
| `FFF_Tusj.ttf`  | Font chữ nghệ thuật dùng để render tiêu đề menu ("DINO RUN"). |

---

###  4. `DinoGame.sln` — **File Solution Visual Studio**

- Mở nhanh project bằng Visual Studio.
- Quản lý liên kết SDL2 tự động.

---

###  Sơ đồ luồng điều khiển tổng quát:

```plaintext
main.cpp
  ↓
Game
  ├── Dino
  ├── Obstacle ──> Bird
  ├── Heart
  ↓
Render Background (sky, ground) + Object + UI (start, gameover)
