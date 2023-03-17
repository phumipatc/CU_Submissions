/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
struct my_message{
	char data[32];
};
osMessageQueueAttr_t queue_attr = {
		.name = "my_queue"
};
osMessageQueueId_t queue_id;
osThreadId_t thread_led1,thread_led2,thread_led3,thread_led4,thread_uart0,thread_uart1,thread_queue;
osMutexAttr_t mutex_attr = {
		.name = "my_mutex"
};
osMutexId_t mutex_id;
void LED1_Thread(void *argument){
//	Lab 6-1
	while(1){
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		osDelay(50);
	}
}
void LED2_Thread(void *argument){
//	Lab 6-1
	while(1){
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
		osDelay(18);
	}
}
void LED3_Thread(void *argument){
//	Lab 6-1
	while(1){
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
		osDelay(128);
	}
}
void LED4_Thread(void *argument){
//	Lab 6-1
	while(1){
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
		osDelay(64);
	}
}
void UART0_Thread(void *argument){
	int threadID = 0; // threadID is 0 for one thread and 1 for another
	int idx = 0;
	char buffer[32];
	while(1) {
//		Lab 6-3
		osMutexAcquire(mutex_id, osWaitForever);
		sprintf(buffer, "TID: %d %d\r\n", threadID, idx);
		idx ++;
		HAL_UART_Transmit(&huart2, buffer, strlen(buffer), 1000);
		osMutexRelease(mutex_id);
//		Lab 6-4
//		sprintf(buffer, "TID: %d %d\r\n", threadID, idx);
//		idx ++;
//		osMessageQueuePut(queue_id, buffer, 0, 0);
	}
}
void UART1_Thread(void *argument){
	int threadID = 1; // threadID is 0 for one thread and 1 for another
	int idx = 0;
	char buffer[32];
	while(1) {
//		Lab 6-3
		osMutexAcquire(mutex_id, osWaitForever);
		sprintf(buffer, "TID: %d %d\r\n", threadID, idx);
		idx ++;
		HAL_UART_Transmit(&huart2, buffer, strlen(buffer), 1000);
		osMutexRelease(mutex_id);
//		Lab 6-4
//		sprintf(buffer, "TID: %d %d\r\n", threadID, idx);
//		idx ++;
//		struct my_message msg;
//		strcpy(msg.data,buffer);
//		osMessageQueuePut(queue_id, buffer, 0, 0);
	}
}
void Queue_Thread(void *argument){
//	Lab 6-4
//	char msg[32];
//	if(osMessageQueueGet(queue_id, msg, NULL, osWaitForever) == osOK){
//		HAL_UART_Transmit(&huart2, (uint8_t *)(msg), sizeof(msg), HAL_MAX_DELAY);
//	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
//  Lab 6-3
  mutex_id = osMutexNew(&mutex_attr);
//  Lab 6-4
  queue_id = osMessageQueueNew(16, sizeof(struct my_message), &queue_attr);
//  Lab 6-1 + 6-2
//  thread_led1 = osThreadNew(LED1_Thread, NULL, NULL);
//  thread_led2 = osThreadNew(LED2_Thread, NULL, NULL);
//  thread_led3 = osThreadNew(LED3_Thread, NULL, NULL);
//  thread_led4 = osThreadNew(LED4_Thread, NULL, NULL);
//  thread_uart0 = osThreadNew(UART0_Thread, NULL, NULL);
//  thread_uart1 = osThreadNew(UART1_Thread, NULL, NULL);
//  thread_queue = osThreadNew(Queue_Thread, NULL, NULL);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();
  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
uint32_t  exec;
void Timer_Callback_1(void const *arg)  {
 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
void Timer_Callback_2(void const *arg)  {
 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
}
void Timer_Callback_3(void const *arg)  {
 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
}
void Timer_Callback_4(void const *arg)  {
 HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
	osTimerDef(Timer_1,Timer_Callback_1);
	osTimerId TimerTaskHandle_1 = osTimerCreate(osTimer(Timer_1), osTimerPeriodic, &exec);
	osTimerStart(TimerTaskHandle_1, 50);
	osTimerDef(Timer_2,Timer_Callback_2);
	osTimerId TimerTaskHandle_2 = osTimerCreate(osTimer(Timer_2), osTimerPeriodic, &exec);
	osTimerStart(TimerTaskHandle_2, 18);
	osTimerDef(Timer_3,Timer_Callback_3);
	osTimerId TimerTaskHandle_3 = osTimerCreate(osTimer(Timer_3), osTimerPeriodic, &exec);
	osTimerStart(TimerTaskHandle_3, 128);
	osTimerDef(Timer_4,Timer_Callback_4);
	osTimerId TimerTaskHandle_4 = osTimerCreate(osTimer(Timer_4), osTimerPeriodic, &exec);
	osTimerStart(TimerTaskHandle_4, 64);
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
