#include "stm32f1xx.h"

void gpio(void) {
    RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC -> CRH |= GPIO_CRH_MODE13_0 | GPIO_CRH_MODE13_1;
    GPIOC -> CRH &= ~(GPIO_CRH_CNF13_0 | GPIO_CRH_CNF13_1);
    GPIOC -> ODR |= GPIO_ODR_ODR13;
}

void delay(uint32_t tempo){
    while(tempo--){
        __NOP();
        __NOP();
        __NOP();
    }
}
int main() {
    gpio();
    while (1){
        GPIOC -> ODR ^= GPIO_ODR_ODR13;
        delay(100000);
    }

    return 0;
}