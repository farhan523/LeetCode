```
class Solution
{
public:
​
set<int> col;
vector<vector < string>> result;
vector<string> temp;
int N;
void place(string res,int queen,int rows,pair<int,int>pr){
if(temp.size() == N)
result.push_back(temp);
if(rows > N || queen == N)
return;
for(int i=0;i<N;i++){
if(col.find(i) == col.end() && i != pr.first && i != pr.second){
// row.clear();
col.insert(i);
// row.insert(i + 1);
// row.insert(i - 1);
res[i] = 'Q';
temp.push_back(res);
res[i] = '.';
place(res,queen + 1,rows+1,{i+1,i-1});
col.erase(i);
// row.erase(rows + 1);
// row.erase(rows - 1);
res[i] = '.';
temp.pop_back();
​
}