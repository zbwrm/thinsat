#include <Arduino_FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <event_groups.h>

#define LED1 9
#define LED2 10
#define BTTN 16
#define portCHAR char

EventBits_t button_pressed = 0;

// the setup function runs once when you press reset or power the board
void setup() {

  // Now set up two tasks to run independently.
  xTaskCreate(TaskBlinkLED, (const portCHAR *)"BlinkLED", 128, NULL, 2, NULL); // toggles LED1 every .5s
  xTaskCreate(TaskReadBttn, (const portCHAR *)"ReadBttn", 128, NULL, 1, NULL); // checks if button is pressed every 30ms
  xTaskCreate(TaskDispBttn, (const portCHAR *)"DispBttn", 128, NULL, 3, NULL); // if button is pressed, enables LED2

 
  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskBlinkLED(void *pvParameters)
{
  (void) pvParameters;

  pinMode(LED1, OUTPUT);
  bool led1_status = false;

  for (;;)
  {
    if (button_pressed == 1){
      led1_status = !led1_status;
    }

    digitalWrite(LED1, led1_status);   // turn the LED on
    vTaskDelay( 100 / portTICK_PERIOD_MS ); // wait for .5s
    
  }
}

void TaskReadBttn(void *pvParameters)
{
  (void) pvParameters;

  pinMode(BTTN, INPUT);

  for (;;) // A Task shall never return or exit.
  {
    button_pressed = digitalRead(BTTN);
    vTaskDelay(5); // delay 5ms
  }
}

void TaskDispBttn(void *pvParameters)
{
  (void) pvParameters;

  pinMode(LED2, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(LED2, button_pressed);
    vTaskDelay(5);
  }
}
