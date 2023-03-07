from collections import deque 

def shortest_path_grid(grid, start, goal):
    
    n = len(grid)
    m = len(grid[0])
    #set up queue to be used for organizing nodes
    starter = (start[0],start[1],0)
    queue = deque([(0, starter)])
    #making a dict for visited nodes
    visited = dict()
    #fill the dict with the starting position
    visited[starter[:2]] = starter[-1]
    #queue loop to find the length of a shortest path
    #if make it out pf loop means no path
    while queue: 
        #set first 4 entries of queue to vars
        steps, (row,col,rem) = queue.popleft()
        if(row,col) == goal: 
            #if we've reached our goal return steps+1 to account for the start node
            return steps+1 
        #set remaining nodes 
        rem -= grid[row][col]
        #if none left start next loop
        if rem < 0:
            continue

        for new_row, new_col in [(row, col+1), (row+1, col), (row, col-1), (row-1,col)]:
            #if inbounds set new state
            if(0<=new_row<n) and (0<=new_col<m):
                new_state = (new_row, new_col, rem)
                #if not in visited or if rem > visited of new state append to queue
                if new_state[:2] not in visited or rem > visited[new_state[:2]]:
                    visited[new_state[:2]] = rem
                    queue.append((steps+1, new_state))
    return -1

            


    

if __name__ == "__main__":
    grid = [[0,0,0],
            [1,1,0],
            [1,1,0]]
    start, goal = (1,2), (0,0)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == 4

    grid = [[0,1],
            [1,0]]
    start, goal = (0, 0), (1,1)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == -1