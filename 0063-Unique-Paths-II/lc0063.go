// Go solution.

// DP method
// f(i, j) = f(i-1, j) + f(i, j-1) if grid[i][j] == 0 else 0
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    rowNum := len(obstacleGrid)
    if rowNum == 0 {
        return 0
    }
    columnNum := len(obstacleGrid[0])

    if obstacleGrid[0][0] == 1 {
        return 0
    }

    dp := make([][]int, rowNum)
    for i := 0; i < rowNum; i++ {
        dp[i] = make([]int, columnNum)
        if i == 0 {
            dp[0][0] = 1
        } else {
            dp[i][0] = dp[i-1][0] & (1 - obstacleGrid[i][0])
        }
    }

    for j := 1; j < columnNum; j++ {
        dp[0][j] = dp[0][j-1] & (1 - obstacleGrid[0][j])
    }

    for i := 1; i < rowNum; i++ {
        for j := 1; j < columnNum; j++ {
            if obstacleGrid[i][j] == 1 {
                dp[i][j] = 0
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
            }
        }
    }
    return dp[rowNum-1][columnNum-1]
}

// DP method with O(N) space complexity
// f(i, j) = f(i-1, j) + f(i, j-1) if grid[i][j] == 0 else 0
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    rowNum := len(obstacleGrid)
    if rowNum == 0 {
        return 0
    }
    columnNum := len(obstacleGrid[0])

    if obstacleGrid[0][0] == 1 {
        return 0
    }

    dp := make([]int, columnNum)
    dp[0] = 1
    for i := 0; i < rowNum; i++ {
        dp[0] &= (1 - obstacleGrid[i][0])
        for j := 1; j < columnNum; j++ {
            if obstacleGrid[i][j] == 1 {
                dp[j] = 0
            } else {
                dp[j] += dp[j-1]
            }
        }
    }
    return dp[columnNum-1]
}