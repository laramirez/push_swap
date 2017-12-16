import random
nums = 5
a = range(-1000,100)
for i in xrange(nums):
    b = a[random.randint(0, len(a)-i)]
    a.remove(b)
    print b