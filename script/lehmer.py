# Lehmer's gcd algorithm;  revised version

DIGIT_BITS = 30
BASE = 1 << DIGIT_BITS

def nbits(n, correction = {
        '0': 4, '1': 3, '2': 2, '3': 2,
        '4': 1, '5': 1, '6': 1, '7': 1,
        '8': 0, '9': 0, 'a': 0, 'b': 0,
        'c': 0, 'd': 0, 'e': 0, 'f': 0}):
    if n < 0:
        raise ValueError("The argument to _nbits should be nonnegative.")
    hex_n = "%x" % n
    return 4*len(hex_n) - correction[hex_n[0]]

def lehmer_gcd(a, b):
    if a < b:
        a, b = b, a

    while b >= BASE:
        size = nbits(a) - DIGIT_BITS
        x, y = int(a >> size), int(b >> size)
        # single-precision arithmetic from here...
        A, B, C, D = 1, 0, 0, 1
        while True:
            if y+C == 0 or y+D == 0:
                break
            q = (x+A)//(y+C)
            if q != (x+B)//(y+D):
                break
            A, B, x, C, D, y = C, D, y, A-q*C, B-q*D, x-q*y

        if B:
            a, b = A*a + B*b, C*a + D*b
        else:
            a, b = b, a % b

    if(b == 0):
	return a
    a, b = int(b), int(a%b)
    while b:
        a, b = b, a%b
    return a

a = input()
b = input()
print lehmer_gcd(a, b)
