// scrambled.c
// check if two arrays have the same values
// #include <assert.h>
// #include <stdio.h>

// int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ) {
//   unsigned short check_arr[len]; // val found punch card
//   for (unsigned int i = 0; i < len; i++) {
//     check_arr[i] = 0;
//   }

//   unsigned short found; // inner loop variables
//   unsigned int in_i = 0;

//   unsigned int out_i = 0; // outer loop variables
//   unsigned int searched_val;
//   unsigned short same = 1;
//   while (same == 1 && out_i < len) {
//     searched_val = arr1[out_i]; // assign val to search in second array
//     // printf("loop iter: %u searched val: %u\n", out_i, searched_val);
//     found = 0;
//     in_i = 0;
//     while (found == 0 && in_i < len) { // loop through second array
//       if (searched_val == arr2[in_i] && check_arr[in_i] == 0) { // set punchcard
//         found = 1;
//         check_arr[in_i] = 1;

//         // printf("\tpunchcard set,");
//         // for (unsigned int i = 0; i < len; i++) {
//         //   printf(" %u", check_arr[i]);
//         // }
//       }

//       // printf(" inner loop iter: %u\n", in_i);
//       in_i++;
//     }

//     if (found == 0) { // exit outter loop when one value doesnt exist in the second list
//       same = 0;
//     }

//     out_i++;
//   }

//   // check for left over values
//   out_i = 0;
//   while (same == 1 && out_i < len) {
//     if (check_arr[out_i] == 0) {
//       same = 0;
//     }
//     out_i++;
//   }

//   return same;
// }

// exercise 4 scrambled.c
// This program tallies instances of elements
// from two arrays and compares the amounts.
// if the amounts are the same then the two
// arrays contain the same values.
// Assuming the two arrays are the same size.
// and only contains values from 0 to 99
//
// By Richard Gao
// JUN 13, 2020
//


int scrambled(unsigned int arr1[], unsigned int arr2[], unsigned int len)
{
    unsigned int tally1[100] = {0}; // make arrays for tallying values from 0 - 99
    unsigned int tally2[100] = {0};

    for (unsigned int i = 0; i < len; i++) // tally loop
    {
        tally1[arr1[i]] += 1;
        tally2[arr2[i]] += 1;
    }

    for (unsigned int i = 0; i < 100; i++) // tally comparison loop
    {
        if (tally1[i] != tally2[i])
        {
            return 0;
        }

    }
    return 1;
}

// int main(void) {
//   unsigned int ar1[4] = {1,2,3,3};
//   unsigned int ar2[4] = {3,1,3,2};
//   int result1 = scrambled(ar1, ar2, 4);
//   assert(result1 == 1);
//
//   unsigned int ar3[4] = {3,2,3,4};
//   unsigned int ar4[4] = {1,2,3,4};
//   int result2 = scrambled(ar3, ar4, 4);
//   assert(result2 == 0);
//   return 0;
// }
