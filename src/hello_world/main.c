#include <stdio.h>
#include <devices.h>
#include <task.h>

#include "opcodes.h"
#include "test.h"

void vTask() {
    printf(" Task created\n");
    while (1) {
        RunTest(ONE_TEST, iconst_0);
        vTaskDelay(2000 / portTICK_RATE_MS);
    }
}


int main()
{

    // Get char - to do not start programm immediatly 
    //getchar();

    puts("Interpreter executed\n");

    // Call default test case
    getchar();

    xTaskCreate(vTask, "vTask", 20480, NULL, 3, NULL);

    while(1);

    return 0;
}


