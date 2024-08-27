# Do subarrays ko merge karne wali function
def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    # Temporary arrays banayenge
    L = arr[left:mid+1]
    R = arr[mid+1:right+1]

    # Merge process start karenge
    i = j = 0
    k = left

    # Dono subarrays ko merge karenge
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Agar L[] mein kuch elements bache hain to unhe copy karenge
    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1

    # Agar R[] mein kuch elements bache hain to unhe copy karenge
    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1

# Merge Sort ko implement karne wali function
def mergeSort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2

        # Pehla aur doosra half ko sort karenge
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)

        # Sorted halves ko merge karenge
        merge(arr, left, mid, right)

# Array ko print karne ki utility function
def printArray(arr):
    for i in arr:
        print(i, end=" ")
    print()

# Main code
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]

    print("Given array hai")
    printArray(arr)

    mergeSort(arr, 0, len(arr) - 1)

    print("\nSorted array hai")
    printArray(arr)
