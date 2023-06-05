from math import gcd

n = int(input())
r = list(map(int, input().split()))

num = 0
den = 1
for i in range(n):
    for j in range(i + 1, n):
        num = (
            num * 2 * max(r[i], r[j])
            + (2 * r[i] - (min(r[i], r[j]) + 1)) * den
        )
        den = den * 2 * max(r[i], r[j])
        d = gcd(num, den)
        num //= d
        den //= d

print(f"{round(num / den, 6):.6f}")
