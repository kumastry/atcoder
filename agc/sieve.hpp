struct sieve
{
    int prime[10000000];
    bool is_prime[100000000 + 1];
    int pcnt = 0;

    sieve(int n) {
    for(int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
 
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[pcnt++] = i;
            for(int j = 2*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    }
};

