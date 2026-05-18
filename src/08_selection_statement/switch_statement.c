#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

bool check_for_manager();
bool check_for_employee(uint32_t);
bool check_for_intern(uint32_t, bool);

int main(void) {

    /*
    权限管理问题：
    身份：经理，员工，实习生
    1.经理：有权限
    2.员工：做完5次任务
    3.实习生：做完10次任务，并获得经理许可

    变量：身份、任务完成次数、经理许可
    */

    uint32_t role = 2;
    uint32_t completed_tasks = 15;
    bool is_manager_approved = true;

    bool access_allowed = false;

    switch(role) {

        case 1: // role == 1
        access_allowed = check_for_manager();
        break;

        case 2:
        access_allowed = check_for_employee(completed_tasks);
        break;

        case 3:
        access_allowed = check_for_intern(completed_tasks, is_manager_approved);
        break;

        default:
        access_allowed = false;
        break;
    }

    if (access_allowed) {
        printf("允许访问");
    }
    else {
        printf("拒绝访问");
    }

    return 0;
}

bool check_for_manager() {
    return true;
}

bool check_for_employee(uint32_t completed_tasks) {
    return completed_tasks >= 5;
}

bool check_for_intern(uint32_t completed_tasks, bool is_manager_approved) {
    return completed_tasks >= 10 && is_manager_approved;
}