# Dino Runner Game (SDL2 + C++)

---

## Giới thiệu

Dino Runner là một trò chơi mini đơn giản được xây dựng bằng **C++ và thư viện SDL2**, lấy cảm hứng từ trò chơi Dinosaur chạy khi mất mạng trên Chrome.  
Trong game, bạn sẽ điều khiển chú khủng long vượt qua các chướng ngại vật như xương rồng và chim, ăn tim để tăng mạng sống, và cố gắng sống sót lâu nhất có thể!

---

## Gameplay

- **Nhấn SPACE** để Dino nhảy qua chướng ngại vật.
- **Ăn tim (Heart)** để tăng mạng (tối đa 3 mạng).
- **Level tăng sau mỗi 20 giây**, game sẽ nhanh hơn.
- **Va chạm với chướng ngại vật** sẽ mất mạng, hết mạng thì **Game Over**.

---

##  Điều khiển

| Hành động            | Phím |
|-----------------------|------|
| Nhảy                  | `Space` |
| Bắt đầu trò chơi      | `Enter` hoặc Click nút `START` |
| Chơi lại khi Game Over| `Enter` |

---

## Cấu trúc thư mục

```plaintext
├── DinoGame/
│   ├── Source/
│   │   ├── main.cpp
│   │   ├── game.cpp / game.h
│   │   ├── dino.cpp / dino.h
│   │   ├── obstacle.cpp / obstacle.h
│   │   ├── bird.cpp / bird.h
│   │   ├── heart.cpp / heart.h
│   │   ├── mylib.cpp / mylib.h
│   ├── Images/
│   │   ├── dino.png
│   │   ├── cactus.png
│   │   ├── bird.png
│   │   ├── heart.png
│   │   ├── ground.png
│   │   ├── sky.png
│   │   ├── start.png
│   │   ├── gameover.png
│   ├── Fonts/
│   │   ├── FFF_Tusj.ttf
│   ├── DinoGame.sln (file solution)
