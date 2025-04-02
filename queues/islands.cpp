// You are given an 8×8 grid (2D array) representing a map where 1 represents land and 0 represents water. An island is defined as a contiguous landmass consisting of at least one fully connected 2×2 block of 1s. That is, a 2×2 subgrid must be entirely filled with 1s to be considered part of an island. Islands may be larger than 2×2 but must include at least one such fully connected block. Your task is to determine the total number of distinct islands in the given 8×8 grid.

// 5 islands

grid = { 	{1, 1, 0, 0, 0, 1, 1, 0}, 
			{1, 1, 0, 0, 0, 1, 1, 0},
			{0, 0, 1, 1, 0, 0, 0, 0}, 
			{0, 0, 1, 1, 0, 0, 1, 1}, 
			{1, 0, 0, 1, 1, 0, 1, 1},
			{1, 0, 0, 1, 1, 0, 0, 0}, 
			{0, 0, 1, 1, 0, 0, 1, 1}, 
			{0, 0, 1, 1, 1, 0, 1, 1}
		};