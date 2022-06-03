class Solution
{
    public:
        bool checkIfExist(vector<int> &arr)
        {

            sort(arr.begin(), arr.end());
            int i = 0;
            int zero = 0;
            bool res = false;
            for (int i = 0; i < arr.size(); i++)
            {
                
                if(arr[i] != 0){
                res = binary_search(arr.begin(), arr.end(), arr[i] *2);
                if (res)
                    return true;
                }else
                    zero++;
               
                    
            }
            return zero >= 2;
            
        }
};