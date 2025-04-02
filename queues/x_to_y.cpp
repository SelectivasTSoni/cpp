// x_to_y.cpp

#include <iostream>
#include <queue>

int convertXY(int src, int dst) 
{
    std::queue<int> que;
    std::vector<int> arr(100);
    
    int steps = 0;
    int index = 0;
    int value;
    
    que.push(src);
    
    std::cout << "Path: ";
    while (que.size() != 0) 
    {
        value = que.front();
        que.pop();
        arr[index++] = value;
        if (value == dst) 
        {
            std::cout << "\n" << "Steps count: " << steps << std::endl;
            return steps;
        }
        
        steps++;
        if (value < dst)
            que.push(value * 2);
        else
            que.push(value - 1);

        std::cout << que.back() << ' ';
	}
	
	return -1; 
}


int main() 
{
    convertXY(5, 27);
	return 0; 
}