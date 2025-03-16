#include <iostream>
#define Max_Limit 20
using namespace std;

int sumOne(int array[], int size);
int sumTwo(int array[], int size);
int calculateSum(int sum1, int sum2);

int main()
{
    int card[Max_Limit];                           // Given 20 as the maximum array limit

    int digit, sum1, sum2, sumCheck;
    int size = 0;

    cout << endl;

    cout << "Welcome to the Credit Card checker using the Luhn Algorithm!" << endl;

    cout << "------------------------------------------------------------" <<endl;

    cout << endl;

    cout << "Enter Credit Card Number (To check enter -1) : \n";

    while(digit != -1 && size < Max_Limit)         // Loop runs until user enters -1 or maximum limit is reached
    {
        cin >> digit;                              // Taking user input from variable 'digit'

        if(digit >= 0 && digit <=9)                // Numbers entered by the user must be between 0 and 9
        {
            card[size] = digit;

            size++;
        }
    }

    sum1 = sumOne(card, size);
    sum2 = sumTwo(card, size);

    cout << endl;

    sumCheck = calculateSum(sum1, sum2);

    cout << "Check sum : " << sumCheck << endl;

    cout << endl;

    if(sumCheck == card[size -1])
    {
        cout << "Credit card status : Valid! " << endl;
    }

    else
    {
        cout << "Credit card status : Invalid! " << endl;
    }

    cout << endl;

    cout << "Thank you for using our validation program! " << endl;
}

int sumOne(int array[], int size)
{
    cout << endl;

    cout << "Sum 1 : ";

    int sum = 0;                                   // Variable to store the processed numbers

    for(int i = size - 2; i >= 0; i -= 2)          // Loop iterates in reverse order from the second to last number and with each iteration decreases by 2 
    {
        int paired = array[i] + array[i];           

        if (paired >= 10)                           
        {
            sum += paired % 10;
            sum += paired / 10;
        }

        else
        {
            sum += paired;                         // Paired value added to variable sum
        }
    }

    for(int j = 0; j < size; j += 2)               // Loop iterates the array with each iteration increasing by 2 
    {
        int multiply = array[j] * 2;               // Multiplies the current number value by 2

        int output = 0;

        if(multiply >= 10)
        {
            output = output + (multiply % 10);
            output = output + (multiply / 10);
        }

        else
        {
            output = multiply;                      // Not necessary to separate the numbers
        }

        cout << output << " ";
    }

    cout << endl;

    return sum;
}

int sumTwo(int array[], int size)
{
    cout << endl;

    cout << "Sum 2 : ";

    int sum = 0;

    for(int i = 1; i <= (size - 2); i += 2)         // Loop iterates from the second number and each iteration increases by 2
    {
        sum += array[i];                            // Adds current number to the sum variable
        cout << array[i] << " ";                    // Displays current number with a space
    }

    cout << endl;

    return sum;
}

int calculateSum(int sum1, int sum2)
{
    int sumTotal = sum1 + sum2;                     // Calculates total sum and stores it in the variable sumTotal

    cout << "Total sum : " << sumTotal << endl;

    cout << endl;

    int sumCheck = (sumTotal * 9) % 10;             // Multiplies sumTotal by 9 and takes the modulo 10 to make sure the sumCheck is between 0 and 9

    return sumCheck;                                // Returns single digit number
}
