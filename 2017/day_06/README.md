This would be better if all the numbers were used to form a key
and each new state was stored in a dict/ hash table. (Rabin fingerprint variant)

There might be some other interesting way to solve this problem
however. Floyd collision algorithm would check for looping, but this
is guaranteed. Perhaps there is a way to get the size of the cycle
and or the second reentrance into the cycle loop.