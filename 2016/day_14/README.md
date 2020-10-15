This one seems like it would be fun to optimize.

Small typo decreased the timing from ~47s to ~23s.
Changing the hash to the ones supplied by macOS changed it to
~13s. Changing it to -O3 but with non CC md5 brought it down to
~7s. Interestingly -O3 with the macOS md5 is ~10s.
So there is enough room to play and optimize here.

Might have to try out memoization with this this. But
sliding window should be just as fast, if not faster due to easier
lookup.