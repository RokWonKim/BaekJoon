def solution(triangle):
    answer = 0
    t_len = len(triangle)
    
    for x in range(0,t_len):
        for y in range(0,len(triangle[x]) ):
            if x == 0:
                break;
            else:
                if y > 0 and y != len(triangle[x])-1:
                    triangle[x][y] = max([triangle[x-1][y-1]+triangle[x][y],triangle[x-1][y]+triangle[x][y]])
                elif y == len(triangle[x])-1:
                    triangle[x][y] += triangle[x-1][y-1]
                else:
                    triangle[x][y] += triangle[x-1][y]
    answer = max(triangle[t_len-1])
    return answer
