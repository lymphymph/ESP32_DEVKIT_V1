#include <stdio.h>
#include "freertos/FreeRTOS.h"//FreeRtos固件
#include "freertos/task.h"
#include "driver/gpio.h" //gpio固件
//#include "esp_rom_gpio.h" 可以不要

#define LED_PIN GPIO_NUM_2  // GPIO2

void app_main(void)
{
    esp_rom_gpio_pad_select_gpio(LED_PIN); // 5.0版本的使能函数改成了esp_rom_gpio_pad_select_gpio()
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);//设置一个模式，应为输出模式
    gpio_set_level(LED_PIN,0);
    while (1) {
        gpio_set_level(LED_PIN, 0);  // 
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 延时1秒

        gpio_set_level(LED_PIN, 1);  // 
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // 延时1秒
    }
}
