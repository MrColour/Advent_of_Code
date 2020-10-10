This would be better if all the numbers were used to form a key
and each new state was stored in a dict/ hash table. (Rabin fingerprint variant)

There might be some other interesting way to solve this problem
however. Floyd collision algorithm would check for looping, but this
is guaranteed. Perhaps there is a way to get the size of the cycle
and or the second reentrance into the cycle loop.

Come back to thi one latter, figured out the method. Involves the part 2 solution
and Floyds algorithm. By having a pointer that is loop_cycles ahead iterating both
until they match. All the elements inside the loop are unique, and can only be found
in the loop itself.