import math


def sieve_of_eratosthenes(limit):
    """Generate a list of primes up to the given limit using the Sieve of Eratosthenes."""
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False  # 0 and 1 are not prime numbers
    for num in range(2, int(math.sqrt(limit)) + 1):
        if is_prime[num]:
            for multiple in range(num * num, limit + 1, num):
                is_prime[multiple] = False
    # Collect all prime numbers
    primes = [i for i, prime in enumerate(is_prime) if prime]
    return primes


def nth_superprime(n):
    """Find the n-th superprime."""
    # Estimate upper bound for the primes. A larger upper bound is set due to double indexing.
    upper_bound = 10000  # Estimated upper bound, chosen to ensure enough primes for indexing
    primes = sieve_of_eratosthenes(upper_bound)

    # Get the prime index list (1-indexed, but in zero-indexed terms it refers to primes)
    superprimes = [primes[prime_index - 1] for prime_index in primes if prime_index <= len(primes)]

    return superprimes[n - 1]


# Input from the user
n = int(input())
print(f"{nth_superprime(n)}")
