class Solution
{

    int previous;

    void flood(vector<vector < int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] != previous or image[sr][sc] == newColor)
            return;
        image[sr][sc] = newColor;
        if (sr + 1 < image.size())
            flood(image, sr + 1, sc, newColor);
        if (sr - 1 >= 0)
            flood(image, sr - 1, sc, newColor);
        if (sc + 1 < image[0].size())
            flood(image, sr, sc + 1, newColor);
        if (sc - 1 >= 0)
            flood(image, sr, sc - 1, newColor);
    }

    public:
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int newColor)
        {
            previous = image[sr][sc];
            flood(image, sr, sc, newColor);
            return image;
        }
};