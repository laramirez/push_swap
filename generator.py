import random
nums = 4
a = range(-500,500)
for i in xrange(nums):
    b = a[random.randint(0, len(a)-i)]
    a.remove(b)
    print b