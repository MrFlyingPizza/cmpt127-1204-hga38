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
