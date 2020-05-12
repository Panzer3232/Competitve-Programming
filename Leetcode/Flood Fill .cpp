/*An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.*/






class Solution {
public:
    void isLocationSafe(vector<vector<int>>& image,int i,int j,int color,int paint){
    if(i<0 || j<0 || i>=image.size()||j>=image[0].size() || image[i][j]!=color )
        return;
    image[i][j]=paint;
    
    isLocationSafe(image,i+1,j,color,paint);
    isLocationSafe(image,i-1,j,color,paint);
    isLocationSafe(image,i,j+1,color,paint);
    isLocationSafe(image,i,j-1,color,paint);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int prevc=image[sr][sc];
        if(image.size()&&prevc!=newColor){
        isLocationSafe(image,sr,sc,prevc,newColor);
        }
        return image;
    }
};
