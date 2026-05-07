#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include <windows.h>
//#include <unistd.h>
// 根据系统选择头文件

int main(void) {
    
    const uint32_t total_step = 100;

    puts("\n进程加载中：");

    for (uint32_t i = 0; i <= total_step; i++) {
        printf("\r[");

        for (uint32_t j = 0; j < i; j++) {     // 打印i个#
            printf("#");
        }
        
        for (uint32_t k = 0; k < total_step - i; k++) {    // 打印total_step-i个空格
            printf(" ");
        }

        printf("] 加载进度：%" PRIu32 "%%", i);
        
        Sleep(1);
    }

    puts("\n加载完毕！\n");

    return 0;
}