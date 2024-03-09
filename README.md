# Binary picture decoding
## Introduction

:small_blue_diamond: Quick Response code (QRcode)其內部紀錄了不少的資料，從原本的一維條碼，擴展到現在常見的二維 QRcode，增加了其可儲存的資料量及讀取速度。

:small_blue_diamond: 利用類似 QRcode 的方式，使用標準輸入輸出進行圖片的解碼，使用的編碼為ASCII。

## Method
- Input: 點陣圖數位影像檔案 (BMP)
    - 每一個字元由 8bit 組成，其編排方式由左至右，由下而上，讀取 24x24 像素的位圖資料，紅框為第一個字元 (下圖)



- Output: BMP解碼後合併出的字串，將像素值轉換為ASCII碼，範圍在32到126之間的值。
- 傳值方式: 
    ```
    int main(int argc,char* argv[])
    {
        ifstream fin;  fin.open(argv[1]);
    }
    ```
- Command: `./source.exe test.bmp`
- Skip the first 54 bytes (assuming it's a bitmap header)
    ```
    for (int i = 0; i < 54; i++)
            fin.get(ch);
    ```
  ![](https://github.com/jaifenny/Binary_picture_decoding/blob/main/picture/1.jpg)
