class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        // If the current pixel is already the target color, no need to proceed further
        if(image[sr][sc] == color)
            return image;

        // Store the original color of the starting pixel
        int temp = image[sr][sc];

        // Change the current pixel to the target color
        image[sr][sc] = color;

        // Get the dimensions of the image (number of rows and columns)
        int n = image.size();
        int m = image[0].size();

        // Recursively check and fill the pixel above (up) if it's within bounds and matches the original color
        if(sr-1 >= 0 && image[sr-1][sc] == temp)
            floodFill(image, sr-1, sc, color);

        // Recursively check and fill the pixel below (down) if it's within bounds and matches the original color
        if(sr+1 < n && image[sr+1][sc] == temp)
            floodFill(image, sr+1, sc, color);

        // Recursively check and fill the pixel to the left if it's within bounds and matches the original color
        if(sc-1 >= 0 && image[sr][sc-1] == temp)
            floodFill(image, sr, sc-1, color);

        // Recursively check and fill the pixel to the right if it's within bounds and matches the original color
        if(sc+1 < m && image[sr][sc+1] == temp)
            floodFill(image, sr, sc+1, color);

        // Return the modified image after performing the flood fill
        return image;
    }
};