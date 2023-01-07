class Solution {
public:
    int trailingZeroes(int n) {
        //So the Approach we use is that for trailing zeroes, we need to check for 10s. 10 = 2 * 5. And we need to check for 2*5s. Now we can get zeroes from 2*5, but there are a lot more number of 2s than 5s. So only by knowing the number of 5s, we can get the number of zeroes.
        //5! -> one 0 as there is only one 5 from 1 to 5.
        //10! -> two 0s as there are two 5s from 1 to 10.
        //15! -> three 0s as there are three 5s from 1 to 10.
        //20! -> four 0s as there are four 5s from 1 to 10.
        //Now we can repeatedly count number of 5s, by dividing n by 5 --> n/5. and count the number of 5s till n reaches 0.
        int count = 0;
        for(int i = 5; i <= n; i=i*5)
        {
            count = count + n/i;
        }
        return count;
    }
};