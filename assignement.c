/*#include <stdio.h>
int main() {
    int values[10];
    printf("Enter 10 integer values:");
    int i,j;
    for (i=0;i<10;++i) {
        scanf("%d",&values[i]);
    }
    printf("\nThe Repeated elements are:-\n");
    for (i=0;i<10;++i) {
        for (j=i+1;j<10;++j) {
            if (values[i]==values[j]) {
                printf("%d\n",values[i]);
            }
        }
    }
   
}

#include <stdio.h>
struct Library {
    int flag,AccessionNumber;
    char Title[35],Author[25];
    float Price;
};
struct Library books[10];
void AddBookinfo() {
    struct Library b;
    int check;
    printf("Enter book title: ");
    scanf("%s",&b.Title);
    printf("Enter author name: ");
    scanf("%s",&b.Author);
    printf("Enter accession number: ");
    scanf("%d",&b.AccessionNumber);
    printf("Enter the price of book: ");
    scanf("%f",&b.Price);
    printf("Is the book issued or not?(0/1): ");
    scanf("%d",&check);
    if (check==1 || check==0 ){
        b.flag = check;
    }
}
void DisplayBookinfo() {
    struct Library b;
    printf("Title of the book: %s\n",b.Title);
    printf("Author of the book: %s\n",b.Author);
    printf("Accession number: %d\n",b.AccessionNumber);
    if (b.flag){
        printf("The book is currently issued.");
    }
    else {
        printf("The book is available to be issued.");
    }
}
void Filter_Author(){

}
void SelectedTitle(){
    struct Library b;
    char t[40];
    printf("Enter title: ");
    scanf("%s",&t);
    printf("Selected title is: %s",t);
}
void BookNumbers() {

}
int main() {
    char choice;
    printf("Press 'a' to: Add book information\nPress 'b' to: b) Display book information\nPress 'c' to: c) List all the books of a given author\nPress 'd' to: d) List the title of the specified book\nPress 'e' to: e) List the count of books in the library\nPress 'f' to: f) List the books in the order of accession number\nPress 'g' to: g) Exit\nEnter choice:");
    scanf("%c",&choice);
    while (1) {
        switch (choice) {
        case 'a':
        AddBookinfo();
        case 'b':
        DisplayBookinfo();
        case 'c':
        Filter_Author();
        case 'd':
        SelectedTitle();
        case 'e':
        BookNumbers();
        case 'f':
        SortAccessionNo();
        case 'g':
        break;
        default:
        printf("Invalid choice!");
        }
    } 
}*/

#include<stdio.h>
#include<omp.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // num is divisible by i, hence not prime
        }
    }
    return true; // num is prime
}

int main() {
    int N;
    int prime_count = 0;

    // Get the upper limit N from the user
    printf("Enter the value of N: ");
    scanf("%d", &N);

    double start_time = omp_get_wtime();
    // Loop through all numbers from 2 to N and count primes
    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            prime_count++; // Increment the prime count
        }
    }
    double end_time = omp_get_wtime();
    // Print the number of prime numbers
    printf("Number of prime numbers between 1 and %d is: %d\n", N, prime_count);
    printf("Time taken: %.6f seconds\n", end_time - start_time);
    return 0;
}
