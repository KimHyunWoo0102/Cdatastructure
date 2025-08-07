#include "InterpolSearch.h"

int ISearch(int arr[], int first, int last, int target)
{
    if (!(arr[first]<=target&&target<=arr[last]))
        return -1;

    int mid = first + (target - arr[first]) / (arr[last] - arr[first]) * (last - first);

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return ISearch(arr, first, mid - 1, target);
    else
        return ISearch(arr, mid + 1, last, target);
}
