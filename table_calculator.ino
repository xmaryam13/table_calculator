//  including ezbutton module (easy button module)
#include<ezButton.h>

//  connect both buttons to pin 4 and 22
const int button1 = 4;
const int button2 = 22;

//  defining a variable to track count of button press
int count = 0;

//  creating button objects
ezButton push_button1(button1);
ezButton push_button2(button2);

void setup()
{
  //  change the baud rate to 9600 if required
  Serial.begin(115200);
  
  //  set debounce time for both the button objects
  push_button1.setDebounceTime(50);

  push_button2.setDebounceTime(50);

}

void loop()
{
  //  loop both the push_buttons : continuous polling
  push_button1.loop();
  push_button2.loop();

  //  check if push_button1 is pressed : store the button push count into count variable
  if (push_button1.isPressed()){
    count ++; 
    Serial.println(count); 
  }

  //  else if push_button2 is pressed : print the table of the number stored in variable count
  else if (push_button2.isPressed())
  {
    Serial.print("Table of");
    Serial.println(count);
    //  draft a loop to print the table
    for (int i = 1; i<=10; i ++) {
      Serial.print(count);
      Serial.print("*");
      Serial.print(i);
      Serial.print("\t");
      Serial.print("=");
      Serial.print("\t");
      Serial.print(i*count);
      }

    //  reset the number to 0, once table is printed
  }
  count = 0;
}
