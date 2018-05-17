from fractions import gcd

a = int(input())
b = int(input())

print ("SUM:\n" + str(a+b) + "\n\n")
print ("SUB:\n" + str(a-b) + "\n\n")
print ("MUL:\n" + str(a*b) + "\n\n")
print ("DIV:\n" + str(a/b) + "\n\n")
print ("MOD:\n" + str(a%b) + "\n\n")
print ("GCD:\n" + str(gcd(a, b)) + "\n\n")
