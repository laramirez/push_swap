import random
nums = 10
a = range(-10000,10000)
for i in xrange(nums):
    b = a[random.randint(0, len(a)-i)]
    a.remove(b)
    print b