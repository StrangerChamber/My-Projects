
#each movement will either be vertical or horizontal
#thus we can form a triangle between the two points 
#we can  use this triangle to find the vert and horizontal distance to be traveled by using the difference between the y and x values of each point
#then 1 must be added to account for the start point
#|(y2-y1)|+|(x2-x1)|+1 will give the distance for any pair of points as long as there are no obstacles

def shortest_path_grid(grid, start, goal):
   
    x = goal[0]-start[0]
    y = goal[1]-start[1]
    
    if x < 0:
        x = x * -1
    
    if y < 0:
        y = y * -1
    
    dist = x + y + 1
    
    return dist



if __name__ == "__main__":
    grid = [[0,0,0],
            [0,0,0],
            [0,0,0]]
    start, goal = (0,0), (2,2)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == 5

