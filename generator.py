import random
nums = 3
a = range(-100,100)
for i in xrange(nums):
    b = a[random.randint(0, len(a)-i)]
    a.remove(b)
    print b