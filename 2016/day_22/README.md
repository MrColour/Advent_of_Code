Will have to come back to this one.
It seems a lot of people actually did it by hand...
For the most case it devolved into the Sliding Puzzle,
The usual way to solve such a problem would be to implement
the A* algorithm.

My current solution is using BFS with a queue. The only problem
is that the nature of the problem may require a lot of memory to
end up being used.

UPDATE: It seems that even BFS would not be a possible solution
for the general case. The search space is roughly:

(A * M)^(S) where
A is the average amount of tiles that can move
M is the average moves each tile can do
S is the steps needed to solve the puzzle

