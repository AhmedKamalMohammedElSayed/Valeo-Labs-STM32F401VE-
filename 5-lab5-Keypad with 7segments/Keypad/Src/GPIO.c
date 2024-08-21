// Names : Ahmed Kamal - Abd El-Rahman Shawky
//BN:		4				35
//team no : 39

#include"GPIO.h"

void Gpio_ConfigPin(uint32 PortName, uint32 PinNum, uint32 PinMode, uint32 DefaultState){

	switch(PortName){
	case GPIO_A:
		CLEAR_BIT(GPIOA_MODER, PinNum*2, 0x03);
		SET_BIT(GPIOA_MODER, PinNum*2, PinMode);
		if(DefaultState == GPIO_OPEN_DRAIN || DefaultState == GPIO_PUSH_PULL){
		CLEAR_BIT(GPIOA_OTYPER, PinNum, DefaultState);
		SET_BIT(GPIOA_OTYPER, PinNum, DefaultState);
		}
		else{
		    SET_BIT(GPIOA_PUPDR, 2*PinNum, DefaultState);
		}
		break;
	case GPIO_B:
		CLEAR_BIT(GPIOB_MODER, PinNum*2, 0x03);
		SET_BIT(GPIOB_MODER, PinNum*2, PinMode);
		if(DefaultState == GPIO_OPEN_DRAIN || DefaultState == GPIO_PUSH_PULL){
		CLEAR_BIT(GPIOB_OTYPER, PinNum, DefaultState);
		SET_BIT(GPIOB_OTYPER, PinNum, DefaultState);
		}
		else{
		    SET_BIT(GPIOB_PUPDR, 2*PinNum, DefaultState);
		}
		break;
	case GPIO_C:
		CLEAR_BIT(GPIOC_MODER, PinNum*2, 0x03);
		SET_BIT(GPIOC_MODER, PinNum*2, PinMode);
		if(DefaultState == GPIO_OPEN_DRAIN || DefaultState == GPIO_PUSH_PULL){
		CLEAR_BIT(GPIOC_OTYPER, PinNum, DefaultState);
		SET_BIT(GPIOC_OTYPER, PinNum, DefaultState);
		}
		else{
		    SET_BIT(GPIOC_PUPDR, 2*PinNum, DefaultState);
		}
		break;
	case GPIO_D:
		CLEAR_BIT(GPIOD_MODER, PinNum*2, 0x03);
		SET_BIT(GPIOD_MODER, PinNum*2, PinMode);
		if(DefaultState == GPIO_OPEN_DRAIN || DefaultState == GPIO_PUSH_PULL){
		CLEAR_BIT(GPIOD_OTYPER, PinNum, DefaultState);
		SET_BIT(GPIOD_OTYPER, PinNum, DefaultState);
		}
		else{
		    SET_BIT(GPIOD_PUPDR, 2*PinNum, DefaultState);
		}
		break;
	default:
		break;
	}

}

Std_ReturnType Gpio_WritePin(uint32 PortName, uint32 PinNum, uint32 Data){

	switch(PortName){
	case GPIO_A:
		if(	READ_BIT(GPIOA_MODER,PinNum*2,0x3) == GPIO_OUTPUT){
			CLEAR_BIT(GPIOA_ODR,PinNum,0x1);
			SET_BIT(GPIOA_ODR,PinNum,Data);
			return OK;
		}
		else{
			return NOK;
		}
		break;
	case GPIO_B:
		if(	READ_BIT(GPIOB_MODER,PinNum*2,0x3) == GPIO_OUTPUT){
			CLEAR_BIT(GPIOB_ODR,PinNum,0x1);
			SET_BIT(GPIOB_ODR,PinNum,Data);
			return OK;
		}
		else{
			return NOK;
		}
		break;
	case GPIO_C:
		if(	READ_BIT(GPIOC_MODER,PinNum*2,0x3) == GPIO_OUTPUT){
			CLEAR_BIT(GPIOC_ODR,PinNum,0x1);
			SET_BIT(GPIOC_ODR,PinNum,Data);
			return OK;
		}
		else{
			return NOK;
		}
		break;
	case GPIO_D:
		if(	READ_BIT(GPIOD_MODER,PinNum*2,0x3) == GPIO_OUTPUT){
			CLEAR_BIT(GPIOD_ODR,PinNum,0x1);
			SET_BIT(GPIOD_ODR,PinNum,Data);
			return OK;
		}
		else{
			return NOK;
		}
		break;
	}
	return 0;
}


uint32 GPIO_ReadPin(uint32 PortName, uint32 PinNum){
	switch(PortName){
	case GPIO_A:
	return READ_BIT(GPIOA_IDR,PinNum,0x1);
	break;

	case GPIO_B:
	return READ_BIT(GPIOB_IDR,PinNum,0x1);
	break;

	case GPIO_C:
	return READ_BIT(GPIOC_IDR,PinNum,0x1);
	break;

	case GPIO_D:
	return READ_BIT(GPIOD_IDR,PinNum,0x1);
	break;
	}
	return 0;
}




