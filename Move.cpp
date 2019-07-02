class Solution {
  public:
    int movingCount(int threshold, int rows, int cols) {
      if (threshold == 0)
        return 1;
      if (threshold < 0)
        return 0;
      int flag[][] = new int[rows][cols];
      return move(threshold, rows, cols, flag, 0, 0);
    }
  public:
    int move(int threshold, int rows, int cols, int* flag[] , int i, int j) {
      if (i >= rows || i < 0 || j >= cols || j < 0 || flag[i][j]==1 || bitSum(i)+bitSum(j)>threshold) {
        return 0;
      }
      flag[i][j] = 1;
      return move(threshold, rows, cols, flag, i+1, j)
        + move(threshold, rows, cols, flag, i-1, j)
        + move(threshold, rows, cols, flag, i, j+1)
        + move(threshold, rows, cols, flag, i, j-1)
        + 1;
    }
  public:
    int bitSum(int n) {
      if (n == 0)
        return 0;
      int sum = 0;
      while (n != 0) {
        sum += n % 10;
        n /= 10;
      }
      return sum;
    }
};
