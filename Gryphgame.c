
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {// indicates that we are running our main program 

  int birthYear, digit, luckyNum;//declared the following variables as integers

  do {
  printf("Enter your birth year (yyyy):");
  scanf("%d", &birthYear);

  } while ( !(birthYear>=1000 && birthYear<=9999));//set the condition for appropriate / accepted values for the user's birth year

  //loop to calculate sum of digits of birth year
  while (birthYear !=0){
    digit = birthYear % 10;//get last digit of birth year
    luckyNum = luckyNum + digit;//add digit to lucky number
    birthYear = birthYear / 10;//use divison to remove last digit
  }

  printf("*************************\n");
  printf("Welcome to Mixed Treasures\n");
  printf("Your Lucky Number is %d\n", luckyNum);
  printf("*************************\n");

  int currentQuestion = 1; //initializing the current question as 1 and as a integer  
  int randMessage; // declaring the random number that will be used to generate a random message as an integer
  int lifeLine = 0; //initializing the use of the life line as 0 (meaning user has not used it yet)
  char userAnswer; // declaring the user's answers for the questions as a character 
 
  while (currentQuestion==1){ //starting the main while loop and setting the testing condition if current question is equal to 1
    printf("Question 1: Here is the $100 question\n");
    printf("What is the University of Guelph's Mascot?\n");
    printf("A. Dragon\nB. Centaur\nC. Aggie\nD. Gryphon\n");

    char lifeChoice=' ';// initlizing the user's choice of if they want to use the life line or not 
    
    if(lifeLine ==0){ //setting the if condition as if the life line has not been used
      printf("Would you like to use a lifeline (50-50)?\n");
      while(lifeChoice!='y' && lifeChoice!='Y' && lifeChoice!='n' && lifeChoice!='N'){ // set the condition for accepted characters for the user's choice of whether they want to use the life line or not  
        printf("Enter Y or y, N or n:");
        scanf(" %c", &lifeChoice);
      }// end the while loop for accepted characters

      if (lifeChoice =='Y'|| lifeChoice =='y'){ // setting the if condition for if the user says yes to using the life line
        lifeLine = 1; // setting the value of life line to 1 because it has now been used 
        printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
        printf("C. Aggie\nD. Gryphon\n");
        printf("Reminder - You get only 1 lifeline - and you are using it now\n");
        while (userAnswer!='C' && userAnswer!='D'){  // set the condition for accepted characters for the user's answer 
          printf("Enter your FINAL ANSWER ('C', or 'D') here:");
          scanf(" %c", &userAnswer); 
        } // end the while loop for accepted characters as answers

      } else if (lifeChoice =='N'||lifeChoice =='n'){ // setting the else if condition for when the user says no to using the life line
        lifeLine = 0; // setting the life line back to 0 because it has not been used
        while(userAnswer!='A'&& userAnswer!='B' && userAnswer!='C' && userAnswer!='D'){ //set the condition for accepted characters for the user's answer
          printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D') here:");
          scanf(" %c", &userAnswer);
        }// end the while loop for accepted characters answers 
      }// ending the block for else if statement
    }// ending the block for if the life line ==0 statement
    
    /* The next block of code is an if statement with a switch inside for when the user gets the answer correct.
       If the user's answer meets the if condition, the switch expression will be evaluated to help randomly generate 1 of the 5 possible cases for a displaying a message to the user
       that they won the money. */
    if(userAnswer =='D'){
      srand (time(NULL));
      randMessage = (rand()%5)+1;
      switch (randMessage){ // switch expression
      case 1:
        printf("Bravo - You just won $100\n");
        break;
      case 2:
        printf("Congrats - You just won $100\n");
        break;
      case 3:
        printf("Well done - You just won $100\n");
        break;
      case 4:
        printf("Very nice - You just won $100\n");
        break;
      case 5:
        printf("Proud of you - You just won $100\n");
      } //ending switch 
      printf("Let us play the next question now\n");

    } else { // starting the else block for when the user gets the answer wrong
      printf("Oops - that was incorrect. You won zero dollars, but it was fun playing with you.\n");
      currentQuestion = 0;
      break; // ends the main while loop and exits so the game can end
    } // ends block for else statement

    ++currentQuestion; //updates the while condition by increasing the current question by 1 
    printf("Question 2: Here is the $500 question\n");
    printf("What is the name of the cannon that is painted by students?\n");
    printf("A. Old Jeremiah\nB. Painty McPaintFace\nC. George III\nD. Duke of Wellington\n");

    lifeChoice = ' ';// reinitializing the user's choice of if they want to use the life line or not so the answer from the previous question isn't inputted 
    userAnswer = ' ';// reinitializing the user's answer so their answer from the previous question isn't inputted 

    /* This next if statement with a while loop inside is made to check if the user has already used the lifeline in any of the previous question(s).
       If it has been used (so the if condition is met), it will ask the user to answer the question right away using one of the appropriate characters. 
       If the user does not enter a valid character for the answer, it will keep asking them until a valid character is entered.*/

    if (lifeLine==1){
      while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){
        printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D' here:");
        scanf(" %c", &userAnswer);
      }
    }

    if(lifeLine ==0){// setting the if condition as if the lifeline has not been used
      printf("Would you like to use a lifeline (50-50)?\n");
      while(lifeChoice!='y' && lifeChoice!='Y' && lifeChoice!='n' && lifeChoice!='N'){//set the conditions for accepted characters for the user's choice of whether they want to use the lifeline or not 
        printf("Enter Y or y, N or n:");
        scanf(" %c", &lifeChoice);
      } // end the while loop for accepted characters as answers

      if (lifeChoice =='Y'|| lifeChoice =='y'){//setting the if condition for yes to using the lifeline
        printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
        lifeLine = 1;// set the value of lifeline to 1 because it has now been used
        printf("A. Old Jeremiah\nB. Painty McPaintFace\n");
        printf("Reminder - You get only 1 lifeline - and you are using it now\n");
        while (userAnswer!='A'&& userAnswer!='B'){// set condition for accepted characters for users answers 
          printf("Enter your FINAL ANSWER ('A', or 'B') here:");
          scanf(" %c", &userAnswer); 
        }//end while loop for accepted characters as answers

      } else if (lifeChoice =='N'||lifeChoice =='n'){//set else if condition for when user says no to using the life line
        lifeLine = 0;
        while (userAnswer!='A'&& userAnswer!='B' && userAnswer!='C' && userAnswer!='D'){// set condition for accepted characters for user's answer
          printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D') here:");
          scanf(" %c", &userAnswer);
        }// end of while loop for accepted characters
      }// ending block for  else if statement
    }// ending the block for if the life line == 0 statement

    /* The next block of code is an if statement with a switch inside for when the user gets the answer correct.
       If the user's answer meets the if conditon, the switch expression will be evaluated to help randomly generate 1 of the 5 possible cases for displaying a message to the user
       that they won the money. */
    if(userAnswer == 'A'){
      srand (time(NULL));
      randMessage = (rand()%5)+1;
      switch (randMessage){
      case 1:
        printf("Bravo - You just won $500\n");
        break;
      case 2:
        printf("Congrats - You just won $500\n");
        break;
      case 3:
        printf("Well done - You just won $500\n");
        break;
      case 4:
        printf("Very nice - You just won $500\n");
        break;
      case 5:
        printf("Proud of you - You just won $500\n");
      }
      printf("Let us play the next question now\n");
    } else {// starting else statement for when user gets the answer wrong
      printf("Oops - that was incorrect. You still won $100. Well done.\nIt was fun playing with you\n");
      currentQuestion = 0;
      break;// ends main while loop and exits 
    }// end block for else statement
  
    ++currentQuestion;//update the while condition by increasing current question by 1
    printf("Question 3: Here is the $1000 question\n");
    printf("Who was the School of Computer Science building at UoG named after?\n");
    printf("A. Joseph Reynolds\nB. Ryan Reynolds\nC. Joshua Reynolds\nD. Greg Klotz\n");

    lifeChoice = ' '; // reinitialize the user's choice  
    userAnswer = ' '; // reinitialize the user's answer

    /* This next if statement with a while loop inside is made to check if the user has already used the lifeline in any of the previous question(s).
       If it has been used (so the if condition is met), it will ask the user to answer the question right away using one of the appropriate characters.
       If the user does not enter a valid character for the answer, it will keep asking them until a valid character is entered*/

    if (lifeLine ==1){
      while (userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){
        printf("Enter your FINAL ANSWER ('A', 'B', 'C' or 'D') here:");
        scanf(" %c", &userAnswer);
      }
    }
    if (lifeLine==0){ // set condition as if user has not used the lifeline yet
      printf("Would you like to use a lifeline (50-50)?\n");
      while(lifeChoice!='y'&& lifeChoice!='Y'&& lifeChoice!='n'&& lifeChoice!='N'){ // set condition for accepted characters for users choice
        printf("Enter Y or y, N or n:");
        scanf(" %c", &lifeChoice);
      } // end while loop

      if (lifeChoice =='Y'|| lifeChoice =='y'){ // set the if condition for yes to using the lifeline
        printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
        lifeLine = 1;// set lifeline to 1 because it has been used
        printf("A. Joseph Reynolds\nC. Joshua Reynolds\n");
        printf("Reminder - You get only 1 lifeline - and you are using it now\n");
        while (userAnswer!='A' && userAnswer!='C'){//set conditions for accepted characters for users answers 
          printf("Enter your FINAL ANSWER ('A', or 'C') here:");
          scanf(" %c", &userAnswer); 
        } //end while loop

      } else if (lifeChoice =='N'||lifeChoice =='n'){// set if condition for when user says no to using lifeline
        lifeLine = 0;
        while (userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){ // set conditions for accepted characters for users choice
          printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D') here:");
          scanf(" %c", &userAnswer);
        }//end while loop for accepted characters as user's answer
      }// ending block for else if statement
    }//end block for if lifeline ==0 statement

    /* The next block of code is an if statement with a switch inside for when the user gets the answer correct. 
       If the user's answer meets the if condition, the switch expression will be evaluated to help randomly generate one of the 5 possible cases for displaying a message to the user
       that they won the money. */

    if(userAnswer == 'A'){
      srand (time(NULL));
      randMessage = (rand()%5)+1;
      switch (randMessage){
      case 1:
        printf("Bravo - You just won $1000\n");
        break;
      case 2:
        printf("Congrats - You just won $1000\n");
        break;
      case 3:
        printf("Well done - You just won $1000\n");
        break;
      case 4:
        printf("Very nice - You just won $1000\n");
        break;
      case 5:
        printf("Proud of you - You just won $1000\n");
      }
      printf("Let us play the next question now\n");
    } else {// starting block for else statement
      printf("Oops - that was incorrect. You still won $500. Well done.\nIt was fun playing with you\n");
      currentQuestion = 0;
      break;// ends main while loop and exits
    }// end block for else statement

    ++currentQuestion;//updates the while condition by increasing current question by 1 
    printf("Question 4: Here is the $5000 question\n");
    printf("What are the 2 majors offered in the Bachelor of Computing?\n");
    printf("A. Software Engineering and Computer Science\nB. Data Science and Computer Science\nC. Data Analytics and Data Science\nD. Computer Science and Project Management\n");

    lifeChoice = ' ';// reinitialize the user's choice of using the lifeline
    userAnswer = ' ';// reinitialize the user's answer

    /* This next if statement with a while loop inside is made to check if the user has already used the lifeline in any of the previous question(s).
       If it has been used (so the if condition is met), it will ask the user to answer the question right away using one of the appropriate characters.
       If the user does not enter a valid character for the answer, it will keep asking them until a valid character is entered.*/

    if (lifeLine ==1){
      while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){
        printf("Enter your FINAL ANSWER ('A', 'B', 'C' or 'D') here:");
        scanf(" %c", &userAnswer);
      }
    }
    if (lifeLine==0){//setting the if condition as if the lifeline has not been used
      printf("Would you like to use a lifeline (50-50)?\n");
      while(lifeChoice!='y'&& lifeChoice!='Y' && lifeChoice!='n'&& lifeChoice!='N'){//set the conditions for the user's choice of whether they want to use the lifeline or not
        printf("Enter Y or y, N or n:");
        scanf(" %c", &lifeChoice);
      }// end the while loop

      if (lifeChoice =='Y'|| lifeChoice =='y'){// set the if condition for yes to using the lifeline 
        printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
        lifeLine = 1;// set the value of lifeline to 1 because it has been used
        printf("A. Software Engineering and Computer Science\nB. Data Science and Computer Science\n");
        printf("Reminder - You get only 1 lifeline - and you are using it now\n");
        while(userAnswer!='A'&& userAnswer!='B'){// set condition for accepted characters for users answer
          printf("Enter your FINAL ANSWER ('A', or 'B') here:");
          scanf(" %c", &userAnswer); 
        }// end while loop

      } else if (lifeChoice =='N'||lifeChoice =='n'){// set else if condition says no to using lifeline
        lifeLine = 0;
        while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C' && userAnswer!='D'){// set the conditions for accepted characters for users answers
          printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D') here:");
          scanf(" %c", &userAnswer);
        }//end of while loop
      }//end block for else if statement
    }//end block for if lifeline == 0 statement

    /* The next block of code is an if statement with a switch inside for when the user gets the answer correct.
       If the user's answer meets the if condition, the switch expression will be evaluated to  help randomly generate 1 of the 5 possible cases for displaying a message to the user
       that they won the money.*/

    if(userAnswer == 'A'){
      srand (time(NULL));
      randMessage = (rand()%5)+1;
      switch (randMessage){
      case 1:
        printf("Bravo - You just won $5000\n");
        break;
      case 2:
        printf("Congrats - You just won $5000\n");
        break;
      case 3:
        printf("Well done - You just won $5000\n");
        break;
      case 4:
        printf("Very nice - You just won $5000\n");
        break;
      case 5:
        printf("Proud of you - You just won $5000\n");
      }
      printf("Let us play the next question now\n");
    } else {// start block for else statement
      printf("Oops - that was incorrect. You still won $1000. Well done.\nIt was fun playing with you\n");
      currentQuestion = 0;
      break;// ends main while loop and exits
    }// end block for else statement

    ++currentQuestion;//update the while condition by increasing the current question by 1
    printf("Question 5: Here is the $10,000 question\n");
    printf("Who do you go to for questions about your courses\n");
    printf("A. The professor\nB. Your friends\nC. The course calender\nD. Your program councellor\n");

    lifeChoice = ' '; // reinitialize the user's choice
    userAnswer = ' '; // reinitialize the user's answer

    /* This next if statement with a while loop inside is made to check if the the user has already used the lifeline in any of the previous question(s).
       If it has been used (so the if condition is met), it will ask the user to answer the question right away using one of the appropriate characters.
       If the user does not enter a valid character for the answer, it will keep asking them until a valid character is answered.*/

    if (lifeLine ==1){
      while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){
        printf("Enter your FINAL ANSWER ('A', 'B', 'C' or 'D') here:");
        scanf(" %c", &userAnswer);
      }
    }
    if (lifeLine==0){// set if condition as if the lifeline has not been used
      printf("Would you like to use a lifeline (50-50)?\n");
      while(lifeChoice!='y'&& lifeChoice!='Y'&& lifeChoice!='n'&& lifeChoice!='N'){//set conditions for accepted characters for user's choice
        printf("Enter Y or y, N or n:");
        scanf(" %c", &lifeChoice);
      }// end while loop

      if (lifeChoice =='Y'|| lifeChoice =='y'){// set if condition for yes to using the lifeline
        printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
        lifeLine = 1;// set the value of lifeline to 1 as it is now used
        printf("B. Your friends\nD. Your program councellor\n");
        printf("Reminder - You get only 1 lifeline - and you are using it now\n");
        while(userAnswer!='B'&& userAnswer!='D'){// set condition for accepted characters for users answer
          printf("Enter your FINAL ANSWER ('B', or 'D') here:");
          scanf(" %c", &userAnswer); 
        } // end while loop

      } else if (lifeChoice =='N'||lifeChoice =='n'){// set else if condition as if user said no to lifeline
        lifeLine = 0;
        while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){// set condition for accepted characters as users answer
          printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D') here:");
          scanf(" %c", &userAnswer);
        }// end while loop
      }// end block for else if statement
    }// end block for if lifeine == 0 statement

    /* The next block of code is an if statement with a switch inside for when the user gets the answer correct.
       If the user's answer meets the if condition, the switch expression will be evaluated to help randomly generate 1 of 5 possible cases for displaying a message to the user
       that they won the money. */ 

    if(userAnswer == 'D'){
      srand (time(NULL));
      randMessage = (rand()%5)+1;
      switch (randMessage){
      case 1:
        printf("Bravo - You just won $10,000\n");
        break;
      case 2:
        printf("Congrats - You just won $10,000\n");
        break;
      case 3:
        printf("Well done - You just won $10,000\n");
        break;
      case 4:
        printf("Very nice - You just won $10,000\n");
        break;
      case 5:
        printf("Proud of you - You just won $10,000\n");
      }
      printf("Let us play the next question now\n");
    } else {// start block for else statement for when user gets answer wrong
      printf("Oops - that was incorrect. You still won $5000. Well done.\nIt was fun playing with you\n");
      currentQuestion = 0;
      break;// ends main while loop and exits
    }// end block for else statement

    ++currentQuestion; // updates the while condition by increasing current question by 1
    printf("Question 6: Here is the $50,000 question\n");
    printf("What clubs do we have at Guelph?\n");
    printf("A. Both B and D\nB. Women in computing\nC. Botany Club\nD. Pre-law society\n");

    lifeChoice = ' ';// reinitializing the users choice
    userAnswer = ' ';// reinitializing the users answer

    /* This next if statement with a while loop inside is made to check if the user has already used the lifeline in any of the previous question(s).
       If it has been used (so the if condition is met), it will ask the user to answer the question right away using one of the appropriate characters.
       If the user does not enter a valid character for the answer, it will keep asking them until a valid character is entered.*/

    if (lifeLine ==1){
      while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C' && userAnswer!='D'){
      printf("Enter your FINAL ANSWER ('A', 'B', 'C' or 'D') here:");
      scanf(" %c", &userAnswer);
      }
    }
    if (lifeLine==0){// set if condition as if lifeline has not been used
      printf("Would you like to use a lifeline (50-50)?\n");
      while(lifeChoice!='y'&& lifeChoice!='Y'&& lifeChoice!='n'&& lifeChoice!='N'){// set the condition for accepted characters for the user's choice 
        printf("Enter Y or y, N or n:");
        scanf(" %c", &lifeChoice);
      }// end while loop

      if (lifeChoice =='Y'|| lifeChoice =='y'){// set the condition as if user said yes to lifeline
        printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
        lifeLine = 1;// set value of lifeline to 1 as it has been used
        printf("A. Both B and D\nD. Pre-law society\n");
        printf("Reminder - You get only 1 lifeline - and you are using it now\n");
        while(userAnswer!='A'&& userAnswer!='D'){// set condition for appropriate characters for user's answer
          printf("Enter your FINAL ANSWER ('A', or 'D') here:");
          scanf(" %c", &userAnswer); 
        } // end while loop

      } else if (lifeChoice =='N'||lifeChoice =='n'){// set else if condition for when user says no to lifeline
        lifeLine = 0;
        while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){// set condition for accepted characters 
          printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D') here:");
          scanf(" %c", &userAnswer);
        }// end of while loop
      }// end block for else if statement
    }// end block for if lifeline == 0 statement

    /* The next block of code is an if statement with a switch inside for when the user gets the answer correct.
       If the user's answer meets the if condition, the switch expression will be evaluated to help randomly generate 1 out of 5 possible cases for displaying a message to the user
       that they won the money. */

    if(userAnswer == 'A'){
      srand (time(NULL));
      randMessage = (rand()%5)+1;
      switch (randMessage){
      case 1:
        printf("Bravo - You just won $50,000\n");
        break;
      case 2:
        printf("Congrats - You just won $50,000\n");
        break;
      case 3:
        printf("Well done - You just won $50,000\n");
        break;
      case 4:
        printf("Very nice - You just won $50,000\n");
        break;
      case 5:
        printf("Proud of you - You just won $50,000\n");
      }
      printf("Let us play the next question now\n");
    } else {// start block for else statement for when user gets answer wrong
      printf("Oops - that was incorrect. You still won $10,000. Well done.\nIt was fun playing with you\n");
      currentQuestion = 0;
      break;// ends main while loop and exits
    }// end block for else statement

    ++currentQuestion;// update the while condition by increasing the current question by 1
    printf("Question 7: Here is the $100,000 question\n");
    printf("What are some student jobs on campus?\n");
    printf("A. Residence Ambassador \nB. Teaching Assistant\nC. Plumber\nD. Both A and B\n");

    lifeChoice = ' ';// reinitializing user's choice
    userAnswer = ' ';// reinitializing user's answer
    
    /* This next if statement with a while loop inside is made to check if the user has already used the lifeline in any of the previous question(s)
       If it has been used (so the if condition is met), it will ask the user to answer the question right way using one of the appropriate characters.
       If the user does not enter a valid character for the answer, it will keep asking them until a valid character is entered.*/

    if (lifeLine ==1){
      while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){
        printf("Enter your FINAL ANSWER ('A', 'B', 'C' or 'D') here:");
        scanf(" %c", &userAnswer);
      }
    }
    if (lifeLine==0){ // set condition as if the lifeline has not been used
      printf("Would you like to use a lifeline (50-50)?\n");
      while(lifeChoice!='y'&& lifeChoice!='Y'&& lifeChoice!='n'&& lifeChoice!='N'){// set the condition for accepted characters
        printf("Enter Y or y, N or n:");
        scanf(" %c", &lifeChoice);
      }// end while loop

      if (lifeChoice =='Y'|| lifeChoice =='y'){// setting if condition for yes to using lifeline
        printf("OK - here are your 2 choices after using the 50-50 lifeline\n");
        lifeLine = 1;// set the value of lifeline to 1 because it has been used
        printf("B. Teaching Assistant\nD. Both A and B\n");
        printf("Reminder - You get only 1 lifeline - and you are using it now\n");
        while(userAnswer!='B'&& userAnswer!='D'){// set condition for accepted characters for users answer
          printf("Enter your FINAL ANSWER ('B', or 'D') here:");
          scanf(" %c", &userAnswer); 
        } // end while loop

      } else if (lifeChoice =='N'||lifeChoice =='n'){// set else if condition for when user says no to using lifeline
        lifeLine = 0;
        while(userAnswer!='A'&& userAnswer!='B'&& userAnswer!='C'&& userAnswer!='D'){//set condition for accepted characters
          printf("Enter your FINAL ANSWER ('A', 'B', 'C' OR 'D') here:");
          scanf(" %c", &userAnswer);
        }// end while loop
      }// end block for else if statement
    }// end block for if lifeline == 0 statement

    /* The next block of code is an if statement with a switch inside for when the user gets the answer correct.
       If the user's answer meets the if condition, the switch expression will be evaluated to help randomly generate 1 of 5 possible cases for displaying a message to the user
       that they won the money. */

    if(userAnswer == 'D'){
      srand (time(NULL));
      randMessage = (rand()%5)+1;
      switch (randMessage){
      case 1:
        printf("Bravo - You just won $100,000\n");
        break;
      case 2:
        printf("Congrats - You just won $100,000\n");
        break;
      case 3:
        printf("Well done - You just won $100,000\n");
        break;
      case 4:
        printf("Very nice - You just won $100,000\n");
        break;
      case 5:
        printf("Proud of you - You just won $100,000\n");
      }
    } else {//starting the else block for when user gets the answer wrong
      printf("Oops - that was incorrect. You still won $50,000. Well done.\nIt was fun playing with you\n");
      currentQuestion = 0;
      break;//ends main loop and exits
    } // end block for else statement
  }// end the main while loop
  return 0;
}// 

