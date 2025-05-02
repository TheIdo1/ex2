/******************
Name: Ido Itzhak
ID: 69420
Assignment: ex2
Submit Username: itzhaki6
*******************/

#include <stdio.h>

int main() {
    int keepTheProgramAlive = 1;
    int userMenuChoise;
    int inputNumberBase = 10;
    while (keepTheProgramAlive) {
        printf("Choose an option:\n");
        printf("\t1. Happy Face\n");
        printf("\t2. Balanced Number\n");
        printf("\t3. Generous Number\n");
        printf("\t4. Circle Of Joy\n");
        printf("\t5. Happy Numbers\n");
        printf("\t6. Festival Of Laughter\n");
        printf("\t7. Exit\n");
        scanf("%d", &userMenuChoise);
        //Validates input.
        int firstChoice=1, lastChoice = 7;
        if (!(userMenuChoise >= firstChoice && userMenuChoise <= lastChoice)) {
            printf("This option is not available, please try again.\n");
            continue;
        }
        switch (userMenuChoise) {
            // Happy Face
            case 1:
                char eyeChar, noseChar, mouthChar;
                int faceSize, validFaceSize = 0, minFaceSize = 1;
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyeChar, &noseChar, &mouthChar);
                printf("Enter face size:\n");

            //validates that face size is odd and positive.
                do {
                    scanf("%d", &faceSize);
                    if ((faceSize >= minFaceSize) && (faceSize % 2 == 1)) {
                        validFaceSize = 1;
                    } else {
                        printf("The face's size must be an odd and positive number, please try again:\n");
                    }
                } while (!validFaceSize);
                int centerSpaces = (faceSize / 2) + 1;

            //Print the Actual Face - starting with eyes
                printf("%c", eyeChar);
                for (int i = 0; i < faceSize; i++) {
                    printf(" ");
                }
                printf("%c\n", eyeChar);
            //Nose
                for (int i = 0; i < centerSpaces; i++) {
                    printf(" ");
                }
                printf("%c\n", noseChar);
            //Mouth
                printf("\\");
                for (int i = 0; i < faceSize; i++) {
                    printf("%c", mouthChar);
                }
                printf("/\n");
                break;

            // Balanced Number
            case 2:
                int userNumberInput, validNumberInput = 0, minInputNumber = 0;
                printf("Enter a number:\n");
            //validates input. (assuming we receive ints)
                do {
                    scanf("%d", &userNumberInput);
                    if (userNumberInput > minInputNumber) {
                        validNumberInput = 1;
                    } else {
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (!validNumberInput);

            //count digits
                int digitsCounter = 0, tempNum = userNumberInput;
                while (tempNum > 0) {
                    tempNum = tempNum / inputNumberBase;
                    digitsCounter++;
                }
            /*Split to cases: Odd number of digits and Even number of digits, sums each section of the number
             accordingly and checks if equal */
                int leftSum = 0, rightSum = 0, currentDigit;
                int digitsAreOdd = (digitsCounter % 2);
                tempNum = userNumberInput;
                if (digitsAreOdd) {
                    for (int i = 1; i <= digitsCounter; i++) {
                        currentDigit = tempNum % inputNumberBase;
                        tempNum = tempNum / inputNumberBase;
                        //Check if digit is before or after the center, and adds to correct sum
                        if (i < (digitsCounter / 2) + 1)
                            rightSum += currentDigit;
                        if (i > (digitsCounter / 2) + 1)
                            leftSum += currentDigit;
                    }
                } else {
                    for (int i = 1; i <= digitsCounter; i++) {
                        currentDigit = tempNum % inputNumberBase;
                        tempNum = tempNum / inputNumberBase;
                        //Check if digit is before or after the center, and adds to correct sum
                        if (i <= (digitsCounter / 2))
                            rightSum += currentDigit;
                        if (i > (digitsCounter / 2))
                            leftSum += currentDigit;
                    }
                }
                if (leftSum == rightSum)
                    printf("This number is balanced and brings harmony!\n");
                else
                    printf("This number isn't balanced and destroys harmony.\n");
                break;

            // Generous Number / Abundant Number.
            case 3:
                int validNumberInput3 = 0, userNumberInput3, minInputNumber3 = 0;
                printf("Enter a number:\n");
            //validates input. (assuming we receive ints)
                do {
                    scanf("%d", &userNumberInput3);
                    if (userNumberInput3 > minInputNumber3) {
                        validNumberInput3 = 1;
                    } else {
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (!validNumberInput3);
                int divisorsSum = 0;
            //running until i=input/2 because this is the highest divisor a number can have except of itself.
                for (int i = 1; i <= (userNumberInput3 / 2); i++) {
                    if (userNumberInput3 % i == 0) {
                        divisorsSum += i;
                    }
                }
                if (divisorsSum > userNumberInput3)
                    printf("This number is generous!\n");
                else
                    printf("This number does not share.\n");
                break;

            // Circle of joy (Prime and reversed prime).
            case 4:
                int validNumberInput4 = 0, userNumberInput4, minInputNumber4=0;
                printf("Enter a number:\n");
            //validates input. (assuming we receive ints)
                do {
                    scanf("%d", &userNumberInput4);
                    if (userNumberInput4 > minInputNumber4) {
                        validNumberInput4 = 1;
                    } else {
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (!validNumberInput4);

            //is Prime?
                int numberIsPrime = 1, skipTheLoop = 0;
                if (userNumberInput4 == 1) {
                    numberIsPrime = 0;
                    skipTheLoop = 1;
                }
                if (userNumberInput4 == 2) {
                    numberIsPrime = 1;
                    skipTheLoop = 1;
                }
                for (int i = 2; i <= userNumberInput4 / 2; i++) {
                    if (skipTheLoop)
                        break;
                    if (userNumberInput4 % i == 0) {
                        numberIsPrime = 0;
                        break;
                    }
                }

                int reversedNum = 0;
                int tempNum4 = userNumberInput4;
                while (tempNum4 > 0) {
                    reversedNum += tempNum4 % inputNumberBase;
                    reversedNum *= inputNumberBase;
                    tempNum4 = tempNum4 / inputNumberBase;
                }
            //while loop multiplies by inputNumberBase one extra time, fixing it here.
                reversedNum /= inputNumberBase;

            //is Prime?, this time we know we dont get 1 or 2 because they would've hit "break;" by now.
                int reversedNumberIsPrime = 1;
                for (int i = 2; i <= reversedNum / 2; i++) {
                    if (skipTheLoop)
                        break;
                    if (reversedNum % i == 0) {
                        reversedNumberIsPrime = 0;
                        break;
                    }
                }
                if (reversedNumberIsPrime && numberIsPrime)
                    printf("This number completes the circle of joy!\n");
                else
                    printf("The circle remains incomplete.\n");
                break;

            //Happy Numbers.
            case 5:
                int validNumberInput5 = 0, userNumberInput5, minInputNumber5 = 0;
                printf("Enter a number:\n");
            //validates input. (assuming we receive ints)
                do {
                    scanf("%d", &userNumberInput5);
                    if (userNumberInput5 > minInputNumber5) {
                        validNumberInput5 = 1;
                    } else {
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (!validNumberInput5);
            //there will always be at least 1 happy number (1).
                printf("Between 1 and %d only these numbers bring happiness: ", userNumberInput5);
                int currentNumber5 = 1, currentDigit5;
                int tempNum5 = 1;
                while (currentNumber5 <= userNumberInput5) {
                    int digitsPowerSum = 0;
                    while (tempNum5 > 0) {
                        currentDigit5 = tempNum5 % inputNumberBase;
                        tempNum5 /= inputNumberBase;
                        digitsPowerSum += currentDigit5 * currentDigit5;
                    }
                    //Happy Number
                    tempNum5 = digitsPowerSum;
                    if (tempNum5 == 1) {
                        printf("%d ", currentNumber5);
                        currentNumber5++;
                        tempNum5 = currentNumber5;
                        continue;
                    }
                    //if entering infinite loop, will always hit 4, and if hitting 4, will always enter infinite loop.
                    if (tempNum5 == 4) {
                        currentNumber5++;
                        tempNum5 = currentNumber5;
                    }
                }
                printf("\n");
                break;

            //Festival of Laughter
            case 6:
                int smile = 0, cheer = 0, minInputNumber6 = 0;
                printf("Enter a smile and cheer number:\n");
                do {
                    scanf("%*[^\n]");
                    scanf("%*c");
                    scanf("smile: %d, cheer: %d", &smile, &cheer);
                    if (smile == 0 || cheer == 0 || smile == cheer) {
                        printf("Only 2 different positive numbers in the given format are allowed for the festival, "
                            "please try again:\n");
                    }
                } while (((smile <= minInputNumber6) || (cheer <= minInputNumber6)) || (cheer == smile));

                printf("Enter maximum number for the festival:\n");
                scanf("%*[^\n]");
                scanf("%*c");
                int validNumberInput6 = 0, userNumberInput6;
            //validates input. (assuming we receive ints)
                do {
                    scanf("%d", &userNumberInput6);
                    if (userNumberInput6 > minInputNumber6) {
                        validNumberInput6 = 1;
                    } else {
                        printf("Only positive maximum number is allowed, please try again:\n");
                    }
                } while (!validNumberInput6);

                for (int currentNumber = 1; currentNumber <= userNumberInput6; currentNumber++) {
                    if (currentNumber % smile == 0 && currentNumber % cheer == 0) {
                        printf("Festival!\n");
                        continue;
                    }
                    if (currentNumber % smile == 0) {
                        printf("Smile!\n");
                        continue;
                    }
                    if (currentNumber % cheer == 0) {
                        printf("Cheer!\n");
                        continue;
                    }
                    printf("%d\n", currentNumber);
                }

                break;
            case 7:
                keepTheProgramAlive = 0;
                printf("Thank you for your journey through Numeria!\n");
                break;
        }
    }
    return 0;
}
