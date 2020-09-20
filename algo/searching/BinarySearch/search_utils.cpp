#include "search_utils.h"

SearchUtil * SearchUtil :: instance = nullptr;
int SearchUtil::BSUtil(int * arr, int l, int r, int item)
{
    if (l > r)
        return -1;

    int mid = l + (r-l)/2;
    if(arr[mid] == item)
        return mid;

    if(item < arr[mid]) {
        return BSUtil(arr,l,mid-1,item);
    } else {
		return BSUtil(arr, mid + 1, r, item);
    }

    return -1;
}

int SearchUtil::BinarySearchRecursive(int * arr, int size, int item)
{
    int pos = BSUtil(arr, 0 , size - 1, item);
    return pos;
}
int SearchUtil::BinarySearchIterative(int * arr, int size, int item)
{
	int l = 0, r = size - 1, mid;
	//while (l <= r) {
	//	mid = l + (r - l) / 2;
	//	if (arr[mid] == item) {
	//		return mid;
	//	}
	//	if (item < arr[mid]) {
	//		r = mid - 1;
	//	}
	//	else {
	//		l = mid + 1;
	//	}
	//}
/*
	// avoid conditional check inside loop
	{
		while (r - l > 1) {
			mid = l + (r - l) / 2;
			if (item < arr[mid]) {
				r = mid;
			}
			else {
				l = mid;
			}
		}

		if (arr[l] == item)
			return l;
		else if (arr[r] == item)
			return r;
		else
			return -1;
	}

*/
	// avoid conditional check inside loop
	{
		while (r - l > 1) {
			mid = l + (r - l) / 2;
			if (item < arr[mid]) {
				r = mid;
			}
			else {
				l = mid;
			}
		}

		if (arr[l] == item)
			return l;
		else if (arr[r] == item)
			return r;
		else
			return -1;
	}

	return -1;
}

int SearchUtil::BinarySearchIterativeFloorValue(int * arr, int size, int item)
{
	int l = 0, r = size - 1, mid;
	
	while (r - l > 1) {
		mid = l + (r - l) / 2;
		if (item < arr[mid]) {
	
			r = mid;
		}
		else {
			l = mid;
		}
	}

	if (arr[l] == item)
		return l;
	else if (arr[r] == item)
		return r;
	else
		return l;
}