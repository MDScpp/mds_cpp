#include <iostream>

// this is function checkNumber
void checkNumber(int number) {
    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }
}

   /*
    *def checkNumber( number ):
    *    if number :
    *        printf( "The number is positive.")
    *    elif nuber < 0 :
    *        printf( "The number is negative.")
    *    else: 
    *        printf( "The number is zero.")
    *
    */

// this is also function  printWhileLoop
void printWhileLoop() {
    std::cout << "Counting from 5 to 1 using while loop:" << std::endl;
    int count = 5;

    while (count > 0) {
        std::cout << count << " ";
        --count;
    }

    do {
        std::cout << count << " ";
        --count;
    } while (count < 0 ) ; 

    std::cout << std::endl;
}


void printForLoop() {
    std::cout << "Counting from 1 to 5 using for loop:" << std::endl;
    int i = 0;
    for ( ;  i < 5;   ++i  ) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}


void printForLoopAsWhile() {
    std::cout << "Counting from 1 to 5 using for loop:" << std::endl;
    int i = 0;
    { 
        while (i< 5) {
            std::cout << i << " ";
            ++i ;// i+=1; // same i++; same i = i+1;
        }
    }
    std::cout << std::endl;
}


void processSwitchCase() {
    std::cout << "Enter a number from 1 to 3: ";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "You selected one." << std::endl;
            break;
        case 2:
            std::cout << "You selected two." << std::endl;
            break;
        case 3:
            std::cout << "You selected three." << std::endl;
            break;
        default:
            std::cout << "Invalid selection!" << std::endl;
            break;
    }

}





int main (){
    int a = 120;
    int b = 30;
    int*  b_p = &b;  

    std::cout << ( long long int ) b_p << " " << *(b_p+1); 
    return 0;
}
