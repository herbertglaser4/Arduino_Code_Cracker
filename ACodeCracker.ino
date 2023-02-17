// include the library code:
#include <LiquidCrystal.h>
//#include <iostream>
//#include <math.h>
using namespace std;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int binary1 = 1;
int binary2 = 2;
int binary3 = 4;
int binary4 = 8;
int binary5 = 16;
int binary6 = 32;
int binary7 = 64;
int binary8 = 128; //all number of binary 
int totalOne; //total of binary
int counter = 0; //counter of which screen is on
int bposition = 8; //position of the cursor
int onOff = 0; //determines whether a number is 1 or 0
long randNumber; //random number 1
long randNumber2; //random number 2
long randNumber3; //random number 3
long randNumber4;
long randNumber5;
int backLight = 6; //sets the pin for the back light
int backLightValue = 30; //sets the back light value of the lcd
int switchState = 0; //button 1
int switchState2 = 0; //button 2
int ledState = 0; //led 1 sets high or low
int ledState2 = 0; //led 2
int ledState3 = 0; //led 3
int dialNumb; //number on the dial
int dialNumb2; //number on the dial not divided by 4
int part = 1; //sets the part of the question for puzzle 3
const int dial = A0; //sets the dial pin value
long solutionNumber; // the first solution for puzzle 3
long solutionNumber2; // the second solution for puzzle 3
long puzzle3Numb1; //all puzzle numbers are what displays on puzzle 3
long puzzle3Numb2;
long puzzle3Numb3;
long puzzle3Numb4;
int answer1; // sets answer for what you put in
int answer2; //sets second answer you put in
boolean complete = false; //checks if all puzzles are complete

void setup() {
  Serial.begin(9600);
  pinMode(backLight, HIGH); //sets the contrast
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Solve the puzzles");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Push 1&2 to go");
  pinMode(7, OUTPUT); //sets the lcd pins to outputs
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
 switchState = digitalRead(13); //sets each button to read for a response
 switchState2 = digitalRead(8);
 ledState = digitalRead(7); //sets each lcd to read for high or low responses
 ledState2 = digitalRead(9);
 ledState3 = digitalRead(10);
 
 dialNumb = analogRead(dial)/4; //sets normal dial number
 dialNumb2 = analogRead(dial); //sets dial number for larger numbers
 

 if(ledState == HIGH && ledState2 == HIGH && ledState3 == HIGH){
    complete = true;
    counter = 5;
    counterChecker();
    //checks if game is complete
 }

 if (counter == 0){
  randNumber = random(0,250); //sets random number 1
 
  }
if (counter == 1){
  randNumber2 = random(0,250); //sets random number 2
}
if (counter == 3){
  randNumber3 = random(1,2); //Which puzzle it will be
  randNumber4 = random(2,3); //constant multiplier either 2 or 3
  randNumber5 = random(1,9); //number to be multiplied
  if(randNumber3 == 1){
    puzzle3Numb1 = randNumber4 * randNumber5;
    puzzle3Numb2 = randNumber4 * puzzle3Numb1;
    puzzle3Numb3 = randNumber4 * puzzle3Numb2;
    solutionNumber = randNumber4 * puzzle3Numb3;
    solutionNumber2 = randNumber4 * solutionNumber;
    //sets puzzle 3 to be multiplied pattern
  }
  else if(randNumber3 == 2){
    puzzle3Numb1 = randNumber4 + randNumber5;
    puzzle3Numb2 = randNumber4 + puzzle3Numb1;
    puzzle3Numb3 = randNumber4 + puzzle3Numb2;
    solutionNumber = randNumber4 + puzzle3Numb3;
    solutionNumber2 = randNumber4 + solutionNumber;
    //sets puzzle 3 to be addition pattern
  }
  answerCheck2(); //Puzzle 2 Answer
}

if (counter == 4){
    answerCheck3(); //puzzle 3 answer
    lcd.setCursor(0, 1);
    lcd.print("                      "); //erases screen to set new dial number
    lcd.setCursor(0, 1);
    if (part == 1){
      lcd.print(dialNumb);
      //
    }
    else{
      lcd.print(dialNumb2);
    }
    //determines which number for the dial to use
}

 // if both buttons are pushed
 if (switchState == HIGH && switchState2 == HIGH){
  Serial.print("HELLO");
  Serial.println(counter);
  counterChecker(); //when both buttons are pushed check which screen setup to display
  delay(1500);
  counter=counter+1; //advance to the next screen next time the button is pushed
  
  if (counter == 2){
     answerCheck();
  }
 }
 
 //if the right button is pushed
 if (switchState == HIGH && counter>0 && counter<2){
  lcd.setCursor(bposition, 1);
  Serial.println("bposition = ");
  Serial.println(bposition);
  if (onOff == 0){
    if (bposition == 8){
      lcd.print("");
    }
    else if (counter > 2){
       lcd.print("");
    }
    else { 
       lcd.print("1"); 
       //changes the number to one is the onOff switch is 0
    }
    if (bposition == 7 && onOff == 0){
      if (counter == 1){
         totalOne = totalOne + binary1;
         Serial.println(" totalOne equals ");
         Serial.println(totalOne);
      }
      onOff = onOff + 1;
    }
    else if (bposition == 6 && onOff == 0){
      if (counter == 1){
        totalOne = totalOne + binary2;
        Serial.println(" totalOne equals ");
        Serial.println(totalOne);
      }
      onOff = onOff + 1;
    }
    else if (bposition == 5 && onOff == 0){
     if (counter == 1){
      totalOne = totalOne + binary3;
      Serial.println(" totalOne equals ");
      Serial.println(totalOne);
     }
      onOff = onOff + 1;
    }
    else if (bposition == 4 && onOff == 0){
      if (counter == 1){
        totalOne = totalOne + binary4;
        Serial.println(" totalOne equals ");
        Serial.println(totalOne);
      }
      onOff = onOff + 1;
    }
    else if (bposition == 3 && onOff == 0){
      if (counter == 1){
        totalOne = totalOne + binary5;
        Serial.println(" totalOne equals ");
        Serial.println(totalOne);
      }
      
      onOff = onOff + 1;
    }
    else if (bposition == 2 && onOff == 0){
      if (counter == 1){
      totalOne = totalOne + binary6;
      Serial.println(" totalOne equals ");
      Serial.println(totalOne);
      }
      
      onOff = onOff + 1;
   
    }
    else if (bposition == 1 && onOff == 0){
      if (counter == 1){
      totalOne = totalOne + binary7;
      Serial.println(" totalOne equals ");
      Serial.println(totalOne);
      }
     
      onOff = onOff + 1;
     
    }
    else if (bposition == 0 && onOff == 0){
      if (counter == 1){
      totalOne = totalOne + binary8;
      Serial.println(" totalOne equals ");
      Serial.println(totalOne);
      }
      onOff = onOff + 1;
    }
   }
 //reverses right buttons action
  else if(onOff == 1) {
    lcd.print("0");
     if (bposition == 7 && onOff == 1){
      if (counter == 1){
      totalOne = totalOne - binary1;
      Serial.println(" totalOne equals ");
      Serial.println(totalOne);
      }
     
      onOff = onOff - 1;
     
      
    }
   else if (bposition == 6 && onOff == 1){
    if (counter == 1){
      totalOne = totalOne - 2;
      Serial.println(" totalOne equals ");
      Serial.print(totalOne);
      }
      
      onOff = onOff - 1;
      
    }
   else if (bposition == 5 && onOff == 1){
     if (counter == 1){
         totalOne = totalOne - binary3;
         Serial.println(" totalOne equals ");
      Serial.print(totalOne);
      }
     
      onOff = onOff - 1;
     
    }
   else if (bposition == 4 && onOff == 1){
      if (counter == 1){
      totalOne = totalOne - binary4;
      Serial.println(" totalOne equals ");
      Serial.print(totalOne);
      }
     
      onOff = onOff - 1;
    }
    else if (bposition == 3 && onOff == 1){
      if (counter == 1){
      totalOne = totalOne - binary5;
      }
      
      onOff = onOff - 1;
    }
   else if (bposition == 2 && onOff == 1){
      if (counter == 1){
      totalOne = totalOne - binary6;
      }
      
      onOff = onOff - 1;
    }
   else if (bposition == 1 && onOff == 1){
      if (counter == 1){
      totalOne = totalOne - binary7;
      }
     
      onOff = onOff - 1;
    }
   else if (bposition == 0 && onOff == 1){
      if (counter == 1){
      totalOne = totalOne - binary8;
      }
      
      onOff = onOff - 1;
    }
    else{
      Serial.println("no more");
    }
  }
  
  
  delay(500);
  
 }
 //sets button for second part
 else if(switchState == HIGH && counter == 4){
  if (part == 1){
  answer1 = dialNumb;
  part++;
  }
  else{
    answer2 = dialNumb2;
  }
  counterChecker();
 }
//left buttons actions
 if (switchState2 == HIGH && counter>0){
  bposition = bposition - 1;
  onOff = 0;
  delay(500);
  if (bposition < 0){
    bposition = 8;
    lcd.print("");
  }
  
 }
 

      
}
void counterChecker(){
  //sets all of the displays
if (counter == 0){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Convert the #");
  lcd.setCursor(0, 1);
  lcd.print("to binary");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(randNumber);
  lcd.setCursor(0, 1);
  lcd.print("00000000");
}
  else if (counter == 1){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GOOD JOB");
  lcd.setCursor(0, 7);
  lcd.print(":D");
  delay(1500);
  bposition = 8;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press both");
  lcd.setCursor(0, 7);
  lcd.print("buttons");
 }
 else if (counter == 2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Puzzle 2");
  lcd.setCursor(0, 1);
  lcd.print("Fix the Dial");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set to ");
  lcd.print(randNumber2);
  lcd.setCursor(1, 1);
  lcd.print("  degrees");
 }
  else if (counter == 3){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Puzzle 3 Finish");
    lcd.setCursor(0, 1);
    lcd.print("the pattern");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(randNumber5);
    lcd.print(",");
    lcd.print(puzzle3Numb1);
    lcd.print(",");
    lcd.print(puzzle3Numb2);
    lcd.print(",");
    lcd.print(puzzle3Numb3);
    lcd.print(",");
    lcd.print(answer1);
    lcd.print(",");
    lcd.print("x");
  }
  else if (counter == 4){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    
    lcd.print(randNumber5);
    lcd.print(",");
    lcd.print(puzzle3Numb1);
    lcd.print(",");
    lcd.print(puzzle3Numb2);
    lcd.print(",");
    lcd.print(puzzle3Numb3);
    lcd.print(",");
    lcd.print(answer1);
    lcd.print(",");
    lcd.print(answer2);
  }
  else if (counter == 5 && complete == true){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CONGRATULATIONS!");
    lcd.setCursor(0,1);
    lcd.print("YOU DID IT!!!");
  }
  else if (counter == 5 && complete == false){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Failure");
    lcd.setCursor(0,1);
    lcd.print("Try Again");
  }
}


void answerCheck(){
  //checks if answer 1 is correct
  if (totalOne == randNumber){
  Serial.println("YEAHHHHHHHHH BOIIIIIIII");
  digitalWrite(7, HIGH);
  }
  else {
    Serial.println("booooooooooooooooooooooooooo");
  }
}
void answerCheck2(){
  //checks if answer 2 is correct
int randNumberGreater = randNumber2 + 2;
int randNumberLess = randNumber2 - 2;
 if (dialNumb > randNumberLess && dialNumb < randNumberGreater){
  Serial.println("YEAHHHHHHHHH BOIIIIIIII");
  digitalWrite(9, HIGH);
  counterChecker();
  counter++;
  
 }
 else {
    Serial.println("booooooooooooooooooooooooooo");
  }
}

void answerCheck3(){
  //checks if answer 3 is correct
  if (solutionNumber == answer1 && solutionNumber2 == answer2){
  Serial.println("YEAHHHHHHHHH BOIIIIIIII");
  digitalWrite(10, HIGH);
  }
  else {
    Serial.println("booooooooooooooooooooooooooo");
  }
}
