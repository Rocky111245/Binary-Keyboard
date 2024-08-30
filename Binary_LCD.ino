#include <LiquidCrystal.h>
// Assuming RS=12, E=11, D4=5, D5=4, D6=3, D7=2 as per earlier connection guidelines.
LiquidCrystal lcd(12, 11, 5, 4, 6, 7);





int ContinousSignal = 2; // LED Signal Pin
int Buzzer=3;
int SignalChecker = LOW; // Signal Checker
int count = 0; // Count
int result;
int BinaryChecker[26][8] = {// Binary Array
{0, 1, 0, 0, 0, 0, 0, 1},
{0, 1, 0, 0, 0, 0, 1, 0},
{0, 1, 0, 0, 0, 0, 1, 1},
{0, 1, 0, 0, 0, 1, 0, 0},
{0, 1, 0, 0, 0, 1, 0, 1},
{0, 1, 0, 0, 0, 1, 1, 0},
{0, 1, 0, 0, 0, 1, 1, 1},
{0, 1, 0, 0, 1, 0, 0, 0},
{0, 1, 0, 0, 1, 0, 0, 1},
{0, 1, 0, 0, 1, 0, 1, 0},
{0, 1, 0, 0, 1, 0, 1, 1},
{0, 1, 0, 0, 1, 1, 0, 0},
{0, 1, 0, 0, 1, 1, 0, 1},
{0, 1, 0, 0, 1, 1, 1, 0},
{0, 1, 0, 0, 1, 1, 1, 1},
{0, 1, 0, 1, 0, 0, 0, 0},
{0, 1, 0, 1, 0, 0, 0, 1},
{0, 1, 0, 1, 0, 0, 1, 0},
{0, 1, 0, 1, 0, 0, 1, 1},
{0, 1, 0, 1, 0, 1, 0, 0},
{0, 1, 0, 1, 0, 1, 0, 1},
{0, 1, 0, 1, 0, 1, 1, 0},
{0, 1, 0, 1, 0, 1, 1, 1},
{0, 1, 0, 1, 1, 0, 0, 0},
{0, 1, 0, 1, 1, 0, 0, 1},
{0, 1, 0, 1, 1, 0, 1, 0}};


int i=0;
int InputArray[8] = {0, 0, 0, 0, 0, 0, 0, 0};
char alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
String DisplayArray[6];


int comparison(int a[][8], int b[], int row, int column) {
  for (int i = 0; i < row; i++) {
    bool match = true;
    for (int j = 0; j < column; j++) {
      if (a[i][j] != b[j]) {
        match = false;
        break;
      }
    }
    if (match) {
      return i;
    }
  }
  return -1; // If no match is found, return -1
}

void setup() {
  pinMode(ContinousSignal, INPUT);
  pinMode(Buzzer, OUTPUT); 
  Serial.begin(9600); 
  lcd.begin(20, 4);  // Initialize the LCD
  lcd.setCursor(0, 0); 
  lcd.print("Reading Signals..");
}


void loop() {
 for (int count = 0; count < 8; count++) {
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    SignalChecker = digitalRead(ContinousSignal);
    digitalWrite(Buzzer, LOW);

    InputArray[count] = SignalChecker;
    Serial.print(InputArray[count]);
    delay(2000);
  }

  result = comparison(BinaryChecker, InputArray, 26, 8);
 if (result != -1) {
    char recognizedChar = alphabets[result];
    Serial.println(recognizedChar);

    if (i < 6) { // You need to check for 6 not 2 as you have 6 spots
      DisplayArray[i] = recognizedChar;
      lcd.setCursor(i*3, 0);  // Set cursor every 3 spaces to spread out letters.
      lcd.print(DisplayArray[i]);
      i++;
       if (i == 1) {
        lcd.clear();
      }
      lcd.setCursor(i - 1, 1); // Assuming you want the alphabets to start from the second row
      lcd.print(DisplayArray[i - 1]);
    }

 if(i == 6){
  lcd.clear(); // Clear the LCD
  lcd.setCursor(0, 1);  // Move to the second line
  for(int j = 0; j < 6; j++) {
    lcd.print(DisplayArray[j]);
  }
  while(1);  // This will stop everything. It's an infinite loop.
}


  }

  delay(5000); 
    
    }


  




