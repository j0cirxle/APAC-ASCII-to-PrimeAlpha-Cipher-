# ASCII-to-PrimeAlpha-Cipher(APAC)
This encryption algorithm converts the plaintext into ASCII codes, then performs prime factorization on each ASCII value. The resulting prime factors are mapped to alphabetic characters to create the ciphertext.


ASCII to PrimeAlpha Cipher (APAC) Encryption Process (Steps 1–4)

Step 1: Convert plaintext to ASCII codes
Each character is converted into its ASCII code, which is a number understood by computers.

Example:
"A" → 65
"b" → 98
" " (space) → 32

Step 2: Prime factorize the ASCII values
Each ASCII number is broken down into its prime factors.
(Prime factorization means expressing a number as a product of prime numbers.)

Example:
65 → 5 × 13
98 → 2 × 7 × 7
32 → 2 × 2 × 2 × 2 × 2

Step 3: Convert each prime factor into a letter
Each prime number is mapped to a letter using the rule:
a = 0, b = 1, c = 2, ..., z = 25

So:
5 → f
13 → n
2 → c
7 → h

Now if we go back to the previous examples:
65 → 5 × 13 → f n
98 → 2 × 7 × 7 → c h h
32 → 2 × 2 × 2 × 2 × 2 → c c c c c

Step 4: Compress repeated letters (optional)
If the same letter appears multiple times in a row, you can shorten it using a number + letter format.

Example:
c c c c c → 5c
h h → 2h

Final compressed outputs:
65 → fn
98 → c2h
32 → 5c
