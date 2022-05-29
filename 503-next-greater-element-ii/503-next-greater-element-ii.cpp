class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &num2)
        {
            stack<int> stk;
            stack<int> secSt;
            vector<int> res(num2.size(),-1);
            vector<int> notFound(num2.size(),0);
            stk.push(num2[num2.size() - 1]);
            int k = 1;
            notFound[0] = num2.size() - 1;
            for (int i = num2.size() - 2; i >= 0; i--)
            {
                while (stk.size() > 0 and stk.top() <= num2[i])
                    stk.pop();
                if (!stk.empty())
                {
                    res[i] = stk.top();
                    secSt.push(stk.top());
                }
                else
                {
                    res[i] = -1;
                    secSt.push(num2[i]);
                    notFound[k++] = i;
                }

                stk.push(num2[i]);
            }
            int i = 0;
            secSt.push(num2[0]);
            while (i < k and!secSt.empty())
            {
                while (!secSt.empty() and num2[notFound[i]] >= secSt.top())
                        secSt.pop();
                if (!secSt.empty())
                {
                    res[notFound[i]] = secSt.top();
                }
                i++;
            }
            return res;
        }
};