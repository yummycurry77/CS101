#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// qsort 輔助函式 (for sorting)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 函式1: 讀取計數器 (Read the counter)
// (符合 CJ 48: 檢查是否有小本本)
int get_current_count() {
    int counter = 0;
    FILE* fp = fopen("counter.bin", "rb"); // "rb" = read binary
    
    if (fp != NULL) {
        // 檔案存在，讀取數字
        fread(&counter, sizeof(int), 1, fp);
        fclose(fp);
    }
    // 檔案不存在 (fp == NULL)，counter 會維持 0 (第一次執行)
    return counter;
}

// 函式2: 儲存新的計數器 (Save the new counter)
// (符合 CJ 48: 把 counter++ 記錄到小本本)
void save_new_count(int new_count) {
    FILE* fp = fopen("counter.bin", "wb"); // "wb" = write binary
    if (fp) {
        fwrite(&new_count, sizeof(int), 1, fp);
        fclose(fp);
    }
}

// 函式3: 產生樂透檔案 (Generate the lotto file)
// (這就是你的 hw3，但加入了排序功能)
void generate_lotto_file(int n, const char* filename) {
    srand(1); // 根據 hw3，使用固定種子
    FILE* fp = fopen(filename, "w+");
    if (!fp) return;

    fprintf(fp, "========= lotto649 =========\n");
    
    // 加入日期
    time_t now; time(&now);
    struct tm *local_time = localtime(&now);
    char date_line[128];
    strftime(date_line, sizeof(date_line), "%B %d %Y\n", local_time);
    fprintf(fp, "%s", date_line);

    // 產生 5 組號碼
    for(int i = 0; i < 5; i++){
        int used[80];
        for(int j = 0; j < 79; j++) { used[j] = 0; }
        fprintf(fp,"%c%d%c:",'[',i+1,']');
        
        if(i + 1 <= n){ // 只產生 n 組
            int count = 0;
            int numbers_to_sort[7]; // 暫存陣列
            
            while(count < 7){
                int tmp = rand() % 69 + 1;
                if(used[tmp] == 0){
                    used[tmp] = 1;
                    numbers_to_sort[count++] = tmp; // 存入
                }
            }
            // 排序
            qsort(numbers_to_sort, 7, sizeof(int), compare);
            
            // 從已排序陣列印出
            for(int k = 0; k < 7; k++) {
                fprintf(fp," %02d", numbers_to_sort[k]);
            }
        } else {
            for(int k = 0; k < 7; k++) fprintf(fp," __");
        }
        fprintf(fp,"\n");
    }
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);
}

// 函式4: Main (小於 50 行)
int main() {
    // 1. 讀取當前計數
    int current_count = get_current_count();
    int new_count = current_count + 1;

    // 2. 準備新檔名 (e.g., lotto[00001].txt)
    char filename[50];
    sprintf(filename, "lotto[%05d].txt", new_count); // %05d = 補零的5位數

    // 3. 詢問使用者要產生幾組 (n)
    int n;
    printf("請輸入要產生的彩券張數 n: ");
    scanf("%d", &n);
    
    // 4. 呼叫函式產生檔案 (hw3 邏輯)
    generate_lotto_file(n, filename);
    
    // 5. 呼叫函式，把新計數 (n+1) 寫回 counter.bin
    save_new_count(new_count);

    printf("已產生 %s\n", filename);
    return 0;
}
