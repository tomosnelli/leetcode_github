/*
  278. First Bad Version
*/
int firstBadVersion(int n) {
  int low = 1;
  int high = n;

  while(low < high){
    int middle = (low + high) / 2;
    if(!isBadVersion(middle)){
      low = middle + 1;
    } else {
      high = middle;
    }
  }

  return low;
}
