// xor math!!
// xor ==> a^a=0 and a^b^b = a;
// using this iterate the entire array with ret set to 0 at start
// xor ret with each element of arr
// the unique value will be left in result as reset of the values will xor to 0
int unique(int *arr, int len)
{
  int res = 0;
  int itr = 0;

  while(itr < len)
  {
    res ^= arr[itr++];
  }
  return res;
}
