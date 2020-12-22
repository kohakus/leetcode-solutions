// C++ solution.

// The idea is Rejection Sampling.
// rand7() will get uniform random 1 ~ 7.
// (rand7() - 1) * 7 + rand7() - 1 will get uniform random 0 ~ 48.
// We discard 40 ~ 48, now we have rand40 equals to random 0 ~ 39.
// We just need to return rand40 % 10 + 1 and we get random 1 ~ 10.

// (rand7() - 1) * 7 + rand7() - 1 gives:
// |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |
// | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
// |  1   |  0   |  1   |  2   |  3   |  4   |  5   |  6   |
// |  2   |  7   |  8   |  9   |  10  |  11  |  12  |  13  |
// |  3   |  14  |  15  |  16  |  17  |  18  |  19  |  20  |
// |  4   |  21  |  22  |  23  |  24  |  25  |  26  |  27  |
// |  5   |  28  |  29  |  30  |  31  |  32  |  33  |  34  |
// |  6   |  35  |  36  |  37  |  38  |  39  |  40  |  41  |
// |  7   |  42  |  43  |  44  |  45  |  46  |  47  |  48  |

// ((rand7() - 1) * 7 + rand7() - 1) % 10 + 1 gives:
// |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |
// | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
// |  1   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |
// |  2   |  8   |  9   |  10  |  1   |  2   |  3   |  4   |
// |  3   |  5   |  6   |  7   |  8   |  9   |  10  |  1   |
// |  4   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |
// |  5   |  9   |  10  |  1   |  2   |  3   |  4   |  5   |
// |  6   |  6   |  7   |  8   |  9   |  10  |  1   |  2   |
// |  7   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |

// In 9/49 cases, we need to start over again;
// In 40/49 cases, we call rand7() two times;
// The expected value for the number of calls to rand7() function: 49/40 * 2 = 2.45;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution {
public:
    int rand10() {
        int rand_num = 40;
        while (rand_num >= 40) {
            rand_num = (rand7() - 1) * 7 + rand7() - 1;
        }
        return rand_num % 10 + 1;
    }
};