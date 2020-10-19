Probably some math to do this. Could create a 3D array
that has previous block size, so that it doesn't have to recalculate
the summation of some of the rects.

But for this one I just ran it with -O3 flags. Made a really, really big
difference. Will have to learn how and why some time. Really big improvement.