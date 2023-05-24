int compare_int(const void* a, const void* b){
  return (*(int*) a - *(int*) b);
}

bool containsDuplicate(int* nums, int numsSize){
  qsort(nums, numsSize, sizeof(int), compare_int);

  for(int i = 0; i < numsSize; ++i){
    if(i != numsSize -1 && nums[i] == nums[i+1]) return true;
  }

  return false;
}