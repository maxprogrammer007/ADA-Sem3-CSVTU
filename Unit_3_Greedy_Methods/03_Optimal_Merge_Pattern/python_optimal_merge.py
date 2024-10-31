import heapq

def optimal_merge(sizes):
    # Create a min-heap from the list of file sizes
    heapq.heapify(sizes)

    total_cost = 0  # Total cost of merging

    # Merge files until one file remains
    while len(sizes) > 1:
        # Take the two smallest files
        first = heapq.heappop(sizes)
        second = heapq.heappop(sizes)

        # Merge the two files
        merged_size = first + second
        total_cost += merged_size

        # Push the merged size back into the heap
        heapq.heappush(sizes, merged_size)

    return total_cost

if __name__ == "__main__":
    sizes = [8, 4, 6, 12]

    min_cost = optimal_merge(sizes)
    print(f"Minimum cost to merge files: {min_cost}")
